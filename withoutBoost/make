#!/usr/bin/bash

vars() {
    if [ -e $1 ];then 
        ls *.cpp
    else
        echo $1
    fi
}

make() {
    tar=$(vars $1)
    for f in $tar; do 
        g++ -c -fPIC -I /usr/include/python3.8 -o py.o $f.cpp
        g++ -shared  -o modd.so py.o -lboost_python38
    done
}

clr() {
    for f in *.so *.o; do rm $f;done
}

get_numfileS() {
    echo $(vars $1) | wc -w
}

if [ "$1" == "clear" ]; then
    clr
    exit
elif [ "$2" == "n" ]; then
    echo $(get_numfileS $1)
    exit
fi

make $1 


