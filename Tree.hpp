#pragma once

#include <cstdint>
#include <string>
#include <memory>

#include "TreeNode.hpp"

class Tree
{
public:
    explicit Tree(std::unique_ptr<TreeNode> root);
    virtual ~Tree() = default;

private:
    std::unique_ptr<TreeNode> _root;
};