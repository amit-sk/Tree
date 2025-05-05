#pragma once

#include <cstdbool>
#include <string>
#include <vector>
#include <memory>

class TreeNode : public std::enable_shared_from_this<TreeNode> 
{
private:
    explicit TreeNode(std::string name, std::shared_ptr<TreeNode> parent = nullptr, double dist = 0);

public:
    virtual ~TreeNode() = default;

    static std::shared_ptr<TreeNode> make_with_children(std::string name, std::vector<std::shared_ptr<TreeNode>>&& children, std::shared_ptr<TreeNode> parent = nullptr, double dist = 0);
    static std::shared_ptr<TreeNode> make(std::string name, std::shared_ptr<TreeNode> parent = nullptr, double dist = 0);

    std::string to_string() const;
    std::string to_newick() const;
    bool is_leaf() const;
    bool is_name_in_subnodes(std::string name) const;

    void get_nodes_preorder(std::vector<std::shared_ptr<TreeNode>>& vec);

    void set_parent(std::weak_ptr<TreeNode> parent, double dist = 0);
    void add_child(std::shared_ptr<TreeNode> child, double dist = 0);

private:
    std::string _name;
    double _dist;
    std::weak_ptr<TreeNode> _parent;
    std::vector<std::shared_ptr<TreeNode>> _children;
};
