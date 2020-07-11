#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    if((int)sqrt(n)==sqrt(n))
        answer = (sqrt(n)+1)*(sqrt(n)+1);
    return answer;
}
