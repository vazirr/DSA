//page 30 -------------------------------------------------------------------------------

#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        arr = new int[100001];
        qfront = 0;
        rear = 0;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int data) {
        //for full queue
        if(rear == size){
            cout << "Queue is full"<<endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        //CHECK empty
        if(qfront ==  rear){
            return -1;
        }else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
                if(qfront == rear){
                      qfront = 0;
                     rear = 0;
                     }
             return ans;
        }
    }

    int front() {
       //CHECK QUEUE IS EMPTY
       if(qfront == rear){
           return -1;
       }else{
           int ans = arr[qfront];
           return ans;
       }

    }
};
