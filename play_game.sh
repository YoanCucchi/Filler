#!/bin/bash

PWD=$(pwd)
PLAYER=$1
GAME=$2
ME=ycucchi.filler
VM=./resources/filler_vm
TRACE=./filler.trace
MAPS=$(find ./resources/maps/*)
i=1
ENEMYWIN=0
MYWIN=0


mkdir -p $PWD/SCORE/$PLAYER
for MAP in $MAPS
do
    STRMAP=$(echo $MAP |  cut -d '/' -f 4)
    i=1
    if [ ! -e "$PWD/SCORE/$PLAYER/$STRMAP.trace" ]; then
        touch $PWD/SCORE/$PLAYER/$STRMAP.trace
    fi
    echo -e "ON $STRMAP FOR $GAME GAME:" >> $PWD/SCORE/$PLAYER/$STRMAP.trace 
    if [ ! -e "$PWD/SCORE/$PLAYER/$STRMAP.result" ]; then
        touch $PWD/SCORE/$PLAYER/$STRMAP.result
    fi
    echo -e "DETAILS GAMES:" >> $PWD/SCORE/$PLAYER/$STRMAP.trace
    while [ "$i" -le "$GAME" ]
    do
        if [ "$(( $i % 2 ))" -eq "0" ]; then
            echo -e "IN $STRMAP MATCH $i P1 $PLAYER vs $ME P2 ..."
            $VM -f $MAP -p1 ./resources/players/$PLAYER.filler  -p2 ./$ME -q > $PWD/SCORE/$PLAYER/$STRMAP.result
            P2=$ME
            P1=$PLAYER
        else
            echo -e "IN $STRMAP MATCH $i P1 $ME vs $PLAYER P2 ..."
            $VM -f $MAP -p1 ./$ME -p2 ./resources/players/$PLAYER.filler -q > $PWD/SCORE/$PLAYER/$STRMAP.result
            P1=$ME
            P2=$PLAYER
        fi
        P1SCORE=$(grep "O fin" $PWD/SCORE/$PLAYER/$STRMAP.result | cut  -d' '  -f 4)
        P2SCORE=$(grep "X fin" $PWD/SCORE/$PLAYER/$STRMAP.result | cut  -d' '  -f 4)
        echo -e "GAME $i     P1: $P1 $P1SCORE VS $P2SCORE P2: $P2" >> $PWD/SCORE/$PLAYER/$STRMAP.trace
        if [ "$P2SCORE" -le "$P1SCORE" ];then
		    if [ "$P1" == "$ME" ]; then
                MYWIN=$(( $MYWIN + 1 ))
            fi
		    if [ "$P1" == "$PLAYER" ]; then
                ENEMYWIN=$(( $ENEMYWIN + 1 ))
            fi
        elif [ "$P1SCORE" -le "$P2SCORE" ];then
		    if [ "$P2" == "$ME" ]; then
                MYWIN=$(( $MYWIN + 1 ))
            fi
		    if [ "$P2" == "$PLAYER" ]; then
                ENEMYWIN=$(( $ENEMYWIN + 1 ))
            fi
        fi
        rm -f $PWD/SCORE/$PLAYER/$STRMAP.result
        i=$(( $i + 1 ))
    done
    let percent=$(((100*$MYWIN)/$GAME))
    echo -e "---------------------------------------------------" >> $PWD/SCORE/$PLAYER/$STRMAP.trace
    echo -e "PLAYER              |    %v   |    victory - game |" >> $PWD/SCORE/$PLAYER/$STRMAP.trace  
    echo -e "--------------------------------------------------" >> $PWD/SCORE/$PLAYER/$STRMAP.trace
    echo -e "$ME     |    "$percent%"    |       $MYWIN - $GAME   |" >> $PWD/SCORE/$PLAYER/$STRMAP.trace
    echo -e "--------------------------------------------------" >> $PWD/SCORE/$PLAYER/$STRMAP.trace 
    let percent=$(((100*$ENEMYWIN)/$GAME)) >> $PWD/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "$PLAYER               |   $percent%  |           $ENEMYWIN - $GAME   |" >> $PWD/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "--------------------------------------------------" >> $PWD/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "\n" >> $PWD/SCORE/$PLAYER/$STRMAP.trace 
    ENEMYWIN=0
    MYWIN=0
done