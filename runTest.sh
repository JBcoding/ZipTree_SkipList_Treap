#!/bin/bash

module load gcc/8.2.0
g++ -std=c++17 Test.cpp OrderedList.h ZipTree.h Treap.h SkipList.h ZipTree.cpp Treap.cpp SkipList.cpp -o Test.out

mkdir results

tests=(1 2 3 4)
structures=(1 2 3)
sizes=(65536 131072 262144 524288 1048576 2097152 4194304 8388608 16777216 33554432 67108864 134217728)

testCount=0
totalTestCount=$((${#tests[@]} * ${#structures[@]} * ${#sizes[@]}))

for test in "${tests[@]}"
do
 for structure in "${structures[@]}"
 do
  for size in "${sizes[@]}"
  do
   printf -v sizeNice "%09d" $size
   testCount=$((testCount+1))
   printf -v testCountNice "%04d" $testCount
   printf -v totalTestCountNice "%04d" $totalTestCount
   percentage="$(bc -l <<< "$testCount / $totalTestCount * 100")"
   printf -v percentageNice "%05.2f" $percentage
   echo "Runnning test #$test on structure $structure with limit $sizeNice, test $testCountNice out of $totalTestCountNice ($percentageNice%)"
   echo "$test $structure $size" | /usr/bin/time -f "%E %P %M" ./Test.out 2>&1 | tee results/$test-$structure-$sizeNice.txt
  done
 done
done
