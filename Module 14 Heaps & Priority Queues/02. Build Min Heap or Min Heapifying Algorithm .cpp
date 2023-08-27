// Time Complexity O(log N)

#include <bits/stdc++.h>

void Heapify(vector<int> &arr, int n, int i) {

    int left = (i*2)+1;
    int right = (i*2)+2;
    int small = i;

    if(left < n && arr[left] < arr[i]) {
        swap(arr[i], arr[left]);
        Heapify(arr,n,left);
    }
    
    if(right < n && arr[right] < arr[i]) {
        swap(arr[i], arr[right]);
        Heapify(arr,n,right);
    }

/*
        
    if(right < n && arr[right] < arr[i]) {
        swap(arr[i], arr[right]);
        Heapify(arr,n,right);
    }

    if(left < n && arr[left] < arr[i]) {
        swap(arr[i], arr[left]);
        Heapify(arr,n,left);
    }
    
*/
    

/*
    if(left < n && arr[left] < arr[small]) {
        small = left;
    }

    if(right < n && arr[right] < arr[small])
        small = right;
    
    if(small != i){
        swap(arr[small],arr[i]);
        Heapify(arr,n,small);
    }
*/
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    for(int i=n/2-1;i>=0;i--){
       Heapify(arr,n,i);
    }

    return arr;
}
