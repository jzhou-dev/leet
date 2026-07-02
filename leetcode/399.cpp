#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Node {
  std::vector<std::pair<Node *, double>> edges;
  std::string val;
  Node(std::string val) {
    edges = {};
    this->val = val;
  }
};

class Solution {
public:
  std::vector<double>
  calcEquation(std::vector<std::vector<std::string>> &equations,
               std::vector<double> &values,
               std::vector<std::vector<std::string>> &queries) {
    std::vector<double> result;
    std::unordered_map<std::string, Node *> nodes = build(equations, values);
    for (auto query : queries) {
      double div = -1;
      std::unordered_set<Node *> visited;
      if (nodes[query[0]] && nodes[query[1]]) {
        evaluate(nodes[query[0]], nodes[query[1]], visited, 1, div);
      }
      result.push_back(div);
    }
    return result;
  }

  std::unordered_map<std::string, Node *>
  build(std::vector<std::vector<std::string>> &equations,
        std::vector<double> &values) {
    std::unordered_map<std::string, Node *> nodes;
    for (int i = 0; i < equations.size(); ++i) {
      if (!nodes.count(equations[i][0])) {
        nodes[equations[i][0]] = new Node(equations[i][0]);
      }
      if (!nodes.count(equations[i][1])) {
        nodes[equations[i][1]] = new Node(equations[i][1]);
      }
      nodes[equations[i][0]]->edges.push_back(
          {nodes[equations[i][1]], values[i]});
      nodes[equations[i][1]]->edges.push_back(
          {nodes[equations[i][0]], 1 / values[i]});
    }
    return nodes;
  }

  void evaluate(Node *curr, Node *end, std::unordered_set<Node *> &visited,
                double val, double &div) {
    if (curr == end) {
      div = val;
      return;
    }
    visited.insert(curr);
    for (auto edge : curr->edges) {
      if (!visited.count(edge.first)) {
        visited.insert(edge.first);
        evaluate(edge.first, end, visited, val * edge.second, div);
      }
    }
  }
};
