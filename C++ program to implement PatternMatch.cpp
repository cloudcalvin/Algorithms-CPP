
/**************************************************************************************
	KMP Pattern matching algorithm
*************************************************************************************/
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int *Create_prefix_table(char p[10])
{
    int *prefix_table;
    int m = strlen(p);
    int k = 0;
    prefix_table = (int *)malloc(m*sizeof(int));//dynamic array
    prefix_table[0] = 0;
    for(int q = 1; q < m; q++)
        {
            while (k > 0 && p[k] != p[q])
                k = prefix_table[k-1];
            if (p[k] == p[q])
                k++;
            prefix_table[q] = k;
        }
    return prefix_table;
}
void kmp_match(char t[50], char p[10])
{
    int *prefix_table;
    int i;
    int j = 0;
    int n = strlen(t);
    int m = strlen(p);
// we generate the prefix array
    prefix_table= Create_prefix_table(p);
// The content of the prefix array
    cout<<"-------------------------------";
    cout << endl << "prefix array is : \n";
    for (i = 0; i < m; i++)
        cout << prefix_table[i] << " ";
    cout<<"\n-------------------------------";
    cout << endl;
//  K-M-P algorithm starts
    for (i = 0; i < n; i++)
        {
            cout<<"\ni= "<<i<<"j= "<<j;
            cout<<"\n Comparing "<<t[i]<<" and "<<p[j];
            while(j > 0 && p[j] != t[i])
                j = prefix_table[j-1];
            if (p[j] == t[i])
                {
                    cout<<" \n Match found at "<<"i = "<<i<<" j= "<<j;
                    j++;
                }
            if (j == m)
                {
                    cout <<"\n\tPattern is present in the text at: ";
                    cout <<i - m + 1 << " position." << endl;
                    j = prefix_table[j-1];
                }
        }
}
int main()
{
    char t[50];
    char p[10];
    clrscr();
    cout << "Enter the T string: ";
    cin >> t;
    cout << "Enter the P string: ";
    cin >> p;
    kmp_match(t,p);
    return 0;
}
