#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while(tc--) {
		ll n, k, target, x = 0, cnt = 0, next;
		map<ll, int> m;
		map<ll, int>::iterator it;
		priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
		cin >> n >> k;
		target = k;
		
		for(int i = 0; i < n; i++) {
			ll num; cin >> num;
			if(num % k != 0) {
				// n보다 큰 k의 배수 중 최소값
				next = (num / k + 1) * k - num;
				it = m.find(next);
				if(m.find(next) != m.end()) {
					(it->second)++;
				} else {
					m.insert(make_pair(next, 1));
				}
			}
		}

		for(it = m.begin(); it != m.end(); it++) {
			pq.push(make_pair(it->first, it->second));
		}

		while(!pq.empty()) {
			next = pq.top().first;
			int rest = pq.top().second;
			pq.pop();

			if(x <= next) {
				cnt += (next - x) + 1;
				x = next + 1;
				if(1 < rest) {
					pq.push(make_pair(next + k, rest - 1));
				}
			} else {
				// next < x
				pq.push(make_pair(next + k, rest - 1));
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}