## 리스트 

데이터를 나란히 저장하는 자료구조로, 중복 저장을 허용

### ADT

```
void ListInit(List* plist) //리스트 초기화
void LInsert(List* plist, LData data) //데이터 삽입
int LFirst(List* plist, LData* pdata) //첫번째 데이터 참조
int LNext(List* plist, LData* pdata) //최근 참조 데이터의 바로 뒤 데이터 참조
LData LRemove(List* plist) //최근 참조 데이터 삭제
```

### 리스트를 구현하는 방법

* [**순차리스트**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EC%88%9C%EC%B0%A8%EB%A6%AC%EC%8A%A4%ED%8A%B8/ArrayList.c)
    * 배열을 이용하여 구현하는 방법(ArrayList)
    * **단점**: 배열의 크기가 고정되어있어 유동적으로 늘릴 수 없고, 원소를 삭제할 때 뒤의 원소를 모두 앞으로 당겨와야 함
* **연결리스트**
    * 메모리 동적할당을 이용하여 구현하는 방법
    * [**단순연결리스트**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EB%8B%A8%EC%88%9C%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8/SLinkedList.c)
        * 한 방향으로만 이어지는 리스트
    * [**원형연결리스트**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EC%9B%90%ED%98%95%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8/CLinkedList.c)
        * 꼬리 노드가 머리 노드를 가르키는 리스트
        * 머리와 꼬리에 자유롭게 접근 가능
        * 머리에 새 노드를 추가하는 것과 꼬리에 새 노드를 추가하는 것이 동일
        * LNext(): 리스트의 원소가 있는 한 무한 순회
    * [**양방향연결리스트**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8/%EC%96%91%EB%B0%A9%ED%96%A5%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8/DBLinkedList.c)
        * 한 노드가 왼쪽 노드와 오른쪽 노드를 가르키는 리스트
        * 왼쪽과 오른쪽으로 자유롭게 순회 가능
