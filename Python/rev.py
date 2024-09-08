num =int(input("Enter the number"))
rev_no=0
while num!=0:
           digit= num % 10
           rev_no=rev_no*10+digit
           num=num//10

print("Reversed Number: " + str(rev_no))
