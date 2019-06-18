#include<iostream>
#include<fstream>
#include<string.h>
#include<regex>
#include<cmath>
using namespace std;

int main()
{
int a[150][2]={0};
string word,word1,line;
string finalname;
int l,k,m;

fstream finalfile;
finalname="final.txt";
finalfile.open(finalname.c_str());

while(getline(finalfile,line))
{
	stringstream is(line);
	is>>word;
	stringstream is1(word);
	is1>>k;
	l=k%151;
	while(1)
	{
		is>>word1;
		stringstream is2(word1);
		is2>>m;
		if(a[l][0]==0)
		{
			a[l][0]=k;
			a[l][1]=m;
			break;
		}
		else
		{
			if(a[l][1]==m)
			{
				if(a[l][0]!=k)
				{
					cout<<word<<","<<word1<<"   "<<a[l][0]<<","<<a[l][1]<<endl;
					break;	
				}
			}
			else
			{
				l=l+1;
			}
		}
	}
}
return(0);
}
