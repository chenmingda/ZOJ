//DFS

#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <memory.h>  
using namespace std;  
int visit[10][10],mmax,n,cou;  
 //visit�0��ɶ��û�ţ�1�Ƿ��˵ﱤ��2�Ƿ��˷���ǽ  
 //cou�����ŵĸ�����mmax��¼���cou�����ֵ������ĿҪ��ֵ  
int find(int x,int y) // �ж��Ƿ���Է���  
{     
    for(int i=y; i>=1; i--) //�ĸ�ѭ�����ӵ㣨X,Y�����������жϣ�����еﱤ������0�������ǽ�������¸�ѭ����  
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