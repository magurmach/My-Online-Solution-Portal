
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

int n;
vector<int> v[100005];

int com[100005];
int comsize[100005];

int mod=(1e9)+7;

lld memo[100005][4];

int mark;

int cnt=1;

void dfs(int indx)
{
    com[indx]=mark;
    comsize[mark]++;
    int i;
    int sz=v[indx].size();
    for(i=0;i<sz;i++)
    {
        if(com[v[indx][i]]==-1)
        {
            dfs(v[indx][i]);
        }
    }
}

lld dp(int indx, int m)
{
    if(m==0)
    {
        return 1;
    }
    else if(indx==cnt)
    {
        return 0;
    }
    lld &ret=memo[indx][m];
    if(ret!=-1) return ret;
    ret=dp(indx+1,m);
    ret=(ret+(dp(indx+1,m-1)*comsize[indx])%mod)%mod;
    return ret;
}

int main()
{
    //FRO
    scanf("%d",&n);
    int i,j;
    int x,y;
    char ln[5];
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d %s",&x,&y,ln);
        if(ln[0]=='b')
        {
            v[x].PB(y);
            v[y].PB(x);
        }
    }

    RESET(memo);
    RESET(com);

    for(i=1;i<=n;i++)
    {
        if(com[i]==-1)
        {
            //new component
            mark=cnt++;
            dfs(i);
        }
    }
    lld ans=dp(0,3);
    printf("%lld\n",ans);
    return 0;
}
