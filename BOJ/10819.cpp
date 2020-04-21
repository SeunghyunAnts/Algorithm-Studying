/*
    BOJ 10819 (https://www.acmicpc.net/problem/10819)
*/

#include <bits/stdc++.h>
#define BIGNUM 100000000;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arrsize, maxsum = - BIGNUM;
	int arr[8] = {0};

	// init
	{
		cin >> arrsize;
		for(int i = 0; i < arrsize; i++) {
			cin >> arr[i];
		}
	}
	
	// sorting array
	sort(arr, arr + arrsize);

	do {
		int cursum = 0;

		// calc data
		for(int i = 0; i < arrsize - 1; i++) {
			cursum += abs(arr[i] - arr[i + 1]);
		}

		// updating sum
		if(maxsum < cursum) {
			maxsum = cursum;
		}
	} while(next_permutation(arr, arr + arrsize));

	// output
	{
		cout << maxsum << "\n";
	}

	return 0;
}