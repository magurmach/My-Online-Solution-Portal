
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

int a[100005];
int cnt[100005];

int main()
{
    //FRO
    //FROut
    int t;
    scanf("%d",&t);
    int i,j;
    while(t--)
    {
        scanf("%d",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        CLR(cnt);
        j=0;
        for(i=0;i<n;i++)
        {
            a[j]=a[i];
            cnt[j]=1;
            while(i+1<n && a[i]==a[i+1])
            {
                cnt[j]++;
                i++;
            }
            j++;
        }
        n=j;
        int mn=1e9;
        for(i=0;i<n;i++)
        {
            queue<int> s;
            j=cnt[i];
            while(j--)
            {
                s.push(i);
            }
            int lev=cnt[i];
            while(i+1<n && a[i]+1==a[i+1])
            {
                i++;
                if(cnt[i]>lev)
                {
                    j=cnt[i]-lev;
                    while(j--)
                    {
                        s.push(i);
                    }
                    lev=cnt[i];
                }
                else if(cnt[i]<lev)
                {
                    j=lev-cnt[i];
                    while(j--)
                    {
                        mn=min(mn,i-s.front());
                        s.pop();
                    }
                    lev=cnt[i];
                }
            }
            while(!s.empty())
            {
                mn=min(mn,i-s.front()+1);
                s.pop();
            }
        }
        printf("%d\n",mn);
    }
    return 0;
}
