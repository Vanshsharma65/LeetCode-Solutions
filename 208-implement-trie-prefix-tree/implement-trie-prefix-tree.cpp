#include <string>
using namespace std;

// 1. Define the Node structure
struct Node {
    Node* links[26];
    bool flag = false;
    
    // Check if the character exists
    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }
    
    // Insert a new node for the character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    // Get the node corresponding to the character
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    // Mark the current node as the end of a word
    void setEnd() {
        flag = true;
    }
    
    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root; // 2. Declare the root node

public:
    Trie() {
        // 3. Initialize the root in the constructor
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node()); // Fixed syntax
            }
            node = node->get(word[i]);
        }
        node->setEnd(); // Fixed syntax
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) { // Fixed syntax
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        // 4. Implement startsWith (similar to search)
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        // If we successfully loop through the whole prefix, it exists.
        return true; 
    }
};