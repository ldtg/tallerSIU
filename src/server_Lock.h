#ifndef TP2_APP_LOCK_H
#define TP2_APP_LOCK_H

#include <mutex>
class Lock {
 private:
  std::mutex &m;
 public:
  explicit Lock(std::mutex &m);
  ~Lock();
  Lock(const Lock&) = delete;
  Lock& operator=(const Lock&) = delete;
  Lock(Lock&&) = delete;
  Lock& operator=(Lock&&) = delete;
};

#endif //TP2_APP_LOCK_H
