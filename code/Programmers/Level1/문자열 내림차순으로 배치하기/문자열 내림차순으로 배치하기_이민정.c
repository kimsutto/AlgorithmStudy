#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환

void QuickSort(char *answer, int n){
    int pivot = 0;
    int left = 0;
    int right = n;
    if (n <= 1) return; 
    while (1){
        for (left++; (left<n) && (answer[0] <= answer[left]); left++);
        for (right--; (right>0) && (answer[0]>answer[right]); right--);
        if (left<right){
            SWAP(answer[left], answer[right]);
        } else break;
    }
    SWAP(answer[0], answer[right]);
    QuickSort(answer, right);
    QuickSort(answer + left, n - left);
}

char* solution(const char* s) {
    
    char* answer = (char*)malloc(strlen(s));
    strcpy(answer, s);
    
    QuickSort(answer, strlen(s));
    
    return answer;
}
