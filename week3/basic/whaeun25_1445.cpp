#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

typedef struct{
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        return a.first > b.first;
    }
}cmp;

priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, cmp> pq;

int graph[51][51];
char map[51][51];
int dist[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
int end_x, end_y;

void find(){
    while(!pq.empty()){
        int sum = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        pq.pop();
        
        if(x == end_x && y == end_y){
            cout << dist[x][y] / 5000 << " " << dist[x][y] % 5000;
            return;
        }
        
        for(int i =0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(!(xx < 0 || yy < 0 || xx >= n || yy >= m)){
                int s_sum = sum + graph[xx][yy];
                
                if(dist[xx][yy] > s_sum){
                    dist[xx][yy] = s_sum;
                    pq.push({s_sum, {xx,yy}});
                }
            }
            
        }
        
    }
}

int main(){
    
    int start_x, start_y;
    
    cin >> n >> m;
    
    for(int i =0; i < n; i++){
        for(int j =0; j < m; j++){
            char a;
                
            cin >> a;
            map[i][j] = a;
        }
    }
    
    for(int i =0; i < n; i++){
        for(int j =0; j < m; j++){
            char a = map[i][j];
            dist[i][j] = 1e9;
            
            if(a == 'F'){
                end_x = i;
                end_y = j;
            }
            
            if(a == 'S'){
                start_x = i;
                start_y = j;
                pq.push({0, {i, j}});
                dist[i][j] = 0;
            }
            
            if(a == 'g'){
                graph[i][j] = 5000;
                for(int k = 0; k<4; k++){
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    
                    if(!(xx < 0 || yy < 0 || xx >= n || yy >= m) && map[xx][yy] == '.'){
                        graph[xx][yy] = 1;
                    }
                }
            }
            
            
        }
    }
    
    /*
    cout << "\n\n";
    
    for(int i =0; i<n;i++){
        for(int j = 0; j < m ;j++){
            cout << graph[i][j];
            
        }
        cout << "\n";
    }
    cout << "\n";
    */
    
    find();
    
}
