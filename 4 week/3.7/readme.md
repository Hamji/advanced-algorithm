## 3.7  

> 먼저 들어온 동물이 먼저 나가는 동물 쉼터가 있다고 하자  
> 이 쉼터는 개와 고양이만 수용할 수 있다. 
> 사람들은 쉼터의 동물들 가운데 들어온 지 가장 오래된 동물부터 입양할 수 있는데,  
> 개와 고양이 중 어떤 동물을 데려갈지 선택할 수도 있다.    
> 특정한 동물을 지정해 데려가는 것은 금지되어 있다.  이 시스템을 자료구조로 구현하라.  
> 해당 자료구조는 `enqueue`, `dequeueAny`, `dequeueDog`, `dequeueCat`의 연산들을 제공해야 한다.    





<details> 황규도
<summary>접기/펼치기 버튼</summary>

## 2개의 Queue? 
 - Dog Queue, Cat Queue
 - `enqueue`   : O(1)
 - `dequeueAny`: O(1)
 - `dequeueDog`: O(1)
 - `dequeueCat`: O(1)

## 1개의 Queue로 가능할까?  
 - `dequeueAny`가 더 자연스럽게 표현 가능.  
 - O(1) 보장하려면 Queue 응용이 필요.
 ```python
class Cat:
    def __init__(self, id):
        self.id = id
        self.type = 'cat'
        
    def __str__(self):
        return "[*] cat : " + self.id
        
class Dog:
    def __init__(self, id):
        self.id = id
        self.type = 'dog'
        
    def __str__(self):
        return "[*] dog : " + self.id

class Queue:
    def __init__(self):
        self.__queue = []
    
    def enqueue(self, data):
        self.__queue.append(data)
        
    def dequeue(self):
        return self.__queue.pop()
    
class Shelter:
    def __init__(self):
        self.dog = Queue()
        self.cat = Queue()
    
    def enqueue(self, data):
        if type(data) is Dog: self.dog.enqueue(data)
        else: self.cat.enqueue(data)
            
    def dequeueAny(self):
        import random
        if random.randint(1,2) == 1: return self.dog.dequeue()
        else: return self.cat.dequeue()
    
    def dequeueDog(self):
        return self.dog.dequeue()
    
    def dequeueCat(self):
        return self.cat.dequeue()
```


```python
shelter = Shelter()
shelter.enqueue(Cat("CA"))
shelter.enqueue(Cat("CB"))
shelter.enqueue(Dog("DA"))
shelter.enqueue(Dog("DB"))
shelter.enqueue(Cat("CC"))
shelter.enqueue(Dog("DC"))
shelter.enqueue(Cat("CD"))
shelter.enqueue(Dog("DD"))
shelter.enqueue(Dog("DE"))
```


```python
print(shelter.dequeueAny())
print(shelter.dequeueAny())
print(shelter.dequeueAny())
print(shelter.dequeueDog())
print(shelter.dequeueCat())
```

    [*] cat : CD
    [*] dog : DE
    [*] dog : DD
    [*] dog : DC
    [*] cat : CC
    


```python
```
</details>




