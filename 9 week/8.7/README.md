## 8.9

> 채팅 서버를 어떻게 구현할 것인지 설명하라. 서버를 뒷받침할 다양한 컴포넌트, 클래스, 메서드에 대해 설명하도록 하라. 어떤 문제가 가장 풀기 어려울 것으로 예상되는가?



정민혁
<details>
<summary>접기/펼치기 버튼</summary>

``` python3
  
#server
import socket
import threading
from queue import Queue

def Send(group, send_queue):
    while True:
        try:
            recv = send_queue.get()
            if recv == "Group changed":
                print("Group changed")
                break
            
            for conn in group:
                msg = "Client" + str(recv[2])+ ">>" + str(recv[0])
                if recv[1] != conn:
                    conn.send(bytes(msg.encode()))
                else:
                    pass
        except:
            pass

def Recv(conn, count, send_queue):
    while True:
        data = conn.recv(1024).decode()
        send_queue.put([[data, conn, count]])
        
if __name__ == '__main__':
    send_queue = Queue()
    HOST = ''
    PORT = 9223
    server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_sock.bind((HOST, PORT))
    server_sock.listen(10)
    count = 0
    group = []
    while True:
        count = count + 1
        conn, addr = server_sock.accept()
        group.append(conn)
        print('Connected' + str(addr))

        if count > 1:
            send_queue.put('Group Changed')
            thread1 = threading.Thread(target=Send, args=(group, send_queue,))
            thread1.start()
            pass
        else:
            thread1 = threading.Thread(target=Send, args=(group, send_queue,))
            thread1.start()

        thread2 = threading.Thread(target=Recv, args=(conn, count, send_queue,))
        thread2.start()
  
  
  
  
#client
import socket
import threading
import sys

def Send(client_sock):
    while True:
        send_data = bytes(input().encode())
        client_sock.send(send_data)

def Recv(client_sock):
    while True:
        recv_data = client_sock.recv(1024).decode()
        print(recv_data)
        
if __name__=='__main__':
    client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    Host = '127.0.0.1'
    Port = 9223
    client_sock.connect((Host, Port))
    print('Connecting to', Host, Port)

    thread1 = threading.Thread(target=Send, args=(client_sock,))
    thread1.start()

    thread2 = threading.Thread(target=Recv, args=(client_sock,))
    thread2.start()

```
  
  
</details>
