#include "SegmentTree.h"

void SegmentTree::Update(int index, int value) { UpdateSub(1, index, value); }

void SegmentTree::RangeUpdate(int left, int right, int add) {
  RangeUpdateSub(1, left, right, add);
}

int SegmentTree::RangeQuery(int left, int right) {
  return RangeQuerySub(1, left, right);
}

void SegmentTree::BuildTree(int id, int left, int right,
                            std::vector<int>& nums) {
  tree_[id].left_edge_ = left;
  tree_[id].right_edge_ = right;

  if (left == right) {
    tree_[id].sum_ = nums[left];
    return;
  }

  int middle = (left + right) / 2;
  BuildTree(2 * id, left, middle, nums);
  BuildTree(2 * id + 1, middle + 1, right, nums);

  tree_[id].sum_ = tree_[2 * id].sum_ + tree_[2 * id + 1].sum_;
  return;
}

void SegmentTree::UpdateSub(int id, int index, int value) {
  if (tree_[id].left_edge_ == index && tree_[id].right_edge_ == index) {
    tree_[id].sum_ = value;
    return;
  }

  int middle = (tree_[id].left_edge_ + tree_[id].right_edge_) / 2;
  if (index <= middle) {
    UpdateSub(2 * id, index, value);
  } else {
    UpdateSub(2 * id + 1, index, value);
  }
  tree_[id].sum_ = tree_[2 * id].sum_ + tree_[2 * id + 1].sum_;
  return;
}

void SegmentTree::LazyDown(int id) {
  if (tree_[id].lazy_tag_ != 0) {
    int lazy_tag = tree_[id].lazy_tag_;
    tree_[2 * id].lazy_tag_ += lazy_tag;
    tree_[2 * id].sum_ =
        lazy_tag * (tree_[2 * id].right_edge_ - tree_[2 * id].left_edge_ + 1);
    tree_[2 * id + 1].lazy_tag_ += lazy_tag;
    tree_[2 * id].sum_ = lazy_tag * (tree_[2 * id + 1].right_edge_ -
                                     tree_[2 * id + 1].left_edge_ + 1);
    //？
    tree_[id].lazy_tag_ -= lazy_tag;
  }
  return;
}

void SegmentTree::RangeUpdateSub(int id, int left, int right, int add) {
  if (tree_[id].left_edge_ >= left && tree_[id].right_edge_ <= right) {
    //区间完全覆盖
    tree_[id].sum_ +=
        (add * (tree_[id].right_edge_ - tree_[id].left_edge_ + 1));
    tree_[id].lazy_tag_ += add;
    return;
  }

  LazyDown(id);
  if (tree_[2 * id].right_edge_ >= left) {
    //左孩子有交集
    RangeUpdateSub(2 * id, left, right, add);
  }

  if (tree_[2 * id + 1].left_edge_ <= right) {
    //右孩子有交集
    RangeUpdateSub(2 * id + 1, left, right, add);
  }
  tree_[id].sum_ = tree_[2 * id].sum_ + tree_[2 * id + 1].sum_;
  return;
}

int SegmentTree::RangeQuerySub(int id, int left, int right) {
  if (tree_[id].left_edge_ >= left && tree_[id].right_edge_ <= right) {
    return tree_[id].sum_;
  }
  if (tree_[id].right_edge_ < left || tree_[id].left_edge_ > right) {
    return 0;
  }

  LazyDown(id);
  int sum = 0;
  if (tree_[2 * id].right_edge_ >= left) {
    sum += RangeQuerySub(2 * id, left, right);
  }

  if (tree_[2 * id + 1].left_edge_ <= right) {
    sum += RangeQuerySub(2 * id + 1, left, right);
  }
  return sum;
}