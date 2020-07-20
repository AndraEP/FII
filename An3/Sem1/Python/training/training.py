import re
import os
import hashlib
import sqlite3
import sys
import zipfile
from os.path import join


def problema1 (s):
    check_word = "\w+"
    result = re.findall(check_word, s)
    if result:
        return sorted(result)



def problema2 (s, url):
    if re.search(s, url):
        return True
    else:
        return False


def problema3 (path):
    result = []
    if os.path.isdir(path):
        for root,dir,files in os.walk(path):
            for file in files:
                m = hashlib.md5(file.encode())
                result.append(m.hexdigest())
    return result


def problema4 ():
    result = []
    path = sys.argv[1]
    for file in os.listdir(path):
        full = join(path, file)
        if os.path.isfile(full):
            result.append(os.stat(full).st_size)
    return list(set(sorted(result)))


def problema8(path, low, high):
    query = '''SELECT a.title, t.name, g.name FROM tracks t 
                JOIN genres g ON t.GenreId=g.GenreId JOIN albums a ON t.AlbumId=a.AlbumId
                WHERE t.Milliseconds BETWEEN {} and {} ORDER BY a.title, t.name, g.name ASC
                '''.format(low, high)

    for dir_path, dir_names, file_names in os.walk(os.path.abspath(path)):
        for file_name in file_names:
            full_path = os.path.join(dir_path, file_name)
            if not zipfile.is_zipfile(full_path):
                continue
            archive = zipfile.ZipFile(full_path, 'r')
            for info in archive.infolist():
                if os.path.splitext(info.filename)[1] != '.sqlite':
                    continue
                database = archive.extract(info.filename)
                conn = sqlite3.connect(database)
                cursor = conn.cursor()
                cursor.execute(query)
                records = cursor.fetchall()
                cursor.close()
                conn.close()
                return records



def ip_file_check(path):
    result = []
    regex = re.compile('(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5]){1,3}')
    with open(path, 'r') as fd:
        text = fd.read()
        result.append(regex.finditer(text))
    return result


def problema9(path):
    result = []
    name = "access.log"
    if os.path.isfile(path) and name == path[-10:]:
        result = ip_file_check(path)
    else:
        for dir, dir_names, files in os.walk(path):
            for file in files:
                full_path = os.path.join(dir, file)
                if not (os.path.isfile(full_path) and name == path[-10:]):
                    continue
                result.extend(ip_file_check(full_path))

    ip_group = []
    for ip in result:
        ip_group.append(ip.group())

    ip_dict = {}
    for ip in ip_group:
        ip_dict[ip] = ip_group.count(ip)

    result = sorted(ip_dict, key=lambda x: ip_dict[x], reverse=True)
    if len(result) >= 7:
        return result[:7]
    else:
        return result
