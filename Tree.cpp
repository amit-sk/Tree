#include "Tree.hpp"

Tree::Tree(std::unique_ptr<TreeNode> root) :
    _root(std::move(root))
{}
