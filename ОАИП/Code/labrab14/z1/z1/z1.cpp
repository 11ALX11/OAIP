#include <iostream>

using namespace std;

struct list {
    int value;
    struct list* next;
};

struct tree
{
    int value;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
};

void pushToList(struct list** head, int data);
void printList(const struct list* head);
void freeList(struct list* head);

struct tree* createTree(struct tree* root, int value);
struct tree* addToTree(struct tree* root, int value);
int countNodes(struct tree* root);

int main()
{
    cout << "Enter amount of elements:\n";
    int n;
    cin >> n;
    
    struct list* list = NULL;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        pushToList(&list, value);
    }

    printList(list);
    freeList(list);

    cout << "Enter amount of elements:\n";
    cin >> n;

    struct tree* tree = NULL;
    tree = createTree(tree, 0);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        addToTree(tree, value);
    }

    cout << "Positive - " << countNodes(tree->right) << endl;
    cout << "Negative - " << countNodes(tree->left) << endl;
}

void pushToList(struct list** head, int data) {
    struct list* tmp = (struct list*)malloc(sizeof(struct list));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void printList(const struct list* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void freeList(struct list* head) {
    struct list* head_old;
    while (head) {
        head_old = head;
        head = head->next;
        free(head_old);
    }
};

struct tree* createTree(struct tree* root, int value) {
    struct tree* tmp = (struct tree*)malloc(sizeof(struct tree));
    tmp->value = value;
    tmp->parent = NULL;
    tmp->left = tmp->right = NULL;
    root = tmp;
    return root;
}

struct tree* addToTree(struct tree* root, int value) {
    struct tree* root2 = root, * root3 = NULL;
    struct tree* tmp = (struct tree*)malloc(sizeof(struct tree));
    tmp->value = value;
    while (root2 != NULL)
    {
        root3 = root2;
        if (value < root2->value)
            root2 = root2->left;
        else
            root2 = root2->right;
    }
    tmp->parent = root3;
    tmp->left = NULL;
    tmp->right = NULL;
    if (value < root3->value) root3->left = tmp;
    else root3->right = tmp;
    return root;
}

int countNodes(struct tree* root) {
    int tmp = 0;
    if (root == NULL)
        return tmp;
    if (root->value) tmp++;
    
    tmp += countNodes(root->left);
    tmp += countNodes(root->right);
    
    return tmp;
}