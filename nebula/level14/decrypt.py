#!/usr/bin/python

ENCRYPTED = "857:g67?5ABBo:BtDA?tIvLDKL{MQPSRQWW."

offset = 0
plain = ''
for c in ENCRYPTED:
	plain = plain +  chr(ord(c) - offset)
	offset +=1
print plain
