num=int(input("Enter the num"))
original_num=num
sum=0
while num!=0:
    digit=num%10
    sum+=digit*digit*digit
    num=num//10

if sum==original_num:
    print("It is armstrong")    
else:
    print("It is not")    