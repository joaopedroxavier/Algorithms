//
//	Problem W - Six Sides
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

int a1[6], a2[6];
int main(){
	double fav=0, total=36, ans;
	for(int i=0;i<6;++i) cin >> a1[i];
	for(int i=0;i<6;++i) cin >> a2[i];
	for(int i=0;i<6;++i){
		for(int j=0;j<6;++j){
			if(a1[i]>a2[j]) fav++;
			else if(a1[i]==a2[j]) total--;
		}
	}
	if(total == 0) ans = 0;
	else ans = fav/total;
	printf("%.5lf\n", ans);
}

