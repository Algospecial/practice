#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k;

vector<pair<int, int>> road[1010];

priority_queue<int> dist[1010];

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0,1});
    dist[1].push(0);
    
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i =0; i < road[node].size(); i++){
            int next_node = road[node][i].first;
            int next_cost = road[node][i].second + cost;
            
            if(dist[next_node].size() < k){
                dist[next_node].push(next_cost);
                pq.push({next_cost, next_node});
            }
            else if(dist[next_node].top() > next_cost){
                dist[next_node].pop();
                dist[next_node].push(next_cost);
                pq.push({next_cost, next_node});
            }
        }
    }
}

/*
vector<int>dist[1010];

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0,1});
    dist[1].push_back(0);
    
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i =0; i < road[node].size(); i++){
            int next_node = road[node][i].first;
            int next_cost = road[node][i].second + cost;
            
            dist[next_node].push_back(next_cost);
            pq.push({next_cost, next_node});
            
        }
    }
}
 */

int main(){

    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        
        cin >> a >> b >> c;
        
        road[a].push_back({b, c});
    }
    
    solve();
    
    for(int i =1; i <= n; i++){
        if(dist[i].size() < k){
            cout << "-1\n";
        }
        else{
            //sort(dist[i].begin(), dist[i].end());
            cout << dist[i].top() << "\n";
            //cout << dist[i][k-1] << "\n";
        }
    }
    
}
