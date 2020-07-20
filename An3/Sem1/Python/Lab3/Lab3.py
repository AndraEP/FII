def firstex(a, b):
    return set([frozenset(a).intersection(frozenset(b)), frozenset(a).union(frozenset(b)),
            frozenset(a).difference(frozenset(b)), frozenset(b).difference(frozenset(a))])
#    return (set(a).intersection(set(b)), set(a).union(set(b)), set(a).difference(set(b)), set(b).difference(set(a)))

a = [1, 2, 3, 5]
b = [2, 6, 4, 8]
print(firstex(a, b))


def secondex(inputstr):
    dictionary = {}
    for char in inputstr:
        i = dictionary.get(char)
        if i is not None:
            dictionary[char] = i + 1
        else:
            dictionary[char] = 1
    return dictionary


inputstr = "This is the input string"
print(secondex(inputstr))



def thirdex(dict1, dict2):
    listDif = []
    listDifStg = list(dict1.keys() - dict2.keys())
    listDifDrp = list(dict2.keys() - dict1.keys())
    for key1 in dict1.keys():
        for key2 in dict2.keys():
            if key1 is key2:
                val1 = dict1.get(key1)
                val2 = dict2.get(key2)
                if val1 is not None and val2 is not None:
                    if val1 is not val2:
                        listDif.append(key1)

    return (listDif, listDifStg, listDifDrp)

print(thirdex({'A': 1, 'n': 1, 'a': 3, ' ': 2, 'h': 1, 's': 2, 'p': 2, 'l': 1, 'e': 1, '.': 1},{'T': 1, 'h': 2, 'i': 4, 's': 3, ' ': 4, 't': 3, 'e': 1, 'n': 2, 'p': 1, 'u': 1, 'r': 1, 'g': 1}))

def forthex(tag, content, href, _class, id):
    return "<" + tag + " href=\""+href+"\" _class=\"" + _class + "\" id=\"" + id + "\">"+content+"</"+tag+">"
