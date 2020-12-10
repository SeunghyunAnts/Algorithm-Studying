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

	int height, ans = 0;
	cin >> height;
	vector<int> tri[height];

	for(int i = 0; i < height; i++) {
		vector<int> cur;
		for(int j = 0; j <= i; j++) {
			int num;
			cin >> num;
			if(i == 0) {
				cur.push_back(num);
			} else if(j == 0) {
				cur.push_back(num + tri[i - 1].front());
			} else if(j == i) {
				cur.push_back(num + tri[i - 1].back());
			} else {
				cur.push_back(num + max(tri[i - 1][j], tri[i - 1][j - 1]));
			}

			tri[i] = cur;
			if(i == height - 1 && ans < tri[i][j]) {
				ans = tri[i][j];
			}
		}
	}

	cout << ans;

	return 0;
}