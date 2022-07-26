#pragma once

#include <random>
#include <string>
#include <vector>
#define DEFAULT_MAX_LEVEL 10
#define DEFAULT_FACTOR 0.25

struct SkipListNode {
  std::string key_;
  std::string value_;
  std::vector<SkipListNode *> next_;

  SkipListNode(std::string key, std::string value,
               int max_level = DEFAULT_MAX_LEVEL)
      : key_(key), value_(value), next_(max_level, nullptr) {}
};

class SkipList {
 public:
  SkipList();

  bool IsExist(std::string key);

  std::string Get(std::string key);

  void Put(std::string key, std::string value);

  void Delete(std::string key);

 private:
  SkipListNode *head_;
  int level_;   //level记录当前跳表中除了第一层的最高层元素

 private:
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis;

  int RandomLevel();
};