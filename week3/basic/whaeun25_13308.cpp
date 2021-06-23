#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

vector<int>price;
vector<pair<int, int>> road[2510];

int visited[2510][2510];

typedef struct{
    bool operator()(pair<pair<int, int>, long> a, pair<pair<int, int>, long> b){
        return a.second > b.second;
    }
}cmp;

priority_queue<pair<pair<int, int>, long>, vector<pair<pair<int, int>, long>>, cmp> pq;

int n, m;

long long dijkstra(){
    
    pq.push({{1,price[1]}, 0});
    
    long long dist = 0;
    
    while(!pq.empty()){
        int node = pq.top().first.first;
        int cost = pq.top().first.second;
        dist = pq.top().second;
        
        pq.pop();
        
        if(visited[node][cost]){
            continue;
        }
        
        if(node == n){
            return dist;
        }
        
        visited[node][cost] = 1;
        
        for(int i =0; i < road[node].size(); i++){
            long long next_dist = cost * road[node][i].second + dist;
            
            pq.push({{road[node][i].first, min(cost, price[road[node][i].first])},next_dist});
        }
    }
    
    return dist;
}

int main(){
    
    cin >> n >> m;
    
    price.push_back(0);
    
    for(int i =0; i<n; i++){
        int a;
        
        cin >> a;
        
        price.push_back(a);
    }
    
    for(int i = 0; i < m; i++){
        int a, b, length;
        
        cin >> a >> b >> length;
        
        road[a].push_back({b, length});
        road[b].push_back({a, length});
    }
    
    cout << dijkstra();
}
