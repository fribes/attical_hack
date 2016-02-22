Without much success here are my attemps on level16.

Exploration:
* target_script.pl is a copy of the vulnerable perl script from this level. I have been using it to get familiar with perl and to try my injections
* GETFLAG is a script that creates a 'flag' file to leave a trace that it has been executed (injection trials only)
* test_cmd.sh contains an example command to play with target_script.pl

Exploitation:
* CMD is the script to be executed on remote machine 
* install is a script to install CMD script on remote machine
* exploit.sh contains an example command that connects and injects data 

So far, I managed to find the correct data to make the perl script execute:
'''
$./target_script.pl "\"&./getflag&\""
$ cat flag
Injection successful!
'''

The tip to execute an arbitrary script, is to put it in a writable folder close to root, by exemple /tmp, and name it with uppercase as username var is translated to upper case.
Then use shell globbing  /*/CMD to refer to it. This way, no lower case letter is used.

URLencoded we get the command:
'''
curl http://<nebula machine>:1616/index.cgi?username="&%2F*%2FCMD&"
'''

Unfortunately, no flag file gets created in /home/level16, there's still something going wrong.



