#include <iostream>
#include <memory>

#include "Tree.hpp"
#include "TreeNode.hpp"

int main()
{
    // building from the bottom up
    std::shared_ptr<TreeNode> N3 = TreeNode::make(std::string("N3"));
    N3->add_child(TreeNode::make(std::string("Dana")), 6);

    std::shared_ptr<TreeNode> N1 = TreeNode::make(std::string("N1"));
    N1->add_child(TreeNode::make(std::string("Tal")), 2);
    N1->add_child(TreeNode::make(std::string("Noam")), 3);

    std::shared_ptr<TreeNode> N2 = TreeNode::make(std::string("N2"), N3, 1.5); // setting parent, but parent will not know child
    N2->add_child(TreeNode::make(std::string("Ben")), 4);
    N2->add_child(N1, 1);
    N3->add_child(N2, 1.5);

    // Example - make with children. does not support giving distances.
    std::shared_ptr<TreeNode> N4 = TreeNode::make_with_children(std::string("N4"), {N3});
    return 0;
}
