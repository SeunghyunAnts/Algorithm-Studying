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

vector<int> nodes;

int make_tree(int stt, int last) {
	int r = stt;
	int left = stt + 1, right = -1;

	if(last == stt) {
		cout << nodes[stt] << "\n";
		return stt;
	}

	for(int i = stt + 1; i <= last; i++) {
		if(nodes[r] < nodes[i]) {
			right = i;
			break;
		}
	}

	if(right == -1) {
		make_tree(stt + 1, last);
	} else if(left == right) {
		make_tree(stt + 1, last);
	} else {
		make_tree(left, right - 1);
		make_tree(right, last);
	}

	cout << nodes[r] << "\n";

	return r;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, root, cnt = 0;

	while(cin >> n) {
		cnt++;
		if(cnt == 1) root = n;
		nodes.push_back(n);
	}

	make_tree(0, nodes.size() - 1);

	return 0;
}