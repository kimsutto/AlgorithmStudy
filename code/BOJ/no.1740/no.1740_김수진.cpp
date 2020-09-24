#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    long long answer = 0;
    long long n;
    cin >> n;

    vector<int> num;
    while (n>0){
        num.push_back(n%2);
        n /=2 ;
    }
    long long add = 1;
    for(int i=0; i<num.size(); i++){
        answer += num[i] * add;
        add *= 3;
    }
    cout << answer;
    return 0;
}
