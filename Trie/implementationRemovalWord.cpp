#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for(int i = 0; i <  26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root;
    
    // constructor


    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case :
        if(word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }

        // find index 

        int index = word[0] - 'A';
        TrieNode*  child;

        if(root -> children[index] != NULL)
        {
            // present
            child = root -> children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // searching  a word

    bool searchUtil(TrieNode* root, string word)
    {
        //  base case

        if(word.length() == 0)
        {
            return root -> isTerminal;
        }

        // present 

        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else{
            return false;
        }

        searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // removing  a word

    bool removeUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {

            root->isTerminal = false;

            // Check if the current node has no children

            for (int i = 0; i < 26; i++) {

                if (root->children[i] != NULL) {
                    
                    return false; // Don't delete this node
                }
            }
            return true; // Delete this node
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            // Word not found
            return false;
        }

        // Recursively delete the word
        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        // If the child node can be deleted, delete the pointer to it
        if (shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;

            // Check if current node can be deleted as well
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Don't delete this node
                    }
                }
                return true; // Delete this node
            }
        }

        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t ->insertWord("APPLE");
    t ->insertWord("BANANA");

    cout << "Present or Not: " << (t->searchWord("APPLE") ? "Yes" : "No") << endl;
    cout << "Present or Not: " << (t->searchWord("BANANA") ? "Yes" : "No") << endl;

    t -> removeWord("BANANA");
    cout << "Present or Not: " << (t->searchWord("BANANA") ? "Yes" : "No") << endl;


    return 0;
}