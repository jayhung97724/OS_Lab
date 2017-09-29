def GuessNumber(target):
  lo = 1
  hi = 10
  guess = 12
  while guess != target: 
    guess = input("Please enter a number between " + str(lo) + " and " + str(hi) + ": ")
    if guess > target:
      hi = guess-1
    elif guess < target:
      lo = guess+1
    else:
      break
  print("Bingo!!!")

print("Welcome to the Number Guessing Game!")
target = input("Please enter your target number: ")  
GuessNumber(target)
