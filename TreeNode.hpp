#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <optional>

class TreeNode : public std::enable_shared_from_this<TreeNode> 
{
private:
    explicit TreeNode(std::string name, std::shared_ptr<TreeNode> parent = nullptr, uint32_t dist = 0);

public:
    virtual ~TreeNode() = default;

    static std::shared_ptr<TreeNode> make_with_children(std::string name, std::vector<std::shared_ptr<TreeNode>>&& children, std::shared_ptr<TreeNode> parent = nullptr, uint32_t dist = 0);
    static std::shared_ptr<TreeNode> make(std::string name, std::shared_ptr<TreeNode> parent = nullptr, uint32_t dist = 0);

    std::string to_string() const;
    bool is_leaf() const;

    void set_parent(std::weak_ptr<TreeNode> parent, uint32_t dist = 0);
    // void set_children(std::vector<std::shared_ptr<TreeNode>>&& children);
    void add_child(std::shared_ptr<TreeNode> child, uint32_t dist = 0);

private:
    std::string _name;
    uint32_t _dist;
    std::weak_ptr<TreeNode> _parent;
    std::vector<std::shared_ptr<TreeNode>> _children;
};
