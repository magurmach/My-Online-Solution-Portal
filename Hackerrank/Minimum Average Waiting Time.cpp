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

vector< pll > v;

priority_queue< pll, vector< pll >, greater< pll > > pq;

int main()
{
    //FRO
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        lld x,y;
        scanf("%lld %lld",&x,&y);
        v.PB(MP(x,y));
    }
    sort(v.begin(),v.end());
    lld sum=0,tm=0;
    for(i=0;i<n;)
    {
        tm=v[i].F;

        while(i<n && tm>=v[i].F)
        {
            pq.push(MP(v[i].S,v[i].F));
            i++;
        }

        while(!pq.empty())
        {
            pll tp=pq.top();
            pq.pop();
            tm+=(tp.F);
            sum+=tm-tp.S;
            while(i<n && tm>=v[i].F)
            {
                pq.push(MP(v[i].S,v[i].F));
                i++;
            }
        }
    }
    printf("%lld\n",sum/n);
    return 0;
}
