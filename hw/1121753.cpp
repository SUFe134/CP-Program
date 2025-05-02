#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* left = nullptr; //指向左節點的pointer
    Node* right = nullptr; //指向右節點pointer
    Node(int v) : val(v) {} //初始化
};

//插入新節點
Node* insert(Node* root, int val) {
    if (!root) return new Node(val); //空的代表找到該插入的地方
    if (val < root->val) //新值比目前節點小，就往左子樹遞迴插入
        root->left = insert(root->left, val);
    else //大於等於目前節點，往右子樹遞迴插入
        root->right = insert(root->right, val);
    return root;
}

//前序走訪
void preorder(Node* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorder(root->left, result); //處理左子樹
    preorder(root->right, result); //處理右子數
}

//範圍搜尋
void searchRange(Node* root, int low, int high, vector<int>& result) {
    if (!root) return; //走到底了
    if (root->val > low) searchRange(root->left, low, high, result); // 往左子樹繼續搜尋
    if (root->val >= low && root->val <= high) result.push_back(root->val); //節點值在範圍內
    if (root->val < high) searchRange(root->right, low, high, result); //往右子樹繼續搜尋
}
//讀入的內容轉成vector
vector<int> parseNumbers(const string& line) {
    vector<int> nums;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        //用 getline 從 ss 中一個一個讀出逗號（,) 分隔的片段，存到 token 中。
        if (!token.empty() && token.back() == ';') token.pop_back();
        nums.push_back(stoi(token));//轉成整數
    }
    return nums;
}

void print(const vector<int>& nums) {
    if (nums.empty()) {
        cout << "NOT FOUND;" << endl;
        return;
    }
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i > 0) cout << ",";
        cout << nums[i];
    }
    cout << ";" << endl;
}

int main() {
    ifstream file("hw3_input.txt");
    if (!file) {
        cerr << "無法開啟檔案" << endl;
        return 1;
    }

    string line;
    getline(file, line);
    //getline(cin, line);
    vector<int> nodes = parseNumbers(line);

    Node* root = nullptr;
    for (int val : nodes) root = insert(root, val);

    vector<int> pre;
    preorder(root, pre);
    print(pre);

    while (getline(file, line)) {
        vector<int> range = parseNumbers(line); //讀入的字串轉成向量，low & high
        if (range.size() != 2) continue;
        vector<int> result; //符合查詢範圍的節點值
        searchRange(root, range[0], range[1], result);
        sort(result.begin(), result.end());
        print(result);
    }

    return 0;
}
