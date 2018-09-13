import socket
import sys

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.connect(("localhost", 80))
request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: keep-alive\r\n\r\n"
socket.send(request)
response = socket.recv(5000)
print response
request_deux = "GET /favicon.ico HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: keep-alive\r\n\r\n"
socket.send(request_deux)
response = socket.recv(5000)
print sys.getsizeof(response)
