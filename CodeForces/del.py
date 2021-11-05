#!/usr/bin/python3
import os
import sys
mypath = 'D:/NITH/CP/CodeForces/'


def main(files: list):
    folders = [f for f in os.listdir(mypath) if len(f) >= 4 and f[:-4] in need]
    print(folders)
    # os.rmdir(mypath)
    pass


if __name__ == "__main__":
    need = ['.'+_ for _ in sys.argv[1:]]
    main(need)
    # getFiles()
    os.system('git add -A')
    os.system('git commit -m "Restructured"')
    os.system('git push')
