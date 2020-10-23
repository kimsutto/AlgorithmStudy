#include <bits/stdc++.h>

using namespace std;

int chk[1000001];

bool isPrimeNumber(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v; 
    set<int> s;
    for(int i=0; i<numbers.size(); i++){
        v.push_back((numbers[i]));
    }
    sort(v.begin(),v.end());
    do{
        for (int i = 0; i <= v.size(); i++) {
            string str = "";
            for (int j = 0; j < i; j++) {
                str += v[j];
                s.insert(stoi(str));
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    for(auto i : s){
        if(isPrimeNumber(i))
            answer++;
    }
    return answer;
}
