
/******************************************************
Program for creating an expression tree and printing it using an inorder traversal
*******************************************************/
#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#define size 20
typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} btree;
class EXP_TREE
{
private:

    /*stack stores the operand nodes of the tree*/
    btree  *stack[size];
    int  top;
public:
    btree *root;
    EXP_TREE();
    void create(char exp[]);
    void push(btree *);
    void display(btree *root);
    btree* pop();

};
EXP_TREE::EXP_TREE()
{
    root=NULL;
    top=-1;//initializing stack
}
void EXP_TREE::create(char exp[])
{
    int pos;
    char ch;
    pos = 0;
    ch = exp[pos];
    while ( ch !='\0')
        {
            /* Create a new node */
            root = new btree;
            root -> left = root -> right = NULL ;
            root -> data = ch;
            if (isalpha( ch) ) /* is it a operand */
                push ( root); /* push operand */
            else if ( ch=='+' ||ch=='-'||ch=='*'||ch=='/')
                {
                    /* it is operator, so pop two nodes from stack
                      set first node as right child and
                      set second as left child and push the
                    operator node on to the stack
                    */
                    root->right = pop();
                    root->left = pop();
                    push(root);
                }
            else
                cout<<"Invalid character in expression\n";
            pos ++;
            ch = exp[pos]; /* Read next character */
        }
    root= pop();
}
void EXP_TREE::push(btree *Node)
{
    if ( top+1 >= size )
        cout<<"Error: Stack is Full\n";
    top++;
    stack[top] = Node;
}

btree* EXP_TREE::pop()
{
    btree *Node;
    if ( top == -1 )
        cout<<"Error: Stack is Empty\n";
    Node = stack[top];
    top--;
    return(Node);
}

void EXP_TREE::display(btree *root)
{
    btree *temp;
    temp = root;
    if (temp != NULL )
        {
            display(temp->left);
            cout<<" "<<temp->data;
            display(temp->right);
        }
}

void main()
{
    char  exp[80]; /* exp stores postfix expression */
    EXP_TREE obj;
    clrscr();
    cout<<"Enter the postfix expression\n";
    cin>>exp;
    obj.create(exp);
    cout<<"\n The Tree is created...\n";
    cout<<"\n The inorder traversal of it is \n ";
    obj.display(obj.root);
    getch();
}
