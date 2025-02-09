#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
private:
    struct Trie
    {
        int is_word;
        vector<Trie *> child;
        Trie()
        {
            is_word = 0;
            child = vector<Trie *>(26, nullptr);
        }
    };

    void insert(Trie *x, string word)
    {
        Trie *temp = x;
        for (auto w : word)
        {
            int index = w - 'a';
            if (temp->child[index] == nullptr)
            {
                temp->child[index] = new Trie;
            }
            temp = temp->child[index];
        }
        temp->is_word = 1;
    }
    pair<int, int> dirs[4] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};

    bool in_range(int x, int y, vector<vector<char>>& board){
        return board.size() && x>=0 && x<board.size() && y>=0&&y<board[0].size();
    }

    void dfs(int x, int y, Trie *t, vector<vector<char>> &board, vector<vector<int>> &vis, vector<string> &ans, string &curr_str)
    {
        vis[x][y] = 1;
        if (t->is_word)
        {
            ans.push_back(curr_str);
        }
        for (auto d : dirs)
        {
            int dx = d.first, dy = d.second;
            if(!in_range(x+dx, y+dy, board)){
                continue;
            }
            char ch = board[x + dx][y + dy];
            int index = ch - 'a';
            if (t->child[index])
            {
                curr_str.push_back(ch);
                dfs(x + dx, y + dy, t->child[index], board, vis, ans, curr_str);
                curr_str.pop_back();
            }
        }
        vis[x][y] = 0;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *head = new Trie;
        for (auto word : words)
        {
            insert(head, word);
        }
        map<char, vector<pair<int, int>>> char_index;
        int n = board.size();
        int m = n ? board[0].size() : 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                char_index[board[i][j]].push_back({i, j});
            }
        }
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < 26; i++)
        {
            if (head->child[i])
            {
                char ch = 'a' + i;
                string curr_str = to_string(ch);
                for (auto x : char_index[ch])
                {
                    int p = x.first, q = x.second;
                    dfs(p, q, head->child[i], board, vis, ans, curr_str);
                }
            }
        }
        return ans;
    }
};

int main()
{
    char ch = 'b';
    string s = (" " + ch);
    cout<<s<<"\n";
}
