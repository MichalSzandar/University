# zad.1

##  ping
polecenie służące do wysyłania żądań echa do podanych serwerów.
przykładowe wywołanie:
ping -c 4 156.17.18.10
PING 156.17.18.10 (156.17.18.10) 56(84) bytes of data.
64 bytes from 156.17.18.10: icmp_seq=1 ttl=48 time=55.3 ms
64 bytes from 156.17.18.10: icmp_seq=2 ttl=48 time=54.9 ms
64 bytes from 156.17.18.10: icmp_seq=3 ttl=48 time=61.9 ms
64 bytes from 156.17.18.10: icmp_seq=4 ttl=48 time=57.5 ms

--- 156.17.18.10 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3004ms
rtt min/avg/max/mdev = 54.857/57.386/61.859/2.765 ms

(pingowanie serwera pwr)

-c oznacza ilosc wysłanych żądań
ttl (time to live) oznacza ilosc przeskokow ktore moze wykonac żądanie, po wykonaniu przeskoku zmniejsza się o 1.
Domyslna ilość przeskoków 