#Here is the code to find the valie of mathematical symbol pie using monte carlo algorithm
import random
def manto_carlo(num_samples):
          inside_circle=0
          for _ in range(0,num_samples):
               x=random.uniform(-1,1)
               y=random.uniform(-1,1)
               if x*x +y*y<=1:
                  inside_circle+=1
          return (inside_circle/num_samples)*4
  
     
     
num_samples=1000000
pi=manto_carlo(num_samples)
print(pi) 