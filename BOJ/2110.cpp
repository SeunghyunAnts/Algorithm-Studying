#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 집의 개수, 공유기의 개수, 최대 거리(출력값)
	int n, c, ans = 0;
	cin >> n >> c;
	// 집의 좌표
	int dir[n] = {0};
	for(int i = 0; i < n; i++) cin >> dir[i];
	// 좌표 정렬
	sort(dir, dir + n);

	// 최소 거리를 이분탐색으로 확인
	int le = 1, ri = dir[n - 1] - dir[0];
	while(le <= ri) {
		// 이번 시행에서의 최소 거리
		int mid = (le + ri) / 2;
		// mid를 기준으로 했을 때, 설치 한 공유기의 개수
		// 가장 최근에 방문한 집의 좌표
		int cnt = 0, prev;

		for(int i = 0; i < n; i++) {
			if(i == 0) { prev = dir[0]; cnt++; continue; }
			if(mid <= dir[i] - prev) {
				prev = dir[i];
				cnt++;
			}
		}

		if(cnt < c) {
			// 설치한 공유기가 부족한 경우
			ri = mid - 1;
		} else {
			// c개 이상 설치할 수 있는 경우
			if(ans < mid) ans = mid;
			le = mid + 1;
		}
	}

	cout << ans;
	
	return 0;
}