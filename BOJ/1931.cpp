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

bool compare(pii x, pii y) {
	if(x.second == y.second) {
		return x.first < y.first;
	} else {
		return x.second < y.second;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pii> arr;
	for(int i = 0; i < n; i++) {
		int stt, end;
		cin >> stt >> end;
		arr.push_back(mp(stt, end));
	}

	sort(arr.begin(), arr.end(), compare);
	
	int cnt = 0, prev = 0;
	for(int i = 0; i < arr.size(); i++) {
		if(prev <= arr[i].first) {
			cnt++;
			prev = arr[i].second;
		} else {
			continue;
		}
	}

	cout << cnt << "\n";

	return 0;
}