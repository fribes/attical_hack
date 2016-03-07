
strings output:

CH16
Hack In Paris - CHIP16 !                merenwen@hackinparis.com
Please, enter the password :
Bad password !
You lucky bastard.


Searching for an emulator or debugger I found:


http://ngemu.com/threads/chip16-official-thread-development-suggestions.145620/

which points to :

https://code.google.com/archive/p/mash16/downloads

which is able to break (pause) by pressing SPACE and step by pressing N

Running the code and stopping at the point the 8 inputs are in:


state @ cycle 1273503:   0090 [ cmpi r3, $0008 ]

...

there is a sequence of test against immediate values :

--------------------------------------------------------------
state @ cycle 1273507:   00a4 [ cmpi rd, $0002 ]
--------------------------------------------------------------
state @ cycle 1273510:   00b0 [ cmpi rd, $0001 ]
--------------------------------------------------------------
state @ cycle 1273513:   00bc [ cmpi rd, $0002 ]
--------------------------------------------------------------
state @ cycle 1273518:   00c8 [ cmpi rd, $0001 ]
--------------------------------------------------------------
state @ cycle 1273521:   00d4 [ cmpi rd, $0004 ]
--------------------------------------------------------------
state @ cycle 1273526:   00e0 [ cmpi rd, $0004 ]
--------------------------------------------------------------
state @ cycle 1273531:   00ec [ cmpi rd, $0008 ]
--------------------------------------------------------------
state @ cycle 1273536:   00f8 [ cmpi rd, $0008 ]
--------------------------------------------------------------

As rd register is popped from the stack, the sequence to be entered on the keyboard is the opposite as tested values order, ie 8 first. 
the sequence is then  8 8 4 4 1 2 1 2 

which maps to right right left left up down up down :-)
