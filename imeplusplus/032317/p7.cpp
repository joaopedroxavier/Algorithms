//
//	(Promotion)
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/PRO/
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << ",  " <<

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

multiset<int> m;
multiset<int>::iterator it;

int main(){
	ios_base::sync_with_stdio(false);
	int t, n=0;
	while(1){
		cin >> t;
		if(t == 0) break;
		else if(t == -1){
			cout << *it << endl;
			if(n%2==1) it=prev(it), m.erase(next(it));
			else it=next(it), m.erase(prev(it));
			n--;
		}
		else{
			if(m.empty()) m.insert(t), it = m.begin(), n++;
			else{
				m.insert(t);
				if(n%2==0) it=next(it);
				n++;
			}
		}
	}
	return 0;
}

