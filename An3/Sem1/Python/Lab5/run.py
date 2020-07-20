import utils
import app


#ex1
print("Write a number:")
x = int(input())
print("\nFirst exercise a:")
print(utils.process_item(x))
print("\nFirst exercise b:")
print(app.function())

# ex2
def my_function(*args, **argsdict):
    sum = 0
    for e in argsdict:
        sum += argsdict[e]
    return sum


suma = 0
result = lambda *arguments, **dict: [dict[e] for e in dict]
for i in result(1, 2, c=3, d=4):
    suma += i

print(my_function(1, 2, c=3, d=4))
print(suma)


# ex3
def ex3_1(string):
    vowels = ["a", "e", "i", "o", "u"]
    '''vect = [None] * len(string)
    m = 0
    for i in string:
        for j in vowels:
            if i == j:
                vect[m] = 1
                break
            else:
                vect[m] = 0
        m += 1
    result = []

    list = [k for k in range(0, len(vect)) if vect[k] == 1]
    for i in list:
        result.append(string[i])
    return result'''
    return list(filter(lambda litera: litera in vowels,string))


print(ex3_1("Programming in Python is fun"))


#ex5
def ex5_funct (list):
    result =[]
    for elem in list:
        if isinstance(elem, int):
            result.append(elem)
        if isinstance(elem, float):
            result.append(elem)
    return result

my_list = [1, "2", {"3": "a"}, {4, 5}, 5, 6, 3.0]
print (ex5_funct(my_list))

#ex9a
def print_arguments(function):
    def wrapper(*args, **kwargs):
        print (args, kwargs)
        return function(*args, **kwargs)
    return wrapper

#pentru ultimele 3 linii
@print_arguments
def multiply_by_two(x):
    return x * 2


def add_numbers(a, b):
    return a + b


# augmented_multiply_by_two = print_arguments(multiply_by_two)
# x = augmented_multiply_by_two(10)
# print(x)
print(multiply_by_two(10))


#ex9b
def multiply_output(function):
    def wrapper(*args):
        print(args)
        return 2*function(*args)
    return wrapper


def multiply_by_three(x):
    return x * 3

augmented_multiply_by_three = multiply_output(multiply_by_three)
x = augmented_multiply_by_three(10)
print(x)


