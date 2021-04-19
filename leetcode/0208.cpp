/*
208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

*/

class Node{
public:
    char data;
    Node* children[26] = {};
    bool isLeaf;
    Node(char d){
        data = d;
        isLeaf = false;
    };
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
       Node* p = root;
        for(int i =0;i<word.size();++i){
            char l = word[i];
            if(p->children[l-'a'] == NULL){
                 p->children[l-'a'] = new Node(l);
            }
            p = p->children[l-'a'];
        }
        p->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(char l : word){
            if(p->children[l-'a'] ==NULL){
                return false;
            }
            p = p->children[l-'a'];
        }
        return p->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for(char l : prefix){
            if(p->children[l-'a'] ==NULL){
                return false;
            }
            p = p->children[l-'a'];
        }
        return true;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */