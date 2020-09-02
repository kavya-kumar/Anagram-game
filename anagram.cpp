#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int p,j=0,mark=5,total=0;
	char ch='y';
	string ans,line,ansf,clue;
	
	ifstream fih("anagramquestion.txt");
	cout<<"Lets start the anagram game :)\n";
	while(ch=='y')
	{
		getline(fih,line);
	//	cout<<line;
		p=line.find(":");
		ansf=line.substr(0,p-1);
		mark=5;
		cout<<"Find the correct word from the letter: "<<ansf<<'\n';
	
		line=line.substr(p+1);
	//	cout<<line;
	//	i=p+1;
		p=line.find(":");
		ansf=line.substr(0,p);
	//	cout<<ansf;
			cin>>ans;
	//	line=line.substr(p+1);
	//	cout<<line;
		while((ans!=ansf)&&(j<3)){
			
			j++;
		//	i=p+1;
			line=line.substr(p+1);
			p=line.find(":");			
			cout<<"\nWRONG ANSWER:(\n Try again\n"<<(3-j)<<" attempts left\n"<<"Hint:";
			clue=line.substr(0,p);
			cout<<clue<<'\n';
			mark=mark-2;
			cin>>ans;
		}
		if((j==3)&&(ans!=ansf))
		{
			cout<<"YOU LOST THIS WORD\nAnswer is: "<<ansf<<'\n';
		}
		else
		{	total+=mark;
			cout<<"Hurray...YOU MADE IT!\n";
			cout<<"SCORE:"<<mark<<'\n';
			cout<<"TOTAL SCORE:"<<total<<'\n';
		}
		cout<<"Do you want to continue?y or n\n";
		cin>>ch;
			
	}
}
