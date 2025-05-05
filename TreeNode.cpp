#include "TreeNode.hpp"

TreeNode::TreeNode(std::string name, std::shared_ptr<TreeNode> parent, uint32_t dist) :
    _name(name),
    _dist(dist),
    _parent(parent)
{}

std::shared_ptr<TreeNode> TreeNode::make(std::string name, std::shared_ptr<TreeNode> parent, uint32_t dist)
{
    return std::shared_ptr<TreeNode>(new TreeNode(name, parent, dist));
}

std::shared_ptr<TreeNode> TreeNode::make_with_children(std::string name, std::vector<std::shared_ptr<TreeNode>>&& children, std::shared_ptr<TreeNode> parent, uint32_t dist)
{
    std::shared_ptr<TreeNode> node = make(name, parent, dist);
    
    for (auto& child : children)
    {
        child->set_parent(node);
    }

    node->_children = std::move(children);
    return node;
}

std::string TreeNode::to_string() const
{
    return _name;
}

void TreeNode::set_parent(std::weak_ptr<TreeNode> parent, uint32_t dist)
{
    _parent = parent;
    _dist = dist;
}

void TreeNode::add_child(std::shared_ptr<TreeNode> child, uint32_t dist)
{
    child->set_parent(shared_from_this(), dist);
    _children.push_back(child);
}
