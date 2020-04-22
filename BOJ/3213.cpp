/*
    BOJ 3213 (https://www.acmicpc.net/problem/3213)
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string pizza;
	int pizzaSize[3] = {0};

	// init
	{
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> pizza;
			if(pizza[0] == '3') {
				pizzaSize[2]++;
			} else {
				if(pizza[2] == '2') {
					pizzaSize[1]++;
				} else {
					pizzaSize[0]++;
				}
			}
		}
	}

	// calc
	int order = 0;
	order += pizzaSize[1] / 2;
	pizzaSize[1] = pizzaSize[1] % 2;
	while(pizzaSize[0] > 0 && pizzaSize[2] > 0) {
		pizzaSize[0]--;
		pizzaSize[2]--;
		order++;
	}
	while(pizzaSize[2] > 0) {
		pizzaSize[2]--;
		order++;
	}
	if(pizzaSize[1] > 0) {
		if(pizzaSize[0] > 0) {
			pizzaSize[0]--;
			if(pizzaSize[0] > 0) pizzaSize[0]--;
			pizzaSize[1]--;
			order++;
		} else {
			pizzaSize[1]--;
			order++;
		}
	}
	if(pizzaSize[0] > 0) {
		order += (pizzaSize[0] + 3) / 4;
	}

	// output
	{
		cout << order;
	}
	
	return 0;
}