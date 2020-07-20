def problema1 (n):
    suma = 0
    for i in range(1, n+1):
        suma += i
    return suma

print(problema1(199))

def problema5(n):
    number = int (n, 8)
    getstringnum = str(number)
    reverseNumber = getstringnum[::-1]
    if number == reverseNumber:
        return True
    return False


print(problema5('30041'))