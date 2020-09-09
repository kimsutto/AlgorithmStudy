#include <bits/stdc++.h>

using namespace std;

int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
//2016년 1월 1일은 금요일 
string solution(int a, int b) {
    string answer = "";
    int days = 0;
    for(int i=0; i<a-1; i++){
        days += month[i];
    }
    days += b; 
    int aa = days%7 -1;
    if(aa == -1){
        aa=6;
    }
    answer += day[aa];
    
    return answer;
}
