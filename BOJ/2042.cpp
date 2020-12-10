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

int n, m, k;
int segT_height, segT_size;
vector<ll> vec, segT;

// 세그먼트 트리를 만드는 함수
ll init_segT(int idx, int le, int ri) {
	if(le == ri) {
		return segT[idx] = vec[le];
	}

	int mid = (le + ri) / 2;
	return segT[idx] = init_segT(2 * idx, le, mid) + init_segT(2 * idx + 1, mid + 1, ri);
}

// 변화된 값이 있을 때, 세그먼트 트리를 업데이트 하는 함수
void update(int idx, int le, int ri, int c_idx, int dif) {
	if(ri < c_idx || c_idx < le) return;

	segT[idx] += dif;
	if(le == ri) return;

	int mid = (le + ri) / 2;
	update(2 * idx, le, mid, c_idx, dif);
	update(2 * idx + 1, mid + 1, ri, c_idx, dif);
}

// 세그먼트 트리에서 구간(stt ~ end)합을 리턴하는 함수
ll seg_sum(int idx, int le, int ri, int stt, int end) {
	if(end < le || ri < stt) {
		// 구간이 현재 범위와 겹치지 않는 경우
		return 0;
	} else if(stt <= le && ri <= end) {
		// 구간이 현재 범위를 포함하는 경우
		return segT[idx];
	} else {
		// 그 외의 경우
		int mid = (le + ri) / 2;
		return seg_sum(2 * idx, le, mid, stt, end) + seg_sum(2 * idx + 1, mid + 1, ri, stt ,end);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 입력
	cin >> n >> m >> k;
	vec.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> vec[i];
	}

	// 세그먼트 트리 크기 정하기
	segT_height = (int)ceil(log2(n));
	segT_size = (1 << (segT_height + 1));
	segT.resize(segT_size);

	// 세그먼트 트리 만들기
	init_segT(1, 1, n);

	for(int i = 0; i < m + k; i++) {
		int order, b;
		ll c;
		cin >> order >> b >> c;
		if(order == 1) {
			// b번째수를 c로 바꿈
			ll dif = c - vec[b];
			update(1, 1, n, b, dif);
			vec[b] = c;
		} else {
			cout << seg_sum(1, 1, n, b, c) << "\n";
		}
	}

	return 0;
}