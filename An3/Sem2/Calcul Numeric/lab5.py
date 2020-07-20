import math
import random
import copy
import numpy as np

n = 0
a = {}
b = {}
EPSILON = 10 ** (-4)
dx = 1


def read_matrix(path1):
    global a
    global n

    # open file for reading a
    with open(path1, 'r') as f1:
        n = int(f1.readline())
        max = 0
        f1.readline()
        while 1:
            line = f1.readline()

            # remove unnecessary white space
            if not line.strip():
                break
            else:
                line = line[:-1]
                line_list = line.split(', ')

                for elem in range(len(line_list)):
                    line_list[elem] = float(line_list[elem])
                    if math.ceil(line_list[elem]) == line_list[elem]:
                        line_list[elem] = int(line_list[elem])

                # create dictionary for a, lines are keys which hold the values for the element and column
                # firs check existence and if true add new items to the corresponding key
                if line_list[1] not in a.keys():
                    a[line_list[1]] = [[line_list[0], line_list[2]]]
                else:
                    for elem, index in enumerate(a[line_list[1]]):
                        if index[1] == line_list[2]:
                            a[line_list[1]][elem][0] += line_list[0]
                        if len(a[line_list[1]]) > max:
                            max = len(a[line_list[1]])
                    a[line_list[1]].append([line_list[0], line_list[2]])

    f1.close()
    return "All good"


reading = read_matrix('a_500.txt')


def generate_matrix():
    global p
    global b
    # initialize empty dictionary with empty lists
    for i in range(p):
        b[i] = []
    # generate random values for the lists for every line i
    for i in range(p):
        b[i].append([i, i])
        j = i + 1
        while j < p:
            # generate float number between 0 and p
            aux = random.uniform(0, p)
            j = random.randint(j + 1, j + 2)
            if j < p:
                b[i].append([aux, j])
                b[j].append([aux, i])


# if n >= 500:
#     p = n
#     generate_matrix()
p = n
generate_matrix()


def check_symmetric_from_file():
    global a
    global EPSILON
    for i in range(n):
        for index, elem in enumerate(a[i]):
            for index1, elem1 in enumerate(a[elem[1]]):
                if elem1[1] == i:
                    if abs(elem[0] - elem1[0]) < EPSILON:
                        continue
                    else:
                        return "Matrix is not symmetric"
    return "The matrix from file is symmetric"


def check_symmetric_generated():
    global b
    global EPSILON
    for i in range(n):
        for index, elem in enumerate(b[i]):
            for index1, elem1 in enumerate(b[elem[1]]):
                if elem1[1] == i:
                    if abs(elem[0] - elem1[0]) < EPSILON:
                        continue
                    else:
                        return "Matrix is not symmetric"
    return "The generated matrix is symmetric"


if reading == "All good":
    print(check_symmetric_from_file())
print(check_symmetric_generated())


def power_method_matrix_file():
    global vector_u
    global a

    # initializing singular value with maxim module
    w = matrix_multiply_vector(vector_u, a)
    lambda_ = vector_multiply_vector(w, vector_u)
    lambda_k = lambda_
    k = 0
    copy_vector_u = copy.deepcopy(vector_u)

    # vector will be at one step further (k+1) than it's copy
    # implementing the function
    while norm_vectors(w, vector_multiply_scalar(copy_vector_u, lambda_)) > n * EPSILON and k <= 1000000:
        copy_vector_u = copy.deepcopy(vector_u)
        lambda_ = lambda_k
        vector_u = copy.deepcopy(vector_multiply_scalar(w, 1 / norm_vector(w)))
        w = matrix_multiply_vector(vector_u, a)
        lambda_k = vector_multiply_vector(w, vector_u)
        k += 1

    # checking result
    if k > 1000000:
        print("failed")
        return None
    else:
        print("Iteration recahed: ", k)
    return lambda_k, vector_u


def power_method_matrix_generated():
    global vector_u
    global b
    # initializing singular value with maxim module
    w = matrix_multiply_vector(vector_u, b)
    lambda_ = vector_multiply_vector(w, vector_u)
    lambda_k = lambda_
    k = 0
    copy_vector_u = copy.deepcopy(vector_u)

    # vector will be at one step further (k+1) than it's copy
    # implementing the function
    while norm_vectors(w, vector_multiply_scalar(copy_vector_u, lambda_)) > n * EPSILON and k <= 1000000:
        copy_vector_u = copy.deepcopy(vector_u)
        lambda_ = lambda_k
        vector_u = copy.deepcopy(vector_multiply_scalar(w, 1 / norm_vector(w)))
        w = matrix_multiply_vector(vector_u, b)
        lambda_k = vector_multiply_vector(w, vector_u)
        k += 1

    # checking result
    if k > 1000000:
        print("failed")
        return None
    else:
        print("Iteration recahed: ", k)
    return lambda_k, vector_u


def norm_vector(vector):
    norm = 0.0
    for i in range(n):
        norm += pow(vector[i], 2)
    norm = math.sqrt(norm)
    return norm


def generate_vector():
    global vector_u
    x = [i * 10 for i in range(n)]
    p1 = norm_vector(x)
    for i in range(n):
        vector_u[i] = (1 / p1) * x[i]


def matrix_multiply_vector(vector, matrix):
    list_vector_mul_matrix = []
    for i in range(n):
        list_vector_mul_matrix.append(0)
        for index, elem in enumerate(matrix[i]):
            list_vector_mul_matrix[i] += elem[0] * vector[elem[1]]
    return list_vector_mul_matrix


# scalar
def vector_multiply_vector(vector1, vector2):
    p2 = 0
    for i in range(n):
        p2 += vector1[i] * vector2[i]
    return p2


def vector_multiply_scalar(vector, scalar):
    for i in range(n):
        vector[i] = vector[i] * scalar
    return vector


def norm_vectors(vector1, vector2):
    norm = 0.0
    for i in range(n):
        norm += pow(vector1[i] - vector2[i], 2)
    norm = math.sqrt(norm)
    return norm


# initializing the singular values vector
vector_u = [0 for i in range(n)]
generate_vector()
print("Initial vector for matrix in the file: ", vector_u)
print("Initial vector norm for matrix in the file: ", norm_vector(vector_u))
m, o = power_method_matrix_file()
print("\nValues from matrix in the file:\nLambda: ", m, "\nVector: ", vector_u, "\n\n\n")


# initializing the singular values vector
vector_u = [0 for i in range(n)]
generate_vector()
print("Initial vector for generated matrix: ", vector_u)
print("Initial vector norm for generated matrix: ", norm_vector(vector_u))
m, o = power_method_matrix_generated()
print("\nValues from generated matrix:\nLambda: ", m, "\nVector: ", vector_u, "\n\n\n")


def build_normal_matrix():
    global b
    global normal_matrix
    for i in range(n):
        for index, elem in enumerate(b[i]):
            normal_matrix[i][elem[1]] = elem[0]


# create matrix from dictionary of b
normal_matrix = [[] for i in range(n)]
for i in range(n):
    for j in range(n):
        normal_matrix[i].append(0)
build_normal_matrix()


def conditioning_number():
    global numpy_matrix
    max = 0
    min = 10000
    for i in range(n):
        for j in range(n):
            if numpy_matrix[i][j] > max:
                max = numpy_matrix[i][j]
            if min > numpy_matrix[i][j] > 0:
                min = numpy_matrix[i][j]
    return max / min


# change to numpy matrix for easier calculations
numpy_matrix = np.array([np.array(xi) for xi in normal_matrix])
U, S, Vt = np.linalg.svd(numpy_matrix, full_matrices=True)
inverse_numpy_matrix_MP = np.linalg.pinv(numpy_matrix)
print("Singular values of the matrix:\n", S)
print("Rang matrix: ", np.linalg.matrix_rank(numpy_matrix))
print("Conditioning number: ", conditioning_number())
print("Moore-Penrose: \n", inverse_numpy_matrix_MP)


new_b = np.array([i for i in range(n)])
x = np.dot(inverse_numpy_matrix_MP, new_b)
A_x = np.dot(numpy_matrix, x)
print("Vector: ", x)
print("Solution for Ax = b: ", A_x)
print("Norm: ", norm_vectors(new_b, A_x))


get_pseudoinv_smallest_squares = np.dot(np.linalg.inv(np.dot(numpy_matrix, numpy_matrix)), numpy_matrix)
# calculate the difference and get norm
diff = [[] for i in range(n)]
for i in range(n):
    for j in range(n):
        diff[i].append(0)
for i in range(n):
    for j in range(n):
        diff[i][j] = inverse_numpy_matrix_MP[i][j] - get_pseudoinv_smallest_squares[i][j]
get_norm = np.linalg.norm(diff, ord=1)
print("\n\nPseudo-inv matrix for smallest squares: \n", get_pseudoinv_smallest_squares)
print("Norm for pseudo-inv matrix for smallest squares: ", get_norm)
