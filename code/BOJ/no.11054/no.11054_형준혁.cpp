#include<iostream>
using namespace std;

#define MAX 1001

int dp[MAX];    // 앞에서부터 찾는 최장수열
int rdp[MAX];    // 뒤에서부터 찾는 최장수열
int arr[MAX];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = n; i >= 1; i--) {
		rdp[i] = 1;
		for (int j = n; j >= i; j--) {
			if (arr[i] > arr[j] && rdp[j] + 1 > rdp[i])
				rdp[i] = rdp[j] + 1;
		}
	}

	int result = 0;
	for (int i = 0; i <= n; i++)
		if (result < dp[i]+rdp[i]-1)  result = dp[i] + rdp[i] - 1;
	cout << result;
	return 0;
}