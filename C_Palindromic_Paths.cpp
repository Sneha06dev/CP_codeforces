#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int>>b(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int x1=i;
                    int y1=j;
                    b[i][j]=x1+y1;
                    cout<<b[i][j]<<" ";
        }
        cout<<endl;
            }cout<<endl;
         vector<vector<int>>c(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int x1=n-i-1;
                    int y1=m-j-1;
                c[i][j]=x1+y1;
                    cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }cout<<"\n";
    cout<<"\n";
    cout<<"\n";
            }
    
}
