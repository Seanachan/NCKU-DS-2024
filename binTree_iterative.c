#include<stdio.h>
#include<stdlib.h>
typedef struct node* treePointer;
struct node{
    char data;
    treePointer left,right;
};
treePointer createNode(char d){
    treePointer newNode = (treePointer) malloc(sizeof(struct node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void postOrder(treePointer ptr){
    if(ptr-> left!= NULL) postOrder(ptr->left);
    if(ptr-> right != NULL) postOrder(ptr->right);
    printf("%c ",ptr->data);
    return;
}
void preOrder(treePointer ptr){
    printf("%c ",ptr->data);
    if(ptr->left != NULL) preOrder(ptr->left);
    if(ptr->right !=NULL) preOrder(ptr->right);
    return;
}
void inOrder(treePointer ptr){
    if(ptr->left != NULL) preOrder(ptr->left);
    printf("%c ",ptr->data);
    if(ptr->right !=NULL) preOrder(ptr->right);
    return;
}   
int main(){
    treePointer root = createNode( 'A'); 
    root->left = createNode('B');
    root->right = createNode('C');

    root->left->left=createNode('D');
    root->left->left->left = createNode('H');

    root->left->right = createNode('E');
    root->left->right->right = createNode('I');

    root->right->right=  createNode('G');
    root->right->left = createNode('F');
    root->right->left->left = createNode('J');
    printf("\nPost Order : ");
    postOrder(root);
    printf("\nPre Order : ");
    preOrder(root);
   printf("\nIn Order : ");
    inOrder(root);
    return 0;
}
