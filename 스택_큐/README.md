## 스택

한 쪽은 막혀있고 다른 한 쪽으로만 데이터가 입출력되는 자료구조<br/>
LIFO(Last-In, First-Out)

### ADT

```
void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void Push(Stack* pstack, Data data); //데이터 삽입
Data Pop(Stack* pstack); //top에 있는 데이터 삭제
Data Peek(Stack* pstack); //top에 있는 데이터 반환
```

### 스택을 구현하는 방법

* [**배열 기반 스택**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EC%8A%A4%ED%83%9D_%ED%81%90/%EC%8A%A4%ED%83%9D/%EB%B0%B0%EC%97%B4%EA%B8%B0%EB%B0%98%EC%8A%A4%ED%83%9D/ArrayStack.c)
* [**연결 리스트 기반 스택**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EC%8A%A4%ED%83%9D_%ED%81%90/%EC%8A%A4%ED%83%9D/%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8%EA%B8%B0%EB%B0%98%EC%8A%A4%ED%83%9D/ListStack.c)


## 큐

한 쪽으로는 데이터가 들어오고, 다른 한쪽으로는 데이터가 나가는 자료구조</br>
FIFO(First-In, First-Out)

### ADT

```
void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data Peek(Queue* pq);
```

### 큐를 구현하는 방법

* [**배열 기반 큐**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EC%8A%A4%ED%83%9D_%ED%81%90/%ED%81%90/%EB%B0%B0%EC%97%B4%EA%B8%B0%EB%B0%98%ED%81%90/CircleQueue.c)

    * 배열의 빈 공간을 효율적으로 사용하기 위해 `원형큐` 사용
    * `front == rear` 일 때 큐가 빈 상태
    * `rear+1 == front` 일 때 큐가 꽉찬 상태

* [**연결리스트 기반 큐**](https://github.com/GyeongahNa/DataStructureTIL/blob/main/%EC%8A%A4%ED%83%9D_%ED%81%90/%ED%81%90/%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8%EA%B8%B0%EB%B0%98%ED%81%90/ListQueue.c)
