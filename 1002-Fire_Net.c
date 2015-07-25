/*ZOJ 1002 - Fire Net */
/*n���Ϊ4��ʹ�û��ݷ�������ռ���*/
#include <stdio.h>

char map[4][5];
int maxCount;/*���ɷ��õﱤ��*/

/* ���ԣ�x��y��λ���Ƿ���Է��õﱤ */
int CanPut(int n, int x, int y)
{
    /*��Ϊ�����ǵ����ģ����ֻ�����Ϻ����������Ƿ��еﱤ����*/
    int i;

    /*��������, 0��ʾ���ܱ�ռ��*/
    i=x;
    while(i>0 && map[i-1][y]!='X') 
        if (map[--i][y]=='O') return 0;
    

    /*����*/
    i=y;
    while(i>0 && map[x][i-1]!='X')
        if(map[x][--i]=='O') return 0;
            
    /*���Է���*/
    return 1;
}


/*�ҳ����ﱤ��, n��city�ĳߴ磬k�Ǿ�����ʼ���һά���Ⱦ���*/
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
            /*�õ���Է��ã������÷�֧*/
            map[x][y]='O';/*put a houseblock*/
            Search(n, k+1, curCount+1);
            /*����*/
            map[x][y]='.';
        }
        /*����һ����֧*/
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