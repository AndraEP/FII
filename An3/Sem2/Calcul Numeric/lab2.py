import numpy
import math

A = [[2, 0, 1],
     [-2, 1, -1],
     [0, 1, -1]]

A_init = A.copy()

L = numpy.zeros([3, 3], dtype=float)
U = numpy.zeros([3, 3], dtype=float)

for i in range(0, len(L)):
    L[i][i] = 1


# ex1
def get_element_L(i_int, j, A_int, L_int, U_int):
    suma = 0
    for t in range(0, j):
        suma += L_int[i_int][t] * U_int[t][j]
    return (A_int[i_int][j] - suma) / U_int[j][j]


def compute_line_L(i_int, A_int, L_int, U_int):
    for j in range(0, i_int):
        L_int[i_int][j] = get_element_L(i_int, j, A_int, L_int, U_int)


def get_element_U(i_int, j, A_int, L_int, U_int):
    suma = 0
    for t in range(0, i_int):
        suma += L_int[i_int][t] * U_int[t][j]
    return (A_int[i_int][j] - suma) / L_int[i_int][i_int]


def compute_line_U(i_int, A_int, L_int, U_int):
    for j in range(i, len(A_int)):
        U_int[i_int][j] = get_element_U(i_int, j, A_int, L_int, U_int)


for i in range(0, len(A)):
    compute_line_U(i, A, L, U)
    if not i == 2:
        compute_line_L(i + 1, A, L, U)

print("Ex1:\nL:\n", L)
print("U:\n", U)
print("\n")


# print(numpy.dot(L, U))


# 2
def ex_2(L_int, U_int):
    det_L = numpy.linalg.det(L_int)
    det_U = numpy.linalg.det(U_int)
    print("Ex2:\ndet(A) = ", det_L * det_U)


ex_2(L, U)
print("\n")

# 3
b = [0, 0, 1]
nDim = 3
sol_x_inf = [0, 0, 0]
sol_x_sup = [0, 0, 0]


def get_solution_inferior_matrix(i, A, b):
    get_bi = 0
    for j in range(0, i):
        get_bi += A[i][j] * sol_x_inf[j]
    sol_x_inf[i] = b[i] - get_bi


def get_solution_superior_matrix(i, A, y):
    get_bi = 0
    y = numpy.array(y)
    for j in reversed(range(i, len(A))):
        get_bi += A[i][j] * sol_x_sup[j]
    sol_x_sup[i] = (y[i] - get_bi) / A[i][i]


for i in range(nDim):
    get_solution_inferior_matrix(i, L, b)
for i in reversed(range(nDim)):
    get_solution_superior_matrix(i, U, sol_x_inf)

print("Ex3:\nx inferior:\n", sol_x_inf)
print("x superior:\n", sol_x_sup)
print("\n")


# ex4
def norme(v):
    return math.sqrt(sum([x * x for x in v]))


def check_norme(A_init, x_LU, b_init):
    A_init = numpy.array(A_init)
    x_LU = numpy.array(x_LU)
    z = A_init.dot(x_LU) - b_init
    return norme(z)


norma = check_norme(A_init, sol_x_sup, b)
print("Ex4:\nNorma:\n", norma)
print("\n")


# ex5
x = numpy.linalg.solve(A, b)
A_inv = numpy.linalg.inv(A)
print("Ex5:\nx:\n", x)
print("A inversa:\n", A_inv)


def get_norms(x_LU, A, b):
    A = numpy.array(A).astype(float)
    A_inv = numpy.linalg.inv(A)
    x_lib = numpy.linalg.solve(A_inv, b)
    norm1 = norme(x_LU - x_lib)
    norm2 = norme(x_LU - numpy.dot(A_inv, b))
    return norm1, norm2


print("Norme:\n", get_norms(sol_x_sup, A_init, b))
print("\n")


# ex6
def invers(A):
    A_inv_LU = numpy.array([[0, 0, 0], [0, 0, 0], [0, 0, 0]])
    for i in range(len(A)):
        e_i = [0] * len(A)
        e_i[i] = 1
        for j in range(len(A)):
            get_solution_inferior_matrix(j, L, e_i)
        for j in reversed(range(len(A))):
            get_solution_superior_matrix(j, U, sol_x_inf)
        A_inv_LU[i] = sol_x_sup
    return A_inv_LU


A_inv_LU = invers(A_init)
print("Ex6:\nA invers LU:\n", A_inv_LU)
