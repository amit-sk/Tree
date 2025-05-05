#include <iostream>
#include <memory>

#include "Tree.hpp"
#include "TreeNode.hpp"

int main()
{
    // building from the bottom up
    std::shared_ptr<TreeNode> N3 = TreeNode::make(std::string("N3"));

    std::shared_ptr<TreeNode> N1 = TreeNode::make(std::string("N1"));
    N1->add_child(TreeNode::make(std::string("Tal")), 2);
    N1->add_child(TreeNode::make(std::string("Noam")), 3);

    std::shared_ptr<TreeNode> N2 = TreeNode::make(std::string("N2"), N3, 1.5); // setting parent, but parent will not know child
    N2->add_child(N1, 1);
    N2->add_child(TreeNode::make(std::string("Ben")), 4);

    N3->add_child(N2, 1.5);
    N3->add_child(TreeNode::make(std::string("Dana")), 6);

    Tree tree(N3);

    std::cout << std::boolalpha << "is Ben in tree: " << tree.is_name_in_tree("Ben") << std::endl;
    std::cout << std::boolalpha << "is Michael in tree: " << tree.is_name_in_tree("Michael") << std::endl;

    // exact order depends on the order of insertion to the tree.
    auto vec = tree.get_nodes_preorder();
    for (auto& node : vec)
    {
        std::cout << node->to_string() << std::endl;
    }

    std::cout << tree.to_newick() << std::endl;

    // Example - make with children. does not support giving distances.
    std::shared_ptr<TreeNode> N4 = TreeNode::make_with_children(std::string("N4"), {N3});
    return 0;
}
