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
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);

	int s = 0, num = 0, status = 1;
	string cur = "";

	string problem;
	cin >> problem;

	for(int i = 0; i < problem.size(); i++) {
		if(problem[i] == '-' || problem[i] == '+') {
			int curnum = stoi(cur);
			cur = "";
			if(status == 1) {
				// 이전에 -가 없는 경우
				s += curnum;
				if(problem[i] == '-') {
					status = 0;
				}
			} else {
				// 이전에 -가 있어서 괄호로 묶인 경우
				if(problem[i] == '-') {
					num += curnum;
					s -= num;
					num = 0;
				} else {
					num += curnum;
				}
			}
		} else {
			cur.push_back(problem[i]);
		}

		if(i == problem.size() - 1) {
			int curnum = stoi(cur);
			if(status == 1) {
				// 이전에 -가 없는 경우
				s += curnum;
			} else {
				// 이전에 -가 있어서 괄호로 묶인 경우
				num += curnum;
				s -= num;
			}
		}
	}

	cout << s;

	return 0;
}