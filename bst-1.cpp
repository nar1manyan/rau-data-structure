#include <iostream>
#include <queue>
#include <stack>
#include <climits>

struct Node {
    int val;
    Node* l = nullptr;
    Node* r = nullptr;

    Node() : val(0) {}
    explicit Node(const int v) : val(v) {}
};

int getSize(const Node* p) {
    return p ? (1 + getSize(p->l) + getSize(p->r)) : 0;
}

int getSizeIterative(Node* startNode) {
    if (!startNode) return 0;

    std::stack<Node*> s;
    s.push(startNode);
    int total = 0;

    while (!s.empty()) {
        const Node* current = s.top();
        s.pop();
        total++;

        if (current->l) s.push(current->l);
        if (current->r) s.push(current->r);
    }
    return total;
}

int getTreeDepth(const Node* p) {
    if (!p) return 0;
    const int leftDepth = getTreeDepth(p->l);
    const int rightDepth = getTreeDepth(p->r);

    const int maxDepth = (leftDepth > rightDepth) ? leftDepth : rightDepth;
    return maxDepth + 1;
}

int countLeafNodes(const Node* p) {
    if (!p) return 0;
    if (!p->l && !p->r) return 1;
    return countLeafNodes(p->l) + countLeafNodes(p->r);
}

void printPreOrder(const Node* p) {
    if (!p) return;
    std::cout << p->val << " ";
    printPreOrder(p->l);
    printPreOrder(p->r);
}

void printInOrder(const Node* p) {
    if (!p) return;
    printInOrder(p->l);
    std::cout << p->val << " ";
    printInOrder(p->r);
}

void printPostOrder(const Node* p) {
    if (!p) return;
    printPostOrder(p->l);
    printPostOrder(p->r);
    std::cout << p->val << " ";
}

void printLevelOrder(Node* start) {
    if (!start) return;

    std::queue<Node*> q;
    q.push(start);

    while (!q.empty()) {
        const Node* temp = q.front();
        q.pop();
        std::cout << temp->val << " ";

        if (temp->l) q.push(temp->l);
        if (temp->r) q.push(temp->r);
    }
}

int calculateSum(const Node* p) {
    return p ? (p->val + calculateSum(p->l) + calculateSum(p->r)) : 0;
}

int getMaxValue(const Node* p) {
    if (!p) return INT_MIN;

    int maxVal = p->val;
    const int lMax = getMaxValue(p->l);
    const int rMax = getMaxValue(p->r);

    if (lMax > maxVal) maxVal = lMax;
    if (rMax > maxVal) maxVal = rMax;

    return maxVal;
}

int getMinValue(const Node* p) {
    if (!p) return INT_MAX;

    int minVal = p->val;
    const int lMin = getMinValue(p->l);
    const int rMin = getMinValue(p->r);

    if (lMin < minVal) minVal = lMin;
    if (rMin < minVal) minVal = rMin;

    return minVal;
}

bool checkIdentical(const Node* a, const Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    return (a->val == b->val) &&
           checkIdentical(a->l, b->l) &&
           checkIdentical(a->r, b->r);
}

int nodesAtLevel(const Node* p, const int level) {
    if (!p || level <= 0) return 0;
    if (level == 1) return 1;

    return nodesAtLevel(p->l, level - 1) + nodesAtLevel(p->r, level - 1);
}

void invertTree(Node* p) {
    if (!p) return;
    Node* temp = p->l;
    p->l = p->r;
    p->r = temp;

    invertTree(p->l);
    invertTree(p->r);
}

int main() {
    return 0;
}