#include <iostream>

using namespace std;

int main(){
  char chess[8][8];
  int cnt = 0;

	for (int i = 0; i < 8; i++)
		cin >> chess[i];

	for (int i = 0; i < 8; i++){
		for (int j = i%2; j < 8; j++){
			if (chess[i][j] == 'F'){
				cnt++;
      }
      j++;
		}
  }
  cout << cnt;

	return 0;	

}