#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int i;
    for (i = 0; (budget-=d[i]) >= 0 && i < d.size(); i++) ;
    return i;
}
