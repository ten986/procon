#!/bin/zsh

mkdir $3

for i in `seq 1 $1`
do
cp $2 "$3/$i.cpp"
done
