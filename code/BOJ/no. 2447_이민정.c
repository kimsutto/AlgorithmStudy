#include <stdio.h>

void draw(int x, int y) {
	while (y != 0) {
		if (y % 3 == 1 && x % 3 == 1){
			printf(" ");
			return 0;
		}
		x /= 3;
		y /= 3;
	}
	printf("*");
}

int main() {
	int n;
	scanf("%d",&n);
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			draw(x, y);
		}
		printf("\n");
	}
	return 0;
}
