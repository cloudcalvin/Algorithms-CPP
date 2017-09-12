/*************************************************************************
Implementation of various operations of  B-tree
*************************************************************************/
#include<iostream.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 5 //maximum order m
#define MIN 2 //minimum allowed elements in each node

typedef char Type[20];
typedef struct Btree
{
    Type key;//handling character type of elements
} BT;

typedef struct treenode
{
    int count;
    BT entry[MAX+1];
    treenode *branch[MAX+1];
} node;
class B
{
private:
    node *root;
public:
    int LT(char *,char *);
    int EQ(char *,char *);
    node *Search(Type target,node *root,int *targetpos);
    int SearchNode(Type target,node *current,int *pos);
    node *Insert(BT New,node *root);
    int MoveDown(BT New,node *current,BT *med,node **medright);
    void InsertIn(BT med,node *medright,node *current,int pos);
    void Split(BT med,node *medright,node *current,int pos,BT *newmedian, node **newright);
    void Delete(Type target, node **root);
    void Del_node(Type target, node *current);
    void Remove(node *current, int pos);
    void Successor(node *current, int pos);
    void Adjust(node *current, int pos);
    void MoveRight(node *current, int pos);
    void MoveLeft(node *current, int pos);
    void Combine(node *current, int pos);
    void InOrder(node *root);
};


int B::LT(char *a,char *b)
{
    if((strcmp(a,b)) < (0))
        return 1;
    else
        return 0;
}
int B::EQ(char *a,char *b)
{
    if((strcmp(a,b)) == (0))
        return 1;
    else
        return 0;
}
/*
Search: traverse B-tree in search of desired node
*/

node* B::Search(Type target, node *root, int *targetpos)
{
    if (root==NULL)
        return NULL;
    else if (SearchNode(target, root, targetpos))
        return root;
    else
        return Search(target, root->branch[*targetpos], targetpos);
}


/*
SearchNode: searches keys in current node for target
*/
int B::SearchNode(Type target,node *current, int *pos)
{
    if (LT(target, current->entry[1].key))
        {
            /* searching the leftmost branch. */
            *pos = 0;
            return 0;
        }
    else
        {
            /* searching between the keys   */
            for(*pos = current->count;
                    LT(target, current->entry[*pos].key) && *pos > 1; (*pos)--);
            return EQ(target, current->entry[*pos].key);
        }
}
/*
Insert: inserts key into the B-tree
*/
node *B::Insert(BT newentry,node *root)
{
    BT medentry; // node to be inserted as new root
    node *medright; // subtree on right of medentry
    node *New;  // required when the height of the tree increases
    if (MoveDown(newentry, root, &medentry, &medright))
        {
            New = new node;
            New->count = 1;
            New->entry[1] = medentry;
            New->branch[0] = root;
            New->branch[1] = medright;
            return New;
        }
    return root;
}
/*
 MoveDown: recursively move down tree searching for new key node
*/

int B::MoveDown(BT New,node *current,BT *med,node **medright)
{
    int pos;
    if (current == NULL)
        {
            *med = New;/*new node*/
            *medright = NULL;
            return 1;
        }
    else
        {
            /* Search the current node completely    */
            if(SearchNode(New.key, current, &pos))
                cout<<"Duplicate key !!";
            if(MoveDown(New, current->branch[pos], med, medright))
                if (current->count < MAX)
                    {
                        //median key will be inserted
                        InsertIn(*med, *medright, current, pos);
                        return 0;
                    }
                else//Due to new entry
                    {
                        //node has to split at median
                        Split(*med, *medright, current, pos, med, medright);
                        return 1;
                    }
            return 0;
        }
}


/*
 InsertIn: inserts a key into a node
 */

void B::InsertIn(BT med,node *medright,node *current, int pos)

{
    /* index to move keys to insert the current node   */
    int i;
    for (i = current->count; i > pos; i--)
        {
            /* Shift all the keys and branches to the right    */
            /* and insert the current node*/
            current->entry[i+1] = current->entry[i];
            current->branch[i+1] = current->branch[i];
        }
    current->entry[pos+1] = med;
    current->branch[pos+1] = medright;
    current->count++;
}


/* Split: splits a full node.
*/

void B::Split(BT med,node *medright,node *current, int pos,
              BT *newmedian,node **newright)
{
    int i;      /* used for copying from *current to new node   */
    int median; /* median position in the combined, overfull node   */
    if (pos <= MIN) /* Determine if new key belongs to left or right  */
        median = MIN;
    else
        median = MIN + 1;
    /* Get a new node and put it on the right  */
    *newright = new node;
    for (i = median+1; i <= MAX; i++)
        {
            /* Move half the keys  */
            (*newright)->entry[i - median] = current->entry[i];
            (*newright)->branch[i - median] = current->branch[i];
        }
    (*newright)->count = MAX - median;
    current->count = median;
    if (pos <= MIN)     /* Insertin the new key */
        InsertIn(med, medright, current, pos);
    else
        InsertIn(med, medright, *newright, pos - median);
    *newmedian = current->entry[current->count];
    (*newright)->branch[0] = current->branch[current->count];
    current->count--;
}


/*
 Delete: deletes desired node from the B-tree
*/

void B::Delete(Type target, node **root)
{
    node *Prev;
    Del_node(target,*root);
    if ((*root)->count == 0)//empty root
        {
            Prev = *root;
            *root = (*root)->branch[0];
            delete Prev;
        }
}


/* Del_node: look for target to delete.
*/

void B::Del_node(Type target,node *current)
{
    int pos;    /* location of target or of branch on which to search   */
    if (!current)
        {
            cout<<"Item not in the B-tree.";
            return;
        }
    else
        {
            if (SearchNode(target, current, &pos))
                if (current->branch[pos-1])
                    {
                        Successor(current, pos);
                        /* replaces entry[pos] by its successor */								Del_node(current->entry[pos].key,current->branch[pos]);
                    }
                else
                    Remove(current, pos);
            /* removes key from pos of *current   */
            else
                /* Desired node not present in the current node*/
                Del_node(target, current->branch[pos]);
            if (current->branch[pos])
                if (current->branch[pos]->count < MIN)
                    Adjust(current, pos);
        }
}


/* Remove: delete an entry and the branch to its right
*/

void B::Remove(node *current, int pos)
{
    int i;      /* index for moving entries */
    for (i = pos+1; i <= current->count; i++)
        {
            current->entry[i-1] = current->entry[i];
            current->branch[i-1] = current->branch[i];
        }
    current->count--;
}
/*
Successor: finds and replaces node  by its immediate successor
*/

void B::Successor(node *current, int pos)
{
    node *leaf;     /* used to move down the tree to a leaf */
    /* Move to leftmost    */
    for (leaf=current->branch[pos]; leaf->branch[0]; leaf = leaf->branch[0]);
    current->entry[pos] = leaf->entry[1];
}


/* Adjust: Adjusts the minimum number of nodes
*/

void B::Adjust(node *current, int pos)
{
    if (pos == 0)   /*  leftmost key  */
        if (current->branch[1]->count > MIN)
            MoveLeft(current, 1);
        else
            Combine(current, 1);
    else if (pos == current->count) /*  rightmost key */
        if (current->branch[pos-1]->count > MIN)
            MoveRight(current, pos);
        else
            Combine(current, pos);
    else if (current->branch[pos-1]->count > MIN)
        MoveRight(current, pos);
    else if (current->branch[pos+1]->count > MIN)
        MoveLeft(current, pos+1);
    else
        Combine(current, pos);
}

/*
 MoveRight: move a key to the right
*/
void B::MoveRight(node *current, int pos)
{
    int i;
    node *t;
    t = current->branch[pos];
    for (i = t->count; i > 0; i--)
        {
            /* Shift all keys in the right node one position   */
            t->entry[i+1] = t->entry[i];
            t->branch[i+1] = t->branch[i];
        }
    /* Move key from parent to right node  */
    t->branch[1] = t->branch[0];
    t->count++;
    t->entry[1] = current->entry[pos];
    /* Move last key of left node into parent  */
    t = current->branch[pos-1];
    current->entry[pos] = t->entry[t->count];
    current->branch[pos]->branch[0] = t->branch[t->count];
    t->count--;
}

/*
 MoveLeft: move a key to the left

 */
void B::MoveLeft(node *current, int pos)
{
    int i;
    node *t;
    t = current->branch[pos-1]; /* Move key from parent into left node */
    t->count++;
    t->entry[t->count] = current->entry[pos];
    t->branch[t->count] = current->branch[pos]->branch[0];
    t = current->branch[pos];  /* Move key from right node into parent */
    current->entry[pos] = t->entry[1];
    t->branch[0] = t->branch[1];
    t->count--;
    for (i = 1; i <= t->count; i++)
        {
            /* Shift all keys in right node one position leftward  */
            t->entry[i] = t->entry[i+1];
            t->branch[i] = t->branch[i+1];
        }
}


/*
Combine: combine adjacent nodes
*/

void B::Combine(node *current, int pos)
{
    int i;
    node *right;
    node *left;
    right = current->branch[pos];
    left = current->branch[pos-1];      /* Handling the left node */
    left->count++;              /* Insert the key from the parent  */
    left->entry[left->count] = current->entry[pos];
    left->branch[left->count] = right->branch[0];
    for (i = 1; i <= right->count; i++)
        {
            /* Insert all keys from right node */
            left->count++;
            left->entry[left->count] = right->entry[i];
            left->branch[left->count] = right->branch[i];
        }
    for (i = pos; i < current->count; i++)
        {
            /*  key from parent node gets deleted */
            current->entry[i] = current->entry[i+1];
            current->branch[i] = current->branch[i+1];
        }
    current->count--;
    delete right;    /* right node deleted  */
}


/*
InOrder: inorder traversal of the B-Tree
*/

void B::InOrder(node *root)
{
    int pos;
    if (root!=NULL)
        {
            InOrder(root->branch[0]);
            for (pos = 1; pos <= root->count; pos++)
                {
                    cout<<"  " <<root->entry[pos].key;
                    InOrder(root->branch[pos]);
                }
        }
}

void main()
{
    int choice,targetpos;
    Type inKey;
    char ans='y';
    BT New;
    B obj;
    node *root, *target;
    root = NULL;
    do
        {
            cout<<"\n\t\t Implementation of B-tree";
            cout<<"\n 1.Insert \n 2.Delete \n 3.Search \n 4.Display \n 5.Exit";
            cout<<"\n Enter Your choice: ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    cout<<"Enter the Key to be inserted :";
                    cin>>New.key;
                    root = obj.Insert(New, root);
                    break;
                case 2:
                    cout<<"Enter the Key to be deleted :";
                    cin>>New.key;
                    cout<<"\n Deleting the desired item..."<<endl;
                    obj.Delete(New.key, &root);
                    break;
                case 3:
                    cout<<"Enter the Key to be searched for :";
                    cin>>New.key;
                    target = obj.Search(New.key, root, &targetpos);
                    if (target)
                        cout<<"The Searched Item: "<<target->entry[targetpos].key<<endl;
                    else
                        cout<<"Item is not present\n";
                    break;
                case 4:
                    cout<<"\n\nInOrder Traversal :\n";
                    obj.InOrder(root);
                    break;
                case 5:
                    exit(0);
                }
            cout<<"\n Do You want to go back to Main Menu?(y/n) ";
            cin>>ans;
        }
    while(ans=='y');
}
