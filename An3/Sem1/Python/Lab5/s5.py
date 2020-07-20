def problem1(my_list):
    even = []
    odd = []
    for i in my_list:
        if i%2 == 0:
            even.append(i)
        else:
            odd.append(i)

    result = []
    for j in range (0, len(even)):
        a = (even[j], )
        b = odd[j]
        tuple = (*a, b)
        result.append(tuple)
    return result

my_list = [2, 2, 2, 4, 5, 5, 5, 7, 7, 2, 4, 5, 7, 7, 4, 4]
print (problem1(my_list))

def problem2 (pairs):
    result = []
    for list in pairs:
        suma = 0
        produs = 1
        for j in range(0, len(list)):
            suma += list[j]
            produs *= list[j]
            if j+1 < len(list):
                power = list[j] ** list[j+1]
        dictionary={'sum': suma, 'prod': produs, 'pow': power}
        copy = dictionary.copy()
        result.append(copy)
        dictionary.clear()
    return result

pairs = [(2, 3), (5, 6)]
print (problem2(pairs))