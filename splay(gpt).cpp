#include <bits/stdc++.h>
// 万能头文件，包含所有std库
using namespace std;

// 定义树节点结构体
struct Node
{
    int val;      // 节点数值
    int cnt;      // 数值出现次数
    int size;     // 子树大小
    Node *left;   // 左子节点
    Node *right;  // 右子节点
    Node *father; // 父节点

    // 构造函数
    Node(int val) : val(val), cnt(1), size(1), left(nullptr), right(nullptr), father(nullptr) {}
};

// 定义Splay平衡树类
class Splay
{
public:
    // 构造函数
    Splay() : root(nullptr) {}

    // 插入节点
    void insert(int val)
    {
        // 如果根节点为空，则创建新节点作为根节点
        if (!root)
        {
            root = new Node(val);
            return;
        }
        // 遍历整棵树
        Node *cur = root;    // 当前节点设为根节点
        Node *pre = nullptr; // 当前节点的父节点设为nullptr
        while (cur)
        { // 一直循环到叶节点为止
            if (cur->val == val)
            {                        // 如果当前节点的值等于要插入的值
                cur->cnt += 1;       // 将计数器+1
                splay(cur, nullptr); // 旋转当前节点到根节点（因为后续需要对其进行操作）
                return;              // 直接返回
            }
            pre = cur; // 将当前节点设为父节点
            if (cur->val > val)
            {                    // 如果要插入的值小于当前节点的值
                cur = cur->left; // 向左子树递归
            }
            else
            {                     // 否则
                cur = cur->right; // 向右子树递归
            }
        }
        // 创建新节点并插入到树中
        cur = new Node(val); // 创建新节点
        cur->father = pre;   // 将其父节点设为pre
        if (pre->val > val)
        {                    // 如果pre的值大于要插入的值
            pre->left = cur; // 将新节点插入到左子树
        }
        else
        {                     // 否则
            pre->right = cur; // 将新节点插入到右子树
        }
        splay(cur, nullptr); // 旋转新节点到根节点
    }

    // 查询数值对应的排名
    int rank(int val)
    {
        Node *cur = root; // 当前节点设为根节点
        int rank = 0;     // 排名从0开始计算
        while (cur)
        { // 遍历整棵树
            if (cur->val == val)
            {                                            // 如果当前节点的值等于要查询的值
                rank += cur->left ? cur->left->size : 0; // 将当前节点左子树的大小加到rank上
                splay(cur, nullptr);                     // 旋转当前节点到根节点
                return rank + 1;                         // 返回rank+1（因为排名从1开始计算）
            }
            if (cur->val > val)
            {                    // 如果要查询的值小于当前节点的值
                cur = cur->left; // 向左子树递归
            }
            else
            {                                                         // 否则
                rank += (cur->left ? cur->left->size : 0) + cur->cnt; // 将当前节点左子树的大小与右子树的大小加上当前节点的计数器后加到rank上
                cur = cur->right;                                     // 向右子树递归
            }
        }
        return rank + 1; // 如果没找到，返回rank+1（因为排名从1开始计算）
    }

    // 查询排名对应的数
    int at(int rank)
    {
        Node *cur = root; // 当前节点设为根节点
        while (cur)
        {                                                    // 遍历整棵树
            int left_size = cur->left ? cur->left->size : 0; // 计算左子树的大小
            if (left_size + 1 <= rank && rank <= left_size + cur->cnt)
            {                        // 如果当前节点就是要查询的节点
                splay(cur, nullptr); // 旋转当前节点到根节点（方便后续操作）
                return cur->val;     // 直接返回当前节点值
            }
            if (rank <= left_size)
            {                    // 如果要查询的排名小于等于左子树大小
                cur = cur->left; // 向左子树递归
            }
            else
            {                                   // 否则
                rank -= (left_size + cur->cnt); // 将当前节点左子树的大小与右子树的大小加上当前节点的计数器后减掉rank
                cur = cur->right;               // 向右子树递归
            }
        }
        return -1; // 没找到，返回-1
    }

    // 删除数值为val的节点
    void erase(int val)
    {
        Node *node = find(val); // 找到要删除的节点
        if (!node)
        { // 如果没找到，直接返回
            return;
        }
        splay(node, nullptr); // 旋转要删除的节点到根节点
        if (node->cnt > 1)
        {                   // 如果要删除的节点的计数器大于1
            node->cnt -= 1; // 将计数器减1
            update(node);   // 更新节点信息（因为节点信息可能已经变化）
            return;         // 直接返回
        }
        if (node->left == nullptr)
        {                       // 如果要删除的节点没有左子树
            root = node->right; // 将右子树作为新的根节点
            if (node->right)
            {                                  // 如果有右子树
                node->right->father = nullptr; // 将右子节点的父节点设为nullptr
            }
        }
        else if (node->right == nullptr)
        {                      // 如果要删除的节点没有右子树
            root = node->left; // 将左子树作为新的根节点
            if (node->left)
            {                                 // 如果有左子树
                node->left->father = nullptr; // 将左子节点的父节点设为nullptr
            }
        }
        else
        {                                // 如果要删除的节点既有左子树又有右子树
            Node *left_max = node->left; // 找到左子树中最大的节点
            while (left_max->right)
            {
                left_max = left_max->right;
            }
            splay(left_max, node);          // 旋转最大节点到要删除的节点下面
            root = left_max;                // 将最大节点作为新的根节点
            left_max->right = node->right;  // 将要删除节点的右子树挂在最大节点的右子树上
            node->right->father = left_max; // 将要删除节点右子树的父节点设为最大节点
            update(left_max);               // 更新最大节点信息（因为信息可能已经变化）
        }
        delete node; // 删除节点
    }

    // 查询val的前驱
    int predecessor(int val)
    {
        Node *node = find(val); // 找到节点
        if (node)
        { // 如果节点存在
            if (node->left)
            {                           // 如果节点有左子树
                Node *cur = node->left; // 将cur设为节点的左子节点
                while (cur->right)
                {
                    cur = cur->right; // 不断向右遍历，找到左子树中最大的节点
                }
                splay(cur, nullptr); // 旋转最大节点到根节点
                return cur->val;     // 直接返回最大节点的值
            }
        }
        // 如果节点不存在，或者节点没有左子树
        Node *cur = root;    // 从根节点开始遍历
        Node *pre = nullptr; // pre设为nullptr
        while (cur)
        { // 遍历整棵树
            if (cur->val < val)
            { // 如果当前节点的值小于要查询的值
                if (!pre || pre->val < cur->val)
                {              // 如果pre不存在，或者当前节点的值比pre的值大
                    pre = cur; // 更新pre为当前节点
                }
                cur = cur->right; // 向右子树递归
            }
            else
            {                    // 否则
                cur = cur->left; // 向左子树递归
            }
        }
        if (pre)
        {                        // 如果pre存在
            splay(pre, nullptr); // 旋转pre到根节点
            return pre->val;     // 直接返回pre的值
        }
        return -1; // 否则返回-1
    }

    // 查询val的后继
    int successor(int val)
    {
        Node *node = find(val); // 找到节点
        if (node)
        { // 如果节点存在
            if (node->right)
            {                            // 如果节点有右子树
                Node *cur = node->right; // 将cur设为节点的右子节点
                while (cur->left)
                {
                    cur = cur->left; // 不断向左遍历，找到右子树中最小的节点
                }
                splay(cur, nullptr); // 旋转最小节点到根节点
                return cur->val;     // 直接返回最小节点的值
            }
        }
        // 如果节点不存在，或者节点没有右子树
        Node *cur = root;    // 从根节点开始遍历
        Node *suc = nullptr; // suc设为nullptr
        while (cur)
        { // 遍历整棵树
            if (cur->val > val)
            { // 如果当前节点的值大于要查询的值
                if (!suc || suc->val > cur->val)
                {              // 如果suc不存在，或者当前节点的值比suc的值小
                    suc = cur; // 更新suc为当前节点
                }
                cur = cur->left; // 向左子树递归
            }
            else
            {                     // 否则
                cur = cur->right; // 向右子树递归
            }
        }
        if (suc)
        {                        // 如果suc存在
            splay(suc, nullptr); // 旋转suc到根节点
            return suc->val;     // 直接返回suc的值
        }
        return -1; // 否则返回-1
    }

private:
    Node *root; // 根节点

    // 更新节点信息（子树大小）
    void update(Node *node)
    {
        node->size = (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0) + node->cnt; // 计算子树大小
    }

    // 将节点旋转到父节点
    void rotate(Node *node)
    {
        Node *father = node->father;    // 父节点
        Node *grandpa = father->father; // 祖父节点
        if (grandpa)
        { // 如果祖父节点存在
            if (grandpa->left == father)
            {                         // 如果父节点是祖父节点的左子节点
                grandpa->left = node; // 将要旋转的节点设为祖父节点的左子节点
            }
            else
            {                          // 如果父节点是祖父节点的右子节点
                grandpa->right = node; // 将要旋转的节点设为祖父节点的右子节点
            }
        }
        node->father = grandpa; // 将祖父节点设为要旋转的节点的父节点
        if (node == father->left)
        {                               // 如果要旋转的节点是父节点的左子节点
            father->left = node->right; // 将要旋转节点的右子节点设为父节点的左子节点
            if (node->right)
            {                                 // 如果要旋转节点的右子节点存在
                node->right->father = father; // 将要旋转节点的右子节点的父节点设为父节点
            }
            node->right = father; // 将父节点设为要旋转的节点的右子节点
        }
        else
        {                               // 否则
            father->right = node->left; // 将要旋转节点的左子节点设为父节点的右子节点
            if (node->left)
            {                                // 如果要旋转节点的左子节点存在
                node->left->father = father; // 将要旋转节点的左子节点的父节点设为父节点
            }
            node->left = father; // 将父节点设为要旋转的节点的左子节点
        }
        update(father); // 更新父节点信息（因为信息可能已经变化）
        update(node);   // 更新要旋转的节点信息（因为信息可能已经变化）
    }

    // 旋转节点到根节点或父节点
    void splay(Node *node, Node *to)
    {
        while (node->father != to)
        {                                   // 一直循环直到节点的父节点是to
            Node *father = node->father;    // 父节点
            Node *grandpa = father->father; // 祖父节点
            if (grandpa != to)
            { // 如果祖父节点不是to
                if ((grandpa->left == father) != (father->left == node))
                {                 // 如果节点是左右子节点
                    rotate(node); // 先旋转一次节点
                }
                else
                {                   // 否则
                    rotate(father); // 先旋转一次父节点
                }
            }
            rotate(node); // 旋转节点到根节点或父节点
        }
        if (!to)
        {                // 如果to是nullptr
            root = node; // 将节点设为根节点
        }
    }

    // 查找树中数值为val的节点
    Node *find(int val)
    {
        Node *cur = root; // 当前节点设为根节点
        while (cur)
        { // 遍历整棵树
            if (cur->val == val)
            {                        // 如果当前节点的值等于要查找的值
                splay(cur, nullptr); // 旋转当前节点到根节点
                return cur;          // 直接返回当前节点
            }
            if (cur->val > val)
            {                    // 如果要查找的值小于当前节点的值
                cur = cur->left; // 向左子树递归
            }
            else
            {                     // 否则
                cur = cur->right; // 向右子树递归
            }
        }
        return nullptr; // 如果没找到，返回nullptr
    }
};

int main()
{
    Splay splay_tree;

    // 插入元素
    splay_tree.insert(1);
    splay_tree.insert(3);
    splay_tree.insert(2);
    splay_tree.insert(4);

    // 查询排名
    cout << splay_tree.rank(3) << endl; // 输出2（因为3是第2小的数）

    // 查询值
    cout << splay_tree.at(2) << endl; // 输出3（因为第2小的数是3）

    // 删除元素
    splay_tree.erase(2);

    // 查询前驱
    cout << splay_tree.predecessor(3) << endl; // 输出1（因为3的前驱是1）

    // 查询后继
    cout << splay_tree.successor(3) << endl; // 输出4（因为3的后继是4）

    return 0;
}