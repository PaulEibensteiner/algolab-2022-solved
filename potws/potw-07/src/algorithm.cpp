#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

struct Node {
  Node *parent, *left, *right;
  int t;

  Node() : parent(NULL), left(NULL), right(NULL), t(-1){};
};

void get_children_recursively(Node *n, stack<Node *> *children) {
  if (n == NULL) {
    return;
  }
  children->push(n);
  get_children_recursively(n->left, children);
  get_children_recursively(n->right, children);
}

int main() {
  int t;
  cin >> t;

  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;

    vector<Node *> nodes;
    nodes.reserve(n);

    auto heap = map<int, Node *>();

    for (int ni = 0; ni < n; ni++) {
      auto node = new Node();
      cin >> node->t;
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

    stack<Node *> *children;

    int time = 0;
    bool possible = true;
    while (!heap.empty() && possible == true) {
      Node *min = heap.begin()->second;
      children = new stack<Node *>();
      get_children_recursively(min, children);
      while (!children->empty()) {
        auto child = children->top();
        if (time >= child->t) {
          possible = false;
          break;
        }
        children->pop();
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
}