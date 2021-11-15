#!/usr/bin/env bash

if [ "$1" == "-h" ]; then
  echo "Usage: ./testmaker.sh [gen] [sol] [numTests]"
  echo "Makes tests."
  exit 0
fi

bb.sh $1
bb.sh $2

for ((testNum=0;testNum<$3;testNum++))
do
    ./$1 > ./tests/test$testNum.in
    ./$2 < ./tests/test$testNum.in > ./tests/test$testNum.out
    echo Test \#$testNum made!
done
echo Made $4 tests for $1

