#! /bin/bash

compile() {
    clear
    echo "Preparing Compile"
    rm game
    echo ""
    echo "Compiling game"
    echo ""
    make

    gcc album.o array.o collection.o -o collection
    if [ -e collection ]
        then {
            echo ""
            echo "Compile Successful"
            echo ""
        } else {
            echo "Compile Failure"
            exit -1    
        }
    fi
    # clear
    ./collection

}

compile
