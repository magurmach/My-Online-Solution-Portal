//Bismillahir Rahmanir Rahmeem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define INF 1e9
#define lld long long int
#define CLR(a) memset(a,0,sizeof(a))
#define RESET(a) memset(a,-1,sizeof(a))
#define act(a) memset(a,1,sizeof(a))
#define setinf(a) memset(a,0b01111111,sizeof(a));
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define ui unsigned int
#define came "came"
#define pii pair<int,int>
#define plii pair<long long int, int>
#define pll pair<long long,long long>
#define pic pair<int,char>
#define ninf (-1e9)-2
#define inf (1e9)+2
#include<fstream>
#include <assert.h>
#include <bitset>

#define foreach(x) for(__typeof(x.begin()) it=x.begin(); it!=x.end();it++)

using namespace std;
#define pid pair<int,double>
#define pdi pair<double,int>

#define PB push_back
#define MP make_pair
#define pri(x) printf("%d\n",x)
#define pi 3.14159265359
#define F first
#define S second
#define vit vector<int>::iterator

lld a[100005];
lld cumu[100005];
set<lld> st;

int main()
{
    //FRO
    int t;
    scanf("%d",&t);
    while(t--)
    {
        st.clear();
        int n;
        lld m;
        scanf("%d %lld",&n,&m);
        int i,j;
        CLR(cumu);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]%=m;
            if(i) cumu[i]=cumu[i-1];
            cumu[i]=(cumu[i]+a[i])%m;
        }
        i=j=0;
        lld mx=-1;
        st.insert(0);
        for(i=0;i<n;i++)
        {
            lld val= *st.begin();
            val=cumu[i]-val;
            if(val<0)
            {
                val%=m;
                val=val+m;
                val%=m;
                mx=max(mx,val);
            }
            else
            {
                mx=max(mx,val);
                val=*st.upper_bound(cumu[i]);
                val=cumu[i]-val;
                val%=m;
                val+=m;
                val%=m;
                mx=max(mx,val);
            }
            st.insert(cumu[i]);
        }
        printf("%lld\n",mx);
    }
    return 0;
}
