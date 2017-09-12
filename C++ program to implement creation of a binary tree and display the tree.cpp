/*************************************************************
Program for creation of a binary tree and display the tree
*************************************************************/
#include <iostream.h>
#include<conio.h>
#define size 10
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
    node *que[10];
    int front,rear;
    TREE_CLASS();
    void create();
    void insert(node *, node *);
    int Height(node *root);
    void Leaf_nodes(node *root,int *);
    void convert();
    void Mirror(node *root);
    void Display(node *root);
    void enque(node *temp);
    node* deque();
};
TREE_CLASS::TREE_CLASS()
{
    root=NULL;
    front=rear=-1;
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
            cin>>ans;
        }
    while(ans=='y'||ans=='Y');
    clrscr();
}
void TREE_CLASS::insert(node *root, node *New)
{
    if(New->data >root->data)
        {
            if(root->right!=NULL)
                insert(root->right,New);
            else
                root->right=New;
        }
    else if(New->data<root->data)
        {
            if(root->left!=NULL)
                insert(root->left,New);
            else
                root->left=New;
        }
}
int TREE_CLASS::Height(node *root)
{
    int d1,d2;
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;
    d1=Height(root->left);//computing height of leftsubtree
    d2=Height(root->right);//computing height of rightsubtree
    if(d1>d2)
        return d1+1;
    else
        return d2+1;
//maximum depth=height of the tree
}
void TREE_CLASS::Leaf_nodes(node *root,int *count)
{
    if(root==NULL)
        cout<<"TREE IS NOT CREATED";
    if(root!=NULL)
        {
            if((root->left==NULL)&&(root->right==NULL))//leaf node obtained
                {
                    cout<<"  "<<root->data;//printing the leaf node
                    *count=*count+1;//incrementing count for leaf noe
                }
            else
                {
                    Leaf_nodes(root->left,count);//move on to the left sub-branch
                    Leaf_nodes(root->right,count);//move onto the right sub-branch
                }
        }
}
void TREE_CLASS::convert()
{
    cout<<"\n Original image is...\n";
    Display(root);
    Mirror(root);
    cout<<"\n Mirror image is created";
    cout<<"\n Mirror image is...\n";
    Display(root);
}

void TREE_CLASS::Mirror(node *root)
{
    node *temp_node;
    if(root!=NULL)
        {
            Mirror(root->left);
            Mirror(root->right);
//swapping the left and right child nodes
            temp_node=root->left;
            root->left=root->right;
            root->right=temp_node;
        }
}

void TREE_CLASS::enque(node *temp)
{
    if ( rear == size-1)
        {
            cout<<"Queue is empty\n";
            return;
        }
    rear = rear + 1;
    que[rear] = temp;
}

node* TREE_CLASS::deque()
{
    node *temp;
    if ( front == rear )
        {
            cout<<"Queue is empty";
            return NULL;
        }
    front++;
    temp = que[front];
    return temp;
}

void TREE_CLASS::Display(node *root)
{
    node *temp, *dummy;
    dummy = new node;
    front=rear=-1;
    if ( dummy == NULL)
        cout<<"Insufficient Memory\n";
    dummy->left = root;
    dummy->right = NULL;
    dummy->data = -999;
    temp = dummy ->left;
    enque(temp); //inserting the node in the queue
    enque(dummy);
    temp=deque();//deleting the node from the queue
    cout<<"\n";
    while ( front != rear)
        {
            if ( temp != dummy)
                {
                    cout<<"  "<<temp->data;
                    if ( temp ->left != NULL)
                        enque(temp -> left);
                    if ( temp ->right != NULL)
                        enque(temp -> right);
                }
            else
                {
                    enque(temp);
                    cout<<"\n";
                }
            temp=deque();
        }
}
void main()
{
    int choice;
    TREE_CLASS obj;
    int ht;
    int *count;
    clrscr();
    do
        {
            cout<<"\n Program For Implementing Simple Binary Tree";
            cout<<"\n 1.Create";
            cout<<"\n 2.Height of Binary Tree";
            cout<<"\n 3.Leaf Nodes";
            cout<<"\n 4.Mirror image";
            cout<<"\n 5.Level-wise Display";
            cout<<"\n 6.Exit";
            cout<<"\n\t Enter Your Choice: ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    obj.create();
                    break;
                case 2:
                    ht=obj.Height(obj.root);
                    cout<<"\n The height of the tree is: "<<ht;
                    break;
                case 3:
                    *count=0;
                    cout<<"\n Leaf nodes are...\n";
                    obj.Leaf_nodes(obj.root,count);
                    cout<<"\n The total leaf nodes are: "<<*count;
                    break;
                case 4:
                    obj.convert();
                    break;
                case 5:
                    obj.Display(obj.root);
                    getch();
                    break;
                }
        }
    while(choice<=5);
    getch();
}
