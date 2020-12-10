#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;	// 수열의 길이
	vector< pair<int,int> > arr;	// 수열 <lis에서 인덱스, 수열의 값>
	vector<int> lis;	// 가장 긴 증가하는 부분 수열
	vector<int> trace; 	// LIS를 저장하는 벡터
	
	for(int i = 0; i < n; i++) {
		int ai; cin >> ai;
		arr.push_back(pair<int,int>(0, ai));
	}

	lis.push_back(-1000000001);
	for(int i = 0; i < n; i++) {
		if(lis.back() < arr[i].second) {
			lis.push_back(arr[i].second);
			arr[i].first = lis.size() - 1;
		} else {
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), arr[i].second);
			*it = arr[i].second;
			arr[i].first = distance(lis.begin(), it);
		}
	}

	int check = lis.size() - 1;
	stack<int> stk;
	for(int i = n - 1; 0 <= i; i--) {
		if(arr[i].first == check) {
			stk.push(arr[i].second);
			check--;
		}
	}

	cout << lis.size() - 1 << "\n";

	while(!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}