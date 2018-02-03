//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, need[4];
map<char, int> b;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = (int)s.size();
	
	for(int i=0;i<4;++i){
		int j=i;
		while(j<=n){
			if(s[j]=='!') need[i]++;
			else b[s[j]] = i%4; 
			j+=4;
		}
	}

	cout << need[b['R']] _ need[b['B']] _ need[b['Y']] _ need[b['G']] << endl;

	return 0;
}

