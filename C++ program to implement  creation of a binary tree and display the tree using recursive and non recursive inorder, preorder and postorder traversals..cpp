/*************************************************************
Program for creation of a binary tree and display the tree
using recursive and non recursive inorder, preorder
and postorder traversals.
*************************************************************/
#include <iostream.h>
#include<conio.h>
class TREE_CLASS
{
private:
    typedef struct bin
    {
        int data;
        struct bin *left;
        struct bin *right;
    } node; /*Binary tree structure*/
public:
    node *New,*root;
    TREE_CLASS();
    void create();
    void insert(node *, node *);
    void push(node *item,int *top,node *s[10]);
    int stempty(int);
    void pop(int *top,node *s[10],node **curent);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void rec_inorder(node *);
    void rec_preorder(node *);
    void rec_postorder(node *);
};
TREE_CLASS::TREE_CLASS()
{
    root=NULL;
}
void TREE_CLASS::create()
{
    char ans='y';
    do
        {
            New=new node;
            cout<<"\n Enter The Element: ";
            cin>>New->data;
            New->left=NULL;
            New->right=NULL;
            if(root==NULL)
                root=New;
            else
                insert(root,New);
            cout<<"\n Do You want To Enter More elements?(y/n): ";
            ans=getche();
        }
    while(ans=='y'||ans=='Y');
    clrscr();
}
void TREE_CLASS::insert(node *root, node *New)
{
    char ch;
    cout<<"\n Where to insert left/right of "<<root->data<<": ";
    ch=getche();
    if((ch=='r')||(ch=='R'))
        {
            if(root->right==NULL)
                {
                    root->right=New;
                }
            else
                insert(root->right,New);
        }
    else
        {
            if (root->left==NULL)
                {
                    root->left=New;
                }
            else
                insert(root->left,New);
        }
}

void TREE_CLASS::inorder(node *root)
{
    node *current,*s[10];
    int top=-1;
    if(root==NULL)
        {
            cout<<"\n Tree is empty\n";
            return;
        }
    current=root;
    for(;;)
        {
            while(current!=NULL)
                {
                    push(current,&top,s);
                    current=current->left;
                }
            if(!stempty(top))
                {
                    pop(&top,s,&current);
                    cout<<" "<<current->data;
                    current=current->right;
                }
            else
                return;
        }
}
void TREE_CLASS::preorder(node *root)
{
    node *current,*s[10];
    int top=-1;
    if(root==NULL)
        {
            cout<<"\n The Tree is empty\n";
            return;
        }
    current=root;
    for(;;)
        {
            while(current!=NULL)
                {
                    cout<<" "<<current->data;
                    push(current,&top,s);
                    current=current->left;
                }
            if(!stempty(top))
                {
                    pop(&top,s,&current);
                    current=current->right;
                }
            else
                return;
        }
}
void TREE_CLASS::postorder(node *root)
{
    struct stack
    {
        node *element;//Here placing the node containing value
        int check;//check 1 means visiting left subtree
        //check 0 means visiting right subtree
    } st[10];
    int top=-1;
    node *current;
    if(root==NULL)
        {
            cout<<"\n The Tree is empty\n";
            return;
        }
    current=root;
    for(;;)
        {
            while(current!=NULL)
                {
                    top++;
                    st[top].element=current;
                    st[top].check=1;//visiting the left subbranch
                    current=current->left;
                }
            while(st[top].check==0)
                {
                    current=st[top].element;
                    top--;
                    cout<<"  "<<current->data;
                    if(stempty(top))
                        return;
                }
            current=st[top].element;//pushing the element onto the stack
            current=current->right;
            st[top].check=0;//visiting right subtree
        }
}
void TREE_CLASS::push(node *item,int *top,node *s[])
{
    *top=*top+1;
    s[*top]=item;
}
/*
	popping the element from the stack

*/
void TREE_CLASS::pop(int *top,node *s[],node **current)
{
    *current=s[(*top)--];
}
/*
 Checking for stack empty condition
*/
int TREE_CLASS::stempty(int top)
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void TREE_CLASS::rec_inorder(node *root)
{
    if(root!=NULL)
        {
            rec_inorder(root->left);
            cout<<"  "<<root->data;
            rec_inorder(root->right);
        }
}
void TREE_CLASS::rec_preorder(node *root)
{
    if(root!=NULL)
        {
            cout<<"  "<<root->data;
            rec_preorder(root->left);
            rec_preorder(root->right);
        }
}
void TREE_CLASS::rec_postorder(node *root)
{
    if(root!=NULL)
        {
            rec_postorder(root->left);
            rec_postorder(root->right);
            cout<<"  "<<root->data;
        }
}

void main()
{
    int choice;
    TREE_CLASS obj;
    clrscr();
    do
        {
            cout<<"\n Program For Implementing Simple Binary Tree";
            cout<<"\n 1.Create";
            cout<<"\n 2.Non-Recursive Inorder";
            cout<<"\n 3.Non-Recursive Preorder";
            cout<<"\n 4.Non-Recursive Postorder";
            cout<<"\n 5.Recursive Inorder";
            cout<<"\n 6.Recursive Preorder";
            cout<<"\n 7.Recursive Postorder";
            cout<<"\n 8.Exit";
            cout<<"\n\t Enter Your Choice: ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    obj.create();
                    break;
                case 2:
                    if(obj.root==NULL)
                        cout<<"Tree Is not Created!";
                    else
                        obj.inorder(obj.root);
                    break;
                case 3:
                    if(obj.root==NULL)
                        cout<<"Tree Is Not Created!";
                    else
                        obj.preorder(obj.root);
                    break;
                case 4:
                    if(obj.root==NULL)
                        cout<<"Tree Is Not Created!";
                    else
                        obj.postorder(obj.root);
                    break;
                case 5:
                    if(obj.root==NULL)
                        cout<<"Tree Is not Created!";
                    else
                        obj.rec_inorder(obj.root);
                    break;
                case 6:
                    if(obj.root==NULL)
                        cout<<"Tree Is Not Created!";
                    else
                        obj.rec_preorder(obj.root);
                    break;
                case 7:
                    if(obj.root==NULL)
                        cout<<"Tree Is Not Created!";
                    else
                        obj.rec_postorder(obj.root);
                    break;
                }
        }
    while(choice<=7);
}
