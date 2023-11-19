#ifndef LIB_MYSTRING_H_
#define LIB_MYSTRING_H_

#include <ctype.h>
#include <memory.h>
#include <stddef.h>
#include <stdlib.h>
#include <string>

#include "lib_config.h"

#include "my_assert.h"
#include "my_typedefs.h"
#include "recalloc.h"

//lib_config-----------------------------------------------------------------------

static const size_t kStrMinAlloc = 16ul;
static const size_t kStrMultiplier = 2;
// static const size_t kStrMemRequest = 3;
// static const size_t kStrMaxSize    = 4096;

//-----------------------------------------------------------------------------

enum class StringError {
  kSuccess   = 1,
  kCantAlloc = 2,
};

struct String {
 public:
  StringError Ctor(const char* origin = "",
                   const size_t min_alloc = kStrMinAlloc);
  void Dtor();

  bool IsEmpty();
  size_t Size();
  size_t Length();
  size_t Capacity();

  StringError Reserve(size_t new_cap);
  StringError Resize(size_t new_cap);
  StringError ShrinkToFit();
  StringError Clear();

  char* At(Index ind);
  const char* CStr();
  const char* Data();

  StringError Append(String* add_str);
  StringError Append(const char* add_str);
  //TODO add other Append overloads
  StringError PushBack(char ch);
  char PopBack();
  StringError Assign(String* str);
  StringError Assign(const char* str);
  //TODO add other Assign overloads
  //TODO Insert
  //TODO Erase
  //TODO Swap
 private:
  char* data_;
  size_t size_;
  size_t cap_;

  StringError Append(size_t add_size, const char* add_str);
};

struct StringView {
 public:
  void Ctor(const char* origin);
  void Ctor(const char* origin, size_t len);
  void Dtor();

  bool IsEmpty();
  size_t Size();
  size_t Length();

  const char* At(Index ind);
  const char* Data();
 private:
  const char* data_;
  size_t size_;
};

#endif // LIB_MYSTRING_H_
