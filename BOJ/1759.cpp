/*
    BOJ 1759 (https://www.acmicpc.net/problem/1759)
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<char> cons, vowel;	// consonant, vowel
	vector<string> pw;			// save pw strings
	int l, c;					// pw size, num of alphabets
	int csize, vsize;			// cons.size(), vowel.size()

	// init
	{
		cin >> l >> c;

		for(int i = 0; i < c; i++) {
			char temp;
			cin >> temp;
			if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
				// vowel
				vowel.push_back(temp);
			} else {
				// consonant
				cons.push_back(temp);
			}
		}

		csize = cons.size();
		vsize = vowel.size();
	}

	// calc
	for(int i = 1; l - i >= 2; i++) {
		// i : num of vowels, l - i : num of cons

		// out of range
		if(i > vsize || l - i > csize) {
			continue;
		}

		vector<int> ccomb, vcomb;
		

		// init
		{
			for(int j = 0; j < csize; j++) {
				if(j < l - i) ccomb.push_back(1);
				else ccomb.push_back(0);
			}

			for(int j = 0; j < vsize; j++) {
				if(j < i) vcomb.push_back(1);
				else vcomb.push_back(0);
			}

			sort(ccomb.begin(), ccomb.end());
			sort(vcomb.begin(), vcomb.end());
		}

		do {
			do {
				string cur;
				
				for(int j = 0; j < csize; j++) {
					if(ccomb[j] == 1) cur.push_back(cons[j]);
				}

				for(int j = 0; j < vsize; j++) {
					if(vcomb[j] == 1) cur.push_back(vowel[j]);
				}

				sort(cur.begin(), cur.end());
				pw.push_back(cur);

			} while(next_permutation(vcomb.begin(), vcomb.end()));
		} while(next_permutation(ccomb.begin(), ccomb.end()));

	}
	sort(pw.begin(), pw.end());

	// output
	{
		for(int i = 0; i < pw.size(); i++) {
			cout << pw[i] << "\n";
		}
	}

	return 0;
}