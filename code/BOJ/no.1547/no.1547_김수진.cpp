#include<bits/stdc++.h>

using namespace std;

int main(){

	cin.tie(NULL);
  ios::sync_with_stdio(false);

	int m;
  
	cin >> m; 
  
  int n1[m];
  int n2[m];

	for(int j=0; j<m ; j++){
    int a,b;
	  cin >> a >> b;
    n1[j]=a;
    n2[j]=b;
	}	

	int ballspot = 1; 
	for(int i=0; i<m; i++){
		if(n1[i]==ballspot){
			ballspot=n2[i];
		}else if(n2[i]==ballspot){
			ballspot=n1[i];
		}
	}
	
	cout << ballspot;

}