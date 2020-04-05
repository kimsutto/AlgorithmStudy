#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool winTable[101][101]{ false, };
bool loseTable[101][101]{ false, };

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	for (int i = 0; i < results.size(); i++) {
		winTable[results[i][0]][results[i][1]] = true;
        // 이긴 정보를 저장하는 table
		loseTable[results[i][1]][results[i][0]] = true;
        // 진 정보를 저장하는 table
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (winTable[j][i] && winTable[i][k]) {
					winTable[j][k] = true;
				} // j가 i를 이기고 i가 k를 이기면 j가 k를 이긴다.
				if (loseTable[j][i] && loseTable[i][k]) {
					loseTable[j][k] = true;
				} // j가 i에게 지고 i가 k에게 지면 j가 k에게 진다.
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (winTable[i][j] || loseTable[i][j]) cnt++;
		}
		if (cnt == n - 1) answer++;
	} // 결과가 자신을 제외하고 전부 존재하면 answer++


	/* table 출력 코드

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << winTable[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << loseTable[i][j] << ' ';
		}
		cout << endl;
	} 
	*/
	return answer;
}

// testCase 
int main() {
	int n = 8;
	vector<vector<int>> v = { {1,2},{2,3},{3,4},{5,6},{3,7},{3,6},{7,8} };
	cout << solution(n, v);
	return 0;
}