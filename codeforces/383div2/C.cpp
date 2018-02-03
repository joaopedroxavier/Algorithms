//
//	(C - Arpa's loud Owf and Mehrdad's evil plan)
//	CodeForces Round #383 Div.2
//	source: http://codeforces.com/contest/742/problem/C
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e3;

ll crush[N];

ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

ll mmc(ll a, ll b){
	ll c = a*b/gcd(a,b);
	return c;
}

ll find_cycle(ll u){
	ll cont = 1, p=crush[u];
	while(p!=u){
		p = crush[p];
		cont++;
		if(cont>N) return 0;
	}
	return cont;
}

int main(){
	ll n, ans=1, aux;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> crush[i];
	for(int i=1;i<=n;++i){
		aux = find_cycle(i);
		if(!aux){
			ans = -1;
			break;
		}
		else{
			if(aux%2==0) aux=aux/2;
			ans = mmc(ans,aux);
		}
	}
	cout << ans << endl;
	return 0;
}

