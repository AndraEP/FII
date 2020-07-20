import socket
import time
import sys
import urllib
import re
from urllib import request

# # ex1
# s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# ipAddress = "127.0.0.1"
# port = int(1234)
# s.connect((ipAddress, port))
# s.send(b"Show info")
# s.close()

# # ex 2
# s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# s.sendto(sys.argv[3].encode("UTF-8"), (sys.argv[1], int(sys.argv[2])))
# s.close()

# # ex4
# urlManagement = 'http://localhost:5000/'
# try:
#     response = urllib.request.urlopen(urlManagement).read()
#     r = re.compile(b".*<a href=.*>(.*)</a>")
#     objs = r.findall(response)
#     for obj in objs:
#         str = obj.decode("UTF=8")
#         if re.match(r"([\w\d\-.]+\.txt)", str):
#             print(str[:-4])
# except Exception as e:
#     print("Error -> ",e)

# # ex 5
# urlManagement = 'http://www.uaic.ro/studii/facultati-2/facultatea-de-informatica/'
# r = re.compile(b"<img src=\"([^\"]+)\" .*>")
# try:
#     response = urllib.request.urlopen(urlManagement).read()
#     objs = r.findall(response)
#     for obj in objs:
#         urllib.request.urlretrieve(obj.decode("UTF-8"), obj.decode("UTF-8").split('/')[-1])
# except Exception as e:
#     print("Error -> ", e)