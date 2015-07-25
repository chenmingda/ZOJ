//DFS

#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <memory.h>  
using namespace std;  
int visit[10][10],mmax,n,cou;  
 //visit里，0是啥都没放，1是放了碉堡，2是放了防火墙  
 //cou计数放的个数，mmax记录最大cou的最大值，即题目要求值  
int find(int x,int y) // 判断是否可以放置  
{     
    for(int i=y; i>=1; i--) //四个循环，从点（X,Y）上下左右判断，如果有碉堡，返回0，如果有墙，继续下个循环。  
    {  
        if( visit[x][i] == 1 )  
            return 0;  
        if( visit[x][i] == 2 )  
            break;  
    }  
    for(int i=y; i<=n; i++)  
    {  
        if( visit[x][i] == 1 )  
            return 0;  
        if( visit[x][i] == 2 )  
            break;  
    }  
    for(int i=x; i>=1; i--)  
    {  
        if( visit[i][y] == 1 )  
            return 0;  
        if( visit[i][y] == 2 )  
            break;  
    }  
    for(int i=x; i<=n; i++)  
    {  
        if( visit[i][y] == 1 )  
            return 0;  
        if( visit[i][y] == 2 )  
            break;  
    }  
    return 1;  
}  
// DFS  
void DFS()  
{  
    if( cou > mmax )  
        mmax = cou;  
    for(int k=1; k<=n; k++)  
        for(int h=1; h<=n; h++)  
            if( !visit[k][h] && find(k,h) )  
            {  
                visit[k][h] = 1;  
                cou++;  
                DFS();  
                visit[k][h] = 0;  
                cou--;  
            }  
}  
int main(void)  
{  
    char str[10];  
    while( cin >> n && n)  
    {  
        mmax = 0; cou = 0;  
        for(int i=1; i<=n; i++)  
        {  
            cin >> str;  
            for(int k=0; k<n; k++)  
            visit[i][k+1] = (str[k] == 'X' ? 2 : 0 );  
        }  
        DFS();  
        cout << mmax << endl;  
    }  
    return 0;  
}  