/*************************************************************************
Program For Implementation Of Inorder Threaded Binary Search Tree
and perform insertion,deletion and display of tree.
**************************************************************************/
# include <iostream.h>
# include <conio.h>
typedef struct bst
{
    int data;
    int lth,rth;
    struct bst *left,*right;
} node;
class thread
{
private:

    node *dummy;
    node *New,*root,*temp,*parent;
public:
    thread();
    void create(); //All The implementation Details are hidden!
    void display();
    void find();
    void delet();
};
/*
--------------------------------------------------------------------------
The constructor defined
--------------------------------------------------------------------------
*/
thread::thread()
{
    root=NULL;
}
/*
--------------------------------------------------------------------------
The create function
--------------------------------------------------------------------------
*/
void thread::create()
{
    void insert(node *,node *);
    New=new node;
    New->left=NULL;
    New->right=NULL;
    New->lth=0;
    New->rth=0;
    cout<<"\n Enter The Element ";
    cin>>New->data;
    if(root==NULL)
        {
            // Tree is not Created
            root=New;
            dummy=new node;
            dummy->data=-999;
            dummy->left=root;
            root->left=dummy;
            root->right=dummy;
        }
    else
        insert(root,New);
}

/*
--------------------------------------------------------------------------
The display function
--------------------------------------------------------------------------
*/
void thread::display()
{
    void inorder(node *,node *dummy);
    if(root==NULL)
        cout<<"Tree Is Not Created";
    else
        {
            cout<<"\n The Tree is : ";
            inorder(root,dummy);
        }
}
/*
--------------------------------------------------------------------------
The find function which calls the routine for searching an elemnt
--------------------------------------------------------------------------
*/
void thread::find()
{
    node *search(node *,node *,int,node **);
    int key;
    cout<<"\n Enter The Element Which You Want To Search";
    cin>>key;
    temp=search(root,dummy,key,&parent);
    if(temp==NULL)
        cout<<"\nElement is Not Present";
    else
        cout<<" It's Parent Node is "<<parent->data;
}
/*
--------------------------------------------------------------------------
The delet function which calls the routine for deletion of an element
--------------------------------------------------------------------------
*/
void thread::delet()
{
    void del(node *,node *,int);
    int key;
    cout<<"\n Enter The Element U wish to Delete";
    cin>>key;
    del(root,dummy,key);
}
/*
--------------------------------------------------------------------------
This function is for creating a binary search tree
--------------------------------------------------------------------------
*/
void insert(node *root,node *New)
{
    if(New->data<root->data)
        {
            if(root->lth==0)
                {
                    New->left=root->left;
                    New->right=root;
                    root->left=New;
                    root->lth=1;
                }
            else
                insert(root->left,New);
        }
    if(New->data>root->data)
        {
            if(root->rth==0)
                {
                    New->right=root->right;
                    New->left=root;
                    root->rth=1;
                    root->right=New;
                }
            else
                insert(root->right,New);
        }
}
/*
--------------------------------------------------------------------------
The search function
--------------------------------------------------------------------------
*/
node *search(node *root,node *dummy,int key,node **parent)
{
    node *temp;
    int flag=0;
    temp=root;
    while((temp!=dummy))
        {
            if(temp->data==key)
                {
                    cout<<"\n The "<<temp->data<<" Element is Present";
                    flag=1;
                    return temp;
                }
            *parent=temp;
            if(temp->data>key)
                temp=temp->left;
            else
                temp=temp->right;
        }
    return NULL;
}

/*
--------------------------------------------------------------------------
This function is for deleting a node from binary search tree
There exists three possible cases for deletion of a node
--------------------------------------------------------------------------
*/

void del(node *root,node *dummy,int key)
{
    node *temp,*parent,*temp_succ;
    node *search(node *,node *,int,node **);
    int flag=0;
    temp=search(root,dummy,key,&parent);
    if(root==temp)
        {
            cout<<"\n Its Root Node Which Can Not Be Deleted!!";
            return;
        }
    //deleting a node with two children
    if(temp->lth==1&&temp->rth==1)
        {
            parent=temp;
            temp_succ=temp->right;//Finding Inorder successor
            while(temp_succ->lth==1)
                {
                    flag=1;
                    parent=temp_succ;
                    temp_succ=temp_succ->left;
                }
            if(flag==0)
                {
                    temp->data=temp_succ->data;
                    parent->right=temp_succ->right;
                    parent->rth=0;
                }
            else//inorder successor is on left subbranch.
                // and it has to be traversed
                {
                    temp->data=temp_succ->data;
                    parent->rth=0;
                    parent->lth=0;
                    parent->left=temp_succ->left;
                }
            cout<<" Now Deleted it!";
            return;
        }
//deleting a node having only one child
    //The node to be deleted has left child
    if(temp->lth==1 &&temp->rth==0)
        {
            if(parent->left==temp)
                {
                    (temp->left)->right=parent;
                    parent->left=temp->left;
                }
            else
                {
                    (temp->left)->right=temp->right;
                    parent->right=temp->left;
                }
            temp=NULL;
            delete temp;
            cout<<" Now Deleted it!";
            return;
        }
    //The node to be deleted has right child
    if(temp->lth==0 &&temp->rth!=0)
        {
            if(parent->left==temp)
                {
                    parent->left=temp->right;
                    (temp->right)->left=temp->left;
                    (temp->right)->right=parent;
                }
            else
                {
                    parent->right=temp->right;
                    (temp->right)->left=parent;
                }
            temp=NULL;
            delete temp;
            cout<<" Now Deleted it!";
            return;
        }
    //deleting a node which is having no child
    if(temp->lth==0 &&temp->rth==0)
        {
            if(parent->left==temp)
                {
                    parent->left=temp->left;
                    parent->lth=0;
                }
            else
                {
                    parent->right=temp->right;
                    parent->rth=0;
                }
            cout<<" Now Deleted it!";
            return;
        }
}
/*
--------------------------------------------------------------------------
The inorder function
--------------------------------------------------------------------------
*/
void inorder(node *temp,node *dummy)
{
    while(temp!=dummy)
        {
            while(temp->lth==1)
                temp=temp->left;
            cout<<"  "<<temp->data;
            while(temp->rth==0)
                {
                    temp=temp->right;
                    if(temp==dummy)
                        return;
                    cout<<"  "<<temp->data;
                }
            temp=temp->right;
        }
}
/*
--------------------------------------------------------------------------
The main function
--------------------------------------------------------------------------
*/
void main()
{
    int choice;
    char ans='N';
    thread th;
    clrscr();
    do
        {
            clrscr();
            cout<<"\n\t Program For Threaded Binary Tree";
            cout<<"\n1.Create \n2.Display \n3.Search \n4.Delete";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    do
                        {
                            th.create();
                            cout<<"\n Do u Want To enter More  Elements?(y/n)";
                            ans=getch();
                        }
                    while(ans=='y');
                    break;
                case 2:
                    th.display();
                    break;
                case 3:
                    th.find();
                    break;
                case 4:
                    th.delet();
                    break;
                }
            cout<<"\n\nWant To See Main Menu?(y/n)";
            ans=getche();
        }
    while(ans=='y');
}

