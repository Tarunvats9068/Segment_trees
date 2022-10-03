#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5+2;
int a[N],tree[N*4];



void Segment_tree(int node,int st,int en)
{
    if(st==en)
    {
        tree[node]=a[st];
         return ;
    }
    else{
        int mid = (st+en)/2;
        Segment_tree(node*2,st,mid); 
        Segment_tree(node*2+1,mid+1,en); 
        tree[node] = max(tree[node*2],tree[node*2+1]);
    }
}int Query(int node,int st,int en,int l,int r)
{
    if( r < st || en < l )
    {
        return INT_MIN;
    }
    if(l<=st && en<=r)
    {
        return tree[node];
    }
    else{
        int mid = (st+en)/2;
     int q1 =   Query(node*2,st,mid,l,r);
      int q2 =  Query(node*2+1,mid+1,en,l,r);
        return max(q1,q2);
    }

}

void Update(int node,int st,int en,int idx,int val)
{
    if(st==idx && st==en)
    {
        tree[node]=val;
        a[st]=val;
        return ; 
    }
    else
    {
        int mid = (st+en)/2;
        if( idx <= mid)
        {
            Update(node*2,st,mid,idx,val);
        }
        else
        {
            Update(node*2+1,mid+1,en,idx,val);
        }
        tree[node] = max(tree[node*2],tree[node*2+1]);
    }

}


int32_t main()
{   
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Segment_tree(1,0,n-1);
    int ans = Query(1,0,n-1,3,7);
    cout<<"Maximum Element in the subarray is ----> "<<ans<<"\n";
    Update(1,0,n-1,5,505);
    int ans1 = Query(1,0,n-1,3,7);
    cout<<"Maximum Element in the subarray is ----> "<<ans1<<"\n";
    cout<<"Maximum Element in the subarray is ----> "<<tree[1]<<"\n";
    return 0; 

}