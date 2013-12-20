#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "tree.h"

int m;

int tree (int x, char *pre, char *post)
{
	m=x;
	int len;
	int k;
	if (m==0)
		return 0;
	else
	{
		len=strlen(pre);
		k=tree_search(len,pre,post);
		return k;
	}

}

int C_num(int x, int y) /* C(x,y)的计算*/
{
	int sum=1;
	int j;
	for (j=1;j<=y;j++)
		sum=sum*(x-j+1)/j;
	return sum;
}

int tree_search(int l, char *pre, char *post) /* 利用递归 求sum, l is the length, pre 是先序数列的指针, post 是后序的指针*/
{
	int child=0;
	int sum=1;
	int left=1;
	int right=0;
	while (left<l)
	{
		++child;
		while (post[right]!=pre[left])
			++right;
		sum=sum*tree_search(right+2-left,pre+left,post+left-1);
		left=right+2;
	}
	sum=sum*C_num(m,child);
	return sum;
}
