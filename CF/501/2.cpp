#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int strsize;
	int alpha[26] = {0};
	vector<char> stt, dst;
	vector<int> ans;

	scanf("%d", &strsize);

	// clear buffer
	getchar();

	for(int i = 0; i < strsize; i++) {
		char piece;
		scanf("%1c", &piece);
		alpha[piece - 'a']++;
		stt.push_back(piece);
	}

	// clear buffer
	getchar();

	for(int i = 0; i < strsize; i++) {
		char piece;
		scanf("%1c", &piece);
		alpha[piece - 'a']--;
		dst.push_back(piece);
	}

	for(int i = 0; i < 26; i++) {
		if(alpha[i] != 0) {
			printf("-1\n");
			return 0;
		}
	}

	

	for(int i = 0; i < strsize; i++) {
		// output : (i + 1) th
		if(stt[i] == dst[i]) {
			// i th value is same
			continue;
		} else {
			// find same value after i
			int needIdx;
			bool isFind = false;
			for(int j = i + 1; j < strsize; j++) {
				if(stt[j] == dst[i]) {
					needIdx = j;
					isFind = true;
					break;
				}
			}

			if(isFind) {
				stt.erase(stt.begin() + needIdx);
				stt.insert(stt.begin() + i, dst[i]);
				for(int k = needIdx - 1; k >= i; k--) {
					ans.push_back(k + 1);
				}
			} else {
				cout << "-1";
				return -1;
			}
		}
	}

	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}