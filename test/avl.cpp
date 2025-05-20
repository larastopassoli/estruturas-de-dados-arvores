#include "../include/avl.hpp"
#include <gtest/gtest.h>
#include <vector>

using IntAVL = AVL<int>;

TEST(AVLTest, InsertAndContain) {
    IntAVL tree;
    EXPECT_TRUE(tree.insert(10));
    EXPECT_TRUE(tree.insert(5));
    EXPECT_TRUE(tree.insert(15));
    EXPECT_FALSE(tree.insert(10));  // Duplicado

    EXPECT_TRUE(tree.contain(10));
    EXPECT_TRUE(tree.contain(5));
    EXPECT_TRUE(tree.contain(15));
    EXPECT_FALSE(tree.contain(20));
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLTest, RemoveNodes) {
    IntAVL tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(25);
    tree.insert(35);

    EXPECT_TRUE(tree.remove(25));  // Remove folha
    EXPECT_TRUE(tree.remove(30));  // Remove com 1 filho
    EXPECT_TRUE(tree.remove(20));  // Remove com 2 filhos
    EXPECT_FALSE(tree.remove(99)); // Valor inexistente

    EXPECT_FALSE(tree.contain(20));
    EXPECT_FALSE(tree.contain(25));
    EXPECT_FALSE(tree.contain(30));
    EXPECT_TRUE(tree.contain(10));
    EXPECT_TRUE(tree.contain(35));
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLTest, InOrderTraversal) {
    IntAVL tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(25);
    tree.insert(35);

    std::vector<int> expected = {10, 20, 25, 30, 35};
    EXPECT_EQ(tree.in_order(), expected);
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLTest, PreOrderTraversal) {
    IntAVL tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);

    std::vector<int> result = tree.pre_order();
    EXPECT_EQ(result.front(), 20);
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLTest, PostOrderTraversal) {
    IntAVL tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);

    std::vector<int> result = tree.post_order();
    EXPECT_EQ(result.back(), 20);
}

TEST(AVLTest, TreeBalanceEmptyAndSingleNode) {
    IntAVL tree;
    EXPECT_TRUE(tree.is_balanced());

    tree.insert(10);
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLTest, TreeBalanceWithMultipleNodes) {
    IntAVL tree;
    for (int i : {30, 20, 40, 10, 25, 35, 50}) {
        tree.insert(i);
    }
    EXPECT_TRUE(tree.is_balanced());
}

// ---------- ROTAÇÕES AVL ----------

TEST(AVLRotationTest, RightRotation) {
    IntAVL tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);  // Rotação simples à direita

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(tree.in_order(), expected);
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLRotationTest, LeftRotation) {
    IntAVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);  // Rotação simples à esquerda

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(tree.in_order(), expected);
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLRotationTest, LeftRightRotation) {
    IntAVL tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(20);  // Rotação dupla à direita (esq-dir)

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(tree.in_order(), expected);
    EXPECT_TRUE(tree.is_balanced());
}

TEST(AVLRotationTest, RightLeftRotation) {
    IntAVL tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(20);  // Rotação dupla à esquerda (dir-esq)

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(tree.in_order(), expected);
    EXPECT_TRUE(tree.is_balanced());
}
