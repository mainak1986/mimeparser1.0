#include <string>
  using std::string;

#include "../mimeTree.h"
#include "../parserException.h"

#include <gmock/gmock.h>
  using ::testing::Eq;
#include <gtest/gtest.h>
  using ::testing::Test;


namespace testing
{
    class ParserTest : public Test
    {
    protected:
        ParserTest(){}
        ~ParserTest(){}

        virtual void SetUp(){}
        virtual void TearDown(){}
    };

    TEST(TreeTest, EmptyTreeCreate)
    {
      MimeTree tree; 
      EXPECT_EQ(tree.numberOfNodes(), 0);
    }

    TEST(TreeTest, OneNodeTree)
    {
      MimeTree tree("One", "Single");
      tree.addChild("Two", "Single");     
      EXPECT_TRUE(tree.getParent() == NULL);
      EXPECT_EQ(tree.numberOfNodes(), 1);
      EXPECT_EQ(tree.getChildAt(0)->numberOfNodes(), 0);
      EXPECT_EQ(tree.getChildAt(0)->getParent()->numberOfNodes(), 1);
      EXPECT_EQ(&tree, tree.getChildAt(0)->getParent());
    }
    
    TEST(TreeTest, MultipleNodes)
    {
      MimeTree tree("One", "Multi");
      EXPECT_EQ(tree.numberOfNodes(), 0);

      tree.addChild("Two", "Single");
      EXPECT_EQ(tree.numberOfNodes(), 1);
      ASSERT_TRUE(tree.getChildAt(0) != NULL);
      EXPECT_EQ(tree.getChildAt(0)->numberOfNodes(), 0);
      
      MimeTree *secondLevel1 = tree.addChild("Two", "Multi");
      EXPECT_EQ(tree.numberOfNodes(), 2);
      ASSERT_TRUE(tree.getChildAt(0) != NULL);
      ASSERT_TRUE(tree.getChildAt(1) != NULL);
      EXPECT_EQ(tree.getChildAt(1)->numberOfNodes(), 0);
     
      tree.addChild("Two", "Single");
      EXPECT_EQ(tree.numberOfNodes(), 3);
      ASSERT_TRUE(tree.getChildAt(2) != NULL);
      EXPECT_EQ(tree.getChildAt(2)->numberOfNodes(), 0);

      secondLevel1->addChild("Three", "Single");
      secondLevel1->addChild("Three", "Single");
      EXPECT_EQ(secondLevel1->numberOfNodes(), 2);
      EXPECT_EQ(tree.getChildAt(1)->numberOfNodes(), 2);

      EXPECT_EQ(secondLevel1, secondLevel1->getChildAt(0)->getParent());
    }

    TEST(TreeTest, GetChildOutOfBounds)
    {
      MimeTree tree("One", "Multi");
      EXPECT_THROW(tree.getChildAt(-1), ParserException);   
      EXPECT_THROW(tree.getChildAt(0), ParserException);   
      EXPECT_THROW(tree.getChildAt(3), ParserException);   

      tree.addChild("Two", "Single");
      EXPECT_EQ(tree.numberOfNodes(), 1);
      ASSERT_TRUE(tree.getChildAt(0) != NULL);
      EXPECT_THROW(tree.getChildAt(-1), ParserException);   
      EXPECT_THROW(tree.getChildAt(1), ParserException);   
      
      MimeTree *secondLevel1 = tree.addChild("Two", "Multi");
      tree.addChild("Two", "Single");
      secondLevel1->addChild("Three", "Single");
      secondLevel1->addChild("Three", "Single");
      EXPECT_THROW(tree.getChildAt(3), ParserException);   
      EXPECT_THROW(tree.getChildAt(1)->getChildAt(-1), ParserException);   
      EXPECT_THROW(tree.getChildAt(1)->getChildAt(2), ParserException);   

      ASSERT_TRUE(tree.getChildAt(1)->getChildAt(0) != NULL);
      ASSERT_TRUE(tree.getChildAt(1)->getChildAt(1) != NULL);
    }
}
