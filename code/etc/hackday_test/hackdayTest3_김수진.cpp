#include <string>
#include <vector>
#include<iostream>

using namespace std;

int cp(int nn, int kk) {
	int cnt = 1;

  if (nn == 1) {
      return 1;
  }

	for(int i = 0; i< nn; i++) {
		cnt *= (kk-nn) -i;
	}

	return cnt + 1; 
}

int solution(int n, int m, int k) {
    int answer = -1;
    int aa = 0;
    
    if(n>m){
        return 0;
    }
    if((n*k)<m){
        return 0;
    }
   
    aa = cp(n/2 + n%2, k) * cp(n/2, k);
    
    aa = aa*2;
    answer = aa % 1000000007;
    return answer;
}



int main(){
	cout << solution(3,8,4);  //6
	cout << solution(10,6,5); //0
	cout << solution(2,10,20);  //0
	cout << solution(50,150,4); //780361386
	return 0;
}