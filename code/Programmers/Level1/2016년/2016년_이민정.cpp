#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
  
    char month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int date = 0;
    
    for(int i=0;i<a-1;i++){
        date += month[i];
    }
    date += b-1;
    answer = day[date%7];
    
    return answer;
}
