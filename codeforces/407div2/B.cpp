//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+5;
ll b1, q, l, m;
set<ll> bad;
set<ll> pg;
bool inf = false;

int main(){
	ios::sync_with_stdio(false);
	cin >> b1 >> q >> l >> m;
	for(int i=1;i<=m;++i){
		int u;
		cin >> u;
		bad.insert(u);
	}
	ll cont=0;
	ll a1 = b1;
	while(abs(b1) <= l){
		cont++;
		if(bad.count(b1))	cont--;
		if(pg.count(b1)){
			if(bad.count(0)){
				if(q == 0) cont = !bad.count(a1);
				else for(auto it = pg.begin(); it!=pg.end(); ++it) if(!bad.count(*it)) inf = true;	 
				break;
			}
			else for(auto it = pg.begin(); it!=pg.end(); ++it) if(!bad.count(*it)) inf = true;
			break;
		}
		pg.insert(b1);
		b1 = b1*q;
	}
	if(inf) cout << "inf" << endl;
	else cout << cont << endl;
	return 0;
}

