#include <iostream>
#include "Main.h"
#include <algorithm> 
#include <iomanip>
using namespace std;
int main()
{
int i,Code; 
string reply,Question;
Main open;
cout<<setw(80)<<"**********Welcome to Chatbot********"<<endl;
cout<<setw(105)<<"********About C++ Programing (Covers only Small portion of C++)********"<<endl;
for(i=1; i>0; i++)
{
system("color b");
cout<<"Enter your Choice:\n1.Syntax\n2.Information"<<"\nEnter:";
cin>>Code;
if(Code==2)
{
cout<<"\nEnter Your Question:";
cin >> ws;
getline(cin,Question);

transform(Question.begin(), Question.end(), Question.begin(), ::toupper);

open.SpellingChecker(Question,Code);
}
else if(Code==1)
{
cout<<"\nEnter Your Question:";
cin >> ws;
getline(cin,Question);

transform(Question.begin(), Question.end(), Question.begin(), ::toupper);

open.SpellingChecker(Question,Code);
}
else
cout<<"Wrong Choice!\n"; 
cout<<"\n\nAsk Another Question, (Yes/No):";
cin>>reply;
cin.ignore();
if(reply=="Yes"||reply=="yes")
continue;
else
break;
}
return 0;
}
