#ifndef LIB_TEXTFILE_H_
#define LIB_TEXTFILE_H_

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "lib_config.h"

#include "my_assert.h"
#include "my_string.h"
#include "debug.h"

struct FileData {
 public:
  char* buf_;
  size_t buf_sz_;

  StringView* text_;
  size_t n_lines_;

  void GetData(FILE* file);
  void PutData(FILE* file);
  void FreeData();
  void Dump();
 private:
  void FileRead(FILE* file);
  void CountLines();
  void FillText();
};

#endif // LIB_TEXTFILE_H_
