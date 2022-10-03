#!/bin/bash

usage()
{
    echo -e "usage: ./game.sh [player-name] [number of games]"
}


rm -rf SCORE
rm -rf *.report

if [ "$1" == "abanlin" ] ;then
    ./play_game.sh $1 $2
elif [ "$1" == "champely" ] ;then
    ./play_game.sh $1 $2
elif [ "$1" == "carli" ] ;then
    ./play_game.sh $1 $2
elif [ "$1" == "hcao" ] ;then
    ./play_game.sh $1 $2
elif [ "$1" == "grati" ] ;then
    ./play_game.sh $1 $2
elif [ "$1" == "superjeannot" ] ;then
    ./play_game.sh $1 $2
elif [ "$1" == "all" ]; then
    ./play_game.sh champely $2 &
    ./play_game.sh abanlin $2 &
    ./play_game.sh hcao $2 &
    ./play_game.sh grati $2 &
    ./play_game.sh superjeannot $2 &
    ./play_game.sh carli $2 &
else
    usage
fi