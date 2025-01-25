#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long 
#define endl '\n'
 
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order, order_of_key
 
int MinSubarraySum(const vector<int>& arr, int start , int end) {
    int current_sum = 0, min_sum = 0;
    
    for (int i=start ; i<=end ; i++) {
        int x = arr[i] ;
        current_sum += x;
        min_sum = min(min_sum, current_sum);
        if (current_sum > 0) current_sum = 0;
    }
    return abs(min_sum);
}
 
int MaxSubarraySum(const vector<int>& arr, int start , int end) {
    int current_sum = 0, max_sum = 0;
    
    for (int i=start ; i<=end ; i++) {
        int x = arr[i] ;
        current_sum += x;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) current_sum = 0;
    }
    return max_sum;
}
 
void solve(){
    
    int n ;
    cin >> n ;
 
    vector<int> arr(n) ;
    
    set<int> st ;
    st.insert(0) ;
    
    int ind = -1 ;
    
    for(int i=0 ; i<n ; i++){
        cin >> arr[i] ;
        st.insert(arr[i]) ;
        if(arr[i]!=1 && arr[i]!=-1){
            ind = i ;
        }
    }
 
    if(ind == -1){
        int pos = MaxSubarraySum(arr,0,n-1) ;
        int neg = MinSubarraySum(arr,0,n-1) ;
 
        for(int i = neg ; i>=0 ; i--){
            st.insert(-i) ;
        }
        for(int i=1 ; i<=pos ; i++){
            st.insert(i);
        }
        
        cout<<st.size()<<endl;
        for(auto it = st.begin() ; it!=st.end() ; it++){
            cout<<*it<<" ";
        }cout<<endl;
        
        return ;
    }
    
    int pos1 = MaxSubarraySum(arr,0,ind-1) , neg1 = MinSubarraySum(arr,0,ind-1) , pos2 = MaxSubarraySum(arr,ind+1,n-1) , neg2 = MinSubarraySum(arr,ind+1,n-1)
    
    ;
    int currpos = 0, currneg = 0 ;
    
    int pos = max(pos1 , pos2) ;
    int neg = max(neg1 , neg2) ;
    
    for(int i = neg ; i>=0 ; i--){
        st.insert(-i) ;
    }
    for(int i=1 ; i<=pos ; i++){
        st.insert(i) ;
    }
 
    int posl = 0 , posr = 0 , negl = 0 , negr = 0 ;
    int sum = 0 ;
    
    for(int i = ind-1 ; i>=0 ; i--){
        if(arr[i] < 0){
            sum-- ;
        }else{
            sum++ ;
        }
        if(sum < 0){
            negl = min(negl , sum) ;
        }else{
            posl = max(posl , sum) ;
        }
    }
    
    sum = 0 ;
    for(int i = ind+1 ; i<n ; i++){
        if(arr[i] < 0){
            sum-- ;
        }else{
            sum++ ;
        }
        if(sum < 0){
            negr = min(negr , sum) ;
        }else{
            posr = max(posr , sum) ;
        }
    }
    
    pos = posl + posr ;
    neg = negl + negr ;
    
    for(int i=neg ; i<= pos ; i++){
        st.insert(arr[ind] + i) ;
    }
    
    cout<<st.size()<<endl;
    for(auto it = st.begin() ; it!=st.end() ; it++){
        cout<<*it<<" ";
    }cout<<endl;
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t = 1 ;
	cin >> t ;
	
	while(t--){
	    solve();
	}
}