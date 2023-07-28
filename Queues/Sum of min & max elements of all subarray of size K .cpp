#include<iostream>
#include<deque>
using namespace std;

int sumMaxMin(int arr[], int n, int k){

    int ans = 0;
    deque<int>maxi;
    deque<int>mini;
    for(int i=0 ; i<k ; i++){

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    ans =  ans + arr[maxi.front()] + arr[mini.front()];

    for(int i=k; i<n; i++){

        while(!maxi.empty() && maxi.front() - i >= k){
                maxi.pop_front();
        }

        while(!mini.empty() && mini.front() - i >= k){
                mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans =  ans + arr[maxi.front()] + arr[mini.front()];
    
    }
        
    return ans;

}

int main(){

        int arr[7] = {2, 5, -1, 7, -3, -1, -2};

        cout<<"sumMaxMin = "<<sumMaxMin(arr,7,4)<<endl;

        return 0;
}
