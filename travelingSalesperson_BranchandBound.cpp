#include<bits/stdc++.h>
using namespace std;
int caluclateReductionCost(vector<vector<int>>& table,int x,int y,int n,int Cost){
    int r_val=0;
    if(x!=-1 && y!=-1){
    r_val=table[x][y];
    for(int i=0;i<n;i++){
        table[i][y]=INT_MAX;
        table[x][i]=INT_MAX;
    }
    }
    vector<int> rowWiseMin(n,0);
    vector<int> colWiseMin(n,0);
    for(int i=0;i<n;i++){
        if(i==x) continue;
        int rowmin=INT_MAX;
        for(int j=0;j<n;j++){
            rowmin=min(rowmin,table[i][j]);
        }
        if(rowmin!=INT_MAX)
        rowWiseMin[i]=rowmin;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            table[i][j]-=rowWiseMin[i];
        }
    }
    for(int i=0;i<n;i++){
        if(i==y) continue;
        int colmin=INT_MAX;
        for(int j=0;j<n;j++){
            colmin=min(colmin,table[j][i]);
        }
        if(colmin!=INT_MAX)
        colWiseMin[i]=colmin;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            table[j][i]-=colWiseMin[i];
        }
    }
    int totalReducedCost=0;
    for(int i=0;i<n;i++){
        totalReducedCost+=(rowWiseMin[i]+colWiseMin[i]);
    }
    totalReducedCost+=Cost+r_val;
    return totalReducedCost;
}
void printTable(vector<vector<int>> table,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve(int index,int n,vector<bool>& vis,vector<vector<int>> table,int& count,int Cost){
    if(count>=n){
        printTable(table,n);
        return;
    }
    int considered_Cost=INT_MAX;
    int reductionCost;
    vector<vector<int>> reducedMatrix;
    int nextDestination;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<vector<int>> temp=table;
            reductionCost=caluclateReductionCost(temp,index,i,n,Cost);
            cout<<index<<" "<<i<<" "<<reductionCost<<endl;
            if(reductionCost<considered_Cost){
                considered_Cost=reductionCost;
                reducedMatrix=temp;
                nextDestination=i;
            }
        }
    }
    vis[nextDestination]=true;
    count++;
    cout<<endl;
    cout<<nextDestination<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<reducedMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    solve(nextDestination,n,vis,reducedMatrix,count,considered_Cost);
}
int main()
{
    vector<vector<int>> table={{INT_MAX,20,30,10,11},
                                {15,INT_MAX,16,4,2},
                                {3,5,INT_MAX,2,4},
                                {19,6,18,INT_MAX,3},
                                {16,4,7,16,INT_MAX}};
    int n=5;
    vector<bool> vis(n,false);
    int count=0;
    vis[0]=true;
    int Cost=caluclateReductionCost(table,-1,-1,n,0);
    cout<<Cost<<endl;
    solve(0,n,vis,table,count,Cost);

return 0;
}