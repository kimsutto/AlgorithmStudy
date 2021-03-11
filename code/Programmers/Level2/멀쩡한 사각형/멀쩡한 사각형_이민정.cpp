using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

long long solution(int w,int h) {
    long long answer = 0;
    
    answer = (long long)(h-1)*(w-1)+gcd(w,h)-1;
        
    return answer;
}
