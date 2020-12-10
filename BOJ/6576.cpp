#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
// board[i][j] == true이면 B, false이면 W
bool board[512][512] = {false};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n;
	cin >> s;

	cout << "#define quadtree_width " << n << "\n";
	cout << "#define quadtree_height " << n << "\n";
	cout << "static char quadtree_bits[] = {\n";

	cout << "};";

	return 0;
}