#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int *arr;
    int qfront;
    int qrear;
    int size;

// Initialise your Data Structure
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){

        // if QUEUE is full
        if((qfront == 0 && qrear == size-1) || (qrear == (qfront-1)%(size-1)))
        //  this can be also written as
        //  if(qrear == (qfront-1)%(size-1))
            return false;

        // if QUEUE is empty
        else if (qrear == -1 && qfront == -1) {
          qfront = 0;
          qrear = 0;
        }

        // to maintain circular condition
        else if (qrear == size - 1 && qfront != 0)
          qrear = 0;

        //Normal Case    
        else
            qrear++;

        arr[qrear] = value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){

        // Empty Queue Case
        if(qfront == -1)
            return -1;
    
        int element = arr[qfront];
       arr[qfront] = -1;
        // to maintain circular condition
        if(qfront == size-1)
            qfront = 0;

        // Single Element
        else if (qrear == qfront)
          qrear = qfront = -1;

        //  Normal Case
        else
            qfront++;
        
        return element;


    }
};