## 2.7

> 주어진 연결 리스트가 회문(回文, palindrome)인지 검사하는 함수를 작성하라.
> * 회문(回文, palindrome): madam이나 nurses run처럼 앞에서부터 읽으나 뒤에서부터 읽으나 동일한 단어나 구.

이재명
<details>
<summary>접기/펼치기 버튼</summary>
	
아이디어
------
- 이중 연결 리스트(doubly linked list)일 경우 (난이도 ★☆☆☆☆)
  - head에서 앞으로, tail에서 뒤로 동시에 읽으면서 하나씩 비교
  - 전방 포인터와 후방 포인터가 같거나, 전방 포인터의 다음 항목이 후방 포인터와 같다면 검증 종료
- 단일 연결 리스트(singly linked list)일 경우 (난이도 ★★☆☆☆)
  - 총 2번의 iteration을 거치게 됨.
  - 첫번째 iteration: head에서부터 마지막 항목까지 stack에 모든 item을 push
  - 두번째 iteration: head에서부터 마지막 항목까지 stack에서 하나씩 pop하면서 value 비교
- 구현은 더 어려운 단일 연결 리스트(singly linked list)의 경우를 구현해 보았음

구현
------
- 언어: Modern C++ (C++11 이상)
- https://ideone.com/smVMQV

``` C++
#include <cstdio>
#include <stack>
using namespace std;

template <class T>
class SinglyLinkedList
{
public:
    class Item
    {
    	friend class SinglyLinkedList;
    	
    public:
        Item() { }
        Item(const T init_value) : value(init_value) { }
        virtual ~Item() { }

        Item *get_next()
        {
            return next;
        }
        const T get_value()
        {
            return value;
        }
        void set_value(const T new_value)
        {
            value = new_value;
        }

    private:
        Item *next { nullptr };
        T value { };
    };

    SinglyLinkedList() { }
    virtual ~SinglyLinkedList()
    {
        Item *cur = head;
        while ( cur )
        {
            Item *const next = cur->get_next();
            delete cur;
            cur = next;
        }
    }

    Item *get_head()
    {
        return head;
    }

    Item *append(const T value)
    {
        Item **final_next = &head;
        while ( *final_next )
        {
            final_next = &( **final_next ).next;
        }

        Item *const new_item = new Item(value);
        *final_next = new_item;
        return new_item;
    }

private:
    Item *head { nullptr };
};

const bool is_palindrome(SinglyLinkedList<char> &list)
{
	stack<char> s;
	
	auto item = list.get_head();
	while ( item )
	{
		s.push(item->get_value());
		item = item->get_next();
	}
	
	item = list.get_head();
	while ( item )
	{
		if ( item->get_value() != s.top() )
		{
			return false;
		}
		s.pop();
		item = item->get_next();
	}
	
	return true;
}

int main()
{
	SinglyLinkedList<char> a;
	a.append('A');
	a.append('B');
	a.append('C');
	a.append('B');
	a.append('A');
	printf("%d\n", int(is_palindrome(a)));
	
	SinglyLinkedList<char> b;
	b.append('A');
	b.append('B');
	b.append('C');
	b.append('B');
	printf("%d\n", int(is_palindrome(b)));
	
	return 0;
}
```
</details>
