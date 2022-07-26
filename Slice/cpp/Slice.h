#pragma once
#include <assert.h>
#include <string.h>

#include <string>

#ifdef _WIN32
typedef unsigned long size_t;
#elif __linux__
#include <unistd.h>
#elif __APPLE__
typedef unsigned long size_t;
#endif

class Slice {
 public:
  Slice();
  Slice(const char *data, size_t size);
  Slice(const std::string &str);
  Slice(const char *data);

 public:
  const char *Data() const;

  size_t Size() const;

  bool Empty() const;

  char operator[](size_t index) const;

  void Clear();

  /**
   * @brief 移除前缀n个元素
   *
   * @param[in] prefix_size
   */
  void RemovePrefix(size_t prefix_size);

  /**
   * @brief 转换为标准string
   *
   * @return std::string
   */
  std::string ToString() const;

  /**
   * @brief 判断other是否是当前的开始元素
   *
   * @param[in] other 待比较的Slice
   * @return true
   * @return false
   */
  bool StandWith(const Slice &other) const;

 public:
  int CompareWith(const Slice &other) const;

 private:
  const char *data_;
  int size_;
};

// 重载==操作符，用于判断Slice==Slice
inline bool operator==(const Slice &x, const Slice &y) {
  return ((x.Size() == y.Size()) &&
          (memcmp(x.Data(), y.Data(), x.Size()) == 0));
}

// 重载不等于操作符
inline bool operator!=(const Slice &x, const Slice &y) { return !(x == y); }

// 重载==操作符，用于判断Slice==Slice
inline bool operator>(const Slice &x, const Slice &y) {
  return x.CompareWith(y) == 1;
}

// 重载不等于操作符
inline bool operator<(const Slice &x, const Slice &y) {
  return x.CompareWith(y) == -1;
}