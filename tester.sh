#!/usr/bin/env bash
FILES=files/*
rm run.log
for f in $FILES
do
    echo "Processing $f file..." >> run.log
    echo "=====================================================" >> run.log
    echo "Input" >> run.log
    cat $f >> run.log
    echo "\n\nOuput:" >> run.log
  ./avm $f >> run.log 2>&1
   echo "=====================================================" >> run.log
   echo "" >> run.log
done

rm drun.log
for f in $FILES
do
    echo "Processing $f file..." >> drun.log
    echo "=====================================================" >> drun.log
    echo "Input" >> drun.log
    cat $f >> drun.log
    echo "\n\nOuput:" >> drun.log
  ./avm -debug $f >> drun.log 2>&1
   echo "=====================================================" >> drun.log
   echo "" >> drun.log
done
