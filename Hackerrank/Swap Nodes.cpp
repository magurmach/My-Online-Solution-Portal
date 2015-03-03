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

int l[2000];
int r[2000];

int k;

bool f;
void preorder(int indx,int dep)
{
    if(indx==-1) return;
    if(dep%k==0)
    {
        swap(l[indx],r[indx]);
    }
    preorder(l[indx],dep+1);
    if(f)
    {
        printf(" ");
    }
    else
    {
        f=true;
    }
    printf("%d",indx);
    preorder(r[indx],dep+1);
}

int main()
{
    //FRO
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        f=false;
        preorder(1,1);
        printf("\n");
    }
    return 0;
}
