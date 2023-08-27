class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int left = (2*i)+1;
        int right = (2*i)+2;
        
        if(left < n && arr[left] > arr[largest]) 
            largest = left;
            
        if(right < n && arr[right] > arr[largest]) 
            largest = right;
            
        if(i != largest){
            swap(arr[i], arr[largest]);
            heapify(arr,n,largest);
        }
        
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2-1; i >=0 ; i--) {
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        int size = n-1;
        
        while(size > 0) {
            swap(arr[0],arr[size]);
            heapify(arr, size, 0);
            size--;
        }
    }
    
};
