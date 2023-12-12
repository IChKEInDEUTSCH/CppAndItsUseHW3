#include <dbnode/dbnodeOperator.h>
#include <gtest/gtest.h>
#define NULL 0

TEST(nodeOperatorTests, TestReverse) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    dbNode* firstNode = new dbNode();
    dbNode* secondNode = new dbNode();
    dbNode* thirdNode = new dbNode();
    firstNode->name = "A";
    firstNode->eng = 100;
    firstNode->name = 100;
    firstNode->prev = NULL;
    firstNode->next = secondNode;
    secondNode->name = "B";
    secondNode->eng = 90;
    secondNode->math = 90;
    secondNode->prev = firstNode;
    secondNode->next = NULL;
    thirdNode->name = "C";
    thirdNode->eng = 80;
    thirdNode->name = 80;
    thirdNode->prev = secondNode;
    thirdNode->next = NULL;
    head_ref = firstNode;
    rear_ref = thirdNode;
    reverseAll(&head_ref, &rear_ref);
    const auto expected = "C";
    const auto actual = rear_ref->name;
    ASSERT_EQ(expected, actual);
}

TEST(nodeOperatorTests, TestPushNew) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    dbNode* firstNode = new dbNode();
    pushNew(&head_ref, &rear_ref, "A", 100, 100);
    pushNew(&head_ref, &rear_ref, "B", 90, 90);
    const auto expected = "B";
    const auto actual = head_ref->name;
    ASSERT_EQ(expected, actual);
}

TEST(nodeOperatorTests, TestAppendNew) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    appendNew(&head_ref, &rear_ref, "A", 100, 100);
    appendNew(&head_ref, &rear_ref, "B", 90, 90);
    const auto expected = "B";
    const auto actual = rear_ref->name;
    ASSERT_EQ(actual, expected);
}
TEST(nodeOperatorTests, TestAppendNewTreverseFromRear) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    appendNew(&head_ref, &rear_ref, "A", 100, 100);
    appendNew(&head_ref, &rear_ref, "B", 90, 90);
    appendNew(&head_ref, &rear_ref, "C", 80, 80);
    const auto expected = "A";
    dbNode* temp = rear_ref;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    const auto actual = temp->name;
    ASSERT_EQ(actual, expected);
}
TEST(nodeOperatorTests, TestExtractMiddle) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    appendNew(&head_ref, &rear_ref, "A", 100, 100);
    appendNew(&head_ref, &rear_ref, "B", 90, 90);
    appendNew(&head_ref, &rear_ref, "C", 80, 80);
    extract(&head_ref, &rear_ref, "B");
    const auto expected = "C";
    dbNode* temp = head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    const auto actual = temp->name;
    ASSERT_EQ(actual, expected);
}
TEST(nodeOperatorTests, TestExtractHead) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    appendNew(&head_ref, &rear_ref, "A", 100, 100);
    appendNew(&head_ref, &rear_ref, "B", 90, 90);
    appendNew(&head_ref, &rear_ref, "C", 80, 80);
    extract(&head_ref, &rear_ref, "A");
    const auto expected = "C";
    dbNode* temp = head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    const auto actual = temp->name;
    ASSERT_EQ(actual, expected);
}
TEST(nodeOperatorTests, TestExtractRear) {
    dbNode* head_ref = new dbNode();
    head_ref = NULL;
    dbNode* rear_ref = new dbNode();
    rear_ref = NULL;
    appendNew(&head_ref, &rear_ref, "A", 100, 100);
    appendNew(&head_ref, &rear_ref, "B", 90, 90);
    appendNew(&head_ref, &rear_ref, "C", 80, 80);
    extract(&head_ref, &rear_ref, "C");
    const auto expected = "B";
    dbNode* temp = head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    const auto actual = temp->name;
    ASSERT_EQ(actual, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
