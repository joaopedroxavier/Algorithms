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

const int N=1e2+5;
const int INF=0x3f3f3f3f;

char s[N];
int cont[30];
int ans;
priority_queue<int> pq;

int main(){
				scanf("%s", s);
				for(int i=0; s[i]; i++) {
								cont[s[i]-'a']++;
				}
				for(int i=0; i<='z'-'a'; i++) {
								pq.push(cont[i]);
								ans+=cont[i];

				}
				ans-=pq.top();
				pq.pop();
				ans-=pq.top();
				pq.pop();
				printf("%d\n", ans);
}

