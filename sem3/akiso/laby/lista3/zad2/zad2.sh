#!/bin/bash

# Script that displays information about the system.
# The information displayed includes: network speed, CPU usage, uptime, battery status, system load, memory usage.

# Function to format bytes to human-readable format
format_bytes() {
    local bytes=$1
    if ((bytes < 1024)); then
        echo "${bytes} B"
    elif ((bytes < 1048576)); then
        echo "$(bc <<< "scale=2; $bytes/1024") KB"
    else
        echo "$(bc <<< "scale=2; $bytes/1048576") MB"
    fi
}

# Function to read network speed
read_network_speed() {
    local interface=$1
    local rx_bytes=$(awk -v iface="$interface" '$1 ~ iface {print $2}' /proc/net/dev)
    local tx_bytes=$(awk -v iface="$interface" '$1 ~ iface {print $10}' /proc/net/dev)
    echo "$rx_bytes $tx_bytes"
}

# initialize variables
interface="wlo1" # change to your network interface
prev_rx=0
prev_tx=0
history_rx=()
history_tx=()
max_history=5

while true; do
    clear

    current=$(read_network_speed "$interface")
    rx=$(echo $current | cut -d ' ' -f1)
    tx=$(echo $current | cut -d ' ' -f2)

    if [[ $prev_rx -ne 0 ]]; then
        rx_speed=$((rx - prev_rx))
        tx_speed=$((tx - prev_tx))
        history_rx+=($rx_speed)
        history_tx+=($tx_speed)
            if (( ${#history_rx[@]} > max_history )); then
                history_rx=("${history_rx[@]:1}")
                history_tx=("${history_tx[@]:1}")
            fi
    else
        rx_speed=0
        tx_speed=0
    fi

    prev_rx=$rx
    prev_tx=$tx

    echo "Sieć ($interface):"
    echo "  Pobieranie: $(format_bytes $rx_speed)"
    echo "  Wysyłanie: $(format_bytes $tx_speed)"
    echo -n "  Historia pobierania: "
    echo
    for val in "${history_rx[@]}"; do echo "$(printf "%0.s#" $(seq 1 $((val / 1000))))"; done

    echo -n "  Historia wysyłania:  "
    echo
    for val in "${history_tx[@]}"; do echo "$(printf "%0.s#" $(seq 1 $((val / 1000))))"; done

    # cpu usage
    echo "CPU:"
    cpus=$(grep -c ^processor /proc/cpuinfo)
    for ((i=0; i<cpus; i++)); do
        usage=($(awk -v cpu="cpu$i" '$1 == cpu {print $2,$3,$4,$5}' /proc/stat))
        total=$(( ${usage[0]} + ${usage[1]} + ${usage[2]} + ${usage[3]} ))
        idle=${usage[3]}
        busy=$((total - idle))
        freq=$(cat /sys/devices/system/cpu/cpu$i/cpufreq/scaling_cur_freq 2>/dev/null || echo "N/A")
        percent=$((100 * busy / total))
        echo "  CPU $i: $percent% (${freq} kHz)"
    done

    # uptime
    uptime=$(awk '{print int($1)}' /proc/uptime)
    days=$((uptime / 86400))
    hours=$(( (uptime % 86400) / 3600 ))
    minutes=$(( (uptime % 3600) / 60 ))
    seconds=$((uptime % 60))
    echo "Czas działania systemu: ${days}d ${hours}h ${minutes}m ${seconds}s"

    # batery
    if [[ -f /sys/class/power_supply/BAT0/uevent ]]; then
        battery=$(grep POWER_SUPPLY_CAPACITY /sys/class/power_supply/BAT0/uevent | cut -d'=' -f2)
        echo "Stan baterii: $battery%"
    else
        echo "Bateria: Brak danych"
    fi

    # load
    loadavg=$(cat /proc/loadavg | awk '{print $1, $2, $3}')
    echo "Obciążenie systemu (1m, 5m, 15m): $loadavg"

    # memory
    meminfo=($(awk '/MemTotal|MemFree|Buffers/ {print $2}' /proc/meminfo))
    mem_total=${meminfo[0]}
    mem_free=${meminfo[1]}
    buffers=${meminfo[2]}
    mem_used=$((mem_total - mem_free - buffers))
    echo "Pamięć: $(format_bytes $((mem_total * 1024))) używane: $(format_bytes $((mem_used * 1024)))"

    sleep 1
done
