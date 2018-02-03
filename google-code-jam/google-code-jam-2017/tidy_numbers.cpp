//
//	(Tidy Numbers)
//	Google Code Jam 2017 - Qualification Round
//	source: https://code.google.com/codejam/contest/3264486/dashboard
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	int t;
	string a;
	cin >> t;
	for(int q=1;q<=t;++q){
	cin >> a;
		int s = a.size(), key = s+1, p=1;
		for(int i=0;i<s-1;++i){
			if((a[i+1]-'0') < (a[i]-'0')){
				key = i;
				p = i;
				if(a[i]!='1') while(a[p]==a[i] and p>=0) p--;
				else key = s+2;
				break;
			}
		}
		cout << "Case #" << q << ": ";
		if(key == s+1) for(int i=0;i<s;++i) cout << a[i];
		else if(key == s+2) for(int i=0;i<(s-1);++i) cout << 9;
		else{
			for(int i=0;i<=p;++i) cout << a[i]-'0';
			cout << a[key]-'0'-1;
			for(int i=p+2;i<s;++i) cout << 9;
		}
		cout << endl;
	}
	return 0;
}

