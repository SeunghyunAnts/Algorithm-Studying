/*
    BOJ 16197 (https://www.acmicpc.net/problem/16197)
*/

#include <bits/stdc++.h>

using namespace std;

char board[20][20];
int row, colm, minbtn = 11;
vector< pair<int, int> > coins;

bool inRange(int y, int x) {
	if(0 <= y && y < row && 0 <= x && x < colm) return true;
	else return false;
}

int solve(pair<int,int> c1, pair<int,int> c2, int curcnt) {
	// 0 < minbtn <= 10
	if(curcnt > 10) {
		return -1;
	}

	int dirx[4] = {1, 0, -1, 0};
	int diry[4] = {0, 1, 0, -1};

	int y1 = c1.first, x1 = c1.second;
	int y2 = c2.first, x2 = c2.second;

	for(int i = 0; i < 4; i++) {
		int next_y1 = y1 + diry[i], next_x1 = x1 + dirx[i];
		int next_y2 = y2 + diry[i], next_x2 = x2 + dirx[i];
	
		if(!inRange(next_y1, next_x1) && !inRange(next_y2, next_x2)) {
			// both coin : out of range
			continue;
		} else if(inRange(next_y1, next_x1) && !inRange(next_y2, next_x2)) {
			// updating
			if(curcnt + 1 < minbtn) {
				minbtn = curcnt + 1;
			}
		} else if(!inRange(next_y1, next_x1) && inRange(next_y2, next_x2)) {
			// updating
			if(curcnt + 1 < minbtn) {
				minbtn = curcnt + 1;
			}
		} else {
			// if next is wall, back to prev index
			if(board[next_y1][next_x1] == '#') {
				next_y1 = y1;
				next_x1 = x1;
			}
			if(board[next_y2][next_x2] == '#') {
				next_y2 = y2;
				next_x2 = x2;
			}

			if(next_y1 == next_y2 && next_x1 == next_x2) {
				// don't move this time
				continue;
			}

			solve(make_pair(next_y1, next_x1), make_pair(next_y2, next_x2), curcnt + 1);
		}
	}

	return 1;
}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// init
	{
		cin >> row >> colm;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < colm; j++) {
				cin >> board[i][j];
				if(board[i][j] == 'o') {
					coins.push_back(make_pair(i, j));
					board[i][j] = '.';
				}
			}
		}
	}

	// calc
	solve(coins[0], coins[1], 0);

	// output
	{
		if(minbtn > 10) minbtn = -1;
		cout << minbtn << "\n";
	}

	return 0;
}