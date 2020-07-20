def problema1(n):
    number = bin(n)
    contor = 0
    for i in range(0, len(number)):
        if number[i] == 1:
            contor += 1
    return contor

print(problema1(23))

def problema2(n):
    result = 0
    for i in range (1, n):
        if i*i < n:
            result = i*i
        if i*i >= n:
            break
    return result

print(problema2(10))


def problema3(my_list):
    listinitial = []
    result = []
    contor = 0

    for i in range(0, len(my_list)):
        pal = 0
        number = my_list[i]
        while (number >= 1):
            pal = pal*10 + int(number%10)
            number = int(number/10)
        if pal == my_list[i]:
            listinitial.append(pal)
            contor += 1
    num = max(listinitial)
    result.append(contor)
    result.append(num)
    return tuple(result)

my_list3 = [103, 36563, 8928, 787, 987]
print(problema3(my_list3))


def problema4(my_list, letter):
    result = []
    for i in range(0, len(my_list)):
        if my_list[i][0] == letter:
            result.append(my_list[i])
            my_list.remove(my_list[i])
            break
    print(my_list)
    j = 0
    for k in range(0, len(my_list)):
        for i in range(0, len(my_list)):
            lenghtres = len(result[j])-1
            if my_list[i] in result:
                break
            if result[j][lenghtres-1] == my_list[i][0] and result[j][lenghtres] == my_list[i][1]:
                result.append(my_list[i])
                j += 1
    return result

my_list4 = ['reclama', 'lacusta', 'nasture', 'matura', 'rafala']
letter = "n"
print(problema4(my_list4, letter))


def problema5(matrix):
    pass

