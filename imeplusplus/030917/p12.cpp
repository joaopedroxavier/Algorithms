//
//	P12 - X-MEN
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/XMEN/
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

const int N=2e6+9;

int m[N], w[N], aux[N], lis[N], b[N];
int main(){
	int n, t, length=1;
	cin >> t;
	for(int k=0;k<t;++k){
		length = 1;
		cin >> n;
		memset(aux,0,sizeof(aux));
		for(int i=0;i<n;++i){
			cin >> w[i];
			aux[w[i]-1] = i;
			w[i]=i;
		}
		for(int i=0;i<n;++i) cin >> m[i];
		for(int i=0;i<n;++i) m[i] = aux[m[i]-1];
		lis[0] = m[0];
		for(int i=1;i<n;++i){
			if(m[i]<lis[0])
				lis[0] = m[i];
			else if(m[i]>lis[length-1]){
				lis[length] = m[i];
				length++;
			}
			else
				lis[upper_bound(lis,lis+length,m[i])-lis] = m[i];
		}
		cout << length << endl;
	}
	return 0;
}

