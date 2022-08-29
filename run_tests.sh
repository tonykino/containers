#!/bin/bash

clear
# make fclean
rm -rf logs
mkdir logs
make -j CPPFLAGS='-Wall -Wextra -Werror -std=c++98 -MD -D STD' NAME='std.out';
make fclean;
make -j CPPFLAGS='-Wall -Wextra -Werror -std=c++98 -MD ' NAME='ft.out';

./std.out > logs/std.log;
./ft.out > logs/ft.log;

diff logs/std.log logs/ft.log > logs/diff.log;
rm ft.out std.out
make clean

if [ -s logs/diff.log ]; then
    echo "Diff found :'(";
else
    echo "No diff found between ft and std !";
fi