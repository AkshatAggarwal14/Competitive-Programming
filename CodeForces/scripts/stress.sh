#!/usr/bin/env bash

# exit immediately on error
set -e

if [ "$1" == "-h" ]; then
  echo "Usage: stress [solA - wrong] [solB] [gen] [numTests]"
  echo "Runs solutionA and solutionB against test cases output by generator and outputs a test on which they give different results"
  exit 0
fi

build.sh $1
build.sh $2
build.sh $3

for ((testNum=0;testNum<$4;testNum++)); do
  ./$3 > input
  ./$2 < input > outSlow
  ./$1 < input > outWrong
  diff outSlow outWrong > /dev/null || break
  echo "Passed Test $testNum"
done

if !(diff outWrong outSlow > /dev/null); then
  echo ""
  echo "WA on following test:"
  cat input
  echo "Your answer:"
  cat outWrong
  echo "Correct answer:"
  cat outSlow
  echo ""
  exit
fi

echo ""
echo Passed $4 tests

