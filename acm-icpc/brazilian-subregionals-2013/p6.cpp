#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;

int n, v[N];
int main(){
	while(1){
		cin >> n;
		if(cin.eof()) break;
		int cusum = 0;
		set<int> has;
		for(int i=0;i<n;++i){
			int u;
			cin >> u;
			cusum += u;
			v[i] = cusum;
			has.insert(cusum);
		}
		has.erase(v[n-1]);
		int c = v[n-1];
		v[n-1] = 0;
		has.insert(0);
		int ans = 0;
		for(int i=0;i<n;++i){
			if(has.count((v[i] + c/3) % c) and has.count((v[i] + 2*c/3) % c)) ans++;	
		}
		cout << ans/3 << endl;
	}
}
