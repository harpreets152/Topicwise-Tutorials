#include<bits/stdc++.h>
#define MAX 100005
#define pi pair<int,int>
using namespace std;
int visited[MAX];
int prims(int x,vector <pi> a[],int n){
    //defining min heap using pq,every iteration will pop top element from heap
    priority_queue <pi,vector <pi>,greater <pi> > pq;
    pq.push(make_pair(0,x));
    int cost=0;
    while(!pq.empty()){
        pi p=pq.top();
        pq.pop();
        //checking for cycle
        if(visited[p.second]==1) continue;
        visited[p.second]=1;
        int node=p.second;
        cost+=p.first;
        for(int i=0;i<a[node].size();i++){
            if(visited[a[node][i].second]==0){
                pq.push(a[node][i]);
            }
        }
    }
    return cost;
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<MAX;i++) visited[i]=0;
    int i,j,k;
    //using adjacency list representation of graph
    vector <pi> adj[MAX];
    for(i=0;i<m;i++){
        int l,r,w;
        cin>>l>>r>>w;
        adj[l].push_back(make_pair(w,r));
        adj[r].push_back(make_pair(w,l));
    }
    int cost=prims(1,adj,n);
    cout<<cost<<endl;
    return 0;
}
