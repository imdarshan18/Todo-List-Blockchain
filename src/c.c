#include<stdio.h>
int main()
{
    int i,j,k,n;
    printf("Enter total number of items:");
    scanf("%d",&n);
    printf("Enter Total Capicity:");
    scanf("%d",&k);
    int w[n+1],v[n+1],b[n+1][k+1];
    printf("Enter Weights:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    printf("Enter Values:\n");
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
            for(i=0;i<n;i++)
    printf("\n%d\t",w[i]);
    for(i=0;i<n;i++)
    printf("\n%d\t",v[i]);
    for(i=0;i<=k;i++)
        b[0][i]=0;
    for(i=1;i<=n;i++)
        b[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(w[i-1]<=j)
            {
                if(v[i-1]+b[i-1][j-w[i-1]]>b[i-1][j])
                {
                    
                    b[i][j]=v[i-1]+b[i-1][j-w[i-1]];
                
                }
                else
                {
                
                    b[i][j]=b[i-1][j];  
                
                }
            }
            else
            {
            
                b[i][j]=b[i-1][j];  
                
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    i=n,j=k;
    while(i>0 && j>0)
    {
        if(b[i][j]!=b[i-1][j])
        {
            printf("%d %d\n",w[i-1],v[i-1]);
            i=i-1,j=j-w[i-1];
        }
        else
        {
            i=i-1;
        }
    }
        return 0;
}
