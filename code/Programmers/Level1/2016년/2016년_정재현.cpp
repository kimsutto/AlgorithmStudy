#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(int a, int b) {
	const char* day[] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
	int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int total = 0;

	for (int i = 0; i < a - 1; i++)
	{
		total += month[i];
	}
	total += b - 1;

	return day[total % 7];
}