import os
import shutil
from os.path import join


def search_by_content(target, to_search):
    list = []
    if os.path.isfile(target):
        if hasSearch(target, to_search):
            list.append(target)
        return list
    for root, dirs, files in os.walk(target):
        for file in files:
            if hasSearch(join(target, file), to_search):
                list.append(join(target, file))
    return list

def hasSearch(target, to_search):
    if os.path.isfile(target):
        file = open(target, "r")
        lists = file.readlines()
        for elm in lists:
            if elm.__contains__(to_search):
                return True
    return False

target = "D:\\Work\\Python\\Lab9"
to_search = "file1.txt"
print(search_by_content(target, to_search))


def get_file_info(filepath):
    if os.path.isfile(filepath):
        return {"full_path":os.path.abspath(filepath),
                "file_size":os.stat(os.path.abspath(filepath)).st_size,
                "file_extension":os.path.splitext(os.path.abspath(filepath))[1],
                "can_read":os.access(os.path.abspath(filepath), os.R_OK),
                "can_write":os.access(os.path.abspath(filepath), os.W_OK)}
    else:
        return {}

filepath = "D:\\Work\\Python\\Lab9\\file1.txt"
print(get_file_info(filepath))


def ex3(filename):
    f = open(filename, "w")
    for line in os.environ:
        f.write(line + '\t' + os.environ.get(line).replace('\n','\s') + '\n')

filename = "file2.txt"
ex3(filename)


def ex4(path):
    for file in os.listdir(path):
        if os.path.isfile(join(path, file)):
            print(join(path, file))
        elif os.path.isdir(join(path, file)):
            ex4(join(path, file))

path = "D:\\An3\\Sem1Materiale\\Python\\Curs\\Old\\all"
ex4(path)


def ex5(filepath, dirpath, dim):
    with open(filepath, 'rb') as fsrc:
        os.chmod(dirpath, 0o777)
        with open(dirpath, 'wb') as fdest:
            shutil.copyfileobj(fsrc, fdest, dim)

filepath = "D:\\Work\\Python\\Lab9\\file1.txt"
dirpath = "C:\\Users\\andra\\Documents\\file.txt"
dim = 10
ex5(filepath, dirpath, dim)


def ex6(dirpath2):
    if os.path.isdir(dirpath2):
        files = []
        dirs = []
        for name in os.listdir(dirpath2):
            path = os.path.join(dirpath2, name)
            if os.path.isfile(path):
                files.append(path)
            if os.path.isdir(path):
                dirs.append(path)
                ex6(path)
    total_size = get_size(dirpath2)
    return {"full_path":os.path.abspath(dirpath2),
            "total_size":total_size,
            "files": files,
            "dirs": dirs}

def get_size(dirpath):
    total_size = 0
    for dirpath, dirnames, filenames in os.walk(dirpath):
        for f in filenames:
            fp = os.path.join(dirpath, f)
            if not os.path.islink(fp):
                total_size += os.path.getsize(fp)
    return total_size

dirpath2 = "D:\\Work\\Python\\Lab9"
print(ex6(dirpath2))