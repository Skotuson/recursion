#! /bin/bash
clear
g++ -Wall -pedantic "$1" -fsanitize=address -g -o a
if [ "$#" -eq 3 ]; then {
    if [ "$2" = "to" ]; 
        then ./a > "$3";
    elif [ "$2" = "from" ]; 
        then ./a < "$2";
    fi
} else ./a
fi
rm a;