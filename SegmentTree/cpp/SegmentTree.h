#pragma once
#include <vector>

struct TreeNode {
 public:
  TreeNode(int left_edge = 0, int right_edge = 0, int sum = 0,
           int lazy_tag = 0)
      : left_edge_(left_edge),
        right_edge_(right_edge),
        sum_(sum),
        lazy_tag_(lazy_tag) {}

 public:
  int left_edge_;
  int right_edge_;
  int sum_;
  int lazy_tag_;
};

class SegmentTree {
 public:
  SegmentTree(std::vector<int>& nums) : tree_(nums.size() * 4) {
    BuildTree(1, 0, nums.size() - 1, nums);
  }

public:
    /**
     * @brief 修改单个索引的值
     * 
     * @param index 
     * @param value 
     */
    void Update(int index, int value);

    void RangeUpdate(int left, int right, int add);

    int RangeQuery(int left, int right);

private:
    //建树操作
    void BuildTree(int id, int left, int right, std::vector<int> &nums);

    void UpdateSub(int id, int index, int value);

    void RangeUpdateSub(int id, int left, int right, int add);

    void LazyDown(int id);

    int RangeQuerySub(int id, int left, int right);

private:
    std::vector<TreeNode> tree_;
};