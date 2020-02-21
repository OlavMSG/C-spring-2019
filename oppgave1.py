"""Funksjon som sjekker om et tall er et fibonacci tall"""

def isFibonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    return b == n

for i in range(10):
    print(i,'is a FibbonacciNumber: ', isFibonacciNumber(i))