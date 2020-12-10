#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

/*
	세그먼트 트리를 초기화 하는 함수
	arr : 배열, tree : 세그먼트 트리, arr_size : 배열의 길이
*/
void init(int arr[], int tree[], int arr_size) {
	//	리프 노드를 초기화
	for(int i = 1; i <= arr_size; i++) {
		tree[arr_size + i - 1] = arr[i];
	}

	//	나머지 트리를 빌드
	for(int i = arr_size - 1; 0 < i; i--) {
		tree[i] = max(tree[2 * i], tree[2 * i + 1]);
	}

	return;
}

int seg_max(int tree[], int le, int ri, int arr_size) {
	int ans = 0;

	// 리프 노드로 le, ri 이동
	le += arr_size - 1;
	ri += arr_size - 1;

	// le, ri의 값이 홀수
	do {
		if(le % 2 == 1) {
			ans = max(ans, tree[le++]);
		}
		if(ri % 2 == 1) ans = max(ans, tree[--ri]);
		le /= 2;
		ri /= 2;
	} while(le < ri);

	return ans;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//	세로 길이 n, 가로 길이 m, 쿼리의 개수 query
	int n, m, query;

	/*
		목장 각각의 가로줄, 세로줄에서의 양의 길이
		lr[세로길이 n][가로길이 m]
		ud[가로길이 m][세로길이 n]
	*/
	int lr[500 + 1][500 + 1] = {0}, ud[500 + 1][500 + 1] = {0};
	
	/* 
		목장 각각의 가로줄/세로줄에서 최댓값을 저장하는 세그먼트 트리
		lrSegTree[세로 길이 n][트리의 길이]
		udSegTree[가로 길이 m][트리의 길이]
	*/
	int lrSegTree[500 + 1][1024 + 1] = {0}, udSegTree[500 + 1][1024 + 1] = {0};

	//	사이즈 입력
	cin >> n >> m;

	//	배열 입력 (목장의 크기)
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int sheep_size; cin >> sheep_size;
			lr[i][j] = ud[j][i] = sheep_size;
		}
	}

	//	각 가로줄에 대한 최댓값 세그먼트 트리 생성 (n개)
	for(int i = 1; i <= n; i++) {
		init(lr[i], lrSegTree[i], m);
	}

	//	각 세로줄에 대한 최댓값 세그먼트 트리 생성 (m개)
	for(int i = 1; i <= m; i++) {
		init(ud[i], udSegTree[i], n);
	}

	//	쿼리의 개수 입력
	cin >> query;

	while(query--) {
		//	CCTV의 좌표 (y, x), CCTV의 범위 (r, c), 촬영 날짜 k, 이동방향 d, 출력값 ans
		int y, x, r, c, k, d, ans = 0;

		/*
			각 가로줄/세로줄에서 범위 내 최대값을 저장한 배열
			cur[i] : i번째 가로줄/세로줄에서 범위 내 최대값
		*/
		int cur[500 + 1] = {0};

		/*
			슬라이딩 윈도우에서 사용할 덱
			deque <양의 크기, 해당 인덱스>
		*/
		deque<pii> dq;

		// 입력
		cin >> y >> x >> r >> c >> k >> d;

		if(d < 3) {
			/*
				상하로 움직일 경우 i번째 세로줄에서 범위 내 가로줄에서의 최대값을 저장
				각각의 가로줄에서의 범위 : [x, x + c)
			*/
			for(int i = 1; i <= n; i++) {
				cur[i] = seg_max(lrSegTree[i], x, x + c, m);
			}
		} else {
			/*
				좌우로 움직일 경우 i번째 가로줄에서 범위 내 세로줄에서의 최대값을 저장
				각각의 세로줄에서의 범위 : [y, y + r)
			*/
			for(int i = 1; i <= m; i++) {
				cur[i] = seg_max(udSegTree[i], y, y + r, n);
			}
		}


		// k회만큼 촬영
		for(int i = 0; i < k; i++) {
			if(i == 0) {	// 첫번째 반복에서는 빈 덱을 채움
				if(d == 1) {
					int limit = y + r;
					for( ; y < limit; y++) {
						while(!dq.empty() && r <= abs(dq.front().second - y)) {
							dq.pop_front();
						}
						while(!dq.empty() && dq.back().first <= cur[y]) {
							dq.pop_back();
						}
						dq.push_back(mp(cur[y], y));
					}
					y--;
				} else if(d == 2) {
					int temp, limit = y + r;
					for(temp = limit - 1; y <= temp; temp--) {
						while(!dq.empty() && r <= abs(dq.front().second - temp)) {
							dq.pop_front();
						}
						while(!dq.empty() && dq.back().first <= cur[temp]) {
							dq.pop_back();
						}
						dq.push_back(mp(cur[temp], temp));
					}
					y = temp + 1;
				} else if(d == 3) {
					int limit = x + c;
					for( ; x < limit; x++) {
						while(!dq.empty() && c <= abs(dq.front().second - x)) {
							dq.pop_front();
						}
						while(!dq.empty() && dq.back().first <= cur[x]) {
							dq.pop_back();
						}
						dq.push_back(mp(cur[x], x));
					}
					x--;
				} else if(d == 4) {
					int temp, limit = x + c;
					for(temp = limit - 1; x <= temp; temp--) {
						while(!dq.empty() && c <= abs(dq.front().second - temp)) {
							dq.pop_front();
						}
						while(!dq.empty() && dq.back().first <= cur[temp]) {
							dq.pop_back();
						}
						dq.push_back(mp(cur[temp], temp));
					}
					x = temp + 1;
				}
			} else {	// 나머지 시행에서는 새로 들어오는 입력값을 확인
				if(d < 3) {
					while(!dq.empty() && r <= abs(dq.front().second - y)) {
						dq.pop_front();
					}
					while(!dq.empty() && dq.back().first <= cur[y]) {
						dq.pop_back();
					}
					dq.push_back(mp(cur[y], y));
				} else {
					while(!dq.empty() && c <= abs(dq.front().second - x)) {
						dq.pop_front();
					}
					while(!dq.empty() && dq.back().first <= cur[x]) {
						dq.pop_back();
					}
					dq.push_back(mp(cur[x], x));
				}
			}
			ans = ans ^ dq.front().first;

			if(d == 1) y++;
			else if(d == 2) y--;
			else if(d == 3) x++;
			else x--;
		}

		cout << ans << "\n";
	}

	return 0;
}