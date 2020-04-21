/*
    BOJ 16198 (https://www.acmicpc.net/problem/16198)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;	// 3 <= n <= 10
ll maxEnergy;
vector<int> e;

void solve(int delIndex, int vectorSize, ll curEnergy, vector<int> curVector) {
	// base condition
	if(vectorSize == 3) {
		// compare energy
		curEnergy += curVector[0] * curVector[2];
		if(maxEnergy < curEnergy) {
			maxEnergy = curEnergy;
		}
		return;
	}

	vector<int> nextVector;
	if(delIndex > 0) {
		curEnergy += curVector[delIndex - 1] * curVector[delIndex + 1];
		for(int i = 0; i < vectorSize; i++) {
			if(i != delIndex) {
				nextVector.push_back(curVector[i]);
			}
		}
	} else {
		nextVector.assign(curVector.begin(), curVector.end());
		vectorSize++;
	}

	for(int i = 1; i < vectorSize - 2; i++) {
		solve(i, vectorSize - 1, curEnergy, nextVector);
	}

	return;
}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int temp;

	// init
	{
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			e.push_back(temp);
		}
		maxEnergy = -1;
	}

	// calc
	solve(-1, n, 0, e);

	// output
	{
		cout << maxEnergy << "\n";
	}


	return 0;
}