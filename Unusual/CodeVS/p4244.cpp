#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

struct TreeNode {
    int num;
    int deep;
    int detla;
    TreeNode* Lchild;
    TreeNode* Rchild;
};

TreeNode *head;
int n, m, x;

int newtree(TreeNode* &k) {
    k = (TreeNode *) malloc (sizeof(TreeNode));
    k->num = 0;
    k->deep = 1;
    k->detla = 0;
    k->Rchild = NULL;
    k->Lchild = NULL;
    return 0;
}

inline int UpdateDeep(TreeNode *k) {
    k->deep = 1;
    k->detla = 0;
    if (k->Lchild != NULL) {
        k->deep = max(k->deep, k->Lchild->deep + 1);
        k->detla = k->Lchild->deep;
    }
    if (k->Rchild != NULL) {
        k->deep = max(k->deep, k->Rchild->deep + 1);
        k->detla -= k->Rchild->deep;
    }
    return 0;
}

int Lchange(TreeNode* &k) {
    TreeNode *k1 = k->Lchild;
    k->Lchild = k1->Rchild;
    k1->Rchild = k;
    k = k1;
    UpdateDeep(k->Rchild);
    UpdateDeep(k);
    return 0;
}

int Rchange(TreeNode* &k) {
    TreeNode *k1 = k->Rchild;
    k->Rchild = k1->Lchild;
    k1->Lchild = k;
    k = k1;
    UpdateDeep(k->Lchild);
    UpdateDeep(k);
    return 0;
}

int DFS(TreeNode *Now) {
    if (Now->Lchild != NULL) {
        printf("(");
        DFS(Now->Lchild);
        printf(")");
    }
    printf("%d",Now->num);
    if (Now->Rchild != NULL) {
        printf("(");
        DFS(Now->Rchild);
        printf(")");
    }
    return 0;
}

int insert(TreeNode* &head, int x) {
    if (head == NULL) {
        newtree(head);
        head->num = x;
        return 0;
    }
    if (x <= head->num) {
        insert(head->Lchild, x);
    } else {
        insert(head->Rchild, x);
    }
    UpdateDeep(head);
    if (head->detla > 1)
        Lchange(head);
    if (head->detla < -1)
        Rchange(head);
    return 0;
}

int find(TreeNode *k) {
    if (k == NULL)
        return 0;
    if (k->num == x) {
        return 1;
    }
    if (x < k->num) {
        return find(k->Lchild);
    }
    return find(k->Rchild);
}

int main() {
    scanf("%d%d",&n,&m);
    head = NULL;
    while (n--) {
        scanf("%d", &x);
        insert(head, x);
    }
    while (m--) {
        scanf("%d", &x);
        printf("%d ", find(head));
    }
    printf("\n");
    return 0;
}
