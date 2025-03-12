#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 后序遍历的递归函数
string postOrder(const string& inorder, const string& preorder) {
    // 递归的终止条件：如果没有节点，返回空字符串
    if (inorder.empty()) {
        return "";
    }
    
    // 前序遍历的第一个字符是根节点
    char root = preorder[0];
    
    // 在中序遍历中找到根节点的位置
    int rootPos = inorder.find(root);
    
    // 左子树的中序遍历是根节点左边的部分
    string leftInorder = inorder.substr(0, rootPos);
    // 右子树的中序遍历是根节点右边的部分
    string rightInorder = inorder.substr(rootPos + 1);
    
    // 左子树的前序遍历是根节点后的部分（与左子树的中序部分大小相等）
    string leftPreorder = preorder.substr(1, leftInorder.size());
    // 右子树的前序遍历是剩下的部分
    string rightPreorder = preorder.substr(1 + leftInorder.size());
    
    // 递归求得左子树和右子树的后序遍历
    string leftPostorder = postOrder(leftInorder, leftPreorder);
    string rightPostorder = postOrder(rightInorder, rightPreorder);
    
    // 后序遍历的顺序是：左子树 + 右子树 + 根节点
    return leftPostorder + rightPostorder + root;
}

int main() {
    string inorder, preorder;
    cin >> inorder;  // 中序遍历
    cin >> preorder; // 前序遍历
    
    // 计算并输出后序遍历
    string postorder = postOrder(inorder, preorder);
    cout << postorder << endl;
    
    return 0;
}
