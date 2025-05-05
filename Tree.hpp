#pragma once

#include <cstdint>
#include <string>
#include <memory>

#include "TreeNode.hpp"

class Tree
{
public:
    explicit Tree(std::shared_ptr<TreeNode> root);
    virtual ~Tree() = default;

    bool is_name_in_tree(std::string name) const;

    std::vector<std::shared_ptr<TreeNode>> get_nodes_preorder();

    std::string to_newick() const;

private:
    std::shared_ptr<TreeNode> _root;
};