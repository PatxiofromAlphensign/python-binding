#!/usr/bin/bash
make() {
    if [ -e $1 ]; then
        g++ -c -fPIC -I /usr/include/python3.8 -o py.o *.cpp
    else
        g++ -c -fPIC -I /usr/include/python3.8 -o py.o $1
    fi
    g++ -shared  -o modd.so py.o -lboost_python38
}

clr() {
    for f in *.so *.o; do rm $f;done
}

if [ "$1" == "clear" ]; then
    clr
elif [ -e $1 ]; then
    make 
else
    make $1
fi
