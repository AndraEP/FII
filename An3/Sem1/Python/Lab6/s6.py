def fibo (n):
    fib = [0, 1, 1]
    for i in range (3,n+1):
        fib.append(fib[i-1]+fib[i-2])
    return fib[n]

n = 25
print (fibo(n))


import math
def is_prime(number):
    if number == 1:
        return False
    if number == 2:
        return True
    for i in range(2, int(math.sqrt(number))+1):
        if number % i == 0:
            return False
    return True

number = 29
print(is_prime(number))


# def custom_filter(my_list):
#     result = []
#     my_list.sort(reverse=True)
#     fib_list = fibo2(my_list[0])
#     for i in range(0, len(my_list)):
#         if is_prime(my_list[i]):
#             if my_list[i] in fib_list:
#                 result.append(my_list[i])
#     result.sort(reverse=False)
#     return result
#
# def fibo2(n):
#     fib = [1, 1]
#     if (n>2):
#         for i in range(2, n):
#             fib.append(fib[i - 1] + fib[i - 2])
#     return fib

def custom_filter(my_list):
    l=[1,1]
    while l[-1]<max(my_list):
        l.append(l[-1]+l[-2])
    return list(sorted(filter(lambda x: is_prime(x) and x in l, my_list)))

print(custom_filter([2,1,4,3]))

# list = [2, 1, 4, 3]
# print(custom_filter(list))


def extract_numbers(text):
    my_list = []
    new_num = 0
    for i in range(0, len(text)):
        if text[i].isdigit():
            new_num = new_num*10 + int(text[i])
        else:
            if new_num != 0:
                my_list.append(new_num)
            new_num = 0
    if new_num != 0:
        my_list.append(new_num)
    my_list.sort()
    my_list.sort(reverse=True)
    return my_list

text = "test12z34p5"
print(extract_numbers(text))


def special_sum(*params):
    result = []
    for i in range(0, len(params)):
        for j in range(0, len(params[i])):
            if params[i][j].isdigit() and int(params[i][j]) % 2 == 0:
                result.append(params[i][j])
    suma = 0
    for i in range(0, len(result)):
        suma += int(result[i])
    return suma


print(special_sum("tPt82eWq31d10P","Lkn111N6aRekJ30E","90n32k1L8dnBa33"))


def sequence(n):
    result = [2, 4]
    for i in range (2, n+1):
        result.append(2 * result[int(i/2)] - result[i-2])
    return result[n]

n = 16
print(sequence(n))