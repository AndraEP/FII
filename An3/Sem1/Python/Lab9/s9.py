import os
from os.path import join


def problema1 (dir):
    list = []
    for file in os.listdir(dir):
        if os.path.isfile(join(dir, file)):
            file_found = join(dir, file)
            extension = os.path.splitext(os.path.abspath(file_found))[1]
            if extension.replace(".", "") not in list:
                list.append(extension.replace(".", ""))
    return sorted(list)


#dir = "testare_2/caz1"
#print(problema1(dir))

def problema2 (my_path):
    result = []
    ok = 0
    if os.path.isfile(my_path):
        ok = 1
        f = open(my_path, "r")
        file = str(f.read())
        result.append(file[-20: ])
    if ok:
        string = result[0]
        return string
    if os.path.isdir(my_path):
        tuple = ()
        for file in os.listdir(my_path):
            if os.path.isfile(join(my_path, file)):
                file_found = join(my_path, file)
                extension = os.path.splitext(os.path.abspath(file_found))[1]
                if extension.replace(".", "") not in list:
                    result.append("nothing")
        return result

my_path = "testare/caz1/fisier.txt"
print(problema2(my_path))