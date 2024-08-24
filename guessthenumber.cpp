/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	string name;
	char input;
	int inputuser;
	cout<<"inter your name  ";
	getline(cin, name);
	cout<<endl;
	do
	{
		srand(0);
		int variable=rand()%5+1;
		cout<<"Enter any number in between range 1 to 5 ";
		cin>>inputuser;
		cout<<endl;
		if(inputuser==variable)
		{
			cout<<"Congratulations ! You guessed the correct number"<<endl;
		}
		else
		{
			cout<<"Soory, You guessed wrong number Try again"<<endl;
		}
		cout<<"Would you like to try again Y/N ";
		cin>>input;
		cout<<endl;
	}
	while(input!='N');
	cout<<"Game end"<<endl;
}