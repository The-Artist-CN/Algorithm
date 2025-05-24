#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(Node* root){
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d",root->value);
    inorderTraversal(root->right);

}

int main(){
    Node* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("result = \n");
    inorderTraversal(root);
    printf("\n");

    return 0;

}
