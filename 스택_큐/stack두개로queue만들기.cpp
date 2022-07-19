#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> st1, st2;

public:
    bool IsEmpty() {
        return st1.empty() && st2.empty();
    }

    void Enqueue(int data) {
        st1.push(data);
    }

    void Shift() {
        
        if (!st2.empty()) return ;
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }

    int Dequeue() {
        
        if (IsEmpty()) exit(-1);
        Shift();
        int rdata = st2.top();
        st2.pop();
        return rdata;
    }

    int Peek() {

        if (IsEmpty()) exit(-1);
        Shift();
        return st2.top();
    }   
};

int main() {

    MyQueue q;

    int arr1[5] = {7, 77, 11, 15, 12};
    for (int i=0; i<5; i++) q.Enqueue(arr1[i]);

    cout<<q.Dequeue()<<" "; 
    cout<<q.Dequeue()<<" "; 

    int arr2[2] = {19, 20};
    for (int i=0; i<2; i++) q.Enqueue(arr2[i]);

    while (!q.IsEmpty()) cout<<q.Dequeue()<<" ";
    return 0;
}