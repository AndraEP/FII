import numpy


def f(x):
    return x ** 4 - 12 * (x ** 3) + 30 * (x ** 2) + 12


def least_squares(n, m, x0, xn, x):
    h = (xn - x0) / n
    points = [(x0, f(x0))]

    for i in range(1, n):
        points.append((x0 + i * h, f(x0 + i * h)))

    points.append((xn, f(xn)))

    a = numpy.array([[sum([point[0] ** (i + j) for point in points])
                for j in range(0, m + 1)]
            for i in range(0, m + 1)])
    b = numpy.array([sum([point[1] * (point[0] ** i) for point in points])
            for i in range(0, m + 1)])
    c = numpy.linalg.solve(a, b)

    print('x =', x)
    print('f(x) =', f(x))
    print('Sm(x) =', schema_horner(c, x))
    print('|Sm(x) - f(x)| =', abs(schema_horner(c, x) - f(x)))


def schema_horner(c, x0):
    d = c[0]
    for i in c[1:]:
        d = i + d * x0
    return d


least_squares(5, 4, 1, 5, 3)
