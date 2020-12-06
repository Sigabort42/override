#!/usr/bin/env python

import os

if __name__ == "__main__":
    for i in range(0, 21):
        res = 322424845 - i
        print(res)
        os.system("echo " + str(res) + " | ~/level03")
