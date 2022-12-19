///3
#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

struct State {
  unsigned short start, end; // both inclusive!
  int lvalue, rvalue;
  
  State *rparent;
};

void print(State* state) {
  cout << state->lvalue 
       << "." 
       << state->rvalue 
       << ": " 
       << state->start 
       << "-" 
       << state->end 
       << " " 
       << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    int sum = 0;
    
    vector<int> vs(n);
    for (int ni = 0; ni < n; ni++) {
      cin >> vs[ni];
      sum += vs[ni];
    }
    
    // states are ordered by how many coins were taken from
    // the beginning, states[0] means all coins were taken from
    // beginning
    // the number denotes my_score - opponent_score
    // we start with one state where we and opponent have zero score
    auto state_0 = new State();
    state_0->lvalue = 0;
    state_0->rvalue = 0;
    state_0->rparent = NULL;
    state_0->start = 0;
    state_0->end = n-1;
    vector<State*> prev_states = {};
    prev_states.push_back(state_0);
    vector<State*> cur_states = {};
    cur_states.push_back(state_0);
    for (int ni = 0; ni < n; ni++) {
      
      /*
      cout << endl;
      for (auto state : prev_states) {
        print(state);
      }
      */
      
      // ni denotes the amount of coins that were already taken
      // so this turn ni + 1 are taken
      bool myturn = ni % 2 == 0;
      int sign = myturn ? 1 : -1;
      
      // last round is special
      if (ni == n - 1) {
        // cur_states = prev_states + last remaining value
        for (auto& state : cur_states) {
          assert(state->start == state->end);
          state->rvalue += vs[state->start] * sign;
          state->lvalue += vs[state->start] * sign;
        }
        /*
        cout << endl;
        for (auto state : cur_states) {
          print(state);
        }
        */
        prev_states = cur_states;
        break;
      }
      
      
      // the possible ways to take x coins is x + 1
      cur_states = vector<State*>(ni+2); // else do reserve
      
      // I think this makes sense
      // i says how many coins we are taking from the right
      for (int i = 0; i < ni + 2; i++) {
        // initialize new state
        State* newState = new State();
        newState->start = (ni + 1) - i;
        newState->end = n - i - 1;
        
        // find parent and calculate value
        if (i == 0) {
          newState->rparent = prev_states[0];
          newState->rvalue = vs[newState->rparent->start] * sign;
        } else if (i == ni+1) {
          newState->lvalue = vs[prev_states[ni]->end] * sign;
        } else {
          assert(prev_states[i-1]->start == newState->start || prev_states[i-1]->end == newState->end);
          assert(prev_states[i]->start == newState->start || prev_states[i]->end == newState->end);
          
          newState->rparent = prev_states[i];
          
          newState->rvalue = vs[prev_states[i]->start] * sign;
          newState->lvalue = vs[prev_states[i-1]->end] * sign;
        }
        cur_states[i] = newState;
      }
      prev_states = cur_states;
    }
    
    /*
    cout << endl << "input:" << endl;
    for (auto i : vs) {
      cout << i << ", ";
    }
    cout << endl;
    */
    
    // now calculate all endstates backwards
    // by using the parent's children's maximum or minimum
    while (cur_states.size() > 1) {
      
      /*
      cout << "--" << endl;
      for (auto state : prev_states) {
        print(state);
      }
      */
      
      int cur_size = prev_states.size() - 1;
      bool myturn = cur_size % 2 == 1;
      cur_states = vector<State*>(cur_size);
      
      for (int i = 0; i < cur_size; i++) {
        cur_states[i] = prev_states[i]->rparent;
        
        int newValue = myturn ?
                         max(prev_states[i]->rvalue, prev_states[i+1]->lvalue) :
                         min(prev_states[i]->rvalue, prev_states[i+1]->lvalue);
        
        cur_states[i]->lvalue += newValue;
        cur_states[i]->rvalue += newValue;
      }
      for (auto state : prev_states) {
        delete(state);
      }
      prev_states = cur_states;
    }
      
    int difference = cur_states[0]->lvalue;
    delete(cur_states[0]);
    // cout << difference << "!" << endl;
    int myValue = (sum + difference) / 2;
    cout << myValue << endl;
    
  }
  return 0;
}