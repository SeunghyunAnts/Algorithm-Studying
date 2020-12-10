#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		string s;
		cin >> s;

		for(int i = 0; i < s.size() / 2; i++) {
			if(i == s.size() / 2 - 1) {
				cout << s.substr(i * 2, 2);
			} else if(i == 0) {
				cout << s[0];
			} else {
				cout << s[i * 2]; 
			}
		}
		cout << "\n";
	}

	return 0;
}