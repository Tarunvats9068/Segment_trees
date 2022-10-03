#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+2;
int a[N],tree[N*4];


void build(int node,int st,int en)
{
    if(st == en)
    {
        tree[node] = a[st];
        return ;
    }
    else
    {
        int mid = (st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node] = tree[node*2]+tree[node*2+1];
        return ;
    }
}

int Query(int node,int st,int en,int l,int r)
{   
      if( r < st  || en < l)
      {
        return 0;
      }
      if(  l <=st && en <= r )
      {
       return tree[node];
      }
      else
      {
         int mid = (st+en)/2;
        int q1 = Query(node*2,st,mid,l,r);
        int q2 = Query(node*2+1,mid+1,en,l,r);
        int ans = q1+q2;
        return ans;
        
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
    build(1,0,n-1);
    int ans = Query(1,0,n-1,1,6);
    cout<<ans<<endl;
    cout<<tree[1]<<endl;
    return 0;
    }
