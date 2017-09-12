/**************************************************************
Implementation of Knuth-Morris-Pratt algorithm
**************************************************************/
#include <iostream.h>
#include<string.h>
#include <stdlib.h>

class KMP
{
private:
    char *text;
    char *pattern;
public:

    KMP()
    {
        *text=NULL;
        *pattern = NULL;
    }
    void get_input();
    void display();
    const char *kmp(const char *text,const char *pattern);
};

const char *KMP::kmp(const char *text,const char *pattern)
{
    int T[50];
    int i, j;
    const char *result = NULL;
    //no pattern to match
    if (pattern[0] == '\0')
        return text;
    // construct the lookup table
    T[0] = -1;
    for (i=0; pattern[i] != '\0'; i++)
        {
            T[i+1] = T[i] + 1;
            while (T[i+1]>0 && pattern[i]!=pattern[T[i+1]-1])
                T[i+1] = T[T[i+1]-1] + 1;
        }
    // searching for pattern match
    for (i=j=0; text[i] != '\0'; )
        {
            if (j < 0 || text[i] == pattern[j])
                {
                    ++i, ++j;
                    if (pattern[j] == '\0')
                        {
                            result = text+i-j;//storing the matched pattern
                            break;
                        }
                }
            else j = T[j];
        }
    return result;
}
void KMP::get_input()
{
    cout<<"\n Enter The text";
    cin>>text;
    cout<<"\n Enter pattern";
    cin>>pattern;
}
void KMP::display()
{
    cout<<"\n The pattern matched is ... ";
    cout<<kmp(text,pattern);
}
void main()
{
    KMP obj;
    obj.get_input();
    obj.display();
}

