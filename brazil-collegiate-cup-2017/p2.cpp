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

int main(){
	ios_base::sync_with_stdio(false);
	int h[4], t[4], win1, los1, win2, los2;
	for(int i=0;i<4;++i) cin >> h[i] >> t[i];

	(h[0]+t[0] >= h[1]+t[1]) ? (win1 = 0, los1 = 1) : (win1 = 1, los1 = 0);
	(h[2]+t[2] >= h[3]+t[3]) ? (win2 = 2, los2 = 3) : (win2 = 3, los2 = 2);

	t[win1]+=t[los2], t[win2]+=t[los1];

	cout << ((h[win1]+t[win1] >= h[win2]+t[win2]) ? win1+1 : win2+1) << endl;

	return 0;
}

