#include<iostream>
#include<stack>
using namespace std;
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
void postOrder(treePointer root) {
    stack<treePointer> s;
    treePointer cur = root;
    while(true){
        while(cur){
            if(cur->right)
                s.push(cur->right);
            s.push(cur);

            cur=cur->left;
        }
        cur=s.top();
        s.pop();

        if(cur->right!=NULL && s.top()==cur->right){
            //cur is root
            //before traverse right, push root again
            //printf("%d\n",cur->right==s.top());
            s.pop();//the right of cur(root)
            s.push(cur);//root
            cur=cur->right;
        }else{
            printf("%c ",cur->data);
            cur=NULL;
        }
        if(s.empty()) break;
    }
}
void inOrder(treePointer ptr){
    if(ptr->left != NULL) inOrder(ptr->left);
    printf("%c ",ptr->data);
    if(ptr->right !=NULL) inOrder(ptr->right);
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
    return 0;
}
