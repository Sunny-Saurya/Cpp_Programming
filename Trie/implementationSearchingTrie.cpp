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
};

int main()
{
    Trie *t = new Trie();
    t ->insertWord("APPLE");
    t ->insertWord("BANANA");

    cout << "Present or Not: " << (t->searchWord("APPLE") ? "Yes" : "No") << endl;
    return 0;
}