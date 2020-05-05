/*
    BOJ 2631 (https://www.acmicpc.net/problem/2631)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c, l;
	vector<int> childs;	// 1~N까지 아이 번호 저장
	vector<int> lis;	// 증가하는 부분수열 저장

	// init
	{
		l = 0;
		cin >> n;
		childs.push_back(0);
		lis.push_back(0);
		for(int i = 1; i <= n; i++) {
			cin >> c;
			childs.push_back(c);
		}
	}

	// calc
	for(int i = 1; i <= n; i++) {
		if(lis.back() < childs[i]) {
			lis.push_back(childs[i]);
		} else {
			// 마지막 원소보다 값이 작을 때
			// 적절한 위치에 현재 값을 삽입.
			auto it = lower_bound(lis.begin(), lis.end(), childs[i]);
			if(it != lis.end()) {
				*it = childs[i];
			}
		}
	}

	// output
	cout << n - lis.size() - 1;

	return 0;
}