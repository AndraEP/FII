import math

n = 0
a = {}
b = []
p = -4
EPSILON = 10 ** p
dx = 1


def read_matrix(path1, path2):
    global a
    global b
    global n

    # open file for reading a
    with open(path1, 'r') as f1:
        n1 = int(f1.readline())

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
                        if len(a[line_list[1]]) > 10:
                            return "More than 10 elements on the line"
                    a[line_list[1]].append([line_list[0], line_list[2]])

    # open file for reading b
    with open(path2, 'r') as f2:
        n2 = int(f2.readline())
        # check if lengths are the same
        if n1 == n2:
            n = n1

        while 1:
            line = f2.readline()
            if not line.strip():
                break
            else:
                line = line[:-1]
                b.append(float(line))

    f1.close()
    f2.close()
    return "All good"


reading = read_matrix('a_1.txt', 'b_1.txt')
x = [j for j in range(n)]


def verify_diagonal():
    for i in range(n):
        ok = 0
        for index, elem in enumerate(a[i]):
            if elem[1] == i:
                ok = 1
        if ok == 0:
            return "The matrix has 0 on diag_p", i
        else:
            return "All good"


verifing = verify_diagonal()


def gauss_seidel(a, b):
    global x
    global dx
    global n
    k = 1

    # check termination condition
    while (k <= 10000) and (dx >= EPSILON) and (dx <= 10 ** 8):
        norm = 0

        for i in range(n):
            sum1 = 0.0
            sum2 = 0.0
            elem_diag = 0

            # calculate sums from formula
            for index, elem in enumerate(a[i]):
                if elem[1] <= i - 1:
                    sum1 = sum1 + x[int(elem[1])] * elem[0]
                elif elem[1] >= i:
                    sum2 = sum2 + elem[0] * x[int(elem[1])]
                    if elem[1] == i:
                        elem_diag = elem[0]

            # calculate xi(k+1)
            final_x = x[i] + (b[i] - sum1 - sum2) / elem_diag
            # calculate norm
            norm += pow(final_x - x[i], 2)
            x[i] = final_x
        dx = math.sqrt(norm)
        k += 1
    return k, dx


def get_solutions(a, b, x, n):
    # print("Gauss - Seidel: ")
    # print(gauss_seidel(a, b))
    gauss_seidel(a, b)
    print("\nx: ")
    print(x)
    get_b = []
    for i in range(n):
        get_b.append(0.0)
        for index, elem in enumerate(a[i]):
            get_b[i] += a[i][index][0] * x[int(elem[1])]
    print("\nb: ")
    print(get_b)
    norma = 0.0
    for i in range(n):
        norma += pow(get_b[i] - b[i], 2)
    norma = math.sqrt(norma)
    print("\nNorma: ")
    return norma


if reading == "All good" and verifing == "All good":
    print(get_solutions(a, b, x, n))
else:
    print(reading, verifing)

