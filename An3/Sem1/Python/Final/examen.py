import re
import urllib
from urllib import request
import zipfile
import hashlib
import json

def problema1 (sir):
    check ="\d+"
    count = 0
    res = re.findall(check, sir)
    for i in res:
        count = count + len(i)
    return count

#print(problema1("1a23bc4"))

def problema2 (url):
    count = 0
    response = urllib.request.urlopen(url).read().decode('utf-8')
    result = json.dumps(response)
    example = re.findall(",", result)
    for i in example:
        count = count + 1
    return count

# print(problema2("https://pastebin.com/raw/2ngjcGKn"))

def problema4 (my_path):
    result = []
    files = zipfile.ZipFile(my_path)
    for file in files.infolist():
        text = files.open(file).read()
        m = hashlib.md5()
        m.update(text).encode()
        result.append(m.hexdigest())
    return result

