#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

queue< pair<int,int> > ans;

int hanoi(int h, int stt, int mid, int dst) {
	int cnt = 0;
	if(1 < h) {
		cnt += hanoi(h - 1, stt, dst, mid);
		cnt += hanoi(1, stt, mid, dst);
		cnt += hanoi(h - 1, mid, stt, dst);
	} else {
		ans.push(make_pair(stt ,dst));
		cnt += 1;
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << hanoi(n, 1, 2, 3) << "\n";
	while(!ans.empty()) {
		cout << ans.front().first << " " << ans.front().second << "\n";
		ans.pop();
	}

	return 0;
}