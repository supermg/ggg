#include <limits.h>
#include "tree.h"
#include "gtest\gtest.h"




TEST(treetest,test1)
{
	char tree_a[30]="abc";
	char tree_b[30]="cba";
	EXPECT_EQ(4,tree(2,tree_a,tree_b));
}

TEST(treetest,test2)
{
	char tree_a[30]="abc";
	char tree_b[30]="bca";
	EXPECT_EQ(1,tree(2,tree_a,tree_b));
	
}

TEST(treetest,test3)
{
	char tree_a[30]="abejkcfghid";
	char tree_b[30]="jkebfghicda";
	EXPECT_EQ(207352860,tree(13,tree_a,tree_b));
}