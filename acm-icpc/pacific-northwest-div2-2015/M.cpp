//
//
//
//
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

int v[N];
string s[N];
int main(){
	ios_base::sync_with_stdio(false);
	int n, ans=0;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> s[i] >> v[i];
	}
	for(int i=1;i<=100;++i){
		int u = i;
		for(int j=0;j<n;++j){
			if(s[j] == "SUBTRACT"){
				if(u - v[j] < 0){
					ans++;
					break;
				}
				else u-=v[j];
			}
			else if(s[j] == "ADD") u+=v[j];
			else if(s[j] == "MULTIPLY") u*=v[j];
			else{
				if((u%v[j])!=0){
					ans++;
					break;
				}
				else u/=v[j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}

