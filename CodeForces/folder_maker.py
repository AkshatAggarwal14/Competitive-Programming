#!/usr/bin/python3
import os
import sys
mypath = os.getcwd()


def getContestName(problem: str):
    contest_name = ""
    for c in problem:
        if not c.isdigit():
            break
        contest_name += c
    return contest_name


def makeFolders():
    onlyfiles = [f for f in os.listdir(mypath) if os.path.isfile(
        os.path.join(mypath, f)) and f[0].isdigit()]

    contests = {}
    added = []

    #  make a dict {contest :[problems]}
    for code in onlyfiles:
        contest_name = getContestName(code)
        if contest_name not in added:
            temp = []
            temp.append(code)
            contests[contest_name] = temp
            added.append(contest_name)
        else:
            contests[contest_name].append(code)

    print(contests)

    # make the folders and move the files
    for contest in contests:
        try:
            os.mkdir(os.path.join(mypath, contest))
            for code in contests[contest]:
                os.rename(os.path.join(mypath, code),
                          os.path.join(mypath, contest, code))
                # os.rename('D:/NITH/CP/CodeForces/'+code,
                #   'D:/NITH/CP/CodeForces/'+contest+'/'+code)
        except:
            print(contest, 'Already exists!')
            for code in contests[contest]:
                try:
                    os.rename(os.path.join(mypath, code),
                              os.path.join(mypath, contest, code))
                    # os.rename('D:/NITH/CP/CodeForces/'+code,
                    #   'D:/NITH/CP/CodeForces/'+contest+'/'+code)
                except:
                    print(contest, '/', code, 'Already exists!')


def getFiles():
    folders = [f for f in os.listdir(mypath) if os.path.isdir(
        os.path.join(mypath, f)) and f[0].isdigit()]
    # print(folders)
    for contest in folders:
        files = [f for f in os.listdir(
            os.path.join(mypath, contest)) if os.path.isfile(os.path.join(mypath, contest, f)) and f[0].isdigit()]
        # print(files)
        for code in files:
            os.rename(os.path.join(mypath, contest, code),
                      os.path.join(mypath, code))
        os.rmdir(os.path.join(mypath, contest))


if __name__ == "__main__":
    makeFolders()
    # getFiles()
    os.system('git add ./')
    os.system('git commit -m "'+sys.argv[1]+'"')
    os.system('git push')
