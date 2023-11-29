#include <iostream>
using namespace std;
void print(int res[],int s){
    for(int i=0;i<s;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
bool issafe(int res[],int x2,int y2){
    for(int i=0;i<x2;i++){
        if(res[i] == y2 || abs(i-x2)==abs(res[i]-y2))
            return 0;
    }
    return 1;
}
void placeQueens(int res[],int x,int size){
    for(int i=0;i<size;i++){
        if(issafe(res,x,i)){
            res[x] = i;
            if(x == size-1){
                print(res,size);
                return;
            }
            placeQueens(res,x+1,size);
        }
    }
}
int main() {
    int res[4];
    placeQueens(res,0,4);
    return 0;
}
