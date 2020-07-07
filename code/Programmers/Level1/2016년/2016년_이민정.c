#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {

    char *day[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    char month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int date = 0;
    
    for(int i=0;i<a-1;i++){
        date += month[i];
    }
    date += b-1;
    char* answer = (char*)malloc(sizeof(day));
    answer = day[date%7];
    
    return answer;
    free(answer);
}
