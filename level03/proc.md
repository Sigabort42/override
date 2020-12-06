En desassemblant le code on peux avoir peur avec tout ce que le binaire manipule d'adresse qui semblent étrange mais en faite c'est juste les caracteres ascii sous format hexadecimal.

Ce que l'on doit faire c'est lui passer un entier qui correspond a une chaine de carateres qui sera egal a "Congratulations!" une fois passé par tous les filtres présent dans le code.

Le script python nous permet de tester plus vite et nous donne le résultat.

```bash
level03@OverRide:/tmp$ ./level03.py
322424845
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424844
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424843
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424842
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424841
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424840
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424839
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424838
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424837
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424836
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424835
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424834
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424833
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424832
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424831
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424830
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424829
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424828
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424827
***********************************
*		level03		**
***********************************
Password:322424826
***********************************
*		level03		**
***********************************
Password:
Invalid Password
322424825
***********************************
*		level03		**
***********************************
Password:
Invalid Password
level03@OverRide:/tmp$ ls
level01  level03.py
level03@OverRide:/tmp$ cd
level03@OverRide:~$ ls
level03
level03@OverRide:~$ ./level03
***********************************
*		level03		**
***********************************
Password:322424827
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
$
```