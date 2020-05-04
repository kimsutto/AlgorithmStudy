
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int arr[100];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  int answer = 100000;
  int answer2;
  int f, s = 0;
  int sum = arr[f];

  while(!(s==n||f==n)){
    if(sum>=m){
      answer2 = s-f+1;
      answer = min(answer2,answer);
      sum -= arr[f];
      f++;
    }
    else{
      if(s<n){
        sum += arr[++s];
      }
      
    }
  }

  cout << answer;

}