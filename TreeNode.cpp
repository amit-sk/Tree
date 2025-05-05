#include "TreeNode.hpp"

TreeNode::TreeNode(std::string name, std::unique_ptr<std::vector<std::unique_ptr<TreeNode>>> children, std::optional<TreeNode&> parent, uint32_t dist) :
    _name(name),
    _dist(dist)
{
    if (children.has_value())
    {
        _children = std::move(children.);
    }
    if (parent.get() != nullptr)
    {
        _parent = std::move(parent);
    }
}

std::string TreeNode::to_string() const
{
    return _name;
}

void TreeNode::set_parent(std::unique_ptr<TreeNode> parent, uint32_t dist)
{
    _parent = std::move(parent);
    _dist = dist;
}

void TreeNode::set_children(std::unique_ptr<std::vector<TreeNode>> children)
{
    _children = std::move(children);
}

void TreeNode::add_child(std::unique_ptr<TreeNode> child)
{
    // _children->push_back(*child);
}
