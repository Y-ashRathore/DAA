#include <iostream>
using namespace std;

const int N = 4; // Specify the size of the array

int g[N][N] = {{0,1,0,1},{1,0,1,1},{0,1,0,1},{1,1,1,0}};

void print(int res[], int s){
    for(int i = 0; i < s; i++){
        cout << res[i] << " ";
    }
    cout<<endl;
}

bool issafe(int k, int c, int res[]){
    for(int i = 0; i < N; i++){
        if(g[k][i] == 1 && res[i] == c)
            return false;
    }
    return true;
}

void graphcolor(int k, int res[]){
    for(int c = 1; c <= 4; c++){
        if(issafe(k, c, res)){
            res[k] = c;
            if(k + 1 < N)
                graphcolor(k + 1, res);
            else{
                print(res, N);
                return;
            }
        }
    }
}

int main() {
    int res[N];
    graphcolor(0, res);
    return 0;
}

