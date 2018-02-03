//
//	(B - Arpa's obvious problem and Mehrdad's terrible solution)
//	CodeForces Round #383 Div.2
//	source: http://codeforces.com/contest/742/problem/B
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

const int N=1e6;

int a[N], v[N], agora_vai[N];
/*bool find(int u, int l, int r){
	int m;
	while(l<=r){
		m = (l+r)/2;
		if(u==a[m]) return true;
		else if(u<a[m]) r = m-1;
		else l = m+1;
	}
	return false;
}*/

int main(){	
	ll n, x, cont=0, b;
	cin >> n >> x;
	for(int i=0;i<n;++i){
		cin >> a[i];
		v[a[i]]++;
	}
	if(x==0) for(int i=0;i<n;++i) cont+=v[a[i]]-1;
	else{
		for(int i=0;i<n;++i){
			b = a[i]^x;
			cont+=v[b];
		}
	}
	cont = cont/2;
	cout << cont << endl;
	return 0;
}

