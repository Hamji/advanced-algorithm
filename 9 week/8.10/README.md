### 8.10

> 체인(chain, Linkedlist)를 사용해 충돌을 해결하는 해시 테이블을 설계하고 구현하라


<details>  황규도

<summary>접기/펼치기 버튼 </summary>
```python
import hashlib
from termcolor import colored

class Hash:
    
    def __init__(self):
        self.color = None
        self.table = [-1 for i in range(8)]
        self.keys = [i for i in range(8)]
        self.new = None
        self.crashed = []
        
    def printHash(self):
        if self.color is None:
            print("============ HASH TABLE ============")
        else:
            print(colored("========= SMART HASH TABLE =========", self.color))
        for i in range(8):
            if type(self.table[i]) is list:
                print(f' {self.keys[i]} == > {self.table[i]}', end='')
            else:
                print(f' {self.keys[i]:10} == > {self.table[i]:10}', end='')
            if i in self.crashed:
                print(colored(" <<< Collision", "red"))
            elif i == self.new:
                print(colored(" <<< new NODE", "green"))
            else:
                print()
                

    def hash_function(self, key):
        return ord(hashlib.sha1(key.encode("UTF-8")).hexdigest()[:1]) % 8
    
    def put(self, key, value):
        address = self.hash_function(key)
        if self.table[address] != -1: 
            self.crashed.append(address)
        
        self.new = address
        self.table[address] = value
        self.keys[address] = key
    
    def smart_put(self, key, value):
        if self.color is None: self.color = "blue"
        address = self.hash_function(key)
        
        if self.table[address] != -1: # 해쉬 충돌이 발생한 경우
            if key == self.keys[address]: # 만약 같은 Key를 가진다면? Overwrite
                self.table[address] = value
            else: # 진짜 충돌
                self.keys[address] = [self.keys[address], key]
                self.table[address] = [self.table[address], value]
        else:
            self.new = address
            self.table[address] = value
            self.keys[address] = key
                
    def get(self, key):
        if key not in self.keys:
            raise KeyError
        return self.table[self.hash_function(key)]
    
    def smart_get(self, key):
        address = self.hash_function(key)
        key_set = self.keys[address]
        if type(key_set) is list:
            return self.table[address][key_set.index(key)]
        else: 
            return self.table[address]
        
            
                
```


```python
import random
import string
myHash = Hash()
smartHash = Hash()

sets = {}
for i in range(6):
    key = ''.join(random.choices(string.ascii_uppercase + string.digits, k=8))
    value = random.randint(0, 256)
    sets[key] = value
    
    myHash.put(key, value)
    myHash.printHash()
    
    smartHash.smart_put(key, value)
    smartHash.printHash()
    
```

    ============ HASH TABLE ============
              0 == >         -1
              1 == >         -1
     5Q50HNPQ   == >         27[32m <<< new NODE[0m
              3 == >         -1
              4 == >         -1
              5 == >         -1
              6 == >         -1
              7 == >         -1
    [34m========= SMART HASH TABLE =========[0m
              0 == >         -1
              1 == >         -1
     5Q50HNPQ   == >         27[32m <<< new NODE[0m
              3 == >         -1
              4 == >         -1
              5 == >         -1
              6 == >         -1
              7 == >         -1
    ============ HASH TABLE ============
              0 == >         -1
              1 == >         -1
     6O7RQQ3H   == >         25[31m <<< Collision[0m
              3 == >         -1
              4 == >         -1
              5 == >         -1
              6 == >         -1
              7 == >         -1
    [34m========= SMART HASH TABLE =========[0m
              0 == >         -1
              1 == >         -1
     ['5Q50HNPQ', '6O7RQQ3H'] == > [27, 25][32m <<< new NODE[0m
              3 == >         -1
              4 == >         -1
              5 == >         -1
              6 == >         -1
              7 == >         -1
    ============ HASH TABLE ============
              0 == >         -1
              1 == >         -1
     6O7RQQ3H   == >         25[31m <<< Collision[0m
     9201X5PB   == >        247[32m <<< new NODE[0m
              4 == >         -1
              5 == >         -1
              6 == >         -1
              7 == >         -1
    [34m========= SMART HASH TABLE =========[0m
              0 == >         -1
              1 == >         -1
     ['5Q50HNPQ', '6O7RQQ3H'] == > [27, 25]
     9201X5PB   == >        247[32m <<< new NODE[0m
              4 == >         -1
              5 == >         -1
              6 == >         -1
              7 == >         -1
    ============ HASH TABLE ============
              0 == >         -1
              1 == >         -1
     6O7RQQ3H   == >         25[31m <<< Collision[0m
     9201X5PB   == >        247
              4 == >         -1
              5 == >         -1
     7XPAGGD9   == >        164[32m <<< new NODE[0m
              7 == >         -1
    [34m========= SMART HASH TABLE =========[0m
              0 == >         -1
              1 == >         -1
     ['5Q50HNPQ', '6O7RQQ3H'] == > [27, 25]
     9201X5PB   == >        247
              4 == >         -1
              5 == >         -1
     7XPAGGD9   == >        164[32m <<< new NODE[0m
              7 == >         -1
    ============ HASH TABLE ============
              0 == >         -1
              1 == >         -1
     6O7RQQ3H   == >         25[31m <<< Collision[0m
     4F97F5FO   == >        100[31m <<< Collision[0m
              4 == >         -1
              5 == >         -1
     7XPAGGD9   == >        164
              7 == >         -1
    [34m========= SMART HASH TABLE =========[0m
              0 == >         -1
              1 == >         -1
     ['5Q50HNPQ', '6O7RQQ3H'] == > [27, 25]
     ['9201X5PB', '4F97F5FO'] == > [247, 100]
              4 == >         -1
              5 == >         -1
     7XPAGGD9   == >        164[32m <<< new NODE[0m
              7 == >         -1
    ============ HASH TABLE ============
              0 == >         -1
              1 == >         -1
     6O7RQQ3H   == >         25[31m <<< Collision[0m
     4F97F5FO   == >        100[31m <<< Collision[0m
              4 == >         -1
              5 == >         -1
     3BQPNK2H   == >         25[31m <<< Collision[0m
              7 == >         -1
    [34m========= SMART HASH TABLE =========[0m
              0 == >         -1
              1 == >         -1
     ['5Q50HNPQ', '6O7RQQ3H'] == > [27, 25]
     ['9201X5PB', '4F97F5FO'] == > [247, 100]
              4 == >         -1
              5 == >         -1
     ['7XPAGGD9', '3BQPNK2H'] == > [164, 25][32m <<< new NODE[0m
              7 == >         -1



```python
print("\n============ HASH GET =============")
for key in sets.keys():
    try:
        print(f"{key} ==> ", end='')
        value = myHash.get(key)
        print(f"{value}")
    except:
        print(colored(" <<< Key Error", "red"))
        

        
print("\n========= SNART HASH GET ==========")
for key in sets.keys():
    print(f"{key} ==> {smartHash.smart_get(key)}")
```

    
    ============ HASH GET =============
    5Q50HNPQ ==> [31m <<< Key Error[0m
    6O7RQQ3H ==> 25
    9201X5PB ==> [31m <<< Key Error[0m
    7XPAGGD9 ==> [31m <<< Key Error[0m
    4F97F5FO ==> 100
    3BQPNK2H ==> 25
    
    ========= SNART HASH GET ==========
    5Q50HNPQ ==> 27
    6O7RQQ3H ==> 25
    9201X5PB ==> 247
    7XPAGGD9 ==> 164
    4F97F5FO ==> 100
    3BQPNK2H ==> 25



```python

```

</details>