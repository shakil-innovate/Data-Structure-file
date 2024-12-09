//L3. Longest Word With All Prefixes | Complete String | Trie
//problem link:https://bit.ly/3n3kedU
#include <bits/stdc++.h> 
using namespace std;

// Structure to represent a node in the Trie
struct Node {
   Node* links[26]; // Array to store references to child nodes (for 26 lowercase letters)
   bool flag = false; // Indicates if the node marks the end of a word

   // Checks if a node exists for the given character
   bool containsKey(char ch) {
      return links[ch - 'a'] != nullptr;
   }

   // Creates a link to a new node for the given character
   void put(char ch, Node* node) {
      links[ch - 'a'] = node;
   }

   // Retrieves the node linked with the given character
   Node* getlink(char ch) {
      return links[ch - 'a'];
   }

   // Marks the current node as the end of a word
   void setEnd() {
      flag = true;
   }

   // Checks if the current node is the end of a word
   bool end() {
      return flag;
   }
};

// Trie class to manage word insertion and search operations
class Trie {
   private:
      Node* root; // Root node of the Trie

   public:
      // Constructor initializes the root node
      Trie() {
         root = new Node();
      }

      // Inserts a word into the Trie
      void insert(string word) {
         Node* node = root;

         // Traverse through each character of the word
         for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
               // Create a new node if the character is not already linked
               node->put(word[i], new Node());
            }
            // Move to the linked node for the character
            node = node->getlink(word[i]);
         }
         // Mark the last node as the end of a word
         node->setEnd();
      }

      // Checks if a word and all its prefixes exist in the Trie
      bool search(string word) {
         Node* node = root;

         // Traverse through each character of the word
         for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) 
               return false; // If a character is missing, the word doesn't exist
            node = node->getlink(word[i]); // Move to the next node
            if (!node->end()) 
               return false; // Ensure all prefixes are valid words
         }
         return true;
      }
};

// Function to find the lexicographically smallest longest word with all prefixes present
string completeString(int n, vector<string>& a) {
    Trie trie; // Create a Trie instance

    // Insert all words into the Trie
    for (auto word : a) {
        trie.insert(word);
    }

    string longest_string = ""; // To store the result

    // Check each word in the input list
    for (auto word : a) {
        if (trie.search(word)) { // Check if all prefixes of the word exist
            if (longest_string.length() < word.length()) {
                // Update if the current word is longer
                longest_string = word;
            } else if (word.length() == longest_string.length()) {
                // Update if lexicographically smaller
                longest_string = (word < longest_string ? word : longest_string);
            }
        }
    }

    // Return "None" if no valid word is found, otherwise return the longest word
    return (longest_string == "" ? "None" : longest_string);
}
