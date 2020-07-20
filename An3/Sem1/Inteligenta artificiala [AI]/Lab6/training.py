def problema1 ():
    suma = 0
    for i in range (1, 11):
        suma += i
    return suma

print (problema1())


def problema3(m):
    result = []
    for i in range(2, m):
        if (isPrime(i)):
            result.append(i)
    return result


def isPrime(n):
    if n == 2:
        return True
    if n <= 1:
        return False
    for j in range(2, n):
        if n % j == 0:
            return False
    return True

print(problema3(5))


def problema4(my_list):
    result = []
    for i in range(0, len(my_list)):
        if isinstance(my_list[i], int):
            result.append(my_list[i])
    result.sort(reverse=True)
    return result

my_list = [1, 2, 'trei', 4, [5, 6]]
print (problema4(my_list))

def problema2(n, m):
    while n > 0 and m > 0:
        c = m - n*2
        m = n
        n = c
        problema2(n, m)
    first = 2*m + n
    second = 2*first + m
    return (first, second)

print(problema2(41, 99))

def problema5(n):
    number = int (n, 8)
    getstringnum = str(number)
    reverseNumber = getstringnum[::-1]
    if number == reverseNumber:
        return False
    return True

print(problema5("10"))
