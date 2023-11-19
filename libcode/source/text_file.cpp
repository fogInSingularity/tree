#include "text_file.h"

//static-----------------------------------------------------------------------

static size_t FileSize(FILE* file);
static size_t CountChars(char* buf, char ch);

//public-----------------------------------------------------------------------

void FileData::GetData(FILE* file) {
  ASSERT(file != nullptr);

  buf_sz_ = FileSize(file) + 1;

  buf_ = (char*)calloc(buf_sz_, sizeof(char));

  FileRead(file);
  CountLines();

  text_ = (StringView*)calloc(n_lines_, sizeof(StringView));
  FillText();
}

void FileData::PutData(FILE* file) {
  for (size_t i = 0; i < n_lines_; i++) {
    for (size_t j = 0; j < text_[i].Size(); j++) {
      putc(*(text_[i].Data() + j), file);
    }
  }
}

void FileData::FreeData() {
  free(buf_);
  buf_ = nullptr;
  buf_sz_ = 0;

  free(text_);
  text_ = nullptr;
  n_lines_ = 0;
}

void FileData::Dump() {
  fprintf(stderr, "#  %lu\n", buf_sz_);
  fprintf(stderr, "#  %lu\n", n_lines_);
}

//private----------------------------------------------------------------------

void FileData::FileRead(FILE* file) {
  ASSERT(file != nullptr);

  fread(buf_, sizeof(char), buf_sz_, file);
  buf_[buf_sz_ - 1] = '\0';
}

void FileData::CountLines() {
  n_lines_ = CountChars(buf_, '\n');
  if (buf_[buf_sz_ - 2] != '\n') { n_lines_++; }
}

void FileData::FillText() {
  char* move = buf_;
  char* hold = buf_;

  StringView* moveView = text_;

  while (move < buf_ + buf_sz_) {
    if (*move == '\n') {
      moveView->Ctor(hold, (size_t)(move - hold + 1));

      moveView++;
      hold = move + 1;
    }

    move++;
  }

  // if (buf_[buf_sz_ - 2] != '\n') {
  //   moveView->Ctor(hold, (size_t)(move - hold - 2));
  //   n_lines_--;
  // } else {
  //   ;
  // }
}

//static-----------------------------------------------------------------------

static size_t FileSize(FILE* file) {
  ASSERT(file != nullptr);

  fseek(file, 0, SEEK_END);

  size_t size = (size_t)ftell(file);

  fseek(file, 0, SEEK_SET);

  return size;
}

static size_t CountChars(char* buf, char ch) {
  size_t counter = 0;
  while (*buf != '\0') {
    // if (*buf == ch) { counter++; }
    counter += (*buf == ch);
    buf++;
  }

  return counter;
}
