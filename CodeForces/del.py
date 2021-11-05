#!/usr/bin/python3
import os
import sys
mypath = 'D:/NITH/CP/CodeForces/'


def main():
    need = ['.'+_ for _ in sys.argv[1:]]
    if(len(need) == 0):
        return
    files = [f for f in os.listdir(mypath) if len(f) >= 4 and f[-4:] in need]
    print(files)
    for file in files:
        # print(os.path.join(mypath, file))
        os.remove(os.path.join(mypath, file))


if __name__ == "__main__":
    main()
