/*
 Time Complexity: O(n)
 Auxiliary Space: O(log(n))
*/


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        // MAX Heap
        priority_queue<int>pq;
        
        int i;
        for(i = l ; i < l+k ; i++)
            pq.push(arr[i]);

        
        for( i = l+k ; i <= r ;i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();    
    }
};
