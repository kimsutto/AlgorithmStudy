#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int i;
bool comp(string s1, string s2){
	return s1[i]==s2[i] ? s1 < s2 : s1[i]<s2[i];
}

vector<string> solution(vector<string> strings, int n) {

    i = n;
    sort(strings.begin(), strings.end(),comp);
        
    return strings;
}
