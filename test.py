import socket
import sys

sockett = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockett.connect(("localhost", 80))
request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: keep-alive\r\n\r\n"
sockett.sendall(request)
response = sockett.recv(5000)
print len(response)

request_deux = "GET /favicon.ico HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: keep-alive\r\n\r\n"
sockett.sendall(request_deux)
response_deux = sockett.recv(5000)
print len(response_deux)
