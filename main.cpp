#include <iostream>
#include <memory>

#include "Tree.hpp"
#include "TreeNode.hpp"

int main()
{
    // building from the bottom up
    std::unique_ptr<TreeNode> N3 = std::make_unique<TreeNode>(std::string("N3"));
    N3->add_child(std::make_unique<TreeNode>(std::string("Dana")), 6);

    std::unique_ptr<TreeNode> N1 = std::make_unique<TreeNode>(std::string("N1"));
    N1->add_child(std::make_unique<TreeNode>(std::string("Tal")), 2);
    N1->add_child(std::make_unique<TreeNode>(std::string("Noam")), 3);

    std::unique_ptr<TreeNode> N2 = std::make_unique<TreeNode>(std::string("N2"));
    N2->add_child(std::make_unique<TreeNode>(std::string("Ben")), 4);
    N2->add_child(std::move(N1), 1);
    N3->add_child(std::move(N2), 1.5);

    // Example - make with children
    // std::unique_ptr<TreeNode> Ex(TreeNode::make_with_children("N1", {std::move(Tal), std::move(Noam)}, std::move(Ben), 1).get());
    return 0;
}
