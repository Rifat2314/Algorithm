#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Node{
    ll mn;
    ll cnt;
};

vector<ll>a(100005);
vector<Node>seg(4*100005);

Node merge(Node left,Node right){
    if(left.mn<right.mn)return left;
    else if(right.mn<left.mn)return right;
    else return {left.mn,left.cnt+right.cnt};
}

void build(ll ind,ll low,ll high){
    if(low==high){
        seg[ind] = {a[low],1};
        return;
    }
    ll mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = merge(seg[2*ind+1],seg[2*ind+2]);
}


Node query(ll ind,ll low,ll high,ll l,ll r){
    if(low>=l && high<=r){
        return seg[ind];
    }
    if(high<l || low>r)return {LLONG_MAX,1};
    ll mid = (low+high)/2;
    Node left = query(2*ind+1,low,mid,l,r);
    Node right = query(2*ind+2,mid+1,high,l,r);
    return merge(left,right);
}


void pointUpdate(ll ind,ll low,ll high,ll node,ll val){
    if(low==high){
        seg[ind] = {val,1};
        return;
    }
    else{
        ll mid = (low+high)/2;
        if(node<=mid) pointUpdate(2*ind+1,low,mid,node,val);
        else pointUpdate(2*ind+2,mid+1,high,node,val);

        seg[ind] = merge(seg[2*ind+1] , seg[2*ind+2]);
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
            Node ans = query(0,0,n-1,a,b-1);
            cout<<ans.mn<<" "<<ans.cnt<<endl;
         }
    }
}