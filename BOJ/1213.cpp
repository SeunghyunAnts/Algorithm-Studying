#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int alphabetCnt[26] = {0};
	int oddcnt = 0;
	string s;
	cin >> s;
	
	for(int idx = 0; idx < s.size(); idx++) {
		int alpha = (int)(s[idx] - 'A');
		if(alphabetCnt[alpha] % 2 == 0) {
			oddcnt++;
		} else {
			oddcnt--;
		}
		alphabetCnt[alpha]++;
	}

	if(oddcnt > 1) { cout << "I'm Sorry Hansoo"; }
	else {
		vector<char> half;
		int oddidx = -1;
		for(int i = 0; i < 26; i++) {
			if(alphabetCnt[i] == 0) continue;
			else if(alphabetCnt[i] % 2 == 1) {
				oddidx = i;
				alphabetCnt[i]--;
				for(int j = 0; j < alphabetCnt[i] / 2; j++) {
					half.push_back((char)(i + 'A'));
				}
			} else {
				for(int j = 0; j < alphabetCnt[i] / 2; j++) {
					half.push_back((char)(i + 'A'));
				}
			}
		}
		sort(half.begin(), half.end());
		for(int i = 0; i < half.size(); i++) {
			cout << half[i];
		}
		if(0 <= oddidx) cout << (char)(oddidx + 'A');
		sort(half.begin(), half.end(), greater<>());
		for(int i = 0; i < half.size(); i++) {
			cout << half[i];
		}
	}

	return 0;
}