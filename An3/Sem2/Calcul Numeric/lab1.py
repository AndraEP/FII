import copy
import math
import random
from bitstring import BitArray
import numpy

# def problema1(u):
#     m = 0
#     while 1 + u != 1 and u > 0:
#         u = u/10
#         m = m+1
#     return m, u
#
# print(problema1(1)[0])
#
# def problema2():
#     x = 1.0
#     u = copy.copy(problema1(1)[1])
#     y = u
#     z = u
#
#     check1 = (x + y) + z
#     check2 = x + (y + z)
#
#
#     if check1 != check2:
#         result1 = True
#     else:
#         result1 = False
#
#     x = x * 2.3
#     checkMultiply1 = (x * y) * z
#     checkMultiply2 = x * (y * z)
#
#     if checkMultiply1 != checkMultiply2:
#         result2 = True
#     else:
#         result2 = False
#     return result1, result2
#
# print (problema2())

def problema3():
    n = random.randint(4, 10)
    while not n % math.floor(math.log2(n)) == 0:
        n = random.randint(4, 10)
    print('n = ', n)
    m = math.floor(math.log2(n))
    p = math.ceil(n / m)

    v1 = [random.randint(0, 1) for i in range(n * n)]
    A_first = numpy.array(v1).reshape(n, n)
    v2 = [random.randint(0, 1) for i in range(n * n)]
    B_first = numpy.array(v2).reshape(n, n)

    print('A_original = \n', A_first)
    print('B_original = \n', B_first)

    sum_linii_B = {}
    A_sec = {}
    B_sec = {}
    C_sec = {}

    for i in range(1, p + 1):
        sum_linii_B.clear()
        sum_linii_B[0] = [0] * n
        A_sec[i] = A_first[0: n, (m * (i - 1)): m * i]
        B_sec[i] = B_first[(m * (i - 1)): m * i, 0:n]
        C_sec.setdefault(i, [])
        C_final = numpy.array([0] * (n ** 2)).reshape(n, n)

        for j in range(1, 2 ** m):
            k = math.floor(math.log2(j))
            sum_linii_B[j] = [(x or y) for x, y in zip(sum_linii_B[j - 2 ** k], B_sec[i][k])]

        for line in A_sec[i]:
            line_copy = line.copy()
            line_copy[:] = line_copy[::-1]
            nr = BitArray(line_copy).uint
            C_sec[i].append(sum_linii_B[nr])

    for m in C_sec.values():
        C_final = C_final | numpy.array(m)

    # print(A_sec, "\n", B_sec, "\n", C_sec)
    return C_final

print(problema3())