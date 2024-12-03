//problem link is:https://bit.ly/3n4m3Hu
//at code360


#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool isContainKeys(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool End() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (!node->isContainKeys(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);  // Move to the next node
        }
        node->setEnd();  // Mark the end of the word
    }

    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (node->isContainKeys(word[i])) {
                node = node->get(word[i]);  // Move to the next node
            } else {
                return false;
            }
        }
        return node->End();  // Check if it's the end of a valid word
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.length(); i++) {
            if (node->isContainKeys(prefix[i])) {
                node = node->get(prefix[i]);  // Move to the next node
            } else {
                return false;
            }
        }
        return true;
    }
};
