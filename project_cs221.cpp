
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

fstream Employees;


struct date{
	
	int day;
	int month;
	int year;		
	
};

struct employee{
	
	string ID;
	string name;
	string department;
	date birthdate;
	double salary;	
	
}employees[100];

int numOfEmployee = 0;
bool login=false;

void add(employee employees[]);
void Delete(employee employees[]);	
void display(employee employees[]);	 
void sort(employee employees[]); 
void update(employee employees[]);
void search(employee employees[]);
void fillArray(employee employees[]);
void write(employee employees[]);
void password();
double calculateYearlySalary(employee employees[]);
void html(employee employees[]);

int main(){

	password();
	if(login==true)
	{
	system("");

	
	fillArray(employees);
	char choose;
	bool exit = false;
	double newSalary;
	do{
		cout<<" Employee System! \n\n"
		"How can we help you?\n\n"
		"1 - Add employee.\n"
		"2 - Delete an employee.\n"    
		"3 - Display employees.\n"
		"4 - Sort employees.\n"
		"5 - Search for an employee.\n"
		"6 - Update an employee's information\n"
		"7 - Calculate an employee's salary\n"
		"8 - Save & exit\n\n";
		cin>>choose;
		
		switch(choose){
			case '1':
				add(employees);
				system("PAUSE");
				break;
			case '2':
				Delete(employees);
				system("PAUSE");
				break;
			case '3':
				display(employees);
				system("PAUSE");
				break;
			case '4':
				sort(employees);
				system("PAUSE");
				break;
			case '5':
				search(employees);
				system("PAUSE");
				break;
			
			case '6':
				update(employees);
				system("PAUSE");
				break;
			case '7':
				newSalary = calculateYearlySalary(employees);
				cout<<"\nNew salary is : "<<newSalary<<"\n";
				break;
			case '8':
				exit = true;
				break;
			default:
				cout<<"Incorrect option! Please choose again.\n\n";
				main();
				break;
		}
		html(employees);
	}while(!exit);
	
	write(employees);
}
}
void password(){
	string user;
	string password;
	
	for(int i=0 ; i<2 && login==false ;i++){
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEmployee System \n\n";
   cout<<"\t\t\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t\t\t     LOGIN \n";
   cout<<"\t\t\t\t\t\t\t------------------------------\n\n";
   cout << "\t\t\t\t\t\t\tEnter user: ";
   cin>>user;
   cout << "\t\t\t\t\t\t\tEnter Password: ";
	cin>>password;
	if	(user=="admin" && password=="admin"){
	login=true;
	return;
}

	else
	cout<<"\n\t\t\t\t\t\t\tincorrect try again "<<endl;
	
}
}
void fillArray(employee employees[]){
	
	string line;
	Employees.open("employees.txt");
	if(Employees.is_open()){
		while(!Employees.eof()){
			getline(Employees, line);
            numOfEmployee++;
        }
        Employees.close();
        Employees.open("employees.txt");
		for(int i = 0; i < numOfEmployee; i++){
			Employees>>employees[i].ID>>employees[i].name>>employees[i].department>>employees[i].birthdate.day
			>>employees[i].birthdate.month>>employees[i].birthdate.year>>employees[i].salary;
		}
		
	}
	Employees.close();
	
}



void add(employee employees[]){	
	int d,mon,y;
	double sal;
	bool check=false;
	for(int i = numOfEmployee; i < 100; i++){
		int x = i + 110;
		employees[i].ID = to_string(x);
	}
	cout<<endl<<"Enter Employee #"<<numOfEmployee+1<<" Name : ";
	cin.ignore();
    getline(cin, employees[numOfEmployee].name);
    cout<<endl<<"Enter Employee #"<<numOfEmployee+1<<" Department : ";
	cin>>employees[numOfEmployee].department;
	
	cout<<endl<<"Enter Employee #"<<numOfEmployee+1<<" Day of birth : ";
    while(check==false)
    {
    	cin>>d;
    	if(d>0&&d<32)
     	{
		employees[numOfEmployee].birthdate.day=d;
		check=true;
    	}
		else
		cout<<"\nError\nDays should be between 1 and 31, please try again: \n";
	}
	check=false;

	cout<<endl<<"Enter Employee #"<<numOfEmployee+1<<" Month of birth : ";
    while(check==false)
    {
    	cin>>mon;
    	if(mon>0&&mon<13)
     	{
		employees[numOfEmployee].birthdate.month=mon;
		check=true;
    	}
		else
		cout<<"\nError\nMonth should be between 1 and 12, please try again: \n";	
	}
	check=false;
	
	cout<<endl<<"Enter Employee #"<<numOfEmployee+1<<" Year of birth : ";
	while(check==false)
    {
    	cin>>y;
    	if(y>1950&&y<2050)
     	{
		employees[numOfEmployee].birthdate.year=y;
		check=true;
    	}
		else
		cout<<"\nError\nYears should be between 1950 and 2050, please try again: \n";	
	}
	check=false;
	cout<<endl<<"Enter Employee #"<<numOfEmployee+1<<" Salary : ";
	while(check==false)
    {
    	cin>>sal;
    	if(sal>0)
     	{
		employees[numOfEmployee].salary=sal;
		check=true;
    	}
		else
		cout<<"\nError\nThe salary should be greater then 0, please try again: \n";
	}

	
	cout<<"-------------------------------------------------------------\n\n";		
	numOfEmployee++;
	
}

void Delete(employee employees[]){
	
	string ID;
	bool found=false;
	cout<<"Enter the ID of the employee you want to delete (if you wish to cancel the opration enter -1): ";
	while(found==false)
	{
	cin>>ID;
	if(ID=="-1")
     	break;
	for(int i = 0; i < numOfEmployee; i++){
		if(employees[i].ID == ID){
			for(int j = i; j < numOfEmployee; j++){
				employees[j] = employees[j+1];
			}
			found=true;
		}
	}
	if(found==true)
	numOfEmployee--;
	else
	cout<<"The ID you enter is wrong, please try again(or enter -1 to exit the task): ";
	}	
}

	
	



void display(employee employees[]){
	
	cout<<"ID     Name      	 Dep.            D.O.B       Salary\n\n";
	for(int i = 0; i < numOfEmployee; i++){
			cout<<employees[i].ID<<"    "<<employees[i].name<<"      "<<employees[i].department<<"      "<<employees[i].birthdate.day<<"/"
			<<employees[i].birthdate.month<<"/"<<employees[i].birthdate.year<<"      "<<employees[i].salary<<"SR\n";
		}
	
}


	 
void sort(employee employees[]){
	
	employee temp;
	char option;
	cout<<"In what way do you want to sort the employees ? \n\n1 - Salary\n2 - Department\n3 - Name\n4 - Go back\n";

	
	for(int i=0;i<1;)
	{
	cin>>option;
	if(option=='4')
	{
    	break;
	}
    if(option=='1')
    {
    for(int i = 0; i < numOfEmployee; i++){
				for(int j = i+1; j < numOfEmployee; j++){
					if(employees[i].salary < employees[j].salary){
							temp = employees[i];
							employees[i] = employees[j];
							employees[j] = temp;
					}		
				}
			}
		i=1;
	}
	else if(option=='2')
    {
    for(int i = 0; i < numOfEmployee; i++){
				for(int j = i+1; j < numOfEmployee; j++){
					if(employees[i].department < employees[j].department){
							temp = employees[i];
							employees[i] = employees[j];
							employees[j] = temp;
					}		
				}
			}
	    i=1;
	} 
    else if(option=='3')
    {
    for(int i = 0; i < numOfEmployee; i++){
				for(int j = i+1; j < numOfEmployee; j++){
					if(employees[i].name > employees[j].name){
							temp = employees[i];
							employees[i] = employees[j];
							employees[j] = temp;
					}		
				}
			}
		i=1;			
	}
	else
	{
	    cout<<"Incorrect input\nPlease choose another one: ";	
	}
	}
} 


void update(employee employees[]){
	
string ID;
	bool found = false;
	cout<<"Enter employee ID (if you wish to cancel the opration enter -1):";
	for(int errorRepeat=0;errorRepeat<1;)
	{
	cin>>ID;
	if(ID=="-1")
	   break;
	for(int i = 0; i < numOfEmployee; i++){
		if(employees[i].ID == ID){
			char option;
			cout<<"Which info do you want to update ?\n\n1 - Name\n2 - Department\n3 - Birthday\n4 - Salary\n";
			cin>>option;
			switch(option){
				case '1':
					cout<<"Enter new name : ";
					cin>>employees[i].name;
					break;
				case '2':
					cout<<"Enter new department : ";
					cin>>employees[i].department;
					break;
				case '3':
					cout<<"Enter new day : ";
					cin>>employees[i].birthdate.day;
					cout<<"Enter new month : ";
					cin>>employees[i].birthdate.month;
					cout<<"Enter new year : ";
					cin>>employees[i].birthdate.year;
					break;
				case '4':
					cout<<"Enter new salary : ";
					cin>>employees[i].salary;
					break;	
				default:
					cout<<"Incorrect input.\n";
					break;
				
			}
			found = true;
		}
	}
	if(found == false)
		cout<<"ID does not exist.\nTry again or enter -1 to exit:\n";
		else
		errorRepeat=1;
	};
}


void search(employee employees[]){
	
	string ID;
	bool found = false;
	cout<<"Enter ID for the employee you want to search for : ";
	cin>>ID;
	for(int i = 0; i < numOfEmployee; i++){
		if(employees[i].ID == ID){
			cout<<"\nID    Name      Dep.      D.O.B      Salary\n\n";
			cout<<employees[i].ID<<"    "<<employees[i].name<<"      "<<employees[i].department<<"      "<<employees[i].birthdate.day<<"/"
			<<employees[i].birthdate.month<<"/"<<employees[i].birthdate.year<<"      "<<employees[i].salary<<"\n";
			found = true;
		}
	}
	if(found == false){
		cout<<"\nEmployee does not exist!\n";
	}
}
double calculateYearlySalary(employee employees[]){
	string ID;
	bool found = false;
	cout<<"Enter ID of employee you want to calculate the yearly salary of or(Enter -1 to go back) : \n\n";
	display(employees);
	cout<<"\n\n";
	while(found==false)
	{	
	cin>>ID;
	if(ID=="-1")
	break;
	for(int i = 0; i < numOfEmployee; i++){
		if(employees[i].ID == ID){
			found = true;
			return employees[i].salary * 12;
		}
	}
	if(!found)
		cout<<"\nEmployee ID not found.\nPlease try again or enter -1 to exist: ";
	}		
}
void write(employee employees[]){
	
	Employees.open("employees.txt", ios::out | ios::trunc);
	if(Employees.is_open()){
		for(int i = 0; i < numOfEmployee; i++){
			Employees<<employees[i].ID<<" "<<employees[i].name<<" "<<employees[i].department<<" "<<employees[i].birthdate.day
			<<" "<<employees[i].birthdate.month<<" "<<employees[i].birthdate.year<<" "<<employees[i].salary<<"\n";
		}
	}
	Employees.close();
}
void html(employee employees[]){
	
	ofstream HTML;
	HTML.open("employee.HTML");
	HTML<<"<html>\n"
	"<body>\n"
	"<style>"
    "table, th, td {"
    "padding: 40px;"
    "border: 1px solid red;" 
    "border-collapse: collapse;"
    "}"
    "</style>"
	"<center>"
	"<h1><b>employees!</b></h1>\n"
	"<table style=""width:70%"">"
	"<tr><th><h1>ID</h1></th>"
	"<th><h1>Name</h1></th>"
	"<th><h1>department</h1></th>"
	"<th><h1>salary</h1></th></tr>"
	"</center>";
	for(int i = 0;i <  numOfEmployee; i++){
		HTML<<"<td><h2><center>"<<employees[i].ID<<"</td></h2></center>"
		<<"<td><h2><center>"<<employees[i].name<<"</td></h2></center>"
		<<"<td><h2><center>"<<employees[i].department<<"</td></h2></center>"
		<<"<td><h2><center>"<<employees[i].salary<<"</td></h2></center></tr>";
	}
	HTML.close();
	
}

	/*
the end.
*/	




