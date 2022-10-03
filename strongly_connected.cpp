#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
   map<T,list<T>> gr;
   map<T,list<T>> grev;
   vector<T> vi;
   public:
   void Addedge(T parent,T child)
   {
       gr[parent].push_back(child);
       grev[child].push_back(parent);
   }
   void Dfs() 
   {
      map<T,bool> visited;
      for(auto x:gr)
      {
        if(!visited[x.first])
        {
            DFS_helper(x.first,visited);
        }
      }

   }
   void DFS_helper(T src,map<T,bool> &visitied)
   {
        stack<T> st;
        st.push(src);
        
        while(!st.empty())
        {
            T node = st.top();
            visitied[src] = true;
          
            for(auto nbr:gr[node])
            {
                if(!visitied[nbr])
                {
                    st.push(nbr);
                    DFS_helper(nbr,visitied);
                }
            }
              vi.push_back(node);
              st.pop();

        }
    }
    void Strongly_check()
    {
        Dfs();
        map<T,bool> visit;
        stack<T> st;
        int count =0;
        for(auto it = vi.rbegin();it<vi.rend();it++)
        {
            if(!visit[*it])
            { 
             count++;
              cout<<"Components "<<count<<" ----> ";
            st.push(*it); 
            while(!st.empty())
            {
                T node = st.top();
               cout<<node<<" ";
                visit[node] = true;
                st.pop();
                for(auto nbr:grev[node])
                {
                    if(!visit[nbr])
                    {
                        st.push(nbr);
                    }
                }
            }           
            }
            cout<<"\n";   
        }
       if(count>=1)
       {
        cout<<(count)<<" components are present in the Graph"<<endl;
       }
    }

};

int main()
{
    Graph<int> gr;
    gr.Addedge(1,2);
    gr.Addedge(2,3);
    gr.Addedge(3,1);
    gr.Addedge(3,4);
    gr.Addedge(4,5);
    gr.Addedge(5,6);
    gr.Addedge(6,4);
    gr.Addedge(6,7);
    gr.Strongly_check();
    return 0;
}