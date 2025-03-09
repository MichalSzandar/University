#!/bin/bash

# Script that displays information about all processes in the system.
# The information displayed includes: PPID, PID, COMM, STATE, TTY, RSS, PGID, SID, OPEN_FILES.

echo -e "PPID\tPID\tCOMM\tSTATE\tTTY\tRSS\tPGID\tSID\tOPEN_FILES"
echo -e "------------------------------------------------------------------"

for pid in /proc/[0-9]*; do
  pid="${pid##*/}"

  if [[ -f "/proc/$pid/status" && -f "/proc/$pid/stat" ]]; then
    ppid=$(grep "^PPid" /proc/$pid/status | awk '{print $2}')
    comm=$(grep "^Name" /proc/$pid/status | awk '{print $2}')
    state=$(grep "^State" /proc/$pid/status |awk '{print $2}')
    tty=$(awk '{print $7}' /proc/$pid/stat)
    rss=$(grep "^VmRSS" /proc/$pid/status | awk '{print $2}')
    pgid=$(awk '{print $5}' /proc/$pid/stat)
    sid=$(awk '{print $6}' /proc/$pid/stat)

    open_files=$(ls /proc/$pid/fd 2>/dev/null | wc -l)
    echo -e "$ppid\t$pid\t$comm\t$state\t$tty\t$rss\t$pgid\t$sid\t$open_files"
  fi
done | column -t
