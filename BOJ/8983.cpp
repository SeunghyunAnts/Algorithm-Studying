/*
    BOJ 8983 (https://www.acmicpc.net/problem/8983)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if(p1.first == p2.first) {
		return p1.second > p2.second;
	} else {
		return p1.first < p2.first;
	}
}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n, cnt;
	ll l, x, y;
	vector< pair<int, int> > xy;
	vector<int> gun;

	// init
	{
		cnt = 0;
		cin >> m >> n >> l;
		for(int i = 0; i < m; i++) {
			cin >> x;
			gun.push_back(x);
		}
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			if(y > l) {
				continue;
			}
			xy.push_back(make_pair(x, y));
		}
		sort(gun.begin(), gun.end());
		sort(xy.begin(), xy.end(), compare);
	}

	for(int i = 0; i < xy.size(); i++) {
		// pair<int,int> cur : 현재 x좌표에서 y좌표가 가장 큰 동물
		// 즉, cur가 거리 안에 있으면, 다른 y좌표를 가진 동물은 잡을 수 있음.
		int curX = xy[i].first, curY = xy[i].second;
		
		int left = 0, right = m - 1, ans = -1;

		// cout << "cur i :" << i << "cur x, y : "<< curX << " " << curY << "\n";

		while(left <= right) {
			int mid = (left + right) / 2;
			int d = curY + abs(curX - gun[mid]);

			// cout << "mid, d :" << mid << " " << d << "\n";

			if(d > l) {
				if(gun[mid] < curX) {
					left = mid + 1;
				} else {
					// gun[mid] >= curX
					right = mid - 1;
				}
			} else {
				// d <= l
				// cout << "okay\n";
				ans = gun[mid];
				break;
			}
		}

		// cout << "ans :" << ans << "\n";

		if(ans == -1) {
			// 도달불가
			continue;
		}

		// 현재 x좌표에서 가장 y좌표가 큰 점이 ans 점에서 도달가능
		int temp = i + 1;
		cnt++;

		while(temp < xy.size() && xy[temp].first == curX) {
			// cout << "i, temp : " << i << " " <<  temp << "\n";
			cnt++;
			temp++;
			i++;
		}
	}

	cout << cnt;

	return 0;
}