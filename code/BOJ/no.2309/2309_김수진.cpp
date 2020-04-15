#include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int> nine;

	for(int i = 0; i<9; i++){
		int n;
		cin >> n;
		nine.push_back(n);
	}

	int sum=0;

	for(auto i : nine){
		sum+=i;
	}

	for(int j=0; j<9; j++){
		for(int k=j+1; k<9; k++){
			if(sum-nine[j]-nine[k]== 100){
				nine.erase(nine.begin()+j);
				nine.erase(nine.begin()+(k-1));
        break;
			}
      }
		}
	

	sort(nine.begin(),nine.end());


	for(int i = 0; i<7; i++){
		cout << nine[i] <<endl;
	} 



	return 0;
}