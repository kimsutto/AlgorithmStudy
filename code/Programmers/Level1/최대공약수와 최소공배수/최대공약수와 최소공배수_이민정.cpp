#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    
    answer[0] = gcd(n,m);
    answer[1] = n*m/gcd(n,m);
    
    return answer;
}
