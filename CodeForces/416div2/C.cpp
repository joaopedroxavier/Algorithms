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

int a[N], s[N], first[N], last[N], dp[N], n, p;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i){
		if(!first[a[i]]) first[a[i]] = i, p=p^a[i];
		last[a[i]] = i;
		s[i] = p;
	}

	for(int i=1;i<=n;++i){
		int j=i, fr=i;
		while(j){
			if(last[a[j]] > i){
        break;
			}
			fr = min(first[a[j]], fr);
			if(j == fr){
				dp[i] = max(dp[i], dp[j-1] + (s[i]^s[j-1]));
			}
			j--;
		}
		dp[i] = max(dp[i], dp[i-1]);
	}

	cout << dp[n] << endl;
	return 0;
}

