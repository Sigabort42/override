#!/usr/bin/env python3

TAB = [
    "756e505234376848",
    "45414a3561733951",
    "377a7143574e6758",
    "354a35686e475873",
    "48336750664b394d"
]

PASSWD = ""

if __name__ == "__main__":
    for s in TAB:
        print(s, bytes.fromhex(s).decode('utf-8'))
        PASSWD += bytes.fromhex(s).decode('utf-8')[::-1]
    print(PASSWD)
