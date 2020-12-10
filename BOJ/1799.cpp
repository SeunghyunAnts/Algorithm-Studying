#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n, b, ans;
int check[15 + 1][15 + 1];

// 조건 내의 위치인지 검사
bool inRange(int y, int x) {
	return (0 < y && y <= n && 0 < x && x <= n);
}

int solve(int y, int x, int cnt) {
	// 범위를 벗어난다면 탐색 종료
	if(!inRange(y, x)) return cnt;

	int ret = 0;
	bool isE = ((x + y) % 2 == 0);

	// 이동할 수 있는 다음 칸을 탐색
	int xx = x + 2;
	int yy = y;
	
	// 다음 칸의 좌표 설정
	if(isE && (n < xx)) {
		if(yy % 2 == 0) {
			yy++; xx = 1;
		} else {
			yy++; xx = 2;
		}
	} else if(!isE && (n < xx)) {
		if(yy % 2 == 0) {
			yy++; xx = 2;
		} else {
			yy++; xx = 1;
		}
	}

	if(check[y][x] == 0) {
		// 현재 칸에 놓을 수 있는지 확인
		bool one = false;
		bool canPlace = true;
		for(int i = 1; i < y; i++) {
			one = !one;
			if(isE) {
				for(int j = (one ? 1 : 2); j <= n; j += 2) {
					if(check[i][j] == 1 && abs(i - y) == abs(j - x)) {
						canPlace = false;
						break;
					}
				}
			} else {
				for(int j = (one ? 2 : 1); j <= n; j += 2) {
					if(check[i][j] == 1 && abs(i - y) == abs(j - x)) {
						canPlace = false;
						break;
					}
				}
			}
		}

		// 현재 칸에 놓을 수 있으면, 놓은 후 다음 칸 탐색
		if(canPlace) {
			check[y][x] = 1;
			ret = max(ret, solve(yy, xx, cnt + 1));
			check[y][x] = 0;
		}
	}

	// 현재 칸에 놓지 않은 경우, 다음 칸 탐색
	ret = max(ret, solve(yy, xx, cnt));

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> b;
			if(b == 0) {
				check[i][j] = 100;
			}
		}
	}

	ans = solve(1, 1, 0);
	ans += solve(1, 2, 0);
	cout << ans;

	return 0;
}