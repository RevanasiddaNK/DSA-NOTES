#include <bits/stdc++.h> 
class Queue {
    //Members of Class
        int *arr;
        int size;
        int qfront;
        int qrear;
    
public:
    Queue() {
        size = 1000005;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qrear == qfront)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qrear == size)
            cout<<"Queue is full \n";
        else{
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qrear == qfront )
            return -1;
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear){
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qrear == qfront)
            return -1;
        else
            return arr[qfront];
    }
};
