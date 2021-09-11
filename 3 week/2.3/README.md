## 2.3

> 단방향 연결 리스트의 중간에 있는 노드 하나를 삭제하는 알고리즘을 구현하라.
> 삭제할 노드에 대한 접근만 가능하다는 것에 유의하라.

---

수원

<details>
<summary>접기/펼치기 버튼</summary>

``` c

/**
 * @brief 단방향 연결 리스트의 중간에 있는 노드 하나를 삭제하는 알고리즘을 구현하라. 삭제할 노드에 대한 접근만 가능하다는 것에 유의하라.
 * 
 * Distributor ID: Ubuntu
 * Description:    Ubuntu 20.04.2 LTS
 * Release:        20.04
 * Codename:       focal
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 주어진 인자들의 개수를 반환하는 함수
 * 
 */
#define NUMARGS(...) (sizeof((int[]){0, ##__VA_ARGS__}) / sizeof(int) - 1)

/**
 * @brief list_name으로 리스트를 생성하여 나머지 인자들로 값들을 채우는 함수
 * 
 * @param list_name // 리스트의 이름
 */
#define DECLARE_LIST(list_name, ...)                      \
    struct node *list_name = malloc(sizeof(struct node)); \
    list_name->next = NULL;                               \
    do                                                    \
    {                                                     \
        if (NUMARGS(__VA_ARGS__) <= 0)                    \
            break;                                        \
        int _t[] = {__VA_ARGS__};                         \
        int _numt = sizeof _t / sizeof _t[0];             \
        struct node *_temp = list_name;                   \
        for (int _i = 0; _i < _numt; _i++)                \
        {                                                 \
            _temp->data = _t[_i];                         \
            if (_i >= _numt - 1)                          \
            {                                             \
                _temp->next = NULL;                       \
                break;                                    \
            }                                             \
            _temp->next = malloc(sizeof(struct node));    \
            _temp = _temp->next;                          \
        }                                                 \
    } while (0)

/**
 * @brief 리스트의 끝까지 출력하는 함수
 * 
 * @param list_name // 리스트의 이름
 */
#define PRINT_LIST(list_name)                                                            \
    do                                                                                   \
    {                                                                                    \
        printf("START ->");                                                              \
        for (struct node *_cursor = list_name; _cursor != NULL; _cursor = _cursor->next) \
            printf(" %d ->", _cursor->data);                                             \
        printf(" END\n");                                                                \
    } while (0)

struct node
{
    int data;
    struct node *next;
};

/**
 * @brief 주어진 노드의 주소를 다음 노드의 주소로 바꾸고 주어졌던 노드를 삭제한다
 * 
 * @param n // 노드의 주소값 
 */
void delNode(struct node **n)
{
    // n은 NULL이 아니라고 가정
    struct node *temp = *n; // 이전 노드 백업
    *n = (*n)->next;        // n의 다음 노드의 포인터를 n으로 복사
    free(temp);             // 이전 노드 free
}

int main()
{
    DECLARE_LIST(head, 1, 2, 3, 4, 5); // 리스트 선언 함수

    PRINT_LIST(head); // 리스트 출력함수

    delNode(&head->next->next);

    PRINT_LIST(head);
}

```
  
</details>
