#include<iostream>
using namespace std;

class stack {
    public:
// Data members 
    int data ;
    int *next ;

// constructor
    stack(){
        this->next = NULL;
    }

// Behaviour
    int top(){
        
    }

    void push(int element){
        stack temp;
        temp->data = element;
        temp->next = NULL;
        this->next = temp;
    }

    void pop(){

    }

    int size1(){
    
    }

    bool empty(){

    }

};

int main() {

    stack arr1;
    stack tail = arr1;
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