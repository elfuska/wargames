
# wargames
Wargames Simulator written in C highly based on the one written by Andy Glenn (kudos!).

Compiled using [The Amsterdam Compiler Kit](https://github.com/davidgiven/ack):

```
ack -mcpm -O4 -ansi -o wargames.com imsai8080.c
```
The cross compiled binary (wargames.com) can be copied to a CP/M disk using cpmutils:
```
cpmcp ./z80pack/imsaisim/disks/library/wargames.dsk wargames.com 0:WG.COM
```
Once inside imsaisim just cd into your disk and exec "WG".

I've included the compiled executable. Just copy to your disk and execute.
