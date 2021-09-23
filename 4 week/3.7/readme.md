## 3.7  

> 먼저 들어온 동물이 먼저 나가는 동물 쉼터가 있다고 하자  
> 이 쉼터는 개와 고양이만 수용할 수 있다. 
> 사람들은 쉼터의 동물들 가운데 들어온 지 가장 오래된 동물부터 입양할 수 있는데,  
> 개와 고양이 중 어떤 동물을 데려갈지 선택할 수도 있다.    
> 특정한 동물을 지정해 데려가는 것은 금지되어 있다.  이 시스템을 자료구조로 구현하라.  
> 해당 자료구조는 `enqueue`, `dequeueAny`, `dequeueDog`, `dequeueCat`의 연산들을 제공해야 한다.    




황규도
<details> 
<summary>접기/펼치기 버튼</summary>

## 2개의 Queue? 
 - Dog Queue, Cat Queue
 - `enqueue`   : O(1)
 - `dequeueAny`: O(1)  
   - 순서를 저장할 buffer OR 입양 시간을 기록
 - `dequeueDog`: O(1)
 - `dequeueCat`: O(1)

## 1개의 Queue?  
1. dequeueX를 O(1) ~ O(N)으로 탐색   
1개의 Queue에 `enqueue`하고, `dequeueX`를 탐색 기법으로.  


2. Array 방식과 LinkedList 방식의 Queue 혼용  
1개의 Array Queue에 Node를 넣는 방식  
 - Animal Queue
 - `enqueue`   : O(1)
 - `dequeueAny`: O(1)  
 - `dequeueDog`: O(1)
 - `dequeueCat`: O(1)
 


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
        self.animal = Queue()
    
    def enqueue(self, data):
        if type(data) is Dog: self.dog.enqueue(data)
        else: self.cat.enqueue(data)
        self.animal.enqueue(data)
            
    def dequeueAny(self):
        animal = self.animal.dequeue()
        if type(animal) is Dog: self.dog.dequeue()
        else: self.cat.dequeue()
        return animal
    
    def dequeueDog(self):
        self.animal.dequeue()
        return self.dog.dequeue()
    
    def dequeueCat(self):
        self.animal.dequeue()
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

    [*] dog : DE
    [*] dog : DD
    [*] cat : CD
    [*] dog : DC
    [*] cat : CC
    


```python

```

</details>




