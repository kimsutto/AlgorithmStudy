#include <iostream>
#include <algorithm>

using namespace std;

int adj[101][101];
int node, edge;

void floyd(){
     for(int i=1; i<=node; i++){
	  for(int j=1;j<=node; j++){
		  for(int k=1; k<=node; k++){
              if(j!=k){
			          adj[j][k] = min(adj[j][k],adj[j][i]+adj[i][k]);
              }
		  }
	  }
  }
}

int main() {
  cin >> node; 
  cin >> edge;
    
    for (int i = 1; i <= node; i++) {     
        for (int j = 1; j <=node; j++) {
            adj[i][j] = 987654321;
        }
    }

  for(int i=0; i<edge; i++){
	  int a,b,c;
    cin >> a >> b >> c;
    if(adj[a][b]>c){
      adj[a][b] = c;
    }
	   	
  }

 floyd();

for(int i=1; i<node+1; i++){
	for(int j=1; j<node+1; j++){
		if(adj[i][j] == 987654321){
			cout << 0 << " ";
		}else {
            cout << adj[i][j] <<" ";
        }
		
	}
	cout << endl;
}
    return 0;
}
