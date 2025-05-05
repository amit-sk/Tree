#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <optional>

class TreeNode
{
public:
    explicit TreeNode(std::string name, std::optional<std::vector<std::unique_ptr<TreeNode>>> children = std::nullopt, std::optional<TreeNode&> parent = std::nullopt, uint32_t dist = 0);
    virtual ~TreeNode() = default;

    std::string to_string() const;

    void set_parent(TreeNode& parent, uint32_t dist);
    void set_children(std::vector<std::unique_ptr<TreeNode>>& children);
    void add_child(TreeNode& child);

private:
    std::string _name;
    std::vector<std::unique_ptr<TreeNode>> _children;
    std::unique_ptr<TreeNode> _parent;
    uint32_t _dist;
};
