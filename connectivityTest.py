from time import sleep

import socket
# ser = serial.Serial('/dev/cu.usbmodem14501', 9600) # Establish the connection on a specific port


#counter = 32 # Below 32 everything in ASCII is gibberish
#while True:
#     print(ser.readline())
     


import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("connecting")
s.connect((socket.gethostbyname('tcp://0.tcp.ngrok.io'), 15572))
print("connected")

while True:
    inp = input("enter somthing : ")
    if(inp == 'exit'):
        s.close()
        exit(0)
    inp += '\0'
    s.sendall((inp.encode('utf-8')))


print("end")
