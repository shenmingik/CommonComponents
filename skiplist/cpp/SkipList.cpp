#include "SkipList.h"

#include <iostream>
using namespace std;

SkipList::SkipList()
    : level_(0), head_(new SkipListNode("-1", "")), dis(0, 1) {}

int SkipList::RandomLevel() {
  int lv = 1;
  // 随机生成 lv
  while (dis(gen) < DEFAULT_FACTOR && lv < DEFAULT_MAX_LEVEL) {
    lv++;
  }
  return lv;
}

void SkipList::Put(std::string key, std::string value) {
  // update存储的是每一层为nullptr或者大于等于key的元素
  std::vector<SkipListNode *> update(DEFAULT_MAX_LEVEL, head_);
  SkipListNode *current = head_;

  for (int i = level_ - 1; i >= 0; i--) {
    /*
      两个退出条件：
      1. current->next[i] == nullptr表示此层遍历到最后也没有找到，转到下一层
      2. current->key_ >= key此时就代表找到了一个大于等于key的元素
    */
    while (current->next_[i] && current->next_[i]->key_ < key) {
      current = current->next_[i];
    }
    update[i] = current;
  }

  if (current->next_[0] && current->next_[0]->key_ == key) {
    //修改语义
    current->next_[0]->value_ = value;
  } else {
    //添加语义

    //生成这个node的高度，每个node的高度是随机的
    int random_level = RandomLevel();
    level_ = std::max(level_, random_level);

    SkipListNode *node = new SkipListNode(key, value, random_level);
    //插入其中
    for (int i = 0; i < random_level; i++) {
      node->next_[i] = update[i]->next_[i];
      update[i]->next_[i] = node;
    }
  }
}

std::string SkipList::Get(std::string key) {
  SkipListNode *current = head_;
  for (int i = level_ - 1; i >= 0; i--) {
    while (current->next_[i] && current->next_[i]->key_ < key) {
      current = current->next_[i];
    }
  }

  current = current->next_[0];
  if (current && current->key_ == key) {
    return current->value_;
  }
  return "";
}

bool SkipList::IsExist(std::string key) { return Get(key) != ""; }

void SkipList::Delete(std::string key)
{}