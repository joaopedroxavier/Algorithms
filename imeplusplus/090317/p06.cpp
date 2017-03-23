//
//	P6 - Sum of Digits
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/CPCRC1C/
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

const int N=13;

ll pot(int p, int e){
	if(e==0)	return 1;
	else return p*pot(p,e-1);
}

ll v[N], q[N], a1[N], a2[N];
int main(){
	int c[] = {0,1,3,6,10,15,21,28,36,45};
	v[0] = 1;
	q[0] = 0;
	q[1] = 1;
	v[1] = 45;
	ll n1, n2, cont1, cont2, aux1, aux2;
	for(int i=2;i<=10;++i){
		q[i]=q[i-1]*10;
		v[i]=v[i-1]*10+45*q[i];
	}
	while(1){
		cont1=0, cont2=0;
		cin >> n1 >> n2;
		aux1 = n1;
		aux2 = n2;
		ll sum1 = 0;
		ll sum2 = 0;
		if(n1==-1 and n2==-1) break;
		aux1 = n1;
		while(aux1){
			cont1++;
			a1[cont1] = aux1%10;
			aux1=aux1/10;
		}
		for(int i=1;i<=cont1;++i) aux1+=a1[i];
		for(int i=cont1;i>=1;--i){
			if(a1[i]==0) sum1+=45*(n1/pot(10,i))*q[i];
			else sum1+=c[a1[i]-1]*q[i]+a1[i]*((n1%pot(10,i-1))+1)+45*(n1/pot(10,i))*q[i];
		}
		while(aux2){
			cont2++;
			a2[cont2] = aux2%10;
			aux2=aux2/10;
		}
		for(int i=1;i<=cont2;++i) aux2+=a2[i];
		for(int i=cont2;i>=1;--i){
			if(a2[i]==0) sum2+=45*(n2/pot(10,i))*q[i];
			else sum2+=c[a2[i]-1]*q[i]+a2[i]*((n2%pot(10,i-1))+1)+45*(n2/pot(10,i))*q[i];
		}
		if(sum1>sum2) sum2-=aux2;
		else sum1-=aux1;
		cout << max(sum1,sum2) - min(sum1,sum2) << endl;
	}
	return 0;
}
