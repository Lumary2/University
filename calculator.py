#This hashtag means, that this line is a comment and it is
#not part of the actual code.

#choice is a variable which saves what the user has entered.
#"Select operation..." will be printed when you execute the
#program.
choice = input("Select operation(+ - * /): ")

#The only thing different here is the int() before the input.
#Variables can have different data types, like for example
#Strings and Integers. A String consists of one or more
#characters surrounded by 'x' or "x". An Integer is a
#whole number like -1 or 2 without decimal places.

#Because the user input is saved as a String and
#we want to use it as a number to calulate with it,
#int() changes it into an Integer.

num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))

#Now that we saved the user input in the choice
#variable we want to check what the user has entered.
#if the user entered a + sign, we print the addition
#of num1 and num2.

if choice == '+':
   print(num1+num2)

#if the user didnt enter a plus sign, the line above
#saying print(num1+num2) wont be executed and the
#following line will be checked. If he entered
#a - sign, the result of the substraction gets printed.
elif choice == '-':
   print(num1-num2)

#the following lines only get checked for when we
#neither already had a case of addition or substraction.
#Between the four operator possibilities only the
#matching one gets executed, the others are skipped.
elif choice == '*':
   print(num1*num2)

elif choice == '/':
   print(num1/num2)
