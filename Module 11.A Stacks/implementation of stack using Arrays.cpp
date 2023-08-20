#include<iostream>
using namespace std;

class stack {
    public:
// Data members 
    int index;
    int *arr;
    int size;
    int capacity;

// constructor
    stack(int size){
        arr = new int(size);
        index = -1;
        this->capacity = size;
        this->size = 0;
    }
// Behaviour

    int top(){
        if(index >= 0)
            return arr[index];
        else{
            cout<<"Stack is Empty \n";
            return -1;
        }
    }

    void push(int element){
        if(index+1 < capacity ){
            index++;
            arr[index] = element;
            size++;
        }
        else
            cout<<"Stack Over flow \n";
    }

    void pop(){
        if(index-1 < 0)
            cout<<"stack underflow \n";
        else{
            index--;
            size--;
        }
    }

    int size1(){
        return this->size;
    }

    bool empty(){
        if(index >= 0)
            return 0;
        else
            return 1;
    }

};

int main() {

    stack arr1(5);
    cout<<"is empty? " << arr1.empty()<<endl;
    arr1.pop();
    arr1.push(45);
    arr1.push(67);
    arr1.push(35);
    arr1.push(7);
    arr1.push(44);
    arr1.push(34);
    cout<<"Size = " << arr1.size1()<<endl;
    cout<<arr1.index<<endl;
    cout<<"Top  = " << arr1.top()<<endl;
    cout<<"is empty? " << arr1.empty()<<endl;
    arr1.pop();
    cout<<"Top  = " << arr1.top()<<endl;
    cout<<"Hello World \n";
}