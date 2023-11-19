#include <stdio.h>
#include <string.h>

#include "lib_config.h"
#include "b_tree.h"

int main() {
  BTree tree = {};
  tree.Ctor();

  tree.Insert(10);
  tree.Insert(8);
  tree.Insert(2);
  tree.Insert(15);
  tree.Insert(20);
  tree.Insert(15);

  tree.LoadToFile(stdout);

  // tree.Traversal(&DataPrint);

  tree.Dtor();

  return 0;
}
