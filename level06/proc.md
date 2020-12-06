En desassemblant le code le code peut faire peur mais il n'en ai rien il suffit juste de comprendre que en fonction du logni passé il y a un numero de serie qui est associé et qui ne change pas.

Donc si on reverse avec gdb en prenant soin de desactivé le ptrace et de verifié quel valeur a le numéro de serie une fois le login envoyé et l'algorithme de chiffrement terminé on peux faire en sorte que sa match pour avoir acces la fonction system("/bin/sh").

```bash
level06@OverRide:~$ ./level06
***********************************
*		level06		  *
***********************************
-> Enter Login: 42born2code
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6236458
Authenticated!
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
$
```
