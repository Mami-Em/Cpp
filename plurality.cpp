#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define MAX 10

// our data
typedef struct {
  string name;
  int votes;
} candidate;

candidate candidates[MAX];

bool vote(string names);
// look for a candidate called name
// if vote found, update votes and return true
// else, no update and return false

void print_winner(void);
// candidates with the most votes

int main(int argc, char **argv) {

  // check for cmd
  if (argc < 2) {
    cout << "Missing command-line\n";
  }

  // Populate candidates
  for (int i = 0; i < argc - 1; i++) {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
  }

  // prompt user for number of votes
  int number_of_votes;

  cout << "Number of votes: ";
  cin >> number_of_votes;

  // loop
  for (int i = 0; i < number_of_votes; i++) {
    // get names
    string names;
    cout << "Vote: ";
    cin >> names;

    // vote function
    vote(names);
  }

  // print winner function
  print_winner();

  return 0;
}

bool vote(string names) {
  for (int i = 0; i < MAX; i++) {

    if (candidates[i].name != "") {

      if (candidates[i].name.compare(names) == 0) {

        candidates[i].votes++;
        return true;
      }
    }
  }

  return false;
}

void print_winner(void) {
  for (int i = 0; i < MAX; i++) {
    
    if (candidates[i].name != "") {
      
      if (candidates[i].votes > candidates[0].votes) {
        
        candidates[0] = candidates[i];
      }
    }
  }

  cout << candidates[0].name << endl;
}
