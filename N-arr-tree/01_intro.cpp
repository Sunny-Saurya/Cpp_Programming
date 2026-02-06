#include <bits/stdc++.h>
using namespace std;

// ----------- N-ary Tree Node Definition -----------
class Node {
public:
    int val;
    vector<Node*> children;

    Node(int _val) {
        val = _val;
    }
};

// ----------- Solution Class -----------
class Solution {
public:
    // 🔹 PREORDER
    void dfsPre(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);
        for (Node* child : root->children)
            dfsPre(child, ans);
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfsPre(root, ans);
        return ans;
    }

    // 🔹 POSTORDER
    void dfsPost(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        for (Node* child : root->children)
            dfsPost(child, ans);

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfsPost(root, ans);
        return ans;
    }

    // 🔹 COUNT NODES
    int countNodes(Node* root) {
        if (root == NULL) return 0;

        int count = 1;
        for (Node* child : root->children)
            count += countNodes(child);

        return count;
    }

    // 🔹 MAX DEPTH
    int maxDepth(Node* root) {
        if (root == NULL) return 0;

        int depth = 0;
        for (Node* child : root->children)
            depth = max(depth, maxDepth(child));

        return depth + 1;
    }
};

// ----------- MAIN FUNCTION -----------
int main() {

    /*
            Tree structure:

                    1
                 /  |  \
                2   3   4
                   / \
                  5   6
    */

    // Create nodes
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    // Build tree
    root->children = {node2, node3, node4};
    node3->children = {node5, node6};

    // Solution object
    Solution sol;

    // Preorder
    vector<int> pre = sol.preorder(root);
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << endl;

    // Postorder
    vector<int> post = sol.postorder(root);
    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << endl;

    // Count nodes
    cout << "Total Nodes: " << sol.countNodes(root) << endl;

    // Max depth
    cout << "Max Depth: " << sol.maxDepth(root) << endl;

    return 0;
}
