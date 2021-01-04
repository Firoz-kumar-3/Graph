https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/description/


#include <bits/stdc++.h> 
using namespace std; 
  
class DSU
{
   int *parent;
   int *rank;


 public:
   
   DSU(int n)
   { 
      
      parent = new int[n+1];
      rank = new int[n+1];

      for(int i=1;i<=n;i++)
      {
        rank[i]=1;
        parent[i]=-1;
      }
   }

   int find(int i)
   {
      if(parent[i]==-1)
       return i;

      parent[i]=find(parent[i]);
      return parent[i];
   }

  void unite(int x,int y)
   {
     int s1 = find(x);
     int s2 = find(y);

     if(s1!=s2)
     {
      // rank based
        if(rank[s1]>rank[s2])
        {
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
        else
        {
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }

     }

    }  

};

class graph{

  vector<vector<int>> v;
  int N;

  public :

   graph(int x)
   {
    this->N=x;
   }

   void addege(int x,int y, int w)
   {
       v.push_back({w,x,y});
   }

   int kruskal_mst()
   {
     
     DSU s(N);

     sort(v.begin(),v.end());

     int ans=0;

     for(auto x : v)
     {
       int w= x[0];
       int k= x[1];
       int l= x[2];

       if(s.find(k)!=s.find(l))
       {
            ans+=w;
            s.unite(k,l);
       }

     }
     return ans;
   } 


};







// Driver code 
int main() 
{ 
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("outp.txt", "w", stdout);
    #endif


     int n,m;
     cin>>n>>m;
     vector<vector<int>> v;
     
     graph g(n);
     while(m--)
     {
        int a,b,c;
        cin>>a>>b>>c;
        g.addege(a,b,c);
     }

     cout<<g.kruskal_mst();

    return 0; 
} 

