/*ZOJ 1002 - Fire Net */
/*n最大为4，使用回溯法搜索解空间树*/
#include <stdio.h>

char map[4][5];
int maxCount;/*最多可放置碉堡数*/

/* 测试（x，y）位置是否可以放置碉堡 */
int CanPut(int n, int x, int y)
{
    /*因为行列是递增的，因此只需向上和向左搜索是否有碉堡即可*/
    int i;

    /*向左推移, 0表示不能被占用*/
    i=x;
    while(i>0 && map[i-1][y]!='X') 
        if (map[--i][y]=='O') return 0;
    

    /*向上*/
    i=y;
    while(i>0 && map[x][i-1]!='X')
        if(map[x][--i]=='O') return 0;
            
    /*可以放置*/
    return 1;
}


/*找出最大碉堡树, n是city的尺寸，k是距离起始点的一维长度距离*/
void Search(int n, int k, int curCount)
{
    int x,y;
    if(k==n*n)
    {
        /*arrived the bottom*/
        if(curCount>maxCount)
            maxCount=curCount;
        return;
    }
    else
    {
        x=k/n;
        y=k%n;
        if(map[x][y]=='.' && CanPut(n,x,y))
        {
            /*该点可以放置，则进入该分支*/
            map[x][y]='O';/*put a houseblock*/
            Search(n, k+1, curCount+1);
            /*回退*/
            map[x][y]='.';
        }
        /*向下一个分支*/
        Search(n,k+1,curCount);
    }
}

int main()
{
    int n,i,count;
    while(scanf("%d",&n)!=EOF && n>0)
    {
        for(i=0;i<n;i++)
            scanf("%s", map[i]);
        
        maxCount=0;
        Search(n, 0, 0);
        printf("%d\n",maxCount);
    }
}