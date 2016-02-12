Playing with flag14 -e:

```
level14@nebula:~$ echo -n  AAAAAAAAAAA | ../flag14/flag14 -e
ABCDEFGHIJK
level14@nebula:~$ echo -n  111111111111 | ../flag14/flag14 -e
123456789:;<
level14@nebula:~$ 
```
the encrypting scheme seems obivous : every character is translated in ascii table according to its position in the string.

Performing the reverse algorithm with [decrypt.py](decrypt.py) on available token, we get 8457c118-887c-4e40-a5a6-33a25353165
which is flag14 password 

```
level14@nebula:~$ su flag14
Password: 
sh-4.2$ getflag
You have successfully executed getflag on a target account
```

