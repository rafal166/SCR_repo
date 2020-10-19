#!/bin/bash

usage() { 
    echo "Usage $0:"; 
    echo "[-d]    - gdzie ma szuka czyli scieszka dla find"; 
    echo "[-m]    - maska lub nazwy plikow do spakowania"; 
    echo "[-n]    - liczba dni w ciagu ktorych pliki byly modyfikowane"; 
    echo "[-a]    - pelna nazwa archiwum w ktorym ma byc wszystko spakowane"; 
    exit 1; 
}
numRegex='^[0-9]+$'

while getopts ":d:m:n:a:" o; do
    case "${o}" in
        d)
            d=${OPTARG}
            ;;
        m)
            m=${OPTARG}
            ;;
        n)
            n=${OPTARG}
            if ! [[ "$n" =~ $numRegex ]] ; then
               usage
            fi
            ;;
        a)
            a=${OPTARG}
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))
#
if [ -z "${d}" ] ; then # sprawdza czy ktoras zmienna nie jest pusta
    if [ -z $FAT_D ] ; then
        REPLY="";
        while [ -z "$REPLY" ]; do
            echo "Podaj katalog w ktorym rozpocznie sie wyszukiwanie:";
            read -i "";
        done
        d="$REPLY";
    else
        d=$FAT_D;
    fi
fi
#
if [ -z "${m}" ] ; then
    if [ -z $FAT_M ] ; then
        REPLY="";
        while [ -z "$REPLY" ]; do
            echo "Podaj maske lub nazwy plikow do spakowania:";
            read -i "";
        done
        m="$REPLY";
    else
        m="$FAT_M";
    fi
fi
#
if [ -z "${n}" ] ; then
    if [ -z $FAT_N ] ; then
        REPLY="";
        while [ -z "$REPLY" ]; do
            echo "Podaj liczbe dni w ciagu ktorych pliki byly modyfikowane:";
            read -i "";
        done
        n="$REPLY";
    else
        n=$FAT_N;
    fi
fi
#
if [ -z "${a}" ] ; then
    if [ -z $FAT_A ] ; then
        REPLY="";
        while [ -z "$REPLY" ]; do
            echo "Podaj liczbe dni w ciagu ktorych pliki byly modyfikowane:";
            read -i "";
        done
        a="$REPLY";
    else
        a=$FAT_A;
    fi
fi

echo "d = ${d}"
echo "m = ${m}"
echo "n = ${n}"
echo "a = ${a}"
echo $(tar -czvf $a $(find $d -mtime -$n -iname "$m"))