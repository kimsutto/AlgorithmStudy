#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b) {
	return stoi(to_string(a) + to_string(b)) > stoi(to_string(b) + to_string(a));
} // 숫자 a, b를  문자열로 합쳤을때 더 큰 숫자의 순서로 정렬 (a+b or b+a)

string solution(vector<int> numbers) {
	string answer = "";
	
    sort(numbers.begin(), numbers.end(), cmp);  
    // cmp 함수 기준 정렬
	
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	} // 정렬된 순서로 answer에 합침
    
	return answer;
}

// Test Code 
int main() {
	vector<int> v = {30, 35, 3, 5 };
	cout << solution(v);
	return 0;
}