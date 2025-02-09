#include<iostream>
using namespace std;

class vector{
    int* arr;
    int size;
    public:
        vector(int m){
            size = m;
            arr = new int[size];
        }
        int length(self){
            return self.size;
        }
        int dotProduct(vector &v){
            if(size != v.length()){
                cerr<<"Dot product is only possible for equal size vectors\n";
                exit();
            }
            int d=0;
            for(int i=0;i<size; i++){
                d+=(v.arr[i] + arr[i]);
            }
            return d;
        }
};


int main()