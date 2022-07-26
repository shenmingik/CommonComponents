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
  ~SkipList();

  /**
   * @brief 判断当前key是否存在于跳表之中
   *
   * @param[in] key key
   * @return true 存在
   * @return false 不存在
   */
  bool IsExist(std::string key);

  /**
   * @brief 得到key对应的value
   *
   * @param[in] key key
   * @return std::string value
   */
  std::string Get(std::string key);

  /**
   * @brief 往跳表中放入key，value
   * 注：当key不存在的时候为Add语义，当key存在的时候为Update语义
   *
   * @param[in] key key
   * @param[in] value value
   */
  void Put(std::string key, std::string value);

  /**
   * @brief 删除key
   *
   * @param[in] key key
   */
  void Delete(std::string key);

 private:
  SkipListNode *head_;  //头节点
  int level_;  // level记录当前跳表中除了第一层的最高层元素

 private:
  //用于生成随机数
  std::mt19937 gen{std::random_device{}()};
  std::uniform_real_distribution<double> dis;

  int RandomLevel();
};