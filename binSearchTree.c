#include<stdio.h>
#include<stdlib.h>
typedef struct Node* node;
#define COUNT 10
struct Node{
    node left,right;
    int key; 
};
node createNode(int key){
    node n = (node) malloc(sizeof(struct Node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    return n;
}
node insert(node root, int key){
   if(root==NULL)
        return createNode(key);
   if(root->key==key)
        return root;
   if(root->key < key)
       root->right=insert(root->right,key);

    else
        root->left = insert(root->left,key);

    return root;
}
node search(node root, int key){
   if(root->key==key)
        return root;
    if(key < root->key)
        return search(root->left,key);
    else
        return search(root->right,key);
}
void print2DUtil(struct Node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
int main(){
    node root = createNode(20);
    insert(root,10);
    insert(root,40);
    insert(root,6); 
    insert(root,15);
    insert(root,30);
    insert(root,2);
    insert(root,8);
    insert(root,30);
    insert(root,25);
    insert(root,35);
    print2D(root);
    return 0;
}   
