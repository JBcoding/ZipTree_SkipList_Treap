#!/bin/bash

module load gcc/8.2.0

mkdir results
mkdir results/count
mkdir results/noCount

comparatorArray=(1 1 1 2 2 1 1 1 2 2)
internalTest=(1 2 3 4 5 6 7 8 9 10)

randomRankArray=(0 0 0 0 0 0 0 1 2 3 4)
structures=(1 2 3 4 5 6 7 7 7 7 7)

sizes=(65536 131072 262144 524288 1048576 2097152 4194304 8388608 16777216 33554432 67108864 134217728)

testCount=0
totalTestCount=$((${#internalTest[@]} * ${#structures[@]} * ${#sizes[@]} * 2))

for count in 0 1 
do
 for ((i=0;i<${#internalTest[@]};++i)); do
  test=${internalTest[i]}
  comparator=${comparatorArray[i]}
  countNice="Not counting"
  countFolder="noCount"
  if [ $count == '1' ]; then
   comparator=3
   countNice="With counting"
   countFolder="count"
  fi
  for ((j=0;j<${#structures[@]};++j)); do
   structure=${structures[i]}
   randomRank=${randomRankArray[i]}
   g++ -std=c++17 -D COMPARATOR=${comparator} -D RANDOM_RANK=${randomRank} *.cpp -o Test.out
   for size in "${sizes[@]}" 
   do
    printf -v sizeNice "%09d" ${size}
    testCount=$((testCount+1))
    printf -v testCountNice "%04d" ${testCount}
    printf -v totalTestCountNice "%04d" ${totalTestCount}
    percentage="$(bc -l <<< "$testCount / $totalTestCount * 100")"
    printf -v percentageNice "%05.2f" ${percentage}
    structureNum=$((structure + randomRank))
    echo "Runnning test #$test on structure $structureNum with limit $sizeNice, $countNice, test $testCountNice out of $totalTestCountNice ($percentageNice%)"
    echo "$test $structure $size" | /usr/bin/time -f "%E %P %M" ./Test.out 2>&1 | tee results/${countFolder}/${test}-${structureNum}-${sizeNice}.txt
   done
  done
 done
done
