/*

refer the page in the link below for problem statement.
link->https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

*/



#include<bits/stdc++.h>
#define pi pair<int,int>
#define MAX 1000000000
using namespace std;
void initialize(int dist[],int n){
    for(int i=0;i<=n;i++) dist[i]=INT_MAX;
    return ;
}
void shortest_path(int x,vector <pi> adj[],int n){
    priority_queue <pi,vector <pi>,greater<pi> > pq;
    int dist[n+1];
    int i;
    initialize(dist,n);
    dist[x]=0;
    pq.push(make_pair(0,x));
    while(!pq.empty()){
        pi node=pq.top();
        pq.pop();
        int weight,vertex;
        weight=node.first;
        vertex=node.second;
        for(i=0;i<adj[vertex].size();i++){
            if(dist[adj[vertex][i].second]>dist[vertex]+adj[vertex][i].first){
                dist[adj[vertex][i].second]=dist[vertex]+adj[vertex][i].first;
                pq.push(adj[vertex][i]);
            }
        }
    }
    for(i=2;i<=n;i++){
        if(dist[i]==INT_MAX) cout<<MAX<<" ";
        else cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a,b,w;
    vector <pair <int,int> > adj[n+1];
    int i;
    for(i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(w,b));
        //adj[b].push_back(make_pair(w,a));
    }
    shortest_path(1,adj,n);
    return 0;
}
