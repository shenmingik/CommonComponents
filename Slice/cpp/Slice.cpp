#include "Slice.h"

Slice::Slice() : data_(""), size_(0) {}
Slice::Slice(const char *data, size_t size) : data_(data), size_(size) {}
Slice::Slice(const std::string &str) : data_(str.data()), size_(str.size()) {}
Slice::Slice(const char *data) : data_(data), size_(strlen(data)) {}

const char *Slice::Data() const { return data_; }

size_t Slice::Size() const { return size_; }

bool Slice::Empty() const { return size_ == 0; }

char Slice::operator[](size_t index) const {
  assert(index < Size());
  return data_[index];
}

void Slice::Clear() {
  data_ = "";
  size_ = 0;
}

/**
 * @brief 移除前缀n个元素
 *
 * @param[in] prefix_size
 */
void Slice::RemovePrefix(size_t prefix_size) {
  assert(prefix_size <= Size());
  data_ += prefix_size;  //指针向前移动n个字符
  size_ -= prefix_size;  //长度减n}
}

/**
 * @brief 转换为标准string
 *
 * @return std::string
 */
std::string Slice::ToString() const { return std::string(data_, size_); }

int Slice::CompareWith(const Slice &other) const {
  const size_t min_len = (size_ < other.size_) ? size_ : other.size_;
  int r = memcmp(data_, other.data_, min_len);
  if (r == 0) {  //字符串相等的情况下，可能长度不一样，所以也要进行判断。
    if (size_ < other.size_)
      r = -1;
    else if (size_ > other.size_)
      r = +1;
  }
  return r;
}

bool Slice::StandWith(const Slice &other) const {
  return ((size_ >= other.size_) &&
          (memcmp(data_, other.data_, other.size_) == 0));
}