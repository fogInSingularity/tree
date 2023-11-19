#ifndef LIB_MYASSERT_H_
#define LIB_MYASSERT_H_

#include <stdio.h>

#include "lib_config.h"

#include "color.h"

#ifdef ASSERT_ON
#define ASSERT(expr)                                                          \
  if ((expr) == 0) {                                                          \
    fprintf(stderr, BOLD RED "#  ERROR:\n");                                  \
    fprintf(stderr,          "#    %s\n", #expr);                             \
    fprintf(stderr,          "#    file: %s\n", __FILE__);                    \
    fprintf(stderr,          "#    func: %s\n" RESET, __PRETTY_FUNCTION__);   \
    abort();                                                                  \
    }
#else
#define ASSERT(expr) ;
#endif // ASSERT_ON

#endif // LIB_MYASSERT_H_
