/***********************************************************************
Program for performing various operations on
Sequential File organisation.
************************************************************************/
#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
class PERSON_CLASS
{
    typedef struct PERSON
    {
        char name[10];
        char source[10];
        char dest[10];
        char sex;
        int age;
    } Rec;
    Rec Records;
public:
    void Create();
    void Display();
    void Update();
    void Delete();
    void Append();
    void Display_One();
    int Search();
    void Sort();
};
void PERSON_CLASS::Create()
{
    char ch='y';
    fstream seqfile;
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    if(!seqfile)
        {
            cerr<<"Error in opening file";
            exit(0);
        }
    do
        {
            cout<<"\n Enter Name: ";
            cin>>Records.name;
            cout<<"\n Enter Sex: ";
            cin>>Records.sex;
            cout<<"\n Enter Age: ";
            cin>>Records.age;
            try
                {
                    cout<<"\n Enter starting place of journey: ";
                    cin>>Records.source;
                    cout<<"\n Enter destinating place of journey: ";
                    cin>>Records.dest;
                    if(strcmp(Records.source,Records.dest)==0)
                        throw 100;
                }
            catch(int exc)
                {
                    cout<<"\n Same source and destination not allowed!!";
                    return;
                }
            seqfile.write((char*)&Records,sizeof(Records));
            cout<<"\nDo you want to add more records?";
            cin>>ch;
        }
    while(ch=='y');
    seqfile.close();
}
void PERSON_CLASS::Display_One()
{
    int pos=-1;
    fstream seqfile;
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    try
        {
            pos=Search();
            if(pos==-1)
                {
                    throw pos;
                }
        }
    catch(int pos)
        {
            cout<<"\n The record is not present in the file";
            return;
        }
    int offset=pos*sizeof(Rec);
    seqfile.seekp(offset);//seeking the desired rec.
    cout<<"\n The Desired Record is present and it is as follows...";
    cout<<"\nName: "<<Records.name;
    cout<<"\nAge: "<<Records.age;
    cout<<"\nSex: "<<Records.sex;
    cout<<"\nStarting of journey: "<<Records.source;
    cout<<"\nDestination : "<<Records.dest;
    seqfile.close();
}
void PERSON_CLASS::Display()
{
    fstream seqfile;
    int n;
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    cout<<"\n The Contents of file are ..."<<endl;
    while(seqfile.read((char *)&Records,sizeof(Records)))
        {
            if(strcmp(Records.name,"")!=0)
                {
                    cout<<"\nName: "<<Records.name;
                    cout<<"\nAge: "<<Records.age;
                    cout<<"\nSex: "<<Records.sex;
                    cout<<"\nStarting of journey: "<<Records.source;
                    cout<<"\nDestination : "<<Records.dest;
                    cout<<"\n";
                }
        }
    int last_rec=seqfile.tellg();//last record position
    n=last_rec/(sizeof(Rec));
    cout<<"\n\n Total number of objects are "<<n<<"(considering logical deletion)";
    seqfile.close();
}

void PERSON_CLASS::Update()
{
    int pos;
    cout<<"\n For updation,";
    fstream seqfile;
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    if(!seqfile)
        {
            cerr<<"Error in opening file";
            exit(0);
        }
    seqfile.seekg(0,ios::beg);
    try
        {
            pos=Search();
            if(pos==-1)
                throw pos;
        }
    catch(int pos)
        {
            cout<<"\n The record is not present in the file";
            return;
        }
    int offset=pos*sizeof(Rec);
    seqfile.seekp(offset);//seeking the desired record for modification
    cout<<"\n Enter the values for updation...";
    cout<<"\n Name: ";
    cin>>Records.name;
    cout<<"\n Age: ";
    cin>>Records.age;
    cout<<"\n Sex: ";
    cin>>Records.sex;
    cout<<"\n Starting of journey: ";
    cin>>Records.source;
    cout<<"\n Destination : ";
    cin>>Records.dest;
    seqfile.write((char*)&Records,sizeof(Records))<<flush;
    seqfile.seekg(0);
    seqfile.close();
    cout<<"\n The record is updated!!!";
}

void PERSON_CLASS::Delete()
{
    int pos=-1;
    cout<<"\n For deletion,";
    fstream seqfile;
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    if(!seqfile)
        {
            cerr<<"Error in opening file";
            exit(0);
        }
    seqfile.seekg(0,ios::beg);
    try
        {
            pos=Search();
            if(pos==-1)
                throw pos;
        }
    catch(int pos)
        {
            cout<<"\n The record is not present in the file";
            return;
        }
    int offset=pos*sizeof(Rec);
    seqfile.seekp(offset);//seeking the desired record for deletion
    strcpy(Records.name,"");
    Records.age=-1;
    Records.sex=' ';
    strcpy(Records.source,"");
    strcpy(Records.dest,"");
    seqfile.write((char*)&Records,sizeof(Records))<<flush;
    seqfile.seekg(0);
    seqfile.close();
    cout<<"\n The record is Deleted!!!";
}

void PERSON_CLASS::Append()
{
    fstream seqfile;
    seqfile.open("DATA.DAT",ios::ate|ios::in|ios::out|ios::binary);
    if(!seqfile)
        {
            cerr<<"Error in opening file";
            exit(0);
        }
    seqfile.seekg(0,ios::beg);
    int i=0;
    while(seqfile.read((char *)&Records,sizeof(Records)))
        {
            i++;//going through all the records
            // for reaching at the end of the file
        }
    seqfile.clear();//turning off EOF flag
    cout<<"\n Enter the record for appending";
    cout<<"\n Name: ";
    cin>>Records.name;
    cout<<"\n Age: ";
    cin>>Records.age;
    cout<<"\n Sex: ";
    cin>>Records.sex;
    cout<<"\n Starting of journey: ";
    cin>>Records.source;
    cout<<"\n Destination : ";
    cin>>Records.dest;
    seqfile.write((char*)&Records,sizeof(Records));
    seqfile.seekg(0);//reposition to start
    seqfile.close();
    cout<<"\n The record is Appended!!!";
}
int PERSON_CLASS::Search()
{
    fstream seqfile;
    int pos;
    char key[10];
    cout<<"\n Enter the name for searching the record ";
    cin>>key;
    seqfile.open("DATA.DAT",ios::ate|ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    int i=0;
    pos=-1;
    while(seqfile.read((char *)&Records,sizeof(Records)))
        {
            if(strcmp(key,Records.name)==0)
                {
                    pos=i;
                    break;
                }
            i++;
        }
    seqfile.close();
    return pos;
}
void PERSON_CLASS::Sort()
{
    fstream seqfile;
    Rec temp,next_Records;
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    while(seqfile.read((char *)&Records,sizeof(Records)));
    //note while statement is terminated for reaching
    //at the end of the file
    int last_rec=seqfile.tellg();//last record position
    int n=last_rec/(sizeof(Rec));
    //n denotes total number of records in the file
    seqfile.close();
    seqfile.open("DATA.DAT",ios::in|ios::out|ios::binary);
    int offset2,offset3;
    seqfile.seekg(0,ios::beg);
    //Applying Bubble sort method
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-1; j++)
                {
                    offset3=(j+1)*sizeof(Rec);
                    seqfile.seekg(offset3,ios::beg);
                    seqfile.read((char *)&Records,sizeof(Rec));//reading a[j+1] record
                    next_Records=Records;
                    seqfile.seekg(0);//resetting the file
                    offset2=j*sizeof(Rec);
                    seqfile.seekg(offset2,ios::beg);
                    seqfile.read((char *)&Records,sizeof(Rec));
                    if(strcmp(Records.name,next_Records.name)>0)//if(a[j]>a[j+1])
                        {
                            temp=Records;//temp=a[j]
                            seqfile.seekp(offset2);//positiong for writing the rec.at jth loc.
                            seqfile.write((char *)&next_Records,sizeof(Rec));//a[j]=a[j+1]
                            seqfile.seekp(offset3);//positioning for writing the rec.at (j+1)th loc.
                            seqfile.write((char *)&temp,sizeof(Rec));//a[j+1]=temp
                        }
                }
        }
    cout<<"\n The Record is Sorted!!!";
    seqfile.close();
}

void main()
{
    PERSON_CLASS List;
    char ans='y';
    int choice;
    do
        {
            cout<<"\n             Main Menu             "<<endl;
            cout<<"\n 1.Create";
            cout<<"\n 2.Display";
            cout<<"\n 3.Update";
            cout<<"\n 4.Delete";
            cout<<"\n 5.Append";
            cout<<"\n 6.Display Particular Record";
            cout<<"\n 7.Sort";
            cout<<"\n 8.Exit";
            cout<<"\n Enter your choice";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    List.Create();
                    break;
                case 2:
                    List.Display();
                    break;
                case 3:
                    List.Update();
                    break;
                case 4:
                    List.Delete();
                    break;
                case 5:
                    List.Append();
                    break;
                case 6:
                    List.Display_One();
                    break;
                case 7:
                    List.Sort();
                    break;
                case 8:
                    exit(0);
                }
            cout<<"\n\t Do you want to go back to Main Menu?";
            cin>>ans;
        }
    while(ans=='y');
}
