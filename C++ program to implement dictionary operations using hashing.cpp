/*************************************************************
Program to implement dictionary operations using hashing
*************************************************************/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
class HashTab
{
private:
    struct DCT
    {
        int k;
        int val;
    } a[MAX];
public:
    int hash(int);
    void init();
    void insert(int,int,int);
    void display();
    void size();
    void search(int);
};

void HashTab::init()
{
    for(int i=0; i<MAX; i++)
        {
            a[i].k= -1;
            a[i].val=-1;
        }
}

int HashTab::hash(int num)
{
    int Hkey;
    Hkey=num%10;
    return Hkey;
}

void HashTab::insert(int index,int key,int value)
{
    int flag,i,count=0;
    flag=0;
    if(a[index].k==-1)/*if the location indicated by hash key is empty*/
        {
            a[index].k=key;
            a[index].val=value;
        }
    else
        {
            i=0;
            while(i<MAX)
                {
                    if(a[i].k!= -1)
                        count++;
                    i++;
                }
            if(count==MAX)         /*checking for the hash full*/
                {
                    cout<<"\nHash Table Is Full";
                }
            for(i=index+1; i<MAX; i++) /*moving linearly down*/
                if(a[i].k== -1)     /*searching for empty location*/
                    {
                        a[i].k=key;
                        a[i].val=value;
                        /*placing the number at empty location*/
                        flag=1;
                        break;
                    }
            /*From key position to the end of array we have searched empty 	location and now we want to check empty location in the upper part of the array*/
            for(i=0; i<index&&flag==0; i++) /*array from 0th to keyth location will be scanned*/
                if(a[i].k== -1)
                    {
                        a[i].k=key;
                        a[i].val=value;
                        flag=1;
                        break;
                    }
        } /*outer else*/
} /*end*/

void HashTab::display()
{
    int i;
    cout<<"\n The Hash Table is...\n";
    cout<<"\n--------------------------------";
    for(i=0; i<MAX; i++)
        {
            cout<<"\n  "<<i<<"  "<<a[i].k<<"  "<<a[i].val;
        }
    cout<<"\n--------------------------------";
}

void HashTab::size()
{
    int len=0,i;
    for(i=0; i<MAX; i++)
        {
            if(a[i].k!=-1)
                len++;
        }
    cout<<"\n The size of dictionary is ";
    cout<<len;
}

void HashTab::search(int search_key)
{
    int i,j;
    i=hash(search_key);
    if(a[i].k==search_key)
        {
            cout<<"\n The Record is present at location  "<<i;
            return;
        }
    if(a[i].k!=search_key)
        {
            //searching from hash key to end of hash table
            for(j=i; j<MAX; j++)
                {
                    if(a[j].k==search_key)
                        {
                            cout<<"\n The Record is present at location  "<<j;
                            return;
                        }
                }
            //searching from beginning of hash table upto hash key
            for(j=0; j<i; j++)
                {
                    if(a[j].k==search_key)
                        {
                            cout<<"\n The Record is present at location "<<j;
                            return;
                        }
                }
        }
    else
        cout<<"\n The Record is not present in the hash table";
}

void main()
{
    int key,value,Hkey,search_key;
    char ans;
    HashTab obj;
    clrscr();
    cout<<"\nDictionary Functions using Hashing";
    obj.init();
    do
        {
            cout<<"\n Enter The key";
            cin>>key;
            cout<<"\n Enter The Value";
            cin>>value;
            Hkey=obj.hash(key);/*returns hash key*/
            obj.insert(Hkey,key,value);/*collision handled by linear probing*/
            cout<<"\n Do U Wish To Continue?(y/n)";
            ans=getche();
        }
    while(ans=='y');
    obj.display();/*displays hash table*/
    obj.size();
    cout<<"\n Enter the key for searching the record";
    cin>>search_key;
    obj.search(search_key);
    getch();
}
