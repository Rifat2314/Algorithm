#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll>a(100005),seg(4*100005);


void build(ll ind,ll low,ll high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    ll mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = (seg[2*ind+1]+seg[2*ind+2]);
}


ll query(ll ind,ll low,ll high,ll l,ll r){
    if(low>=l && high<=r){
        return seg[ind];
    }
    if(high<l || low>r)return 0;
    ll mid = (low+high)/2;
    ll left = query(2*ind+1,low,mid,l,r);
    ll right = query(2*ind+2,mid+1,high,l,r);
    return (left+right);
}


void pointUpdate(ll ind,ll low,ll high,ll node,ll val){
    if(low==high){
        seg[ind] = val;
    }
    else{
        ll mid = (low+high)/2;
        if(node<=mid) pointUpdate(2*ind+1,low,mid,node,val);
        else pointUpdate(2*ind+2,mid+1,high,node,val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
}

int main(){
    optimize();
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,0,n-1);
    while(q--){
         ll type,a,b;
         cin>>type>>a>>b;
         if(type==1){
            pointUpdate(0,0,n-1,a,b);
         }
         else{
            cout<<query(0,0,n-1,a,b-1)<<endl;
         }
    }
}