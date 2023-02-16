#ifndef BANK_H
#define BANK_H

#include<stdlib.h>
#include<string>
#include <stdio.h>
#include<conio.h>

using namespace std;

class node
{
	public:

		float cash;
		double phn;
		string email;
		string name;
		string lname;
		int id;
		
		node * next;
};

class bank //new class for bank
{
	private:
		node * head; //first node
	public:
		int length = 0;
		bank()
	{
	head = NULL; //initial address of first node
	}
	
//function/operations for the code
void openAccount();
void displayDetails();
void deposite(int );
void withdrawal(int );
void search();


};



//function for account setup.
//gathers the details of the customer as per input by the user.
//info is stored in linked list node.
void bank::openAccount() 
{
	node*temp = NULL;
	node*p = NULL;
	float no,ca;
	double ph;
	int ch1=1,ID;
	string na;
	string lna;
	string em;
	while(ch1==1)
	{
	cout<<"\nEnter First Name= ";
	cin>>na;
	cout<<"\nEnter Last Name= ";
	cin>>lna;
	cout<<"\nEnter Phone Number= ";
	cin>>ph;
	cout<<"\nEnter Email ID= ";
	cin>>em;
	cout<<"\nEnter Account ID= ";
	cin>>ID; 
	cout<<"\nEnter expected cash(in Rupees)= ";
	cin>>ca;
	if(head==NULL)
	{
	head = new(node);
	head -> cash=ca;
	head -> name= na;
	head -> lname= lna;
	head -> id= ID;
	head ->phn=ph;
	head ->email=em;
	head -> next = NULL;
	p = head;
	length++;
	}
else
{
	temp = new(node);

	temp -> cash=ca;
	temp -> name= na;
	temp -> lname= lna;
	temp -> phn=ph;
	temp -> id= ID;
	temp ->email=em;
	temp -> next = NULL;
	p -> next = temp;
	p = temp; 
	length++;
}
cout<<"Press 1 to Enter again= "; cin>>ch1;
}//while closed
}//function closed




//function for displaying the overall Bank database
// each node is traversed and data is displayed accordingly with respect each customer
void bank::displayDetails() //to display linked list
{
	node *p = NULL; p=head;
	if(head==NULL) //condition to check if list is empty or not
{
	cout<<"\nThere is no data found!!";
}
else
{
	cout<<"\n---------------------------------------Bank Account Management System---------------------------------------\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"Account ID		Last Name		First Name		Phone Number		Email		Balance	in Rs.	";
	while(p!=NULL)
{
	cout<<"\n";
	cout<<p->id<<"			"<<p->lname<<"			"<<p->name<<"			"<<p->phn<<"	 	"<<p->email<<"		"<<p -> cash<<"\n";
	cout<<"\n";
	p=p->next;
}//while closed
	cout<<"\nTotal Account Holders= "<<length;
}//else closed
}//function closed



//Money Deposit function. Here the Account ID is passed as an arguement. The function checks for account presence
//and if the account is present then user is allowed to deposit money into the his/her account.
//the node will be updated with the latest balance according to the money deposited. 
void bank::deposite(int id)
{
	node*current=head;
	int amt;
	bool found=false;
	
	if(head==NULL)
	{
		cout<<"Data is not found"<<endl;
	}
	else{
		while(current!=NULL)
		{
			int nid;
			cout<<"Enter Account ID"<<endl;
			cin>>nid;
			if(current->id==nid)
			{
				found=true;
				break;
			}
			current=current->next;
			
		}
	}
	if(found)
	{
		cout<<"Enter amount you want to deposite"<<endl;
		cin>>amt;
		int total=current->cash+amt;
		cout<<"After deposition your total amount in account is "<<total<<endl;
		current->cash=total;
	}
}



//Money Withdrawal function. The function checks for account presence
//and if the account is present then user is allowed to withdraw money from his/her account.
//the node will be updated with the latest balance according to the money withdrawn. 
void bank::withdrawal(int id)
{
	node*current=head;
	int amt;
	bool found=false;
	
	if(head==NULL)
	{
		cout<<"Data is not found"<<endl;
	}
	else{
		while(current!=NULL)
		{
			int nid;
			cout<<"Enter Account ID"<<endl;
			cin>>nid;
			if(current->id==nid)
			{
				found=true;
				break;
			}
			current=current->next;
			
		}
	}
	if(found)
	{
		cout<<"Enter amount you want to withdraw"<<endl;
		cin>>amt;
		int total=current->cash-amt;
		cout<<"After withdrawal your total amount in account is "<<total<<endl;
		current->cash=total;
	}
}


// Searching an account of a customer. Account ID is passsed as an arguement and if the account is present,
// the entire details about is displayed.
void bank::search() 
{
	int id; string na; string lna;
	int flag=0;
	node *p= NULL;
	p =head;
	cout<<"\nEnter the Account ID you want to search = ";
	cin>>id;
	while(p!=NULL)
	{
	if(p->id==id)
	{
	flag=1;
	break;
	}
	p=p->next;
	}
	if(flag==0)
	{
	cout<<"\nID NOT FOUND!!!\n";
	}
	else
	{
	cout<<"\n-------------DETAILS OF THE ACCOUNT HOLDER------------- \n";
	cout<<"\n"<<"Account id: "<<p->id<<"		"<<"\nLast Name: "<<p->lname<<" 	"<<"\nFirst Name: "<<p->name<<"	  "<<"\nPhone number: "<<p->phn<<"     "<<"\nEmail id: "<<p->email<<"    "<<"\nCash in account: Rs. "<<p -> cash<<"\n";
	cout<<"\n";
	}
}//function closed




#endif
