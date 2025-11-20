#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <limits>

struct Node {
    int key;
    Node *lo;
    Node *hi;

    explicit Node(const int k) : key(k), lo(nullptr), hi(nullptr) {
    }
};

Node *addNode(Node *ptr, const int value) {
    if (!ptr) return new Node(value);

    Node *current = ptr;
    while (true) {
        if (value < current->key) {
            if (!current->lo) {
                current->lo = new Node(value);
                break;
            }
            current = current->lo;
        } else if (value > current->key) {
            if (!current->hi) {
                current->hi = new Node(value);
                break;
            }
            current = current->hi;
        } else {
            break;
        }
    }
    return ptr;
}

void showInOrder(const Node *ptr) {
    if (!ptr) return;

    showInOrder(ptr->lo);
    std::cout << ptr->key << ' ';
    showInOrder(ptr->hi);
}

bool contains(const Node *ptr, const int target) {
    while (ptr) {
        if (ptr->key == target) return true;
        ptr = (target < ptr->key) ? ptr->lo : ptr->hi;
    }
    return false;
}

int getMinimum(const Node *ptr) {
    if (!ptr) throw std::runtime_error("Empty tree");
    while (ptr->lo) {
        ptr = ptr->lo;
    }
    return ptr->key;
}

int getMaximum(const Node *ptr) {
    if (!ptr) throw std::runtime_error("Empty tree");
    while (ptr->hi) {
        ptr = ptr->hi;
    }
    return ptr->key;
}

bool checkRange(const Node *node, const long long minVal, const long long maxVal) {
    if (!node) return true;
    if (node->key <= minVal || node->key >= maxVal) return false;
    return checkRange(node->lo, minVal, node->key) &&
           checkRange(node->hi, node->key, maxVal);
}

bool checkBST(const Node *root) {
    return checkRange(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}

void inorderCounter(const Node *node, int &k, int &result) {
    if (!node || k <= 0) return;
    inorderCounter(node->lo, k, result);
    k--;
    if (k == 0) {
        result = node->key;
        return;
    }
    inorderCounter(node->hi, k, result);
}

int getKthSmallest(const Node *root, int k) {
    int result = -1;
    inorderCounter(root, k, result);
    if (k > 0) throw std::out_of_range("Not enough nodes");
    return result;
}

Node *createTreeFromArray(const std::vector<int> &arr, const int start, const int end) {
    if (start > end) return nullptr;
    const int center = start + (end - start) / 2;
    Node *newItem = new Node(arr[center]);
    newItem->lo = createTreeFromArray(arr, start, center - 1);
    newItem->hi = createTreeFromArray(arr, center + 1, end);
    return newItem;
}

Node *arrayToTree(const std::vector<int> &vec) {
    if (vec.empty()) return nullptr;
    return createTreeFromArray(vec, 0, static_cast<int>(vec.size()) - 1);
}

int main() {
    const std::vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    const Node *root = arrayToTree(data);
    showInOrder(root);
    std::cout << "\nMin: " << getMinimum(root);
}
