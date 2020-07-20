import hashlib
import socket
import time
import http.server
import socketserver

# # ex1
# s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# s.bind(("127.0.0.1", 1234))
# s.listen(10)
#
# (connection, (address, port)) = s.accept()
# print("Connected address:", address)
# tobj = time.localtime()
#
# while True:
#     data = connection.recv(100).decode("UTF-8")
#
#     file = open("myFile.txt", 'w')
#
#     # ipAddress = socket.gethostbyname(socket.gethostname())
#     # port = connection.getpeername()[1]
#     infos = "ipAddress: " + str(address) + ", port: " + str(port) + " time: " + (time.asctime(tobj))
#
#     file.write(infos)
#     break
#
# connection.close()
# print ("Server closed")


# # ex2
# s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# s.bind(('127.0.0.1', 1234))
# while True:
#     (data, (address, port)) = s.recvfrom(100)
#     f = open("file2.txt", "wt")
#     f.write("time: " + time.ctime()+"\n")
#     f.write("address: " + address+"\n")
#     f.write("port: " + str(port)+"\n")
#     f.write("length: " + str(len(data))+"\n")
#     f.write("address: " + address+"\n")
#     f.write("md5: " + str(hashlib.md5(data).hexdigest())+"\n")
#     f.write("sha256: " + str(hashlib.sha256(data).hexdigest())+"\n")
#     f.close()
#     break
#
# print("Server closed")

# ex3
httpd = socketserver.TCPServer(("127.0.0.1", 5000), http.server.SimpleHTTPRequestHandler)
httpd.serve_forever()