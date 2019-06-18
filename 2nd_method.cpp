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
int i=0,k,m;

fstream finalfile;
finalname="final.txt";
finalfile.open(finalname.c_str());

while(getline(finalfile,line))
{
	stringstream is(line);
	is>>word;
	is>>word1;
	stringstream is1(word);
	is1>>k;
	stringstream is2(word1);
	is2>>m;
	a[i][0]=k;
	a[i][1]=m;
	for(int n=i-1;n>=0;n--)
	{
		if(a[n][0]==a[i][0])
		{
			if(a[n][1]!=a[i][1])
				cout<<a[n][0]<<","<<a[n][1]<<" "<<a[i][0]<<","<<a[i][1]<<endl;
		}
		else if(a[n][1]==a[i][1])
		{
			if(a[n][0]!=a[i][0])
				cout<<a[n][0]<<","<<a[n][1]<<" "<<a[i][0]<<","<<a[i][1]<<endl;
		}
	}
	i++;
}

return(0);
}
