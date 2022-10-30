#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 100
#define NULL __null

void find_mode(int *list);
int search(int x, int *list);

int main() {

  // get the length of the set of numbers
  int len;
  cout << "Length: ";
  cin >> len;

  // create empty list where to store all the numbers later
  int *list;
  int *tmp = (int *)malloc(len * sizeof(int));

  // get the set of numbers
  cout << "List of set: " << endl;
  for (int i = 0; i < len; i++) {
    cin >> tmp[i];
  }

  // insert values into empty list
  list = tmp;

  // find mode
  // cout << search(2, list, len) << " found" << endl;
  find_mode(list);

  // print list components
  for (int i = 0; i < len; i++) {
    cout << list[i] << endl;
  }

  // free space
  free(list);
}

void find_mode(int *list) {
  // find the value that appears the most
  int *tmp = list;

  int max = 0;
  int mode, bimode;
  bool is_bimodal;

  int i = 0;
  while (tmp[i]) {

    int max_found = search(tmp[i], tmp);

    // if repetition of the number is highest than max
    if (max_found > max) {
      max = max_found;
      mode = tmp[i];
      is_bimodal = false;
    }
    i++;
  }
  cout << "Mode: " << mode << endl;
}

int search(int x, int *list) {
  int found = 0, i = 0;

  // linear search for how many of x inside a the list
  while (list[i]) {
    if (list[i] == x) {

      // list[i] = 0;
      found++;
    }

    i++;
  }

  return found;
}
