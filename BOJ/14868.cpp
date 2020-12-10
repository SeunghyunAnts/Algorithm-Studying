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

int n, k, ucnt = 0, year = 0;
int parent[100000 + 1] = {0};
int world[2000 + 1][2000 + 1] = {0};
bool check[2000 + 1][2000 + 1] = {0};

void print_map(void) {
	cout << "pm\n";
	for(int i = 1; i <= k; i++) cout << parent[i] << " ";
	cout << "\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << world[i][j] << " ";
		}
		cout << "\n";
	}
}

bool inRange(int y, int x) {
	return 1 <= y && y <= n && 1 <= x && x <= n;
}

int find_parent(int node) {
	if(parent[node] == node) {
		return node;
	} else {
		return parent[node] = find_parent(parent[node]);
	}
}

void union_node(int n1, int n2) {
	n1 = find_parent(n1);
	n2 = find_parent(n2);

	if(n1 == n2) {
		return;
	} else if(n1 < n2) {
		parent[n2] = n1;
	} else {
		parent[n1] = n2;
	}
	ucnt++;
}

int main(void) {
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	queue<pii> q1, q2;
	cin >> n >> k;

	for(int i = 1; i < 100000 + 1; i++) {
		parent[i] = i;
	}

	for(int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;

		world[y][x] = i;
		q1.push(mp(x, y));

		// for(int j = 0; j < 4; j++) {
		// 	int xx = x + dirx[j];
		// 	int yy = y + diry[j];

		// 	if(inRange(yy, xx) && !check[yy][xx] && world[yy][xx] != 0) {
		// 		union_node(world[y][x], world[yy][xx]);
		// 	}
		// }
	}

	while(true) {
		// cout << "year, cnt : " << year << " " << ucnt << "\n";
		// print_map();
		// cout << "---------------\n";
		if(k - 1 == ucnt) break;

		int q1size = q1.size();
		// cout << "q size : " << q1.size() << " " << q2.size() << "\n";

		for(int i = 0; i < q1size; i++) {
			int x = q1.front().first;
			int y = q1.front().second;

			if(k - 1 == ucnt) break;

			q2.push(mp(x, y));
			q1.pop();

			for(int j = 0; j < 4; j++) {
				int xx = x + dirx[j];
				int yy = y + diry[j];

				if(inRange(yy, xx) && world[yy][xx] != 0) {
					union_node(world[y][x], world[yy][xx]);
					// cout << "union merge : " << y << x << " " << yy << xx << " " << ucnt << "\n";
				}
			}

			// cout << x << " " << y << "\n";
			// print_map();
		}

		if(k - 1 == ucnt) break;
		year++;

		// cout << "spread!\n";
		// cout << "q size : " << q1.size() << " " << q2.size() << "\n";
		int q2size = q2.size();

		for(int i = 0; i < q2size; i++) {
			int x = q2.front().first;
			int y = q2.front().second;

			

			q2.pop();
			check[y][x] = true;

			for(int j = 0; j < 4; j++) {
				int xx = x + dirx[j];
				int yy = y + diry[j];

				if(inRange(yy, xx) && !check[yy][xx]) {
					if(world[yy][xx] == 0) {
						world[yy][xx] = world[y][x];
						q1.push(mp(xx, yy));
					}
				}
			}
			// cout << x << " " << y << "\n";
			// print_map();
		}
	}

	cout << year << "\n";

	return 0;
}