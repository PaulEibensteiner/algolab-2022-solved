#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Occurence {
  unsigned int index, word;
};

void testcase() {
  int n;
  cin >> n;

  int m_sum = 0;
  auto ms = vector<int>(n);
  for (int ni = 0; ni < n; ni++) {
    cin >> ms[ni];
    m_sum += ms[ni];
  }

  auto occurences = vector<Occurence>();
  occurences.reserve(m_sum);
  for (int ni = 0; ni < n; ni++) {
    for (int mi = 0; mi < ms[ni]; mi++) {
      int p;
      cin >> p;
      Occurence o;
      o.word = ni;
      o.index = p;
      occurences.push_back(o);
    }
  }

  sort(occurences.begin(), occurences.end(),
       [](Occurence const& o1, Occurence const& o2) {
         return o1.index < o2.index;
       });

  // both inclusive
  auto start = occurences.begin();
  auto end = occurences.begin();

  int num_different_words = 1;
  auto word_counters = vector<int>(n, 0);
  word_counters[end->word]++;
  unsigned int min_interval = -1;

  while (end != occurences.end()) {
    if (num_different_words < n) {
      end++;
      if (word_counters[end->word] == 0) {
        num_different_words++;
      }
      word_counters[end->word]++;
    } else {
      word_counters[start->word]--;
      if (word_counters[start->word] == 0) {
        num_different_words--;
      }
      start++;
    }

    if (num_different_words == n) {
      min_interval = min((end->index - start->index) + 1, min_interval);
    }
  }

  cout << min_interval << endl;
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
