#ex1
import operator
def sort_names(a):
    a.sort(key = operator.itemgetter(0))
    return a

my_list = [("Ana", "Popa"), ("Violeta", "Baciu"), ("Bianca", "Apopei")]
print(sort_names(my_list))

#ex2
def check_existence (a, b):
    if [item for item in a if b in item]:
        return True
    return False

my_string = "Popa"
my_second_list = [("Ana", "Popa"), ("Bianca", "Apopei"), ("Violeta", "Baciu")]
print (check_existence(my_second_list, my_string))

#ex3
dictionary = {
    "+": lambda a, b: a + b,
    "*": lambda a, b: a * b,
    "/": lambda a, b: a / b,
    "%": lambda a, b: a % b
}

def apply_operator (operator, a, b):
    global dictionary
    x=0
    try:
        function = dictionary [operator]
        x = function (a, b)
    except Exception as e:
      print(str(e))
    return x

print(apply_operator("*",3,6))

#ex4
global_dictionary = {
    "print_all": lambda *a, **k: print(a, k),
    "print_args_commas": lambda *a, **k: print(a, k, sep="\n"),
    "print_only_args": lambda *a, **k: print(a),
    "print_only_kwargs": lambda *a, **k: print(k)
}

def apply_function (operator, a, k):
    global global_dictionary
    function = global_dictionary[operator]
    function (a, k)

apply_function("print_only_args", 10, 12)

#ex5
def probl5(*dictionaries):
    result = dictionaries[0]
    length = len(dictionaries)
    for i in range(1, length):
        result = mergeDict(result, dictionaries[i])
    return result

def mergeDict(a, b):
    result = {**a, **b}
    for key, value in result.items():
        if key in a and key in b:
            result[key] = [value, a[key]]
    return result

print(probl5({'Ritika': 5, 'Sam': 7, 'John' : 10 }, {'Aadi': 8,'Sam': 20,'Mark' : 11 }, {'Mark': 18, 'Rose': 22, 'Wong': 22}))