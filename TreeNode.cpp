#include "TreeNode.hpp"

TreeNode::TreeNode(std::string name, std::shared_ptr<TreeNode> parent, uint32_t dist) :
    _name(name),
    _dist(dist),
    _parent(parent)
{}

//make_with_children:
std::shared_ptr<TreeNode> TreeNode::make_with_children(std::string name, std::vector<std::unique_ptr<TreeNode>>&& children, std::shared_ptr<TreeNode> parent, uint32_t dist)
{
    std::shared_ptr<TreeNode> node = std::make_shared<TreeNode>(name, parent, dist);
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

void TreeNode::add_child(std::unique_ptr<TreeNode> child)
{
    _children.push_back(std::move(child));
}
