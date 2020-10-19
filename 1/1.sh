#!/bin/bash

read -p "Na pewno chcesz czytac z $1? (y/n)" -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]];
then
	echo $(cat $1) > .tmp.txt
else
	echo "W takim razie koncze program"
	echo
	exit 1
fi

#
read -p "Na pewno chcesz to zapisac do $2? (y/n)" -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]];
then
	    mv .tmp.txt $2
else
	echo "W takim razie koncze program"
	echo
	exit 1
fi
#
echo "Przeczytano $1 i zapisano zawartosc do $2"
echo