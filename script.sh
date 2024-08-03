#!/bin/bash 

FILENAME=$1

mkdir -p $FILENAME
for LETTER in {A..J}; do
	cd $FILENAME
	DIRNAME="exercise$LETTER"
	mkdir -p $DIRNAME
	
	touch "$DIRNAME/src.cpp"
	touch "$DIRNAME/in.txt"
	cd ..
done
