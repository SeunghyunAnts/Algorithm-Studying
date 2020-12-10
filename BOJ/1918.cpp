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

int opValue(char oper) {
	if(oper == '(') return 0;
	else if(oper == '+' || oper == '-') return 1;
	else return 2;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string p;
	stack<char> opers;
	vector<char> ans;

	cin >> p;

	for(int i = 0; i < p.size(); i++) {
		if('A' <= p[i] && p[i] <= 'Z') {
			// 연산자인 경우 답에 추가
			ans.push_back(p[i]);
		} else {
			// 피연산자인 경우 연산자의 우선순위를 확인
			if(p[i] == '(') {
				opers.push(p[i]);
			} else if(p[i] == ')') {
				while(opers.top() != '(') {
					ans.push_back(opers.top());
					opers.pop();
				}
				opers.pop();
			} else {
				if(opers.empty()) {
					opers.push(p[i]);
				} else if(opValue(opers.top()) < opValue(p[i])) {
					opers.push(p[i]);
				} else {
					while(!opers.empty() && opers.top() != '(' && opValue(opers.top()) >= opValue(p[i])) {
						ans.push_back(opers.top());
						opers.pop();
					}
					opers.push(p[i]);
				}
			}
		}

		if(i == p.size() - 1) {
			while(!opers.empty()) {
				ans.push_back(opers.top());
				opers.pop();
			}
		}
	}

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}

	return 0;
}