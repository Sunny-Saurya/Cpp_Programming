#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int rowNumber, int colNumber) {
        this->data = data;
        this->row = rowNumber;
        this->col = colNumber;
    }
};

// Comparator for min heap
class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    // Min heap
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Push first element of each array into min heap
    for (int i = 0; i < kArrays.size(); i++) {
        if (!kArrays[i].empty()) { // safety check for empty arrays
            Node* temp = new Node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
    }

    vector<int> ans;

    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp->data);

        int i = temp->row;
        int j = temp->col;

        // If next element exists in the same array
        if (j + 1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}
