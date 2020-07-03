#include <iostream>

using namespace std;

int n, m;
int arr[10001] ={0,}; 

int main(){
    //필수
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i< n; i++){
        cin >> m; 
        arr[m]++;
    }
    for(int i=0; i< 10001; i++){
        for (int j = 0; j < arr[i]; j++){
            cout << i << "\n"; //endl 쓰면 실패함
        }
    }
}
