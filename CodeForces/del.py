#!/usr/bin/python3
import os
import sys
mypath = os.getcwd()


def fileUTIL(filename: str):
    if '.' not in filename:
        return None
    return '.' + filename.split('.')[-1]


def deleter():
    if '--help' in sys.argv or '-h' in sys.argv:
        print('Usage:\npython .\\del.py <extensions> (- for no extension)]')
        return

    need = ['.' + _ for _ in sys.argv[1:]]
    files = [f for f in os.listdir(mypath) if os.path.isfile(
        os.path.join(mypath, f)) and fileUTIL(f) in need]
    if '.-' in need:
        for f in os.listdir(mypath):
            if os.path.isfile(os.path.join(mypath, f)) and fileUTIL(f) == None and f != 'Makefile':
                files.append(f)
    for file in files:
        print('Removed', os.path.join(mypath, file))
        os.remove(os.path.join(mypath, file))


if __name__ == "__main__":
    deleter()
