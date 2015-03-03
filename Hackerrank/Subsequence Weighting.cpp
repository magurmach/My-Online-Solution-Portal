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

int a[150005];
int b[150005];
int w[150005];

map<int,int> mp;

int n;

lld seg[1000000];

lld query(int node, int l, int r,int ql, int qr)
{
    if(ql<=l && r<=qr)
    {
        return seg[node];
    }
    else if(r<ql || qr<l)
    {
        return 0;
    }
    else
    {
        lld x,y;
        x=query(2*node,l,(l+r)/2,ql,qr);
        y=query(2*node+1,(l+r)/2+1,r,ql,qr);
        //CODE HERE
        return max(x,y);
    }
}

void update(int node, int l, int r, int ql, int qr, lld val)
{
    if(ql<=l && r<=qr)
    {
        //in Limit Code Here
        seg[node]=max(seg[node],val);
    }
    else if(r<ql || qr<l)
    {
        //Out Of Limit Code Here
        return;
    }
    else
    {
        update(2*node,l,(l+r)/2,ql,qr,val);
        update(2*node+1,(l+r)/2 +1,r,ql,qr,val);
        //Code Here
        seg[node]=max(seg[2*node],seg[2*node+1]);
    }
}

int main()
{
    //FRO
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int cnt=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            if(mp[b[i]]==0)
            {
                mp[b[i]]=cnt;
                cnt++;
            }
        }
        int d=cnt-1;
        CLR(seg);
        for(i=0;i<n;i++)
        {
            int x=mp[a[i]]-1;
            lld val=query(1,1,d,1,x);
            val=val+w[i];
            update(1,1,d,x+1,x+1,val);
        }
        lld res=query(1,1,d,1,d);
        printf("%lld\n",res);
    }
    return 0;
}
