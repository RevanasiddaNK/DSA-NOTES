#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&temp){
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
void solveRec(int arr[], vector<int>&temp, int index, int n, int &sum, int k){
    if(index >= n){
        if(sum == k){
            print(temp);
        }
        return;
    }
    // pick 
    temp.push_back(arr[index]);
    sum += arr[index];
    solveRec(arr,temp,index+1,n,sum,k);

    // not pick
    temp.pop_back();
    sum -= arr[index];
    solveRec(arr,temp,index+1,n,sum,k);
}

int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int k = 6;
    vector<int>temp;
    int index = 0;
    int sum = 0;
    int n = 10;
    solveRec(arr,temp,index,n,sum,k);

    return 0;
}
