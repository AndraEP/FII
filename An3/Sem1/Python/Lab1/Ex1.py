# Ex_1
# Find The largest common divisor of multiple numbers. Define a function with variable number of parameters to resolve this.

from math import gcd
print(gcd(20,8))

print ("Next")

for nr in range (0, 20, 8):
    print(nr)

print ("Next")

def ex1 (x, y):
    while y!=0:
        (x, y) = (y, x%y)
    return x
print (ex1(20, 8))