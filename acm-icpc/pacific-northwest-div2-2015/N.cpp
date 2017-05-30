//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e5;
const int INF=0x3f3f3f3f;

vi safe, broken;
int main({
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> k >> n;
	for(int i=0;i<k;++i){
		int u;
		string s;
		cin >> u >> s;
		if(s == "SAFE") safe.pb(u);
		else broken.pb(u);
	}
	if(safe.empty()){
		sort(broken.begin(), broken.end());
		cout << 2 _ broken[0]-1 << endl;
		return 0;
	}
	else if(broken.empty()){
		sort(safe.begin(), safe.end());
		cout << safe.at(safe.size()-1)+1 _ n-1 << endl;
		return 0;
	}
	else{
		sort(safe.begin(), safe.end());
		sort(broken.begin(), broken.end());
		cout << safe.at(safe.size()-1)+1 _ broken[0]-1 << endl;
		return 0;
	}
}

