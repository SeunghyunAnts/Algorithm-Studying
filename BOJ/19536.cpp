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

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q, lr = -1, rr = -1;
	string farm;

	cin >> n >> q;
	cin >> farm;

	for(int i = 0; i < farm.size(); i++) {
		if(farm[i] == 'R') rr = i;
		if(lr == -1) lr = rr;
	}

	while(q--) {
		int idx; cin >> idx;
		// do something;
	}

	return 0;
}