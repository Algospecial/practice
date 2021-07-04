#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>

#define INF 1e9

using namespace std;

int n;

int graph[21][21];
int visited[21][21];

int sum = 0;

void floyd(){
    //중간
    for (int i = 0; i < n; i++) {
        //시작
        for (int t = 0; t < n; t++) {
            //도착
            for (int j = 0; j < n; j++) {
                //자기 자신일 경우 패스
                if(i == j || j == t || i == t){
                    continue;
                }
                else if(graph[i][j] == graph[i][t] + graph [t][j]){
                    visited[i][j] = false;
                }
                else if(graph[i][j] > graph[i][t] + graph [t][j]){
                    sum = -1;
                    return;
                }
            }
        }
    }
}


int main(){
    
    cin >> n;
    
    for(int i = 0; i < 21; i++){
        for(int j = 0; j< 21; j++){
            visited[i][j] = 1;
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    
    floyd();
    
    if(sum == -1){
        cout << sum;
        return 0;
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]){
                sum += graph[i][j];
            }
        }
    }
    
    cout << sum / 2;
    
}
