#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
class Main
{
	private:
		int Num,Code,i,len,flen,correct=0;
		string str,toRemove,command,voice,Question,line;
		fstream file,obj,fold,words;
	public:
		Printer(string Question, int Code)
		{
		    file.open("Syntax.txt");
	        while(file>>str  && !file.eof())
	        {
    	        if(str==Question)
		        {
		         system("color b");
		         cout<<endl;
			     while(file>>str && str!="end")
			     {
			     if(str!="#")
			     cout<<str<<" ";
			     else
			     cout<<str[+1]<<endl;
			     }	
			    }
			}
			file.close();
		    cout<<endl;
	    }
	    
	    Printer(string Question, double Code)
	    {
	    	fold.open("Main.txt");
	        while(fold>>str && !fold.eof())
	        {
    	        if(str==Question)
		        {
		         system("color b");
		         cout<<endl;
			     while(fold>>str && str!="end")
			     {
			     if(str!="#")
			     {
				 cout<<str<<" ";
			     voice=voice+str;
			     }
			     else
			     {
				 cout<<str[+1]<<endl;
			     voice=voice+str;
			     }
			     }
			     string command = "powershell -command \"Add-Type -AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('" + voice + "');\"";
                 system(command.c_str());
			     voice.clear();
			    }
		    }
		    fold.close();
		    cout<<endl;
		}
	    
	    SpellingChecker(string Question,int Code)
	    {
        obj.open("word.txt");
        while(getline(obj,str) && !obj.eof())
        {
   	    toRemove=str;
   	    size_t pos = Question.find(toRemove);
        if (pos != string::npos)
        Question.erase(pos, toRemove.length());
        }
        obj.close();
        SpaceRemover(Question,Code);
		}
		
		SpaceRemover(string Question,int Code)
		{
		Question.erase(remove_if(Question.begin(), Question.end(), ::isspace),Question.end());
		if(Code==2)
		{
		double Code=2.5;
        SpellingChecker(Question,Code);
        }    
        else
        Printer(Question+"?",Code);
		}
		
		SpellingChecker(string Question,double Code)
		{
		    string Ninput = Question;
		    len = Ninput.length();
            for (int i=0; i < len; i++)
                Ninput[i] = tolower(Question[i]);
            words.open("Spelling.txt");
            while (getline(words,line) && !words.eof())
            {
            	string Nline = line;
                flen = line.length();
                if (len==flen)
                {
                	sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(), Ninput.end());
                    if (Nline==Ninput)
                    {
                    line=line+"?";
    	            transform(line.begin(), line.end(), line.begin(), ::toupper);
    	            Printer(line,Code);
                    correct=1;
                    }
                    else
					continue;
                }
                else 
				continue;
            }
            words.close();
            if(correct!=1)
            cout<<"We can't predict what you are asking!";
        }
};
