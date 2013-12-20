#include <stdio.h>
#include <stdlib.h>

int index,len;
void exc (int *x,int *y);
void change(int a[],int len,int index);

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

int main ()
{
	int i;
	
	int *a;
	scanf("%d",&len);
	a = (int*)malloc(len*sizeof(int));
	for (i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
//	len1=len;


	
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
		printf("%d ",a[i]);
	}
	free(a);

}
