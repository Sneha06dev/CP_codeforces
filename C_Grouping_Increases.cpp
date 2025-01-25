#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&a , int x ){
    return lower_bound(a.begin(), a.end(),x)-a.begin();
}
int main(){
  int k;
    int t;
  k=5;
    cin>>t;
  k=7;
    while(t--){
      int fk;
        int N;
      fk=5;
        cin>>N;
      vector<int> b(5);
        vector<int> A(N);
      b[0]=1;
        for(int i=0;i<N;i++) 
          cin>>A[i];
        int x = A[0];
        sort(A.begin(), A.end(),[](int a , int b ){
          return a<b;
        });
        int z = func(A,x);
         int k=z;
        long long left;
        left=0;
        long long right;
        right=0;
        bool f=true;
        if((k >0)&& f){
            left =  (long long)(A[k-1]) +  (long long)(A[k] );
            left= ((left+1)/2);
            
        }
        else{
            left =1;
        }
        if(k <N-1){
            right = ((long long)A[k] + A[k+1]) /2;
        }
        else{
            right = 1000000;
        }
        left = max(left, (long long)1);
        right = min(right, (long long)1000000);
        long long count;
        if(left > right){
            count=0;
        }
        else{
            count = right - left +1;
        }
        cout<<count<<"\n";
    }
    }
