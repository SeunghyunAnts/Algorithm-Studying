#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n;

// 범위 체크
bool inRange(int y, int x) {
	return (0 <= y && y < n && 0 <= x && x < n);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int fishsize = 2, move = 0, eatcnt = 0;
	int map[20 + 1][20 + 1] = {0};
	int check[20 + 1][20 + 1] = {0};

	// <움직인 횟수, <좌표>>를 입력받는 큐
	queue< pair<int ,pair<int, int>> > q;

	

	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 9) {
				q.push(make_pair(0, make_pair(i, j)));
				map[i][j] = 0;
				check[i][j] = 1;
			}
		}
	}

	while(true) {
		// 출발지에서 가장 가까운 거리에 있는 물고기의 거리
		int d = 400 + 1;
		// 거리가 d인 좌표를 저장하는 벡터
		vector< pair<int, int> > near;

		while(!q.empty()) {
			int curd = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();

			for(int i = 0; i < 4; i++) {
				int yy = y + diry[i];
				int xx = x + dirx[i];

				if(inRange(yy, xx) && !check[yy][xx]) {
					if(fishsize < map[yy][xx]) {
						check[yy][xx] = 1;
					} else if(fishsize == map[yy][xx] || map[yy][xx] == 0) {
						check[yy][xx] = 1;
						q.push(make_pair(curd + 1, make_pair(yy, xx)));
					} else {
						if(curd < d) {
							near.clear();
							near.push_back(make_pair(yy, xx));
							d = curd + 1;
						} else if(curd == d) {
							near.push_back(make_pair(yy, xx));
						}
					}
				}
			}
		}

		if(near.empty()) break;
		else {
			sort(near.begin(), near.end());
			int y = near[0].first;
			int x = near[0].second;
			memset(check, 0, sizeof(check));
			q.push(make_pair(0, make_pair(y, x)));
			map[y][x] = 0;
			check[y][x] = 1;
			move += d;
			d = 401;
			eatcnt++;
			if(fishsize <= eatcnt) {
				fishsize++;
				eatcnt = 0;
			}
		}
	}

	cout << move;
	

	return 0;
}