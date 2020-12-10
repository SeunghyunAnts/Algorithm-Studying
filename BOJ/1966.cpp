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

	int tc;
	cin >> tc;

	while(tc--) {
		int n, m, cnt = 0, ptr = 0;
		queue<pii> q;
		vector<int> val;

		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push(mp(i, num));
			val.push_back(num);
		}

		sort(val.begin(), val.end(), greater<>());
		
		while(true) {
			if(q.front().second < val[ptr]) {
				q.push(q.front());
				q.pop();
			} else {
				
				ptr++;
				cnt++;
				if(q.front().first == m) break;
				else q.pop();
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}