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
};

int main()
{
    Trie *t = new Trie();
    t ->insertWord("APPLE");
    t ->insertWord("BANANA");
    return 0;
}