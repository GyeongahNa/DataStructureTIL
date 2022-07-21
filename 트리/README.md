## 트리

계층적 관계를 표현하는 자료구조

### 트리 용어

* 노드
* 간선: 노드와 노드를 연결하는 연결선
* 루트 노드: 최상위 노드
* 단말 노드: 자식노드가 없는 노드 
* 내부 노드: 비단말 노드
* 부모-자식/조상-후손 관계 존재
<br></br>

## 이진트리

루트 노드를 중심으로 두 개의 서브트리로 나누어지고, 각 서브트리도 이진트리인 트리(재귀적 정의)<br/>
노드가 있어야 하는 자리에 노드가 없다면 해당 자리에 공집합 노드가 있는 것으로 간주
<br></br>

### 이진트리의 종류

* **포화이진트리** 
    * 모든 레벨이 노드로 꽉 차있는 트리
* **완전이진트리**
    * 노드가 위에서 아래로, 왼쪽에서 오른쪽으로 순서대로 차있는 트리
<br></br>

### 이진트리의 구현 방법

* 배열 기반 구현
* [연결리스트 기반 구현](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%ED%8A%B8%EB%A6%AC/%EC%9D%B4%EC%A7%84%ED%8A%B8%EB%A6%AC/BinaryTree.c)
<br></br>

### 이진트리의 순회

* 전위순회(Preorder Traverse)
    * `루트 노드 ➡️ 왼쪽 서브트리 ➡️ 오른쪽 서브트리` 순으로 탐색
* 중위순회(Inorder Traverse)
    * `왼쪽 서브트리 ➡️ 루트 노드 ➡️ 오른쪽 서브트리` 순으로 탐색
* 후위순회(Postorder Traverse)
    * `왼쪽 서브트리 ➡️ 오른쪽 서브트리 ➡️ 루트 노드` 순으로 탐색
<br></br>

## 힙

완전이진트리의 일종으로, 모든 노드에 대하여 부모 노드의 우선순위가 자식 노드의 우선순위 보다 높음<br/>
단말 노드에서 루트 노드로 올라갈수록 우선순위가 높아짐</br>
크기가 작을수록 높은 우선순위를 부여하면 `최소힙`, 크기가 클수록 높은 우선순위를 부여하면 `최대힙`

### ADT

```
typedef int (*PriorityCmp)(HData data1, HData data2);

void HeapInit(Heap* ph, PriorityCmp cmp); //cmp로 우선순위 기준 함수 전달
void HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data);
void HDelete(Heap* ph);
```

### 힙의 구현

* [**배열 기반 구현**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%ED%8A%B8%EB%A6%AC/%ED%9E%99/Heap.c)
    * 삽입: 완전이진트리의 가장 마지막 위치에 노드를 삽입하고, 부모 노드와 비교해가면서 적절한 위치 찾기
    * 삭제: 루트 노드 제거, 가장 마지막 위치에 있는 노드로 루트 노드를 채운 후, 자식 노드들과 비교해가면서 적절한 위치 찾기
