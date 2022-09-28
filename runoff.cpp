#include <cstdio>
#include <iostream>
#include <string>
#include <typeinfo>

#define MAX_VOTERS 10
#define MAX_CANDIDATES 9

using namespace std;


typedef struct {
  string name;
  int votes;
  bool eliminated;
}
candidate;


candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];


// functions

// 1 - VOTE
bool vote(int voter, int rank, string names);
// -look for candidate 'name'
// -update preference, return true
// -else return false

// 2- TABULATE
void tabulate(int vote);
// -update vote counts for non eliminated
// -choose next preference if first preference eliminated

// 3- PRINT_WINNER
bool print_winner(int vote);
// -if candidates has more than half total vote, print their name and return true
// -else return false

// 4- FIND_MIN
int find_min(void);
// -return the minimum number of vote

// 5- IS_TIE
bool is_tie(int min);
// -if remaining candidates except min has same vote return true
// -else return false

// 6- ELIMINATE
void eliminate(int min);
// -eliminate everyone who has the min number of votes


// argc argv get cmd arg
int main(int argc, char **argv) {

  // make sure cmd arg true
  if (argc < 2) {
    cout << "Missing command-line.\n";
    exit(0);
  }

  // populate candidates
  for (int i = 0; i < argc - 1; i++) {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
    candidates[i].eliminated = false;
  }

  // get number of votes
  int votes;
  cout << "Number of votes: ";
  cin >> votes;

  // loop over number of votes
  for (int v = 0; v < votes; v++) {

    // loop over cmd arg
    for (int i = 1; i < argc; i++) {

      // get voted name
      string name;
      cout << "Vote " << i << ": ";
      cin >> name;

      // call vote function
      vote(v,i - 1,name);
    }

    // spacing
    cout << endl;
  }

  tabulate(votes);

  if (is_tie(find_min())) {
      eliminate(find_min());
      tabulate(votes);
  }

  print_winner(votes);
}


bool vote(int voter, int rank, string names) {

  // loop over all candidates
  for (int i = 0; i < MAX_CANDIDATES; i++) {

    // if there is candidate and name found in candidates array
    if (candidates[i].name != "" && names == candidates[i].name) {

      // update preferences
      preferences[voter][rank] = i;
      return true;
    }
  }

  // return false and do not update nun
  return false;
}


void tabulate(int vote) {

  // loop over voters
  for (int i = 0; i < vote; i++) {

    // loop over candidates
    int j = 0;
    while(candidates[j].name != "") {

      // if candidates not eliminated
      if (candidates[preferences[i][j]].eliminated != true) {

        //update votes
        candidates[preferences[i][j]].votes++;
        break;
      }
      j++;
    }
  }
}


bool print_winner(int vote) {

  // loop over candidates
  for (int i = 0; i < MAX_CANDIDATES; i++) {

    // if candidates vote > half total votes
    if (candidates[i].name != "" && candidates[i].votes > vote/2) {

      // print candidates name and reutn true
      cout << candidates[i].name << endl;
      return true;
    }
  }
  return false;
}


int find_min(void) {
  
  // val to return
  int min;

  // loop over candidates
  for (int i = 0; i < MAX_CANDIDATES; i++) {

    // find min
    if (candidates[i].name != "" && candidates[i].votes < candidates[0].votes) {
      min = candidates[i].votes;
    }
    else min = candidates[0].votes;
  }

  // return min
  return min;
}


bool is_tie(int min) {

  // empty array
  int arr[MAX_CANDIDATES];

  // count tie
  int count = 0;
  
  // loop over candidats
  for (int i = 0; i < MAX_CANDIDATES; i++) {

    // if candidates vote not min
    if (candidates[i].votes != min && candidates[i].name != "") {

      // fill emmpty array
      arr[i] = candidates[i].votes;
    }

    else arr[i] = 0;
  }

  // loop over candidates
  for (int i = 0; i < MAX_CANDIDATES; i++) {

    // check the ones onot null only
    if (arr[i] != NULL) {

      // loop again
      for (int j = 0; j < MAX_CANDIDATES; j++) {

        // compare each el in array
        if (arr[j] != NULL && arr[i] != arr[j]) {
          count++;
        }
      }
    }
  }

  // if count more than one it means, there is a tie
  if (count > 0) return false;
  
  return true;
}

void eliminate(int min) {

  // loop over canddiates
  for (int i = 0; i < MAX_CANDIDATES; i++) {

    // find min vote and make sure not to go out of range
    if (candidates[i].name != "" && candidates[i].votes == min) {

      // eliminates candidate when found
      candidates[i].eliminated = true;
    }
  }
}
