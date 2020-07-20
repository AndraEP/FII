def problema4(my_list):
    result = []
    for elem in my_list:
        if isinstance(elem, int):
            result.append(elem)
    return sorted(result, reverse=True)


my_list = [404, 2, 'trei', 4, 5.0, [5, 6]]
print(problema4(my_list))


def checkPrime(n):
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def problema3(m):
    result = []
    for i in range(2, m):
        if checkPrime(i) is True:
            result.append(i)
    return result


print(problema3(14))
