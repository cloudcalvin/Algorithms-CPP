#include<iostream.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 	 1

//Tree node

typedef struct Node
{
    int data;
    int BF;
    struct Node *left;
    struct Node *right;
} node;

class AVL
{
    node *root;
public:
    AVL()
    {
        root=NULL;
    }
    node *insert(int data,int *current)
    {
        root=create(root,data,current);
        return root;
    }
    node *create(node *root,int data,int *current);
    node *remove(node *root,int data,int *current);
    node *find_succ(node *temp,node *root,int *current);
    node *right_rotation(node *root,int *current);
    node *left_rotation(node *root,int *current);
    void display(node *root);
};
node *AVL::create(struct Node *root,int data,int *current)
{
    node *temp1,*temp2;
    if(root==NULL)//initial node
        {
            root= new node;
            root->data=data;
            root->left=NULL;
            root->right=NULL;
            root->BF=0;
            *current=TRUE;
            return(root);
        }
    if(data<root->data)
        {
            root->left=create(root->left,data,current);
            // adjusting left subtree
            if(*current)
                {
                    switch(root->BF)
                        {
                        case 1:
                            temp1=root->left;
                            if(temp1->BF==1)
                                {
                                    cout<<"\n single rotation: LL rotation";
                                    root->left=temp1->right;
                                    temp1->right=root;
                                    root->BF=0;
                                    root=temp1;
                                }
                            else
                                {
                                    cout<<"\n Double rotation:LR rotation";
                                    temp2=temp1->right;
                                    temp1->right=temp2->left;
                                    temp2->left=temp1;
                                    root->left=temp2->right;
                                    temp2->right=root;
                                    if(temp2->BF==1)
                                        root->BF=-1;
                                    else
                                        root->BF=0;
                                    if(temp2->BF==-1)
                                        temp1->BF=1;
                                    else
                                        temp1->BF=0;
                                    root=temp2;
                                }
                            root->BF=0;
                            *current=FALSE;
                            break;
                        case 0:
                            root->BF=1;
                            break;
                        case -1:
                            root->BF=0;
                            *current=FALSE;
                        }
                }
        }
    if(data> root->data)
        {
            root->right=create(root->right,data,current);
//adjusting the right subtree
            if(*current!=NULL)
                {
                    switch(root->BF)
                        {
                        case 1:
                            root->BF=0;
                            *current=FALSE;
                            break;
                        case 0:
                            root->BF=-1;
                            break;
                        case -1:
                            temp1=root->right;
                            if(temp1->BF==-1)
                                {
                                    cout<<"\n single rotation:RR rotation";
                                    root->right=temp1->left;
                                    temp1->left=root;
                                    root->BF=0;
                                    root=temp1;
                                }
                            else
                                {
                                    cout<<"\n Double rotation:RL rotation";
                                    temp2=temp1->left;
                                    temp1->left=temp2->right;
                                    temp2->right=temp1;
                                    root->right=temp2->left;
                                    temp2->left=root;
                                    if(temp2->BF==-1)
                                        root->BF=1;
                                    else
                                        root->BF=0;
                                    if(temp2->BF==1)
                                        temp1->BF=-1;
                                    else
                                        temp1->BF=0;
                                    root=temp2;
                                }
                            root->BF=0;
                            *current=FALSE;
                        }
                }
        }
    return(root);
}
/*
	 Display of Tree in inorder fashion
*/
void AVL::display(node *root)
{
    if(root!=NULL)
        {
            display(root->left);
            cout<<root->data<<"   ";
            display(root->right);
        }
}
/*

  Deletion of desired node the tree

*/
node *AVL::remove(node *root,int data,int *current)
{
    node *temp;
    if(root->data==13)
        cout<<root->data;
    if(root==NULL)
        {
            cout<<"\n No such data";
            return (root);
        }
    else
        {
            if(data<root->data)
                {
                    root->left=remove(root->left,data,current);
                    if(*current)
                        root=right_rotation(root,current);
                }
            else
                {
                    if(data>root->data)
                        {
                            root->right=remove(root->right,data,current);
                            if(*current)
                                root=left_rotation(root,current);
                        }
                    else
                        {
                            temp=root;
                            if(temp->right==NULL)
                                {
                                    root=temp->left;
                                    *current=TRUE;
                                    delete(temp);
                                }
                            else
                                {
                                    if(temp->left==NULL)
                                        {
                                            root=temp->right;
                                            *current=TRUE;
                                            delete(temp);
                                        }
                                    else
                                        {
                                            temp->right=find_succ(temp->right,temp,current);
                                            if(*current)
                                                root=left_rotation(root,current);
                                        }
                                }
                        }
                }
        }
    return (root);
}
node *AVL::find_succ(node *succ,node *temp,int *current)
{
    node *temp1=succ;
    if(succ->left!=NULL)
        {
            succ->left=find_succ(succ->left,temp,current);
            if(*current)
                succ=right_rotation(succ,current);
        }
    else
        {
            temp1=succ;
            temp->data=succ->data;
            succ=succ->right;
            delete temp1;
            *current=TRUE;
        }
    return (succ);
}
node *AVL::right_rotation(node *root,int *current)
{
    node *temp1,*temp2;
    switch(root->BF)
        {
        case 1:
            root->BF=0;
            break;
        case 0:
            root->BF=-1;
            *current=FALSE;
            break;
        case -1:
            temp1=root->right;
            if(temp1->BF<=0)
                {
                    cout<<"\n single rotation: RR rotation";
                    root->right=temp1->left;
                    temp1->left=root;
                    if(temp1->BF==0)
                        {
                            root->BF=-1;
                            temp1->BF=1;
                            *current=FALSE;
                        }
                    else
                        {
                            root->BF=temp1->BF=0;
                        }
                    root=temp1;
                }
            else
                {
                    cout<<"\n Double Rotation:RL rotation";
                    temp2=temp1->left;
                    temp1->left=temp2->right;
                    temp2->right=temp1;
                    root->right=temp2->left;
                    temp2->left=root;
                    if(temp2->BF==-1)
                        root->BF=1;
                    else
                        root->BF=0;
                    if(temp2->BF==1)
                        temp1->BF=-1;
                    else
                        temp1->BF=0;
                    root=temp2;
                    temp2->BF=0;
                }
        }
    return (root);
}
node* AVL::left_rotation(node *root,int *current)
{
    node *temp1,*temp2;
    switch(root->BF)
        {
        case -1:
            root->BF=0;
            break;
        case 0:
            root->BF=1;
            *current=FALSE;
            break;
        case 1:
            temp1=root->left;
            if(temp1->BF>=0)
                {
                    cout<<"\nsingle rotation LL rotation";
                    root->left=temp1->right;
                    temp1->right=root;
                    if(temp1->BF==0)
                        {
                            root->BF=1;
                            temp1->BF=-1;
                            *current=FALSE;
                        }
                    else
                        {
                            root->BF=temp1->BF=0;
                        }
                    root=temp1;
                }
            else
                {
                    cout<<"\nDouble rotation:LR rotation";
                    temp2=temp1->right;
                    temp1->right=temp2->left;
                    temp2->left=temp1;
                    root->left=temp2->right;
                    temp2->right=root;
                    if(temp2->BF==1)
                        root->BF=-1;
                    else
                        root->BF=0;
                    if(temp2->BF==-1)
                        temp1->BF=1;
                    else
                        temp1->BF=0;
                    root=temp2;
                    temp2->BF=0;
                }
        }
    return root;
}
void main()
{
    AVL obj;
    node *root=NULL;
    int current;
    root=obj.insert(40,&current);
    root=obj.insert(50,&current);
    root=obj.insert(70,&current);
    cout<<endl;
    obj.display(root);
    cout<<endl;
    root=obj.insert(30,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(20,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(45,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(25,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(10,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(5,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(22,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(1,&current);
    cout<<endl;
    obj.display(root);
    root=obj.insert(35,&current);
    cout<<"\n\nFinal AVL tree is: \n";
    obj.display(root);
    root=obj.remove(root,20,&current);
    root=obj.remove(root,45,&current);
    cout<<"\n\n AVL tree after deletion of a node: \n";
    obj.display(root);
    cout<<"\n";
}



