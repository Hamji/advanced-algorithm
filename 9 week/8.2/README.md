황구도
<details> 
<summary> 접기/펼치기 버튼 </summary>  

```python
class CallListener:
    def __init__(self):
        pass
    
class Call:
    def __init__(self):
        pass

class Respondent:
    listener = None # call Listener
    call = None # call Info
    callable = True # can catch call?
    def __init__(self, dispatcher):
        self.listener = None
        self.call = None
        self.callable = True
        self.dispatcher = dispatcher
        self.dispatcher.add("Respondent", self)
        
    def __str__(self):
        return " * Callable? : " + str(self.callable)
    
    def iscallable(self) -> bool:
        return self.callable

    def __change_status(self, call=None) -> None:
        if not self.callable:
            self.callable = True
            if self.listener is not None:
                listener.callback()
        else:
            self.callable = False
        self.call = call
        
    def add_callback_listener(self, listener: CallListener) -> None:
        self.listener = listener
    
    def catchCall(self, call: Call) -> bool:
        if not self.iscallable(): return False
        
        self.__change_status(call)
        
    def dispatchCall(self) -> None:
        if self.dispatcher.passCall("Respondent", self.call):
            self.__change_status()
        
class Manager(Respondent):
    def __init__(self, dispatcher):
        self.dispatcher = dispatcher
        self.dispatcher.add("Manager", self)
        
    def dispatchCall(self) -> None:
        if self.dispatcher.passCall("Manager", self.call):
            self.__change_status()
        
class Director(Manager):
    def __init__(self, dispatcher):
        self.dispatcher = dispatcher
        self.dispatcher.add("Director", self)
        
    def dispatchCall(self) -> None:
        if self.dispatcher.passCall("Director", self.call):
            self.__change_status()
    
        
        
    

```


```python
class callHandler:
    
    def __init__(self):
        self.respondents = []
        self.managers = []
        self.directors = []
    
    # Dispatch 하기 위한 정보 등록
    def add(self, id: str, respondent: Respondent):
        if id == "Respondent":
            self.respondents.append(respondent)
        elif id == "Manager":
            self.managers.append(respondent)
        elif id == "Director":
            self.directors.append(respondent)
        else:
            print("?")

    # 실제 Dispatch
    def passCall(self, id: str, call: Call) -> bool:
        if id == "Respondent":
            for manager in self.managers:
                if manager.iscallable():
                    manager.catchCall(call)
                    return True
            return self.passCall("Manager", call)
        elif id == "Manager":
            for director in self.directors:
                if director.iscallable():
                    director.catchCall(call)
                    return True
        return False
    
    def dispatchCall(self, call: Call):

        for respondent in self.respondents:
            if respondent.iscallable():
                respondent.catchCall(call)
                return
                
        for manager in self.managers:
            if manager.iscallable():
                manager.catchCall(call)
                return
                
        for director in self.directors:
            if director.iscallable():
                director.catchCall(call)
                return
        
```


```python
dispatcher = callHandler()

respondents = [Respondent(dispatcher) for _ in range(7)]
managers = [Manager(dispatcher) for _ in range(3)]
directors = [Director(dispatcher) for _ in range(2)]

def showStatus(): 
    print("=============== Respondents ==============")
    for respondent in respondents:
        print(respondent)
    print("=============== Managers   ==============")
    for manager in managers:
        print(manager)
        
    print("=============== Directors ==============")
    for director in directors:
        print(director)


print("****** BEFORE")
showStatus()
for i in range(8):
    dispatcher.dispatchCall(Call())

print("****** AFTER 8call dispatch")
showStatus()

print("****** PASS call 3 times")
for i in range(3):
    respondents[i].dispatchCall()
print("****** After Passing")
showStatus()

```

    ****** BEFORE
    =============== Respondents ==============
     * Callable? : True
     * Callable? : True
     * Callable? : True
     * Callable? : True
     * Callable? : True
     * Callable? : True
     * Callable? : True
    =============== Managers   ==============
     * Callable? : True
     * Callable? : True
     * Callable? : True
    =============== Directors ==============
     * Callable? : True
     * Callable? : True
    ****** AFTER 8call dispatch
    =============== Respondents ==============
     * Callable? : False
     * Callable? : False
     * Callable? : False
     * Callable? : False
     * Callable? : False
     * Callable? : False
     * Callable? : False
    =============== Managers   ==============
     * Callable? : False
     * Callable? : True
     * Callable? : True
    =============== Directors ==============
     * Callable? : True
     * Callable? : True
    ****** PASS call 3 times
    ****** After Passing
    =============== Respondents ==============
     * Callable? : True
     * Callable? : True
     * Callable? : True
     * Callable? : False
     * Callable? : False
     * Callable? : False
     * Callable? : False
    =============== Managers   ==============
     * Callable? : False
     * Callable? : False
     * Callable? : False
    =============== Directors ==============
     * Callable? : False
     * Callable? : True



```python

```


```python

```

</details>
