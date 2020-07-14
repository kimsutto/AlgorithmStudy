#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    bool* PrimeArray = new bool[n + 1];
    for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;

	for (int i = 2; i*i<= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i*i; j <= n; j += i)
			    PrimeArray[j] = false;
	}

    for(int i=2; i<=n;i++){
        if(PrimeArray[i]==true) answer++;
    }
    
    return answer;
}
