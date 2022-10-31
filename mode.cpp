#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#define NULL __null

int square(int a);

int search(int x, int *list, int len);

int find_max(int *list, int len);
int find_min(int *list, int len);

void find_mode(int *list, int len);
void find_range(int *list, int len);

double find_mean(int *list, int len);
double find_median(int *list, int len);

double find_midrange(int *list, int len);
double variance_s2(int *list, int len);

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
  find_mode(list, len);

  // find range
  find_range(list, len);

  // find mean
  cout << "Mean: " << find_mean(list, len) << endl;

  // find median
  cout << "Median: " << find_median(list, len) << endl;

  // find midrange
  cout << "Midrange: " << find_midrange(list, len) << endl;

  //variance S2
  cout << "Variance S2: " << variance_s2(list, len) << endl;

  // print arr
  cout << "\nNew arr: " << endl;
  for (int i = 0; i <len; i++) {
    cout << list[i] << " ";
  }

  cout << endl;

  // free space
  free(list);
}

void find_mode(int *list, int len) {
  // find the value that appears the most
  int *tmp = list;

  int max = 0;
  int mode;

  int i = 0;
  while (tmp[i]) {

    int max_found = search(tmp[i], tmp, len);

    // if repetition of the number is highest than max
    if (max_found > max) {
      max = max_found;
      mode = tmp[i];
    }

    i++;
  }

  max >= 2 ? cout << "Mode: " << mode << endl : cout << "No mode" << endl;
}

int search(int x, int *list, int len) {
  int found = 0, i = 0;

  // linear search for how many of x inside a the list
  while (list[i]) {
    if (list[i] == x) {
      found++;
    }

    i++;
  }

  // cout << x << " repeated " << found << endl;
  return found;
}

int find_min(int *list, int len) {
  int min = find_max(list, len);
  
  for (int i = 0; i < len; i++) {
    
    if(list[i] < min) {
      
      min = list[i];
    }
  }

  return min;
}

int find_max(int *list, int len) {
  int max = 0;
  
  for (int i = 0; i < len; i++) {
    
    if(list[i] > max) {
      
      max = list[i];
    }
  }

  return max;
}

void find_range(int *list, int len) {
  cout << "Range: " << find_max(list, len) - find_min(list, len) << endl;
}

double find_mean(int *list, int len) {
  double sum = 0;
  for (int i = 0; i < len; i++) {
    sum += list[i];
  }

  double val = sum/len;

  return val;
}

double find_median(int *list, int len) {
  int index = 0;

  sort(list, list + len);
  
  for (int i = 1; i < len; i++) {
    index++;
  }
  
  // if len not an odd number
  if (index & 1) {
    return ((double)list[(len/2) - 1] + (double)list[len/2]) / 2;
  }

  return list[index/2];
}

double find_midrange(int *list, int len) {
  return ((double)find_max(list, len) + (double)find_min(list, len)) / 2;
}

double variance_s2(int *list, int len) {
  int x_bar = find_mean(list, len);

  int sum = 0;
  for (int i =0; i < len; i++) {
    sum += square(list[i] - x_bar);
  }

  return (double)sum/(len - 1);
}

int square(int a) {
  return a * a;
}
