#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <vector>

typedef unsigned long int myint;

using namespace std;

struct Node {
  Node *parent, *left, *right;
  myint t;

  Node() : parent(NULL), left(NULL), right(NULL), t(-1){};
};

void get_children_recursively(Node *n, stack<Node *> &children) {
  if (n == NULL) {
    return;
  }
  children.push(n);
  get_children_recursively(n->left, children);
  get_children_recursively(n->right, children);
}

void testcase() {
  int n;
  cin >> n;
  unsigned int max = numeric_limits<unsigned int>::max();

  vector<Node *> nodes;
  nodes.reserve(n);

  auto heap = map<myint, Node *>();

  for (int ni = 0; ni < n; ni++) {
    auto node = new Node();
    myint t;
    cin >> t;
    // prevent multiple entries of same t
    t = (t << 32) + ni;
    node->t = t;
    nodes.push_back(node);
    Node *parent = nodes[(ni - 1) / 2];

    node->parent = parent;
    if (ni % 2 == 0) {
      parent->right = node;
    } else {
      parent->left = node;
    }

    heap.insert({node->t, node});
  }

  stack<Node *> children;

  myint time = 0;
  bool possible = true;
  while (!heap.empty() && possible == true) {
    Node *min = heap.begin()->second;
    children = stack<Node *>();
    get_children_recursively(min, children);
    while (!children.empty()) {
      auto child = children.top();
      if (time >= (child->t) >> 32) {
        possible = false;
        break;
      }
      children.pop();
      // Delete child from data structures
      heap.erase(child->t);
      if (child->parent != NULL) {
        if (child->parent->left == child) {
          child->parent->left = NULL;
        } else {
          child->parent->right = NULL;
        }
      }
      time++;
    }
  }

  if (possible) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  for (auto node : nodes) {
    delete node;
  }
}

void read_thirteen() {
  while (true) {
    int i;
    cin >> i;
    if (i == 13) {
      cout << "wtf" << endl;
      break;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) testcase();
}
