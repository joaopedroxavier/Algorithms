//
//	Problem N - Barbells
//	Pacific Northwest Region Programming Contest
//	Division 2
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

int b[N], p[N];
ll sum;
ll f[N];
map<ll,vi> cand;
set<ll> can;
set<ll> ans;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;++i)	scanf("%d", &b[i]);
	for(int i=0;i<m;++i)	scanf("%d", &p[i]), sum+=p[i];
	int t = (1<<(m+1))-1;
	for(int i=0;i<=t;++i){
		int cont = 0, aux = i;
		while(aux){
			int r = aux%2;
			f[i] += r*p[cont];
			aux /= 2;
			cont++;
		}
		if(f[i]<=sum/2){
			if(cand[f[i]].empty())	cand[f[i]].pb(i);
			else{
				for(int j=0;j<(int)cand[f[i]].size();++j){
					int x = i;
					if((x&=cand[f[i]][j])==0) can.insert(f[i]);
				}
				cand[f[i]].pb(i);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(auto j=can.begin(); j!=can.end(); ++j){
			ans.insert(b[i]+2*(*j));
		}
	}
	for(auto it=ans.begin();it!=ans.end();++it){
		printf("%lld\n", *it);
	}
	return 0;
}

