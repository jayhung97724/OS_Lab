#!bin/sh
lo=1
hi=10
target=$1
guess=12
GuessNumber() {
  while [ $guess -ne $target ];do
    echo -n "Please enter a number between $lo and $hi:"
    read guess
    if [ $guess -gt $target ];then
      hi=$guess
    else
      lo=$guess
    fi
  done
  echo "Bingo!!!"
}

echo "Welcome to the Number Guessing Game!"
#echo -n "Please enter your target number:"
#read target


GuessNumber;

