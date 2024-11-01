#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption: word will be in uppercase
        int index = word[0] - 'A';
        TrieNode* child;

        // if character is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // if character is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word); // Pass root as the first argument
    }

    // search utility
    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // if character is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // character is absent
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word); // Return boolean value
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("APPLE");

    cout << "Present or Not: " << (t->search("APPLE") ? "Yes" : "No") << endl;

    return 0;
}
