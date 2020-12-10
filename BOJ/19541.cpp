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

vector< vector<int> > meet;	// 모임에 참석한 인원을 기록
vector<bool> lastInfected;	// 입력으로 들어온 최종 감염 기록
vector<bool> initInfected;	// 최초 감염자, 비감염자 기록
vector<bool> simulate;		// initInfected로 모임을 시뮬레이션 할 벡터

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 입력, 초기화
	int n, m;
	bool ret = true;
	cin >> n >> m;

	meet.resize(m);
	lastInfected.resize(n + 1);
	initInfected.resize(n + 1, true);
	simulate.resize(n + 1);

	for(int i = 0; i < m; i++) {
		int s;
		cin >> s;
		for(int j = 0; j < s; j++) {
			int p;
			cin >> p;
			meet[i].push_back(p);
		}
	}

	for(int i = 1; i <= n; i++) {
		bool infect;
		cin >> infect;
		lastInfected[i] = initInfected[i] = simulate[i] = infect;
	}

	for(int i = m - 1; i >= 0; i--) {
		bool infect = true;
		for(int j = 0; j < meet[i].size() && infect; j++) {
			if(!simulate[meet[i][j]]) {
				infect = false;
			}
		}

		// 최종 비감염자가 존재한다면, 해당 모임에서 모든 인원은 비감염자임
		if(!infect) {
			for(int j = 0; j < meet[i].size(); j++) {
				initInfected[meet[i][j]] = false;
				simulate[meet[i][j]] = false;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		simulate[i] = initInfected[i];
	}

	for(int i = 0; i < m; i++) {
		bool infect = false;
		for(int j = 0; j < meet[i].size() && !infect; j++) {
			if(simulate[meet[i][j]]) {
				// 모임에 감염자가 있는 경우
				infect = true;
			}
		}

		if(infect) {
			for(int j = 0; j < meet[i].size(); j++) {
				simulate[meet[i][j]] = true;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		// cout << lastInfected[i] << " " << simulate[i] << "\n";
		ret = ret && (simulate[i] == lastInfected[i]);
	}

	if(ret) {
		cout << "YES\n";
		for(int i = 1; i < initInfected.size(); i++) {
			if(initInfected[i]) {
				cout << "1 ";
			} else {
				cout << "0 ";
			}
		}
	} else {
		cout << "NO";
	}

	return 0;
}