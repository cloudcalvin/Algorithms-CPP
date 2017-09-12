#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10
template <class T>
class Heap
{
private:
    T arr[MAX];
    int n;
public:
    Heap();
    void insert(T num);
    void makeheap();
    void heapsort();
    void display();
};
template <class T>
Heap<T>::Heap()
{
    n=0;
    for(int i=0; i<MAX; i++)
        arr[i]=0;
}
template <class T>
void Heap<T>::insert(T num)
{
    if(n<MAX)
        {
            arr[n]=num;
            n++;
        }
    else
        cout<<"\n Array is full";
}
template <class T>
void Heap<T>::makeheap()
{
    for(int i=1; i<n; i++)
        {
            T val=arr[i];
            int j=i;
            int f=(j-1)/2;
            while(j>0&&arr[f]<val)//creating a MAX heap
                {
                    arr[j]=arr[f];
                    j=f;
                    f=(j-1)/2;
                }
            arr[j]=val;
        }
}
template <class T>
void Heap<T>::heapsort()
{
    for(int i=n-1; i>0; i--)
        {
            T temp=arr[i];
            arr[i]=arr[0];
            int k=0;
            int j;
            if(i==1)
                j=-1;
            else
                j=1;
            if(i>2&&arr[2]>arr[1])
                j=2;
            while(j>=0&& temp <arr[j])
                {
                    arr[k]=arr[j];
                    k=j;
                    j=2*k+1;
                    if(j+1<=i-1&&arr[j]<arr[j+1])
                        j++;
                    if(j>i-1)
                        j=-1;
                }
            arr[k]=temp;
        }
}
template <class T>
void Heap<T>::display()
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
    cout<<"\n";
}
void main()
{
    Heap <int> Iobj;
    Heap <char> Cobj;
    Iobj.insert(10);
    Iobj.insert(25);
    Iobj.insert(30);
    Iobj.insert(90);
    Iobj.insert(7);
    Iobj.insert(21);
    Iobj.insert(3);
    Iobj.insert(23);
    cout<<"\n The Elements are ..."<<endl;
    Iobj.display();
    Iobj.makeheap();
    cout<<"\n Heapefied"<<endl;
    Iobj.display();
    Iobj.heapsort();
    cout<<"\nElements sorted by Heap sort... "<<endl;
    Iobj.display();
    cout<<"\n\n\t Now sorting the character type of elements "<<endl;
    Cobj.insert('F');
    Cobj.insert('D');
    Cobj.insert('H');
    Cobj.insert('B');
    Cobj.insert('G');
    Cobj.insert('A');
    Cobj.insert('C');
    Cobj.insert('F');
    cout<<"\n The Elements are ..."<<endl;
    Cobj.display();
    Cobj.makeheap();
    cout<<"\n Heapified"<<endl;
    Cobj.display();
    Cobj.heapsort();
    cout<<"\nElements sorted by Heap sort... "<<endl;
    Cobj.display();
    getch();
}
