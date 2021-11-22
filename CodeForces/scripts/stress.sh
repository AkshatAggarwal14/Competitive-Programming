#!/usr/bin/env bash

if [ "$1" == "-h" ]; then
  echo "Usage: stress.sh [solA - wrong] [solB] [gen] [numTests]"
  echo "Runs solutionA and solutionB against test cases output by generator and outputs a test on which they give different results"
  exit 0
fi

build.sh $1
build.sh $2
build.sh $3

for ((testNum=0;testNum<$4;testNum++))
do
    ./$3 > input
    ./$2 < input > outSlow
    ./$1 < input > outWrong
    H1=`md5sum outWrong`
    H2=`md5sum outSlow`
    if !(cmp -s "outWrong" "outSlow")
    then
        echo "Error found!"
        echo "Input:"
        cat input
        echo "Wrong Output:"
        cat outWrong
        echo "Slow Output:"
        cat outSlow
        exit
    fi
done
echo Passed $4 tests

