#include<iostream>
using namespace std;
class node{
public:
int data;
node * left;
node * right;
node(int data){
    this->data=data;
    this->left=nullptr;
    this->right=nullptr;
}
};
class binarySearchTree{
public:
node * root;
binarySearchTree(){
    this->root=nullptr;
}
};
// recursive insertion apporach
void insertion(node * & root,int value){
    if(root==nullptr){ // base Case
    node * newnode=new node(value);
    root=newnode;
    return;
    }
    if(root->data>value){
        insertion(root->left,value);
    }
    else{
        insertion(root->right,value);
    }
}
int height(node * root){
    if(root==nullptr){
       return 0;
    }
    else {
        return 1+max(height(root->left),height(root->right));
    }
}
void printlevel(node * root,int level){
    
   if(root==nullptr){
    return;
   }
    if(level==1){
        cout<<root->data<<" ";
        return ;
    }
   else if(level>1){
    printlevel(root->left,level-1);
    printlevel(root->right,level-1);
   }
}
void breatfirstsearch(node * root){
    int h=height(root);
    for(int i=0;i<=h;i++){
        printlevel(root,i);
    }
}
string Search_e(node * root,int value){
    if(root==nullptr){
        return "Not Found!";
    }
    if(root->data==value){
        return "Found Successfully";
    }
    if(root->data>value){
       return Search_e(root->left,value);
    }
    else
    {
       return Search_e(root->right,value);
    }
  return "NULL";
}
void infix(node * root){
    if(root==nullptr){
        return;
    }
    else{
        infix(root->left);
        cout<<root->data<<" ";
        infix(root->right);
    }
}
void search_min(node * root){
    if(root==nullptr){
        cout<<"Tree is Empty"<<endl;
    }
    else{
        while(root->left!=nullptr){
          root=root->left;
        }
        cout<<"Minimum Value in the Tree is:\t"<<root->data<<endl;
    }
}
node * search_max(node * root){
    if(root==nullptr){
        return nullptr;
    }
    else{
        while(root->right!=nullptr){
          root=root->right;
        }
        return root;
    }
}
// deletion in binary Search Tree
node * deletebst(node * root,int value){
    if(root==nullptr){
        return root; // mean tree is empty/value not exisit
    }
    if(value<root->data){
        root->left=deletebst(root->left,value);
    }
    else if(value>root->data){
        root->right=deletebst(root->right,value);
    }
    else{
        // case 1  only leave
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return NULL; // update it pointer value
        }
        // case 2 consist of only one node either on left or right
         if(root->left==nullptr){
            node * temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr){
            node * temp=root->left;
            delete root;
            return temp;
        }
     // case three delete node has left and right
     else{
        // find the left must greatest node
        node * replace=search_max(root->left);
        root->data = replace->data;
        root->left=deletebst(root->left,replace->data);
     }

    }
    return root; // updated
}


int main()
{
    binarySearchTree b1;
    insertion(b1.root,10);
    insertion(b1.root,5);
    insertion(b1.root,21);
    insertion(b1.root,3);
    insertion(b1.root,6);
    insertion(b1.root,11);
    insertion(b1.root,31);
    breatfirstsearch(b1.root);
    cout<<endl;
    search_max(b1.root);
    search_min(b1.root);
    cout<<endl;
    cout<<Search_e(b1.root,31);
    cout<<endl;
    cout<<Search_e(b1.root,202);
    b1.root=deletebst(b1.root,5);
    cout<<endl;
    breatfirstsearch(b1.root);





    
    return 0;
}