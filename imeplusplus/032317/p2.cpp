//
//	(Street Parade)
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/STPAR/
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

int main(){
	ios_base::sync_with_stdio(false);
	int n, cont;
	bool ans;
	sti truck, side;
	vi street;
	while(1){
		while(!truck.empty()) truck.pop();
		while(!side.empty()) side.pop();
		street.clear();
		ans = true;
		cont = 1;
		cin >> n;
		if(n==0) break;
		for(int i=0;i<n;++i){
			int u;
			cin >> u;
			street.pb(u);
		}
		for(int i=n-1;i>=0;--i) truck.push(street[i]);
		while(!truck.empty()){
			if(truck.topper() == cont)	cont++, truck.pop();
			else if(!side.empty() and side.topper() == cont) side.pop(), cont++;
			else{
				if(side.empty()) side.push(truck.topper()), truck.pop();
				else if(side.topper() < truck.topper()){
					ans = false;
					if(!ans) break;
				}
				else side.push(truck.topper()), truck.pop();
			}
		}
		cout << ((ans) ? "yes" : "no") << endl;
	}
	return 0;
}

