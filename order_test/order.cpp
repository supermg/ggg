#include <stdio.h>
#include <stdlib.h>
#include "order.h"

int shu[100];

void exc (int *x,int *y)
{
	int tem;
	tem=*x;
	*x=*y;
	*y=tem;
}
void change(int a[],int len,int index)
{
	int lf,rg,max;
	while (1)
	{	
		lf=2*index+1;
		rg=2*index+2;
		max=index;
		if (lf<len&&a[max]<a[lf])
		{				
			max=lf;
		}
		if (rg<len&&a[max]<a[rg])
		{
			max=rg;
		}
		if (max!=index)
		{
			exc(&a[max],&a[index]);
			index=max;
		}
		else
			break;
	}
}

void order (int len, int *b)
{
	int i;	
	int *a;
	a = (int*)malloc(len*sizeof(int));

	for (i=0;i<len;i++)
		a[i]=b[i];
	
	for (i=len/2;i>=0;i--)
	{
		change(a,len,i);

	}
	for (i=0;i<len;i++)
	{
		exc(&a[0],&a[len-1-i]);
		change(a,len-i-1,0);
	}
	for (i=0;i<len;i++)
	{
		shu[i]=a[i];
	}
	free(a);

}
