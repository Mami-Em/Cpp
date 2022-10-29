#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(void) {

  // dynamically allocation
  int *list = (int *)malloc(3 * sizeof(int));

  // in case there is no more memory
  if (list == NULL) {
    return 1;
  }

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // new allocation
  int *tmp = (int *)realloc(list, 4 * sizeof(int));

  if (tmp == NULL) {
    free(list);
    return 1;
  }

  // add new val to list
  tmp[3] = 4;

  list = tmp;

  cout << list[2] << endl;
  free(list);
}
