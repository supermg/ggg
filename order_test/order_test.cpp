#include <limits.h>
#include "order.h"
#include "gtest\gtest.h"

int ii=0;
TEST(Ordertest,test1)
{
	int a[4]={4,15,10,26};
	int b[4]={4,10,15,26};
	int ii;
	order(4,a);
	ii=0;
	while(shu[ii]==b[ii]&&ii<4)
		ii++;
	EXPECT_EQ(4,ii);
}

TEST(Ordertest,test2)
{
	int a[9]={9,8,7,6,5,4,3,2,1};
	int b[9]={1,2,3,4,5,6,7,8,9};
	int ii;
	order(9,a);
	ii=0;
	while(shu[ii]==b[ii]&&ii<9)
		ii++;
	EXPECT_EQ(9,ii);
}

TEST(Ordertest,test3)
{
	int a[6]={4,15,10,26,11,18};
	int b[6]={4,10,11,15,18,26};
	int ii;
	order(6,a);
	ii=0;
	while(shu[ii]==b[ii]&&ii<6)
		ii++;
	EXPECT_EQ(6,ii);
}