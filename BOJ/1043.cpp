#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
int n, k, p;
map<int,int> tp; // 진실을 알고 있는 사람을 저장
vector< vector<int> > party;	// [파티에 오는 사람 수, 사람1, 2, ...]
int listenT[50 + 1] = {0}, listenL[50 + 1] = {0};

int solve(int idx, int cnt) {
	if(k < idx) {
		return cnt;
	}

	vector<int> v = party[idx];

	// 현재 idx의 파티에서 거짓말을 말하는 경우
	int cur = 0;
	bool canSearch = true;
	for(int i = 1; i < v.size(); i++) {
		int people = v[i];
		if(0 < tp.count(people) || 0 < listenT[people]) {
			canSearch = false;
		} else if(listenL[people] == 0) {
			listenL[people] = idx;
		}
	}
	if(canSearch) {
		// 현재 idx에서 거짓을 말하고 다음 idx 파티 확인
		cur = solve(idx + 1, cnt + 1);
	}
	for(int i = 0; i < 50 + 1; i++) {
		if(listenL[i] == idx) {
			listenL[i] = 0;
		}
	}

	// 현재 idx의 파티에서 진실을 말하는 경우
	int next = 0;
	canSearch = true;
	for(int i = 1; i < v.size(); i++) {
		int people = v[i];
		if(0 < listenL[people]) {
			canSearch = false;
		} else if(listenT[people] == 0) {
			listenT[people] = idx;
		}
	}
	if(canSearch) {
		// 현재 idx에서 참을 말하고 다음 idx 파티 확인
		next = solve(idx + 1, cnt);
	}
	for(int i = 0; i < 50 + 1; i++) {
		if(listenT[i] == idx) {
			listenT[i] = 0;
		}
	}

	return max(cur, next);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin >> p;
	
	for(int i = 0; i < p; i++) {
		int people;
		cin >> people;
		tp.insert(make_pair(people, 1));
	}

	vector<int> dummy = {0};
	party.push_back(dummy);
	for(int i = 0; i < k; i++) {
		int pp;
		vector<int> cur;
		cin >> pp;
		cur.push_back(pp);
		for(int j = 0; j < pp; j++) {
			int people;
			cin >> people;
			cur.push_back(people);
		}
		party.push_back(cur);
	}
	cout << solve(1, 0);

	return 0;
}