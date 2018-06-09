/*

Given a weighted undirected graph. Find the sum of weights of edges of a Minimum Spanning Tree.

Input:
Given 2 integers N and M. N represents the number of vertices in the graph. M represents the number of edges between any 2 vertices. 
Then M lines follow, each line has 3 space separated integers  , ,  where  and  represents an edge from a vertex  to a vertex  and  respresents the weight of that edge.

Output:
Print the summation of edges weights in the MST.

SAMPLE INPUT 
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
SAMPLE OUTPUT 
19

*/

#include<bits/stdc++.h>
using namespace std;
void initialize(vector <int> &pre,vector <int> &size,int n){
    int i;
    for(i=0;i<n;i++){
        pre[i]=i;
        size[i]=1;
    }
}
int root(int i,vector <int> &a){
    while(a[i]!=i){
        i=a[a[i]];
    }
    return i;
}
void union1(int x,int y,vector <int> &pre,vector <int> &size,int n){
    int p=root(x,pre);
    int q=root(y,pre);
    if(size[p]<=size[q]){
        pre[p]=q;
        size[q]+=size[p];
    }
    else{
        pre[q]=p;
        size[p]+=size[q];
    }
}
long long kruskal(vector <pair<int,pair<int,int> > > &a,vector <int> &pre,vector <int> &s,int m){
    int i,j;
    int n=a.size();
    long long cost=0;
    for(i=0;i<n;i++){
        pair <int,pair<int,int>> p;
        p=a[i];
        int x=p.second.first;
        int y=p.second.second;
        int w=p.first;
        if(root(x,pre)!=root(y,pre)){
            union1(x,y,pre,s,m);
            cost+=w;
        }
    }
    return cost;
}
int main(){
    int n,m;cin>>n>>m;
    int i,j,k;
    vector <int> pre(n);
    vector <int> size(n);
    initialize(pre,size,n);
    vector <pair<int,pair<int,int>> > edge;
    for(i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(edge.begin(),edge.end());
    long long mincost=kruskal(edge,pre,size,n);
    cout<<mincost<<endl;
}
