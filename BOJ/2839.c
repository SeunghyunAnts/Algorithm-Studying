#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int n3 = 0, n5 = n / 5;

	while(0 <= n5) {
		n3 = (n - 5 * n5) / 3;
		if(3 * n3 + 5 * n5 == n) break;
		n5--;
	}

	if(n5 == -1) {
		printf("-1");
	} else {
		printf("%d", n3 + n5);
	}

	return 0;
}