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

// 범위 내에 있는지 확인
bool inRange(int y, int x) {
	return (0 <= y && y < n && 0 <= x && x < n);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int maxcandy = 0;
	vector<string> arr;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		arr.push_back(s);
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char cur = arr[i][j];

			for(int k = 0; k < 4; k++) {
				int yy = i + diry[k];
				int xx = j + dirx[k];

				if(inRange(yy, xx) && cur != arr[yy][xx]) {
					vector<string> cpy = arr;
					int curmaxcandy = 0, curcandy = 0;
					char prev;
					cpy[i][j] = cpy[yy][xx];
					cpy[yy][xx] = arr[i][j];
					
					// 가로로 확인
					for(int ro = 0; ro < n; ro++) {
						string c = cpy[ro];
						for(int idx = 0; idx < n; idx++) {
							if(idx == 0) {
								prev = c[idx];
								curcandy = 1;
							} else if(prev == c[idx]) {
								curcandy++;
								prev = c[idx];
							} else {
								curmaxcandy = max(curmaxcandy, curcandy);
								curcandy = 1;
								prev = c[idx];
							}
						}
						if(0 < curcandy) curmaxcandy = max(curmaxcandy, curcandy);
					}

					// 세로로 확인
					for(int co = 0; co < n; co++) {
						for(int idx = 0; idx < n; idx++) {
							if(idx == 0) {
								prev = cpy[idx][co];
								curcandy = 1;
							} else if(prev == cpy[idx][co]) {
								curcandy++;
								prev = cpy[idx][co];
							} else {
								curmaxcandy = max(curmaxcandy, curcandy);
								curcandy = 1;
								prev = cpy[idx][co];
							}
						}
						if(0 < curcandy) curmaxcandy = max(curmaxcandy, curcandy);
					}

					// 최신화
					maxcandy = max(maxcandy, curmaxcandy);
				}
			}
		}
	}

	cout << maxcandy;

	return 0;
}