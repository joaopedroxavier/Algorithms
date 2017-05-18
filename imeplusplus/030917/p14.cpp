//
//	P14 - Army Buddies
//	Judge: UVa
//	source: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3778
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

int l[N], r[N];
int main(){
	int s, b, p1, p2;
	while(1){
		cin >> s >> b;
		if(s==0 and b==0) break; 
		for(int i=2;i<=s;++i) l[i] = i-1;
		for(int i=1;i<=s-1;++i) r[i] = i+1;
		l[1] = N;
		r[s] = N;
		for(int i=0;i<b;++i){
			cin >> p1 >> p2;
			if(l[p1] != N){
				l[r[p2]] = l[p1];
			}
			else{
				l[r[p2]] = N;
			}
			if(r[p2] != N){
				r[l[p1]] = r[p2];
			}
			else{
				r[l[p1]] = N;
			}
			if(l[r[p2]] == N) cout << "* ";
			else cout << l[r[p2]] << ' ';
			if(r[l[p1]] == N) cout << '*';
			else cout << r[l[p1]];
			cout << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}

