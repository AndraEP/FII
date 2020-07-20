import re

def ex1(txt):
    result = re.findall("[a-zA-Z0-9]+", txt)
    return result

text1 = "Azi e frumos afara"
print(ex1(text1))


def ex2(regex, text, x):
    result = re.findall(regex, text)
    return list(filter(lambda s: len(s) == x, result))

regex = "[a-zA-Z0-9]+"
text2 = "aa bgb bb"
x = 2
print(ex2(regex, text2, x))


def ex3(text, list):
    result = list()
    for i in list:
        result += re.findall(i, text)
    return result

text3 = "Ana 99 a9 m_m"
lista = ["[a-zA-Z0-9]+", "[0-9]+"]
print(ex3(text3, lista))


def ex4(path, attrs):
    data = open(path, "rt").read()
    result = set()
    for k, v in attrs.items():
        s = "(\s+" + k + "\s*=\s*\"" + v + "\"\s*)"
        s = "(<)([a-zA-z]+).*("+s+")"
        if len(result) > 0:
            aux = set()
            for i in re.findall(s, data):
                aux = aux.union(set([i[1]]))
            result = result.intersection(aux)
        else:
            for i in re.findall(s, data):
                result = result.union(set([i[1]]))
    return list(result)

path1 = "D:\\Work\\Python\\lab11\\file.xml"
dict1 = {"class": "url", "name": "url-form", "data-id": "item"}
print(ex4(path1, dict1))


def ex5(path, attrs):
    data = open(path, "rt").read()
    for k, v in attrs.items():
        s = "(\s+" + k + "\s*=\s*\"" + v + "\"\s*)|"
        s = s[:-1]
    s = "(<)([a-zA-z]+).*("+s+")"
    result = re.findall(s, data)
    s = set()
    for i in result:
        s.add(i[1])
    return list(s)

path2 = "D:\\Work\\Python\\lab11\\file.xml"
dict2 = {"class": "url", "name": "url-form", "data-id": "item"}
print(ex5(path2, dict2))


def censor(s):
    string = str(s.group())
    if re.match("[aeiouAEIOU].*[aeiouAEIOU]", string):
        return "".join("*" if i % 2 == 0 else char for i, char in enumerate(string, 1))
    else:
        return string

def ex6(text):
    return re.sub("\w+", censor, text)

text6 = "alina are mere"
print(ex6(text6))


def ex7(cnp):
    if re.match("[12][0-9][0-9](0[1-9]|1[0-2])(0[1-9]|[12][0-9]|3[10])[0-9][0-9][0-9][0-9][0-9][0-9]$", cnp):
        return True
    return False

cnp = "2951228225894"
print(ex7(cnp))