/*
    BOJ 15730 (https://www.acmicpc.net/problem/15730)
*/

#include <bits/stdc++.h>
#define minHeight 10001
#define maxHeight -1

typedef long long ll;

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int pool[100][100];		// 수영장의 높이를 저장
int curPool[100][100];	// 현재 높이에서의 수영장
bool check[100][100];	// 방문여부 저장 (방문했으면 true)

int main(void) {
	int row, col;			// 세로길이, 가로길이
	int cnt = 0;			// 물을 채울 수 있는 부분
	int low = minHeight;	// 최소 높이
	int high = maxHeight;	// 최대 높이

	cin >> row >> col;		// 세로, 가로 입력

	// 수영장의 높이 입력
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cin >> pool[i][j];
			
			// 최소 높이 갱신
			if(pool[i][j] < low) {
				low = pool[i][j];
			}

			// 최대 높이 갱신
			if(high < pool[i][j]) {
				high = pool[i][j];
			}
		}
	}

	// 높이별로 물을 채울 수 있는 부분 카운트
	for(int height = low; height <= high; height++) {
		// height : 현재 높이
		// height를 기준으로 현재 높이를 기준으로 벽, 빈공간, 새는 공간 구분
		
		// 큐, 배열 초기화
		memset(curPool, 0, sizeof(curPool));
		memset(check, false, sizeof(check));
		queue<pair<int,int>> q;	// 값이 -1인 <y,x> 를 저장하는 큐 

		// 현재 높이에서의 수영장 배열 초기화
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				// 현재 높이보다 작거나 같으면 물을 채울 수 있음 (0)
				// 현재 높이보다 작거나 같은데, 사이드 부분이면 물이 빠져나감 (-1)
				// 현재 높이보다 높으면 벽으로 인식 (1)
				if(height < pool[i][j]) {
					// 현재 높이보다 높은 경우
					curPool[i][j] = 1;
					check[i][j] = true;	// 벽은 탐색할 수 없으니 check해 둠.
				} else {
					// 현재 높이보다 같거나 낮은 경우
					if(i * j == 0 || i == row - 1 || j == col - 1) {
						// 사이드 부분인 경우
						curPool[i][j] = -1;
						q.push(make_pair(i,j));
					} else {
						curPool[i][j] = 0;
					}
				}
			}
		}

		// -1인 값을 기준으로 BFS
		while(!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;

			q.pop();
			check[y][x] = true;	// 방문 처리

			for(int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];

				if(0 <= yy && yy < row && 0 <= xx && xx < col) {
					// 범위 안에 있을 경우
					
					if(!check[yy][xx] && curPool[yy][xx] == 0) {
						q.push(make_pair(yy,xx));
						curPool[yy][xx] = -1;
					}
				} else {
					// 범위 밖에 있을 경우 (탐색불가)
					continue;
				}
			}
		}

		// BFS 이후 남은 0의 개수가 물을 채울 수 있는 부분의 개수임
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(curPool[i][j] == 0) cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}