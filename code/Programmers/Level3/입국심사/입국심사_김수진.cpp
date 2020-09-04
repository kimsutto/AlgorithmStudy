#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long sum = 0;
    int size = times.size();
	long long min = 1;
	long long max = (long long)times[size-1] * n;
                                              
    long long answer = max;
                                              
	long long mid;
    
	while (min <= max) {
		sum = 0;
		mid = (min + max) / 2;
		for (int i = 0; i < size; i++) 
			sum += mid / times[i];
		if (sum < n)
			min = mid + 1;
		else {
			if (mid <= answer)
				answer = mid;
			max = mid - 1;
		}
	}
	return answer;
}
