#include<stdio.h>
#include<string.h>
int n,m,ok,ans,vis[205][205];
char mat[205][205];
void dfs(int x,int y,int step)
{
    if(vis[x][y] || mat[x][y]=='#' || step>=ans) return;
    if(mat[x][y]=='r')
    {
        ok=1;
        if(step<ans) ans=step;
        return;
    }
    if(mat[x][y]=='x')
        step++;
    vis[x][y]=1;
    dfs(x+1,y,step+1);
    dfs(x-1,y,step+1);
    dfs(x,y+1,step+1);
    dfs(x,y-1,step+1);
    vis[x][y]=0;
}
int main()
{
    while(~scanf("%d %d%*c",&n,&m))
    {
        memset(mat,'#',sizeof(mat));
        int i,j,sti,stj;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%c",&mat[i][j]);
                if(mat[i][j]=='a')
                {
                    sti=i;
                    stj=j;
                }
            }
            getchar();
        }
        ok=0;
        ans=100000;
        dfs(sti,stj,0);
        if(ok) printf("%d\n",ans);
        else printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
