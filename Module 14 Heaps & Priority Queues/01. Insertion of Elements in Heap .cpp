#include<iostream>
using namespace std;

class Heap {
    int arr[100];
    int size;

    public :

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void Insert(int data) {
        size++;
        int index = size;
        arr[index] = data;

        while(index > 1) {

             int parent = index/2;
            // for Maximim Heap
            if(arr[parent] < arr[index]) {
                swap(arr[index] , arr[parent]);
                index = parent;
             }
             else {
                return;
             }
/*
            // for Minimum Heap
            if(arr[parent] > arr[index]) {
                swap(arr[index] , arr[parent]);
                index = parent;
             }
             else {
                return;
             }
*/
        }
    }

    void printHeap() {
        for(int i=1; i <= size ; i++) {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main() {
    // cout<<" Hello World \n";
    Heap h1;
    h1.Insert(56);
    h1.printHeap();
    h1.Insert(65);
    h1.Insert(199);
    h1.Insert(234);
    h1.printHeap();
    h1.Insert(45);
    h1.Insert(34);
    h1.printHeap();

    return 0;
}