#include<vector>
#include<queue>
#include<iostream>

#define INF 987654321

using namespace std;



int V;
int E;
int start;
int dist[20001];
vector<pair<int,int>> node[20001];

void solve(){
    priority_queue< pair<int,int> > pq;
    pq.push({ 0, start});
 
    while (!pq.empty()){
        int cost = -pq.top().first;
        int node_num = pq.top().second;
        pq.pop(); 
 
        for(int i=0; i<node[node_num].size(); i++){
            int nn = node[node_num][i].first;
            int cc = node[node_num][i].second;

            if(dist[nn]>cost+cc){
                dist[nn] = cost+cc;
                pq.push({-dist[nn],nn});
            }
        }
 
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >> V >> E;
    cin >> start;
    for(int i=0; i<E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        node[a].push_back({b,c});
    }

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
 
    solve();

    for(int i=1; i<=V; i++){
        if(dist[i]!=INF){
            cout << dist[i] << '\n';
        }else{
            cout << "INF" << '\n';
        }
        
    }
}
