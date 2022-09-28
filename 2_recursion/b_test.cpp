#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node** root, int data);

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
            insert(&root, data);
        }


    }
    return 0;
}

// void insert(node** root, int data) {
//     if(root == NULL){
//         (*root)->data = 5;
//     } else {
//         int base = (*root)->data;
//         // node* child = NULL;
//         if(base > data) { // 기존 보다 작다면 
//             node* leftNode = (*root)->left;
//             if(leftNode == NULL){ //비어 있다면 넣기
//                 node* new_node = new node;
//                 new_node->data = data;
//                 (*root)->left = new_node;
//             } else { //비어져 있지 않으면 탐색
//                 insert(&leftNode,data);
//             }
//         } else { // 기존 보다 크다면
//             node* rightNode = (*root)->right;
//             if(rightNode == NULL){ //비어 있다면 넣기
//                 node* new_node = new node;
//                 new_node->data = data;
//                 (*root)->right = new_node;
//             } else { //비어져 있지 않으면 탐색
//                 insert(&rightNode,data);
//             }
//         }
//     }
// }


