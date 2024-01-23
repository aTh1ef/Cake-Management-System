#include <iostream>
#include<stdio.h>		//standard input/output c
#include<stdlib.h>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>
using namespace std;
void gotoxy (int x, int y);
COORD coord = {0, 0};

class Customer
{
		public : string cust_id;
				 string name;
				 string city;
				 string street;
				 string house_no;
				 string email;
				 string phno;
				 /*void read_data1();
				 void pack1();
				 void write_to_file1();
				 void unpack1();
				 int search1(string);
			   	 int delete_item1(string);
		         void modify1(string);*/
		         void main1();
		         string id_list1[100];
				 string extract_id1();
				 int address_list1[100];
				 int count1;
				 int search_index1(string);
				 void read_data1();
			  	 void pack1();
				 void write_to_file1();
				 void create_index1();
				 void remove1(string);
				 void search1(string);
				 void sort_index1();
		         string buffer1;
};

class Cake : public Customer
{
	public :
			string cake_id;
			string cake_name;
			string kg;
			string veg_nveg;
			string custom;
			string extra1;
			string extra2;
			string cake_price;
			void read_data2();
			void pack2();
			void write_to_file2();
			void unpack2();
			int search2(string);
			int delete_item2(string);
		    void modify2(string);
			void main2();
			string buffer2;
};
class Order : public Cake
{
	public :
			string order_id;
			string total_price;
			string delivery;
			string place;
			void read_data3();
			void pack3();
			void write_to_file3();
			void unpack3();
			int search3(string);
			int delete_item3(string);
		    void modify3(string);
			void main3();
			string buffer3;
};
class mainp : public Order
{
	public:
			void login();
			void menupage();
};

class date;
class date		//class current date and time of system
{
	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;

	}
};

char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}

void frame()
{
	int i,j=117;
	for(i = 0;i<118,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(2);
		cout<<"=";
		gotoxy(j,22);
		Sleep(2);
		cout<<"=";
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top

}

void scroll_note()	//welcome note
{
	system("color 9");
	int j,i,x,y;


	gotoxy(45,10);cout<<"\tCAKE MANAGEMENT SYSTEM";
	gotoxy(50,12);cout<<"\tWELCOME";
	for(int j=115;j>=0;j--)
	{
		gotoxy(j,4);cout<<"@";
		Sleep(2);
	}
	for(int j=0;j<=115;j++)
	{
		gotoxy(j,20);cout<<"@";
		Sleep(2);
	}
	gotoxy(86,23);cout<<"By : Ateef Sheikh";
	gotoxy(86,24);cout<<"        Jagannath";
	Sleep(1000);

}
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mainp::login(){
	char addname[30],pass[30];
	char adname[]="AteefJagga";
	char password[]="123";
	while(1)
	{
		system("cls");
		frame();
		//gotoxy(35,2);
		cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n";
        cout<<"\t\t\t                          WELCOME TO LOGIN PAGE                       \n\n\n";
        cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n";
		gotoxy(29,13);
		cout<<"Enter the Name : ";
		cin>>addname;
			if(strcmp(adname,addname)==0)
			{
            gotoxy(29,16);
				cout<<"Enter the Password : ";
				cin>>pass;
				if(strcmp(password,pass)==0)
				{
					menupage();
				}
			}
	}
}
void mainp::menupage(){
	int op1;
	while(1)
	{
		system("cls");
		frame();
		gotoxy(48,7);
		cout<<"1.CUSTOMER ";
		gotoxy(48,9);
		cout<<"2.CAKE";
		gotoxy(48,11);
		cout<<"3.ORDER";
		gotoxy(48,13);
		cout<<"4.EXIT";
		gotoxy(48,15);
		cout<<"Select your Option : ";
		op1=getch();
		if(op1=='1')

		{
			Customer cust;
			cust.main1();
		}
		else if(op1=='2')
		{
			Cake cake;
			cake.main2();
		}
		else if(op1=='3')
		{
			Order ord;
			ord.main3();
		}
		else if(op1=='4'){
			exit(0);
		}
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			system("cls");
		}
	}
}


//Customer------------------------------------------------------------------------------------------------
void Customer :: main1(){
	int op1;
	Customer cu;
	while(1)
	{
		system("cls");
		frame();
		cu.create_index1();
		gotoxy(48,8);
		cout<<"1.ADD CUSTOMER DETAILS ";
		gotoxy(48,10);
		cout<<"2.DELETE CUSTOMER DETAILS ";
		gotoxy(48,12);
		/*cout<<"3.UPDATE CUSTOMER DETAILS";
		gotoxy(48,14);*/
		cout<<"3.SEARCH CUSTOMER DETAILS";
		gotoxy(48,14);
		cout<<"4.BACK ";
		gotoxy(48,16);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			cu.read_data1();
			cout<<"1";
			cu.pack1();
			cout<<"2";
			cu.write_to_file1();
			cout<<"3";
		}
		else if(op1=='2')
		{
			int i;
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Customer ID to be Searched : ";
			cin>>key;
			gotoxy(40,9);
			/*i=*/cu.remove1(key);
			/*gotoxy(40,13);
			if(i==1)
			    cout<<"Record Deleted\n";
			else
				cout<<"Record is not Deleted\n";
			Sleep(2000);*/
		}
		/*else if(op1=='3')
		{
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Customer ID to be Modified : ";
			cin>>key;
			gotoxy(40,9);
			cu.modify1(key);
			Sleep(2000);
		}*/
		else if(op1=='3')
		{
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Customer ID to be Searched : ";
			cin>>key;
			gotoxy(40,9);
			cu.search1(key);
			Sleep(2000);
		}
		else if(op1=='4'){
			mainp p;
			p.menupage();
		}
		else
		{
			gotoxy(50,26);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(2000);
			system("cls");
		}
	}
}
void Customer :: read_data1()
{
	system("cls");
	frame();
	gotoxy(40,8);
	cout<<"---Customer Details---\n";
	cout<<"\tEnter the CustomerID : ";
	cin>>cust_id;
	gotoxy(40,9);
	cout<<"\n\tEnter the Customer Name(Full Name) : ";
	cin>>name;
	cout<<"\n\t\t\t\t\t---Address Details---\n";
	gotoxy(40,12);
	cout<<"\n\tCity : ";
	cin>>city;
	gotoxy(40,13);
	cout<<"\n\tStreet : ";
	cin>>street;
	gotoxy(40,14);
	cout<<"\n\tHouseNo : ";
	cin>>house_no;
	gotoxy(40,15);
	cout<<"\n\t\t\t\t\t---------------------\n";
	cout<<"\n\tEnter the E-mail : ";
	cin>>email;
	gotoxy(40,18);
	cout<<"\n\tEnter the PhoneNo : ";
	cin>>phno;
	gotoxy(40,19);
}
void Customer :: pack1()
{
	buffer1.erase();
	buffer1+=cust_id+"|"+name+"|"+city+"|"+street+"|"+house_no+"|"+email+"|"+phno+"$$$$$"+"\n";
}
void Customer :: write_to_file1()
{
	fstream file1;
	int pos;
	file1.open("Customer.txt",ios::out|ios::app);
	pos=file1.tellg();
	file1<<buffer1;
	file1.close();
	id_list1[++count1]=cust_id;
	address_list1[count1]=pos;
	sort_index1();
}
string Customer :: extract_id1()
{
	string cust_id;
	int i=0;
	cust_id.erase();
	while(buffer1[i]!='|')
	cust_id+=buffer1[i++];
	return cust_id;
}
/*void Customer :: unpack1()
{
	int i=0;
	cust_id.erase();
	while(buffer1[i]!='|')
		cust_id+=buffer1[i++];

	name.erase();
	i++;
	while(buffer1[i]!='|')
		name+=buffer1[i++];

	name.erase();
	i++;
	while(buffer1[i]!='|')
		name+=buffer1[i++];

	city.erase();
	i++;
	while(buffer1[i]!='|')
		city+=buffer1[i++];

	street.erase();
	i++;
	while(buffer1[i]!='|')
		street+=buffer1[i++];

	house_no.erase();
	i++;
	while(buffer1[i]!='|')
		house_no+=buffer1[i++];

	email.erase();
	i++;
	while(buffer1[i]!='|')
		email+=buffer1[i++];

	phno.erase();
	i++;
	while(buffer1[i]!='$')
		phno+=buffer1[i++];
}*/
void Customer :: create_index1()
{
	fstream file1;
	int pos;
	string cust_id;
	count1=-1;
	file1.open("Customer.txt",ios::in);
	while(!file1.eof())
	{
		pos=file1.tellg();
		buffer1.erase();
		getline(file1,buffer1);
		if(buffer1[0]!='*')
		{
			if(buffer1.empty())
			break;
			cust_id=extract_id1();
			id_list1[++count1]=cust_id;
			address_list1[count1]=pos;
		}
	}
	file1.close();
	sort_index1();
	buffer1.erase();
}
void Customer :: sort_index1()
{
	cout<<"4";
	int i,j,temp_address;
	string temp_id;
	for(int i=0;i<=count1;i++)
	{
		for(int j=i+1;j<count1;j++)
		{
			if(id_list1[i]>id_list1[j])
			{
				temp_id=id_list1[i];
				id_list1[i]=id_list1[j];
				id_list1[j]=temp_id;
				temp_address=address_list1[i];
				address_list1[i]=address_list1[j];
				address_list1[j]=temp_address;
			}
		}
	}
	for(i=0;i<=count1;i++)
	{
		cout<<id_list1[i]<<"\t"<<address_list1[i]<<"\n";
	}
}
int Customer :: search_index1(string key)
{
	int low=0,high=count1,mid=0,flag=0,pos;
	while(low<=high)
	{

		mid=(low+high)/2;

		if(id_list1[mid]==key){
			flag=1;
			break;

		}

		if(id_list1[mid]>key)
			high=mid-1;
		if(id_list1[mid]<key)
			low=mid+1;
	}
	if(flag)
		return mid;
	else
		return -1;

}
/*int Customer :: search1(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("Customer.txt",ios::in);
	while(!file.eof())
	{
		buffer1.erase();
		pos=file.tellg();
		getline(file,buffer1);
		unpack1();
		gotoxy(40,10);
		if(key==cust_id)
		{
			cout<<"Found the Key. The Record is... \n\t\t\t\t\t"<<buffer1;
			flag=1;
			return pos;
		}
	}
	file.close();
	gotoxy(40,10);
	if(flag==0)
	{
		cout<<"Not Found..\n";
		return -1;
	}
}*/
void Customer :: search1(string key)
{
	int pos=0,add;
	fstream file1;
	buffer1.erase();

	pos=search_index1(key);
	gotoxy(40,9);
	cout<<pos;
	if(pos==-1)
	{
		gotoxy(40,11);
		cout<<"Record not Found";
		Sleep(2000);
	}
	else if(pos>=0)
	{
		file1.open("Customer.txt");
		add=address_list1[pos];
		file1.seekp(add,ios::beg);
		getline(file1,buffer1);
		gotoxy(40,11);
		cout<<"Record found....";
		gotoxy(40,12);
		cout<<buffer1;
		file1.close();
		Sleep(2000);
	}
}
void Customer :: remove1(string key)
{
	int pos=0,i,address;
	fstream file1;
	pos=search_index1(key);
	if(pos>=0)
	{
		file1.open("Customer.txt",ios::out|ios::in);
		address=address_list1[pos];
		file1.seekp(address,ios::beg);
		file1.put('*');
		file1.close();
		gotoxy(40,10);
		cout<<buffer1;
		gotoxy(40,11);
		cout<<"Record Deleted";
		Sleep(2000);
		for(i=pos;i<count1;i++)
		{
			id_list1[i]=id_list1[i+1];
			address_list1[i]=address_list1[i+1];
		}
		count1--;
	}
	else
	{
	gotoxy(40,11);
	cout<<"Record not Found\n";
	Sleep(2000);
	}
}
/*int Customer :: delete_item1(string key)
{
	fstream file;
	int pos,flag=0;
	pos=search1(key);
	if(pos>=0)
	{
		file.open("Customer.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
void Customer :: modify1(string key)
{
	int c;
	if(delete_item1(key))
	{
		system("cls");
		frame();
		gotoxy(40,8);
		cout<<"\nWhat to Modify \n1. CustomerID\n2. Customer Name\n3. City\n4. Street\n5. HouseNo.\n6. E-mail\n7. PhoneNo\n\nEnter your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1:gotoxy(40,10);
					cout<<"CustomerID : ";
			       cin>>cust_id;
			       break;
			case 2:gotoxy(40,10);
					cout<<"Customer Name : ";
			       cin>>name;
			       break;
			case 3:gotoxy(40,10);
					cout<<"City : ";
			       cin>>name;
			       break;
			case 4:gotoxy(40,10);
					cout<<"Street : ";
			       cin>>street;
			       break;
			case 5:gotoxy(40,10);
					cout<<"HouseNo. : ";
			       cin>>house_no;
			       break;
			case 6:gotoxy(40,10);
					cout<<"E-mail : ";
			       cin>>email;
			       break;
			case 7:gotoxy(40,10);
					cout<<"PhoneNo. : ";
			       cin>>phno;
			       break;
			default:gotoxy(40,10);
					cout<<"Wrong Choice\n";
		}
	}
}*/
//----------------------------------------------------------------------------------------------------------



//Cake------------------------------------------------------------------------------------------------------
void Cake :: main2(){
	int op1;
	Cake ca;
	while(1)
	{
		system("cls");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD CAKE DETAILS ";
		gotoxy(48,10);
		cout<<"2.DELETE CAKE DETAILS ";
		gotoxy(48,12);
		cout<<"3.UPDATE CAKE DETAILS";
		gotoxy(48,14);
		cout<<"4.SEARCH CAKE DETAILS";
		gotoxy(48,16);
		cout<<"5.BACK ";
		gotoxy(48,18);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			ca.read_data2();
			ca.pack2();
			ca.write_to_file2();
		}
		else if(op1=='2')
		{
			int i;
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Cake ID to be Searched : ";
			cin>>key;
			gotoxy(40,10);
			i=ca.delete_item2(key);
			gotoxy(40,13);
			if(i==1)
			    cout<<"Record Deleted\n";
			else
				cout<<"Record is not Deleted\n";
			Sleep(2000);
		}
		else if(op1=='3')
		{
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Cake ID to be Modified : ";
			cin>>key;
			gotoxy(40,9);
			ca.modify2(key);
			Sleep(2000);
		}
		else if(op1=='4')
		{
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Cake ID to be Searched : ";
			cin>>key;
			gotoxy(40,9);
			ca.search2(key);
			Sleep(2000);
		}
		else if(op1=='5'){
			mainp p;
			p.menupage();
		}
		else
		{
			gotoxy(50,26);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(2000);
			system("cls");
		}
	}
}
void Cake :: read_data2()
{
	system("cls");
	gotoxy(40,8);
	cout<<"---Cake Details---\n";
	cout<<"\n\tEnter the CakeID : ";
	cin>>cake_id;
	gotoxy(40,10);
	cout<<"\n\tEnter the Cake Name : ";
	cin>>cake_name;
	gotoxy(40,11);
	cout<<"\n\tEnter the Size (in Kgs) : ";
	cin>>kg;
	gotoxy(40,12);
	cout<<"\n\tVeg Or Non-Veg : ";
	cin>>veg_nveg;
	gotoxy(40,13);
	cout<<"\n\tEnter the Customization (if required) : ";
	cin>>custom;
	gotoxy(40,14);
	cout<<"\n\tEnter the Extras1 (if required) : ";
	cin>>extra1;
	gotoxy(40,15);
	cout<<"\n\tEnter the Extras2 (if required) : ";
	cin>>extra2;
	gotoxy(40,16);
	Sleep(2000);
}
void Cake :: pack2()
{
	buffer2.erase();
	buffer2+=cake_id+"|"+cake_name+"|"+kg+"|"+veg_nveg+"|"+custom+"|"+extra1+"|"+extra2+"$$$$$"+"\n";
}
void Cake :: write_to_file2()
{
	fstream file2;
	file2.open("Cake.txt",ios::out|ios::app);
	file2<<buffer2;
	file2.close();
}
void Cake :: unpack2()
{
	int i=0;
	cake_id.erase();
	while(buffer2[i]!='|')
		cake_id+=buffer2[i++];

	cake_name.erase();
	i++;
	while(buffer2[i]!='|')
		cake_name+=buffer2[i++];

	kg.erase();
	i++;
	while(buffer2[i]!='|')
		kg+=buffer2[i++];

	veg_nveg.erase();
	i++;
	while(buffer2[i]!='|')
		veg_nveg+=buffer2[i++];

	custom.erase();
	i++;
	while(buffer2[i]!='|')
		custom+=buffer2[i++];

	extra1.erase();
	i++;
	while(buffer2[i]!='|')
		extra1+=buffer2[i++];

	extra2.erase();
	i++;
	while(buffer2[i]!='$')
		extra2+=buffer2[i++];
			extra2.erase();
}
int Cake :: search2(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("Cake.txt",ios::in);
	while(!file.eof())
	{
		buffer2.erase();
		pos=file.tellg();
		getline(file,buffer2);
		unpack2();
		gotoxy(40,10);
		if(key==cake_id)
		{
			cout<<"Found the Key. The Record is... \n\t\t\t\t\t"<<buffer2;
			flag=1;
			return pos;
		}
	}
	file.close();
	gotoxy(40,10);
	if(flag==0)
	{
		cout<<"Not Found..\n";
		return -1;
	}
}
int Cake :: delete_item2(string key)
{
	fstream file;
	int pos,flag=0;
	pos=search2(key);
	if(pos>=0)
	{
		file.open("Cake.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
void Cake :: modify2(string key)
{
	int c;
	if(delete_item2(key))
	{
		system("cls");
		gotoxy(40,8);
		cout<<"\nWhat to Modify \n1. CakeID\n2. Cake Name\n3. Size\n4. Veg or Non-Veg\n5. Customization\n6. Extra1\n7. Extra2\n\nEnter your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1:gotoxy(40,10);
					cout<<"CakeID : ";
			       cin>>cake_id;
			       break;
			case 2:gotoxy(40,10);
					cout<<"Cake Name : ";
			       cin>>cake_name;
			       break;
			case 3:gotoxy(40,10);
					cout<<"Size : ";
			       cin>>kg;
			       break;
			case 4:gotoxy(40,10);
					cout<<"Veg or Non-Veg : ";
			       cin>>veg_nveg;
			       break;
			case 5:gotoxy(40,10);
					cout<<"Customization : ";
			       cin>>custom;
			       break;
			case 6:gotoxy(40,10);
					cout<<"Extra1 : ";
			       cin>>extra1;
			       break;
			case 7:gotoxy(40,10);
					cout<<"Extra2 : ";
			       cin>>extra2;
			       break;
			default:gotoxy(40,10);
					cout<<"Wrong Choice";
		}
		pack2();
		write_to_file2();
	}
}
//--------------------------------------------------------------------------------------------






//Order-------------------------------------------------------------------------------------
void Order :: main3(){
	int op1;
	Order ord;
	while(1)
	{
		system("cls");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD ORDER DETAILS ";
		gotoxy(48,10);
		cout<<"2.DELETE ORDER DETAILS ";
		gotoxy(48,12);
		cout<<"3.UPDATE ORDER DETAILS";
		gotoxy(48,14);
		cout<<"4.SEARCH ORDER DETAILS";
		gotoxy(48,16);
		cout<<"5.BACK ";
		gotoxy(48,18);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			ord.read_data3();
			ord.pack3();
			ord.write_to_file3();
		}
		else if(op1=='2')
		{
			int i;
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Order ID to be Searched : ";
			cin>>key;
			gotoxy(40,10);
			i=ord.delete_item3(key);
			gotoxy(40,13);
			if(i==1)
			    cout<<"Record Deleted\n";
			else
				cout<<"Record is not Deleted\n";
			Sleep(2000);
		}
		else if(op1=='3')
		{
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Order ID to be Modified : ";
			cin>>key;
			gotoxy(40,9);
			ord.modify3(key);
			Sleep(2000);
		}
		else if(op1=='4')
		{
			string key;
			system("cls");
			gotoxy(40,8);
			cout<<"Enter the Order ID to be searched : ";
			cin>>key;
			gotoxy(40,9);
			ord.search3(key);
			Sleep(2000);
		}
		else if(op1=='5'){
			mainp p;
			p.menupage();
		}
		else
		{
			gotoxy(50,26);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(2000);
			system("cls");
		}
	}
}
void Order :: read_data3()
{
	system("cls");
	gotoxy(40,8);
	cout<<"---Order Details---\n";
	cout<<"\n\tEnter the OrderNo : ";
	cin>>order_id;
	gotoxy(40,10);
	cout<<"\n\tEnter the Delivery Date : ";
	cin>>delivery;
	gotoxy(40,11);
	cout<<"\n\tEnter the Place and Time(in hh:mm) : ";
	cin>>place;
	gotoxy(40,12);
	Sleep(2000);
}
void Order :: pack3()
{
	buffer3.erase();
	buffer3+=order_id+"|"+delivery+"|"+place+"$$$$$"+"\n";
}
void Order :: write_to_file3()
{
	fstream file3;
	file3.open("Order.txt",ios::out|ios::app);
	file3<<buffer3;
	file3.close();
}
void Order :: unpack3()
{
	int i=0;
	order_id.erase();
	while(buffer3[i]!='|')
		order_id+=buffer3[i++];

	delivery.erase();
	i++;
	while(buffer3[i]!='|')
		delivery+=buffer3[i++];

	place.erase();
	i++;
	while(buffer3[i]!='$')
		place+=buffer3[i++];
}
int Order :: search3(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("Order.txt",ios::in);
	while(!file.eof())
	{
		buffer3.erase();
		pos=file.tellg();
		getline(file,buffer3);
		unpack3();
		gotoxy(40,10);
		if(key==order_id)
		{
			cout<<"Found the Key. The Record is... \n\t\t\t\t\t"<<buffer3;
			flag=1;
			return pos;
		}
	}
	file.close();
	gotoxy(40,10);
	if(flag==0)
	{
		cout<<"Not Found..\n";
		return -1;
	}
}
int Order :: delete_item3(string key)
{
	fstream file;
	int pos,flag=0;
	pos=search3(key);
	if(pos>=0)
	{
		file.open("Order.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
void Order :: modify3(string key)
{
	int c;
	if(delete_item3(key))
	{
		system("cls");
		gotoxy(40,8);
		cout<<"\nWhat to Modify \n1. OrderID\n2. Delivery Time\n3. Place and Time\n\nEnter your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1:gotoxy(40,10);
					cout<<"OrderID : \t";
			       cin>>order_id;
			       break;
			case 2:gotoxy(40,10);
					cout<<"Delivery Time : \t";
			       cin>>delivery;
			       break;
			case 3:gotoxy(40,10);
					cout<<"Place and Time : \t";
			       cin>>place;
			       break;
			default:gotoxy(40,10);
					cout<<"Wrong Choice\t";
		}
		pack3();
		write_to_file3();
	}
}
//---------------------------------------------------------------------------------------



//MAIN----------------------------------------------------------------------------------
int main()
{
	mainp q;
	scroll_note();
	Sleep(2000);
	q.login();
	return 0;
}
