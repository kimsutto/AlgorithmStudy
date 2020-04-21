#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0, num = budgets.size();
	long long sum = 0;
	for (int i = 0; i < budgets.size(); i++) {
		sum += budgets[i];
	}
	sort(budgets.begin(), budgets.end());

	if (sum <= M) budgets[budgets.size()];

	for (int i = 0; i < budgets.size(); i++) {
		if (budgets[i] > M / num) {
			return M / num;
		}
		else {
			M -= budgets[i];
			num--;
		}
	}
	return answer;
}