#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll>a(100005);
vector<ll>seg(4*100005);


void update(int ind,int low,int high,int pos,int val){
    if(low==high){
        seg[ind] += val;
        return;
    }
    int mid = (low+high)/2;
    if(pos<=mid){
        update(2*ind+1,low,mid,pos,val);
    }
    else{
        update(2*ind+2,mid+1,high,pos,val);
    }
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r){
    if(high<l || low>r)return 0;
    if(low>=l && high<=r)return seg[ind];
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return (left+right);
}


int main(){
    optimize();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<query(0,1,n,a[i]+1,n)<<" ";
        update(0,1,n,a[i],1);
    }
    cout<<endl;

}