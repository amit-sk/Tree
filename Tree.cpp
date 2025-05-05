#include "Tree.hpp"

Tree::Tree(std::shared_ptr<TreeNode> root) :
    _root(root)
{}

bool Tree::is_name_in_tree(std::string name) const
{
    return _root->is_name_in_subnodes(name);
}

std::vector<std::shared_ptr<TreeNode>> Tree::get_nodes_preorder()
{
    std::vector<std::shared_ptr<TreeNode>> vec;
    _root->get_nodes_preorder(vec);
    return vec;
}

std::string Tree::to_newick() const
{
    return _root->to_newick();
}
