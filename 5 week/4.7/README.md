## 4.7

> 이진 트리 내의 두 노드의 공통 선조(ancestor) 노드를 찾는 알고리즘을 설계하고 구현하라.  
> 자료구조 내에 부가적인 노드를 저장해 두는 일은 금한다.  
> 주의: 이진 탐색 트리가 아닐 수도 있다.

이재명
<details>
<summary>접기/펼치기 버튼</summary>

```JavaScript
// Pseudocode in JS style

// The function that computes the depth of a given node
function get_depth(node)
{
    // Let the depth of the root node is zero
    var depth = 0;
    
    // Traverse until its parent does not exist
    while ( node.parent() )
    {
        ++depth;
        node = node.parent();
    }
    
    // Return the computed depth
    return depth;
}

// The function we want to write
function get_common_ancestor(node1, node2)
{
    // Considering that the problem told us to find the 'common ancestor',
    // exclude the current nodes and start from the parents of each node
    node1 = node1.parent();
    node2 = node2.parent();
  
    // Get depths from the given nodes
    depth1 = get_depth(node1);
    depth2 = get_depth(node2);

    // Adjust depth if a node is deeper than the other
    while ( depth1 > depth2 )
    {
        node1 = node1.parent();
        --depth1;
    }
    while ( depth1 < depth2 )
    {
        node2 = node2.parent();
        --depth2;
    }
     
    // Traverse until we get the common ancestor or reach the end
    while ( node1 && node1 != node2 )
    {
        node1 = node1.parent();
        node2 = node2.parent();
    }

    // Return the final result
    return node1;
                           
    // Time complexity
    // = Depth-computing time + Traversal time
    // = O(D(N1) + D(N2)), where D(x) is the depth of a node x
}
  
```
