#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n, cnt = 0;
int checkx[15 + 1];

// 배열 범위을 벗어나는지 체크
bool inRange(int y, int x) {
	return (0 < y && y <= n && 0 < x && x <= n);
}

// 백트래킹
int solve(int y, int x) {
	if(y == 0) {
		memset(checkx, 0, sizeof(checkx));
	} else if(y == n) {
		return 1;
	}

	checkx[x] = y;
	int cur = 0;

	// 다음줄의 경우의수 탐색
	for(int i = 1; i <= n; i++) {
		int xx = i, yy = y + 1;
		if(checkx[xx] != 0) {
			// 해당 x좌표가 다른 퀸의 공격 위치이면 불가능
			continue;
		} else {
			// 또는 대각선 방향에 퀸이 있다면 불가능
			bool cancontinue = true;
			for(int j = 1; j <= n; j++) {
				int qy = checkx[j];
				if(0 < qy && abs(qy - yy) == abs(j - xx)) {
					cancontinue = false;
					break;
				}
			}
			if(cancontinue) cur += solve(yy, xx);
		}
	}

	checkx[x] = 0;
	return cur;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		// 첫번째 줄의 위치를 정해서 각각 백트래킹 실행
		cnt += solve(1, i);
	}
	cout << cnt;

	return 0;
}