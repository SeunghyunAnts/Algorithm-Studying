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

int size;
vector< pair<char, char> > nodes(26);

// 전위순회
int pre_order(char cur) {
	if(cur == '.') {
		return 0;
	} else {
		cout << cur;
		pre_order(nodes[cur - 'A'].first);
		pre_order(nodes[cur - 'A'].second);
	}
	return 1;
}

// 중위순회
int in_order(char cur) {
	if(cur == '.') {
		return 0;
	} else {
		in_order(nodes[cur - 'A'].first);
		cout << cur;
		in_order(nodes[cur - 'A'].second);
	}
	return 1;
}

// 후위순회
int post_order(char cur) {
	if(cur == '.') {
		return 0;
	} else {
		post_order(nodes[cur - 'A'].first);
		post_order(nodes[cur - 'A'].second);
		cout << cur;
	}
	return 1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> size;
	fill(nodes.begin(), nodes.end(), mp('.','.'));

	for(int i = 0; i < size; i++) {
		char cur, le, ri;
		cin >> cur >> le >> ri;
		nodes[cur - 'A'].first = le;
		nodes[cur - 'A'].second = ri;
	}

	pre_order('A'); cout << "\n";
	in_order('A'); cout << "\n";
	post_order('A');

	return 0;
}