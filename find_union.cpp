#include<bits/stdc++.h>
using namespace std;



int Find(int node,int arr[])
{
    if(arr[node]<0)
    {
        return node;
    }
    else
    {
        while(arr[node]>0)
        {
            int parent = arr[node];
          return (Find(parent,arr));
        }
        // return 0;
    }
}
void Union(int node1,int node2,int arr[])
{
   if(arr[node1]>arr[node2])
   {
       arr[node2]= arr[node1]+arr[node2];
       arr[node1]= node2;
   }
   else
   {arr[node1]= arr[node1]+arr[node2];
       arr[node2]= node1;
   }
}

int main()
{
    int arr[]= {1,2,3,4,-5,6,-3,6,7};
    // int arr[]= {1,2,3,-4};
    int parent1 = Find(2,arr);
    int parent3 = Find(5,arr);
    cout<<"parent of node is "<<parent1<<"\n";
    cout<<"parent of node is "<<parent3<<"\n";
    Union(4,6,arr);
    int parent2 = Find(5,arr);
    cout<<"parent of node is "<<parent2<<"\n";
    return 0;
    
 }
