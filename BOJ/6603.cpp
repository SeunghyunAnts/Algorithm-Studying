/*
    BOJ 6603 (https://www.acmicpc.net/problem/6603)
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	// 빠른 입출력
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k = 1;
	
	do {
		vector<int> n_atoms;
		vector<bool> combination;
		int atom;
		
		cin >> k;
		if(k == 0) break;
		
		for(int i = 0; i < k; i++) {
			cin >> atom;
			n_atoms.push_back(atom);
			if(i < 6) combination.push_back(true);
			else combination.push_back(false);
		}
		do {
			for(int i = 0; i < k; i++) {
				if(combination[i]) cout << n_atoms[i] << " ";
			}
			cout << "\n";
		} while(prev_permutation(combination.begin(), combination.end()));
		cout << "\n";
	} while(k > 0);
	
	return 0;
}