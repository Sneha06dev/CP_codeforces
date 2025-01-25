
#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
 int t;cin>>t;
 while ( t--)
 {
    string s;cin>>s;
    int m;cin>>m;
    int n=s.size();
    string l,r;cin>>l>>r;
    int ind=-1;
    vector<int>v[10];
    for(int i=0;i<n;i++){
        int d=(s[i]-'0');
        v[d].push_back(i);
    }
    for(int i=0;i<10;i++){
        v[i].push_back(n);
    }

    int chek=0;
    for(int i=0;i<m;i++){
        int lo=(l[i]-'0');
        int hi=(r[i]-'0');
        if(chek==1){
            break;
        }
        int newind=0;
        for(int j=lo;j<=hi;j++){
            int id=upper_bound(v[j].begin(),v[j].end(),ind)-v[j].begin();
            if(v[j][id]==n){
                chek=1;
            }
            else
            {
                 newind=max(newind,v[j][id]);
            }
            
        }
        ind=newind;
    }

    if(chek==0){
        cout<<"NO"<<endl;
    }
    else
    {
         cout<<"YES"<<endl;
    }
    

 }
 
    
}