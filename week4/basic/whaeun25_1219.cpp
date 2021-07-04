#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>

#define INF -1e9

using namespace std;

vector<pair<pair<int, int>, int>>edge;

long long dist[110];
int visited[110];

int money[110];

int n, start, finish, m;

int minus_cycle = 0;

bool check(int a){
    
    bool result = 0;
    
    if(a == finish){
        return 1;
    }
    visited[a]  = 1;
    for(int i =0; i < edge.size(); i++){
        if(edge[i].first.first == a && !visited[edge[i].first.second]){
            result += check(edge[i].first.second);
        }
    }
    return result;
    
}

void bellman(){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < edge.size(); j++){
            if(dist[edge[j].first.first] != INF){
                long long sum = dist[edge[j].first.first] - edge[j].second + money[edge[j].first.second];
                
                if(dist[edge[j].first.second] < sum){
                    dist[edge[j].first.second] = sum;
                }
                /*
                if(check(edge[j].first.first)){
                    minus_cycle = 1;
                }
                */
                
            }
        }
    }
}

int main(){
    
    for(int i = 0; i < 110; i++){
        dist[i] = INF;
    }
    
    cin >> n >> start >> finish >> m;
    
    for(int i =0; i<m; i++){
        int a, b, c;
        
        cin >> a >> b >> c;
        
        edge.push_back({{a,b}, c});
        
    }
    
    for(int i =0; i< n; i++){
        int a;
        
        cin >>a;
        
        money[i] = a;
    }
    
    //sort(edge.begin(), edge.end());
    
    dist[start] = money[start];
    //cout << "\nstart: " << dist[start] << "\n";
    
    bellman();
    
    //cout << "\nend: " << dist[finish] << "\n";
    
    if(dist[finish] == INF){
        cout << "gg";
        return 0;
    }
    
    for(int j = 0; j < edge.size(); j++){
        if(dist[edge[j].first.first] != INF){
            long long sum = dist[edge[j].first.first] - edge[j].second + money[edge[j].first.second];
                
            if(dist[edge[j].first.second] < sum){
                if(check(edge[j].first.first)){
                    cout << "Gee";
                    return 0;
                }
            }
        }
    }
    
    cout << dist[finish];
    
}
