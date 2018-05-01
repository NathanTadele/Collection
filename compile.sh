#! /bin/bash

compile() {
    clear
    echo "Preparing Compile"
    rm game
    echo ""          #removes current game.exec
    echo "Compiling game"
    echo ""
    make                #runs makefile to compile individual .c files
    #add .o files below
    gcc album.o array.o collection.o -o collection
    if [ -e collection ]      #checks if game.exec was made
        then {
            echo ""
            echo "Compile Successful"
            echo ""
        } else {
            echo "Compile Failure"
            exit -1     #if file was not made compilation fails
        }
    fi
    # clear
    ./collection

}

compile
