#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n, m;	// 배열의 크기
vector<string> board(50 + 1);


// 배열 안에 위치할 수 있는지 리턴
bool inRange(int y, int x) {
	return (0 <= y && y < n && 0 <= x && x < m);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		// 초기화
		cin >> n >> m;
		int gcnt = 0, bcnt = 0;
		stack< pair<int,int> > bs;
		for(int i = 0; i < n; i++) {
			cin >> board[i];
			for(int j = 0; j < m; j++) {
				if(board[i][j] == 'G') gcnt++;
				else if(board[i][j] == 'B') {
					bs.push(make_pair(i,j));
					bcnt++;
				}
			}
		}

		if(gcnt == 0) {
			// G가 없는경우 항상 가능
			cout << "YES\n";
		} else {
			bool ret = true;
			if(0 < bcnt && ret) {
				// B가 있는 경우, B의 주변을 벽으로 막음
				while(!bs.empty()) {
					int x = bs.top().second;
					int y = bs.top().first;
					bs.pop();

					for(int i = 0; i < 4; i++) {
						int xx = x + dirx[i];
						int yy = y + diry[i];

						if(inRange(yy, xx)) {
							if(board[yy][xx] == '.') {
								board[yy][xx] = '#';
							} else if(board[yy][xx] == 'G') {
								ret = false;
							} else {
								continue;
							}
						}
					}
				}
			}
			if(!ret || board[n - 1][m - 1] == '#') {
				// B를 벽으로 막을 수 없어서 불가능
				cout << "NO\n";
			} else {
				// G가 (n - 1), (m - 1) 로 이동가능한지 확인
				bool check[50 + 1][50 + 1] = {0};
				bool canmove[50 + 1][50 + 1] = {0};
				stack< pair<int,int> > solve;
				solve.push(make_pair(n - 1, m - 1));
				while(!solve.empty()) {
					int x = solve.top().second;
					int y = solve.top().first;
					solve.pop();
					check[y][x] = true;

					if(board[y][x] == '#' || board[y][x] == 'B') {
						canmove[y][x] = false;
						continue;
					}

					for(int i = 0; i < 4; i++) {
						int xx = x + dirx[i];
						int yy = y + diry[i];

						if(inRange(yy, xx)) {
							if(!check[yy][xx] && (board[yy][xx] == '.' || board[yy][xx] == 'G')) {
								solve.push(make_pair(yy, xx));
								canmove[yy][xx] = true;
							} else{
								continue;
							}
						}
					}
				}
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						if(board[i][j] == 'G') {
							ret = ret && canmove[i][j];
						}
					}
				}
				if(ret) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}