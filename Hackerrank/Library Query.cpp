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

int n,q;

int seg[105][1001];

int a[10005];

int segsize,sno;

void precal()
{
    segsize=sqrt(n);
    sno=n/segsize;
    if(n%segsize) sno++;
    int i,j;
    CLR(seg);
    for(i=0;i<sno;i++)
    {
        if(i)
        {
            for(j=0;j<=1000;j++)
            {
                seg[i][j]=seg[i-1][j];
            }
        }
        for(j=segsize*i;j<min(segsize*(i+1),n);j++)
        {
            seg[i][a[j]]++;
        }
    }
}

void update(int indx, int val)
{
    int sseg=indx/segsize;
    int i,j;
    for(i=sseg;i<sno;i++)
    {
        seg[i][a[indx]]--;
    }
    for(i=sseg;i<sno;i++)
    {
        seg[i][val]++;
    }
    a[indx]=val;
}

int query(int x, int y, int k)
{
    int cnt[1001];
    CLR(cnt);
    int i;
    int sseg=x/segsize;
    int eseg=y/segsize;
    //cnt filler code
    if(sseg==eseg)
    {
        for(i=x;i<=y;i++)
        {
            cnt[a[i]]++;
        }
    }
    else
    {
        eseg--;
        if(sseg<eseg)
        {
            for(i=0;i<=1000;i++)
            {
                cnt[i]=seg[eseg][i]-seg[sseg][i];
            }
        }
        for(i=x;i<min((sseg+1)*segsize,n);i++)
        {
            cnt[a[i]]++;
        }
        eseg++;
        for(i=segsize*eseg;i<=y;i++)
        {
            cnt[a[i]]++;
        }
    }
    int v=0;
    for(i=0;i<=1000;i++)
    {
        v+=cnt[i];
        if(v>=k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    //FRO
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        precal();

        scanf("%d",&q);
        while(q--)
        {
            int tp;
            scanf("%d",&tp);
            int x,y,k;
            if(tp==1)
            {
                scanf("%d %d",&x,&k);
                update(x-1,k);
            }
            else
            {
                scanf("%d %d %d",&x,&y,&k);
                x--;
                y--;
                int ans=query(x,y,k);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
