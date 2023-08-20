#include<iostream>
using namespace std;

class KQueue{
    private:
        int n;
        int k;
        int freespace;
        int *arr;
        int *front;
        int *rear;
        int *next;

        public:
        // CONSTRUCTOR 
        KQueue(int n, int k){

           freespace = 0; 
            this->n = n;
            this->k = k;

            arr = new int[n];

            front = new int[k];
            rear = new int[k];
            for(int i = 0; i < k ; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i < n-1; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

    
            void push(int data, int q){
                
                // check for wether Queue is Overflow
                if(freespace == -1){
                    cout<<"Queue Overflow \n";
                    return;
                }

                // find index to enque
                int index = freespace;

                // update freespace
                freespace = next[index];

                // check wether it is a first element to insert
                if(front[q-1] == -1){
                    front[q-1] = index;                                                                                                        
                }
                else{
                    next[rear[q-1]] = index;
                }

                // Limiting the Queue
                next[index] = -1;

                // Update Rear
                rear[q-1] = index;

                // Pushing the data
                arr[index] = data;

            }

            void pop(int q){

                if(front[q-1] == -1){
                    cout<<" Queue Under Flow \n";
                    return ;
                }

                //  index to pop
                int index = front[q-1];
                int element = arr[index];

                // delete element by moving one index++ by front
                front[q-1] = next[index];

                // Updating freespace Avalilable
                next[index] = freespace;

                freespace = index;

                // Returning deleted element
                cout<<"deleted element  is "<<element<<endl;
            }

};


    int main()
    {
        KQueue kQ(8,4);
        kQ.push(25,1);
        kQ.push(23,2);
        kQ.push(21,3);
        kQ.push(76,4);
        kQ.push(5,1);
        kQ.push(3,2);
      //  kQ.push(1,3);
        kQ.push(6,4);
        kQ.push(677,4);

        kQ.pop(4);
        kQ.pop(4);
        kQ.pop(4);
        kQ.pop(4);

        kQ.pop(1);
        kQ.pop(2);
        kQ.pop(3);

        kQ.pop(2);
        kQ.pop(2);

    }
