//G-26. Alien Dictionary - Topological Sort
//vedio link:https://www.youtube.com/watch?v=U3N_je7tWAs&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=18
//problem link:https://bit.ly/3C9N6ZU

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    // Function to perform topological sorting
    string topo_sort(vector<vector<int>>& adj, int k) {
        vector<int> inDegree(k, 0); // Array to store the in-degree of each node

        // Calculate in-degree of each node
        for (int i = 0; i < k; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q; // Queue to perform BFS

        // Push all nodes with in-degree 0 into the queue
        for (int i = 0; i < k; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        string ans = ""; // To store the result of topological sort

        // Perform BFS
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans += x + 'a'; // Convert numeric index back to character

            for (auto it : adj[x]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it); // Push nodes with in-degree 0
            }
        }

        return ans; // Return the topological order
    }

  public:
    // Function to determine the order of characters in the alien dictionary
    string findOrder(vector<string> dict, int k) {
        vector<vector<int>> adj(k); // Adjacency list to represent the graph

        // Build the graph by comparing adjacent words
        for (int i = 0; i < dict.size() - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            bool foundDiff = false; // Flag to track if a differing character is found

            for (int ptr = 0; ptr < min(s1.length(), s2.length()); ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // Add edge to the graph
                    foundDiff = true;
                    break;
                }
            }

            // Handle prefix case (e.g., "abc" and "ab" are invalid input)
            if (!foundDiff && s1.length() > s2.length()) {
                return ""; // Invalid input: return an empty string
            }
        }

        string ans = topo_sort(adj, k); // Perform topological sort

        // Validate the result: If the topological order doesn't include all characters, return ""
        if (ans.size() != k) return "";
        else return ans;
    }
};

//{ Driver Code Starts.
string order; // Global variable to store the character order

// Comparator function to check if strings follow the given order
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    // If one string is a prefix of the other, the shorter string should come first
    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2; // Compare positions in the order
}

// Driver program to test the above functions
int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline character

    while (t--) {
        vector<string> a; // Input dictionary
        string input;
        getline(cin, input); // Read the entire line of input
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }

        int K; // Number of characters in the alien language
        cin >> K;
        getchar(); // Consume the newline character

        Solution obj;
        string ans = obj.findOrder(a, K); // Find the order of characters

        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        vector<string> temp(a.begin(), a.end()); // Copy input dictionary
        sort(temp.begin(), temp.end(), f); // Sort using the custom comparator

        bool isValid = true; // Flag to check if the result is valid

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != temp[i]) {
                isValid = false;
                break;
            }
        }

        // Output the result
        if (isValid)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
