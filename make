#!/usr/bin/bash


# USE MAKEFILES, DAMN IT 
vars() {
    if [ -e $1 ];then 
        ls *.cpp | cut -d "." -f1
    else
        echo $1
    fi
}

make() {
    tar=$(vars $1)
    for f in $tar; do 
        g++ -c -fPIC -std=c++11 -I /usr/include/$(ls /usr/include | grep python3) -I src -o py.o $f.cpp
        g++ -shared  -o modd.so py.o -lboost_python38
    done
    rm $(ls *.o)
}

clr() {
    rm $(ls *.so 2> /dev/null) 2> /dev/null || echo E: lib is not built yet
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


