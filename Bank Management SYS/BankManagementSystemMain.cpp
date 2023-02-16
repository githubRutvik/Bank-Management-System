#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include "bank.h"

using namespace std;

int main()
{
// an object L1 of the type Bank is declared.
bank l1; 

// Entire Menu of the Bank management system .
int ch,no,choice;
cout<<"\n ---------------------------------------BANK MANAGEMENT SYSTEM--------------------------------------- ";
cout<<"\n\n			                          BY												   ";
cout<<"\n                                          SNEHARSH & RUTVIK";
cout<<"\n\nPress 1 to start= ";
cin>>ch;
while(ch==1)
{
cout<<"\n MENU ";
cout<<"\n			1.OpenAccount";
cout<<"\n			2.DisplayDetails";
cout<<"\n			3.Deposit";
cout<<"\n			4.Withdrawal ";
cout<<"\n			5.Search an Account";
cout<<"\nEnter your choice= ";
cin>>choice;
switch(choice) //switch case
{
	case 1:
		l1.openAccount(); 
		break;
		
	case 2:
		l1.displayDetails();
		break;
		
 	case 3:
		int id;
 		l1.deposite(id); 
		break;
 
  	case 4:
	  	l1.withdrawal(id);
		break;

	case 5:
		l1.search(); 
		break;

}//switch closed
}while(choice<=5); //do-while closed

return 0;

}

	
