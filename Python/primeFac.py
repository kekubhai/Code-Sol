def primeFac(num):
    factors=[]
    divisor=2
    while num>1:
        if num%divisor==0:
              factors.append(divisor)
              num//=divisor
                          
        else :
            divisor+=1
            
    print(factors)
            
primeFac(100)                  
               
        