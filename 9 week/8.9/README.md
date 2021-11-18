## 8.9

> 메모리 상주형 파일 시스템(in-memory filesystem) 을 구현하기 위한 자료구조와 알고리즘에 대해서 설명해보라. 가능하다면 코드 예제를 들어 설명하도록 하라.



김건희
<details>
<summary>접기/펼치기 버튼</summary>

``` python3
  
  from typing import List
from collections import defaultdict
class TrieNode:
    def __init__(self):
        self.children = {}

class FileSystem:

    def __init__(self):
        self.fs = TrieNode()
        self.file_content = defaultdict(str)

    def ls(self, path: str) -> List[str]:
        if path in self.file_content:
            return path.split("/")[-1:]

        curr = self.fs
        for d in path.split("/"):
            if d in curr.children:
                curr = curr.children[d]
            elif d:
                return []
        return sorted(curr.children.keys())

    def mkdir(self, path: str) -> None:
        curr = self.fs
        for d in path.split("/"):
            if d not in curr.children:
                curr.children[d] = TrieNode()
            curr = curr.children[d]

    # 파일 추가
    def addContentToFile(self, filePath: str, content: str) -> None:
        self.mkdir(filePath)
        self.file_content[filePath] += content

    # 파일 읽기
    def readContentFromFile(self, filePath: str) -> str:
        return self.file_content[filePath]

fs = FileSystem()
fs.mkdir("hello")
fs.mkdir("wow")
fs.mkdir("wow/asd")
print(fs.ls("wow"))
  
```
  
  
</details>
