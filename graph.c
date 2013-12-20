#include <stdio.h>



struct Graph
{
	char name;
	int cost;
	int visited;
	char next;
};

struct Graph fig[27][27],fig_test[27][27];


int main()
{

	int low_nod(int x, int y) ;
	int i,j;


//	int z; /*调试变量*/
	while (1)
	{

		int fig_sub_num[27],max_num; /* fig_sub_num 每个节点连接的节点数， max_num 图的总结点数*/
		int sum,x_nod,x_len,fig_test_num[27];
		char s;
		int n,m,x;
		int k=100;
		
		for (i=0;i<27;i++)
		{
			for (j=0;j<27;j++)
			{
				fig[i][j].name=9999;
				fig[i][j].cost=9999;
				fig[i][j].next=9999;
				fig[i][j].visited=0;
				fig_test[i][j].name=9999;
				fig_test[i][j].cost=9999;
				fig_test[i][j].next=9999;
				fig_test[i][j].visited=0;
			}
			fig_sub_num[i]=0;
			fig_test_num[i]=0;
		}
	

		sum=0;
		scanf("%d",&max_num);
		if (max_num==0)
			break;
		for (i=0;i<max_num-1;i++)
		{
	//		getchar();
			scanf("%s",&s);
	//		getchar();
			scanf("%d",&fig_sub_num[i]);
			if (fig_sub_num[i]==0)
				fig[i][0].name=s;
			for (j=0;j<fig_sub_num[i];j++)
			{
				fig[i][j].name=s;
//				getchar();
				scanf("%s%d",&fig[i][j].next,&fig[i][j].cost);
				fig[i][j].visited=0;
		
			}
		}

		for (i=0;i<max_num-1;i++)
		{
			n=0;
			for (j=0;j<fig_sub_num[i];j++)
			{
				if (fig[i][j].next==(fig[0][0].name+max_num-1))
				{
					m=fig_sub_num[max_num-1];
					fig[max_num-1][m].name=fig[i][j].next;
					fig[max_num-1][m].next=fig[i][j].name;
					fig[max_num-1][m].cost=fig[i][j].cost;
					fig[max_num-1][m].visited=0;
					fig_sub_num[max_num-1]=m+1;
				}
				else 
				{
					while (fig[i][j].next!=fig[n][0].name)
					{
						n++;
						if (n>max_num-1)
							break;
					}
					if (n<max_num-1&&n>i)
					{
						m=fig_sub_num[n];
						fig[n][m].name=fig[i][j].next;
						fig[n][m].next=fig[i][j].name;
						fig[n][m].cost=fig[i][j].cost;
						fig[n][m].visited=0;
						fig_sub_num[n]=m+1;
					}
				}
			}

		}


		x_nod=0;
		x_len=0;
		for(;x_len<max_num-1;)  /* x_len 新结构体的长度，x_nod要加入新结构体的位置 */
		{
			for (i=0;i<fig_sub_num[x_nod];i++)
			{
				fig_test[x_len][i].name=fig[x_nod][i].name;
				fig_test[x_len][i].next=fig[x_nod][i].next;
				fig_test[x_len][i].cost=fig[x_nod][i].cost;
				fig_test[x_len][i].visited=fig[x_nod][i].visited;
			}
			fig_test_num[x_len]=fig_sub_num[x_nod];
			x_len++;

			for (n=0;n<x_len;n++)
			{
				for (m=0;m<fig_test_num[n];m++)
				{
					if (fig_test[n][m].visited!=1&&k>fig_test[n][m].cost)
					{
						for (x=0;x<x_len;x++)
						{
							if (fig_test[x][0].name==fig_test[n][m].next)
								break;
						}
						if (x==x_len)
						{	
							k=fig_test[n][m].cost;
							x_nod=low_nod(n,m);  
							i=n;
							j=m;
						}
					}	
				}

			}
			fig_test[i][j].visited=1;
		//	kk=solve(fig_test[27][27],x_len);
			sum=sum+k;
			k=100;
		}
		printf("%d\n",sum);
	}
	return 0;
}

/* 判断每次进入新结构体的位置*/
int low_nod(int x, int y) 
{
	int a=0;
	while (fig[a][0].name!=fig_test[x][y].next)
		a++;
	return a;
		
}
