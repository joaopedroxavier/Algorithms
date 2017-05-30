//
//	Problem P - Cameras
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

const int N=1e6;
const int INF=0x3f3f3f3f;

int cam[N], m[N];
int main(){
	int n, k, r, p1, p2, ans=0;
	scanf("%d%d%d", &n, &k, &r);
	for(int i=0;i<k;++i){
		scanf("%d", &cam[i]);
		m[cam[i]] = 1;
	}
	p1 = 0;
	while(p1<=n-r){
		bool will_increase = 1;
		int cont = 0;
		p2 = 0;
		for(int i=1;i<=r;++i){
			if(m[p1+i] == 1){
				if(cont == 0) cont++, p2 = i;
				else{
					p1=p1+p2;
					will_increase = 0;
					break;
				}
			}
		}
		if(will_increase){
			if(cont==1){
				int u;
				for(int i=1;i<=r;++i){
					if(m[p1+i]==0) u = p1+i;
				}
				m[u]=1;
				ans++;
			}
			else{
				int u, v;
				for(int i=1;i<=r;++i){
					if(m[p1+i]==0){
						v = u;
						u = p1+i;
					}
				}
				m[u] = 1;
				m[v] = 1;
				ans+=2;
			}
			p1++;
		}
	}
	cout << endl;
	cout << ans << endl;
}

