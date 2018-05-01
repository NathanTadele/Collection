#! /bin/bash

  run () {

  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi

}

run ./collection<<EOF
1
college dropout
kanye west
2004
4
2
6
EOF
