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
		int n, f = 0, b = 0;
		string s;
		cin >> n >> s;
		// 맨앞 0 처리
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') break;
			else {
				f++;
			}
		}
		// 맨뒤 1 처리
		for(int i = n - 1; 0 <= i; i--) {
			if(s[i] == '0') break;
			else {
				b++;
			}
		}
		
		// 출력
		for(int i = 0; i < f; i++) {
			cout << "0";
		}
		if(f + b < n) {
			cout << "0";
		}
		for(int i = 0; i < b; i++) {
			cout << "1";
		}
		cout << "\n";
	}
	
	return 0;
}