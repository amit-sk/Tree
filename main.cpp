#include <iostream>

#include "Tree.hpp"
#include "TreeNode.hpp"

int main()
{
    TreeNode Tal = TreeNode(std::string("Tal"));
    TreeNode Noam = TreeNode(std::string("Noam"));
    TreeNode Ben = TreeNode(std::string("Ben"));
    TreeNode Dana = TreeNode(std::string("Dana"));

    std::cout << Tal.to_string() << std::endl;
    return 0;
}
