#include <algorithm>
#include "TreeNode.hpp"

TreeNode::TreeNode(std::string name, std::shared_ptr<TreeNode> parent, double dist) :
    _name(name),
    _dist(dist),
    _parent(parent)
{}

std::shared_ptr<TreeNode> TreeNode::make(std::string name, std::shared_ptr<TreeNode> parent, double dist)
{
    return std::shared_ptr<TreeNode>(new TreeNode(name, parent, dist));
}

std::shared_ptr<TreeNode> TreeNode::make_with_children(std::string name, std::vector<std::shared_ptr<TreeNode>>&& children, std::shared_ptr<TreeNode> parent, double dist)
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

std::string TreeNode::to_newick() const
{
    if (is_leaf())
    {
        return to_string();
    }

    std::string s = "(";
    for (size_t i = 0; i < _children.size(); i++)
    {
        s += _children[i]->to_newick() + ":" + std::to_string(_children[i]->_dist);
        if (i < _children.size() - 1)
        {
            s += ",";
        }
    }
    return s + ")";
}

bool TreeNode::is_leaf() const
{
    return _children.empty();
}

bool TreeNode::is_name_in_subnodes(std::string name) const
{
    return (_name == name) or std::any_of(_children.begin(), _children.end(), [name](std::shared_ptr<TreeNode> child) { return child->is_name_in_subnodes(name); });
}

void TreeNode::get_nodes_preorder(std::vector<std::shared_ptr<TreeNode>>& vec)
{
    vec.push_back(shared_from_this());
    for (auto& child : _children)
    {
        child->get_nodes_preorder(vec);
    }
}

void TreeNode::set_parent(std::weak_ptr<TreeNode> parent, double dist)
{
    _parent = parent;
    _dist = dist;
}

void TreeNode::add_child(std::shared_ptr<TreeNode> child, double dist)
{
    child->set_parent(shared_from_this(), dist);
    _children.push_back(child);
}
