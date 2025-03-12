#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 辅助函数：根据前序和中序遍历构造后序遍历
vector<char> buildPostorder(const vector<char>& preorder, const vector<char>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<char, int>& inMap) {
    // 如果没有元素，返回空
    if (preStart > preEnd || inStart > inEnd) {
        return {};
    }
    
    // 根节点是前序遍历的第一个元素
    char root = preorder[preStart];
    
    // 在中序遍历中找到根节点的索引
    int rootIndex = inMap[root];
    
    // 左子树的大小
    int leftSize = rootIndex - inStart;
    
    // 递归处理左子树和右子树的后序遍历
    vector<char> leftPostorder = buildPostorder(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1, inMap);
    vector<char> rightPostorder = buildPostorder(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd, inMap);
    
    // 后序遍历：左子树的后序 + 右子树的后序 + 根节点
    leftPostorder.insert(leftPostorder.end(), rightPostorder.begin(), rightPostorder.end());
    leftPostorder.push_back(root);
    
    return leftPostorder;
}

// 主函数：调用递归函数来构造后序遍历
vector<char> postorderTraversal(const vector<char>& preorder, const vector<char>& inorder) {
    unordered_map<char, int> inMap;  // 用于存储中序遍历元素的位置
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }
    
    // 调用递归函数
    return buildPostorder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);
}

int main() {
    // 输入前序遍历
    cout << "请输入前序遍历（字符组成）: ";
    string preorder_str;
    cin >> preorder_str;
    vector<char> preorder(preorder_str.begin(), preorder_str.end());  // 将输入的字符串转换为字符数组
    
    // 输入中序遍历
    cout << "请输入中序遍历（字符组成）: ";
    string inorder_str;
    cin >> inorder_str;
    vector<char> inorder(inorder_str.begin(), inorder_str.end());  // 将输入的字符串转换为字符数组
    
    // 获取后序遍历
    vector<char> postorder = postorderTraversal(preorder, inorder);
    
    // 输出后序遍历
    cout << "后序遍历为: ";
    for (char val : postorder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
