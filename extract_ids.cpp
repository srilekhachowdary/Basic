#include<iostream>
#include<fstream>
#include<string.h>
#include<regex>
#include<cmath>
using namespace std;

int main()
{
int count=10,node=0;

char *token,*word1;
string token1,a;
string name,outname,finalname,word,word2,line,line1;

fstream file;
fstream outfile;
fstream finalfile;

name="consul_with_error.txt";
outname="output.txt";
finalname="final.txt";
file.open(name.c_str());
outfile.open(outname.c_str());
int size,size1;
if(file.is_open())
{
	while(file>>word)
	{
		word1=const_cast<char*>(word.c_str());
		token=strtok(word1,"{}[],");
		while(token!=NULL)
		{
				regex ser("(\"ServiceID\":\")(.*\")");
				regex loc("(\"VLocationId_)(.*\")");
				if(regex_match(token,ser))
				{
					token1=token;
					outfile<<"Service"<<" "<<token1.substr(13,token1.size()-1)<<endl;
				}
				if(regex_match(token,loc))
				{
					token1=token;
					outfile<<"Location"<<" "<<token1.substr(13,token1.size()-1)<<endl;
				}
			token=strtok(NULL, "{}[],");
		}

	}
file.close();
outfile.close();
}

outfile.open(outname.c_str());
finalfile.open(finalname.c_str());
while(getline(outfile,line))
{
	getline(outfile,line1);
	
	stringstream is(line); 
  	stringstream is1(line1); 
    	 
        is>>word;
	is1>>word2;
	if(word=="Service")
	{
		is>>word;
		token1 = word.substr(0, word.size()-1);
		for (int i = 0; i < token1.length(); i++)
		{
        		if (isdigit(token1[i])==false)
				count=1; 
		}
		if(count==10 && token1.length()!=0) 
		{
			node=1;
		}			 
	} 
	else if(word2=="Service")
	{
		is1>>word2;
		token1 = word2.substr(0, word2.size()-1);
		for (int i = 0; i < token1.length(); i++)
		{ 
        		if (isdigit(token1[i])==false)
				count=1;
		}
		if(count==10 && token1.length()!=0)
		{
			node=2;
		}
	} 
	if(count==10 && token1.length()!=0) 
	{
		if(node==1)
		{
			is1>>word;
			if(word.size()!=0)
			{
				finalfile<<token1<<" "<<word.substr(0, word.size()-1)<<endl;
			}
		}
		else if(node==2)
		{
			is>>word2;
			if(word2.size()!=0)
			{
				finalfile<<token1<<" "<<word2.substr(0, word2.size()-1)<<endl;
			}
		}	
	}
count=10;
}

return(0);
}
