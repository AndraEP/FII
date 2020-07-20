import os
from os.path import join
import re


def problema1 (path):
    name = "access.log"
    result = []
    if os.path.isfile(path) and name == path[-10:]:
        result = process(path)
    elif os.path.isdir(path):
        for file in os.listdir(path):
            new = join(path, file)
            if os.path.isfile(new) and name == new[-10:]:
                result = process(new)
            if os.path.isdir(new):
                problema1(new)
    return result

def process(path):
    result = {}
    final = []
    file = open(path, "r")
    lists = file.read().split("\n")
    for i in range(0, len(lists)):
        ip = re.findall(r'[0-9]+(?:\.[0-9]+){3}', lists[i])[0]
        if ip not in result:
            result.update({ip: 1})
        if ip in result:
            result[ip] += 1
    sorting = sorted(result.items(), key =
             lambda kv: (kv[1], kv[0]))
    for i in range(0, 7):
        final.append(sorting[i][0])
    return final

print(problema1("data/667-4e356ec.cluster-e9d/access.log"))