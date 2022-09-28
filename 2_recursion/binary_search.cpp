#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node** root, int data);
int size(node* root);
int height(node* root);
int sumOfWeight(node* root);
int maxPathWeight(node* root);
void mirror(node** root);
void preOrder(node* root);
void inOrder(node* root);
void postOrder(node* root);
void destruct(node** root);

int main(){
    int numTestCases;
    cin >> numTestCases;
    while (numTestCases--){
        int num, i;
        node* root = NULL;

        cin >> num;
        for(int i=0;i<num;i++){
            int data;

            cin >> data;
            // cout << "insert: " << data << endl;
            insert(&root, data);
        }
        
        cout << size(root) << endl;
        cout << height(root) << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;
        mirror(&root);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        destruct(&root);
        if(root == NULL){
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }

    }
    return 0;
}

void insert(node** root, int data) {
    if(*root == NULL){
        // cout << "root" << endl;
        *root = new node;
        (*root)->data = data;
    } else {
        int base = (*root)->data;
        if(base > data) { // 기존 보다 작다면 
            if((*root)->left == NULL){ //비어 있다면 넣기
                // cout << "left insert" << endl;
                node* new_node = new node;
                new_node->data = data;
                (*root)->left = new_node;
            } else { //비어져 있지 않으면 탐색
                // cout << "left" << endl;
                insert(&(*root)->left,data);
            }
        } else { // 기존 보다 크다면
            if((*root)->right == NULL){ //비어 있다면 넣기
                // cout << "right insert" << endl;
                node* new_node = new node;
                new_node->data = data;
                (*root)->right = new_node;
            } else { //비어져 있지 않으면 탐색
                // cout << "right" << endl;
                insert(&(*root)->right,data);
            }
        }
    }
}

int size(node* root){
    if(root == NULL){
        return 0;
    }
    return size(root->left) + 1 + size(root->right);
}

int height(node* root) {
    if(root==NULL){
        return -1;
    }

    int a = height(root->left);
    int b = height(root->right);
    if(a>b){
        return a + 1;
    } else {
        return b + 1;
    }
}

int sumOfWeight(node* root){
    if(root==NULL){
        return 0;
    }
    return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data;
}

int maxPathWeight(node* root){
    if(root==NULL){
        return 0;
    }

    int a = maxPathWeight(root->left);
    int b = maxPathWeight(root->right);
    if(a>b){
        return a + root->data;
    } else {
        return b + root->data;
    }
}

void mirror(node** root){
    if(*root == NULL){
        return;
    }
    mirror(&(*root)->left);
    mirror(&(*root)->right);
    node* temp_node;
    temp_node = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp_node;
}

void preOrder(node* root){
    if(root == NULL){
        return;
    } 
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if(root == NULL){
        return;
    } 
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        return;
    } 
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void destruct(node** root) {
    if((*root) == NULL){
        return;
    } 

    destruct(&(*root)->left);
    destruct(&(*root)->left);
    *root = NULL;
}