// DIGITAL DIARY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<conio.h>
using namespace std;
#include<iomanip>
#include<time.h>
#include "gotoxy.h"
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

class contact
{
 private:

 char name[50],email[50];
 char mobile[12];

 public:
 void border();
 void sub_heading(char str[50]);
 void add();
 void search();
 void Delete();
 void display();
 void edit();
 void contactsMenu();
 char *retmob()
 { return mobile;}

 char *retname()
 {return name;}

 char *retemail()
 { return email;}

 void update_mob(char m[10])
 {
  strcpy(mobile,m);
 }
 void display1()
 {int x=29,y=17;
  gotoxy(x,y);
  cout<<"Name :-";
  gotoxy(x,y+1);
  cout<<"Number :-";
  gotoxy(x,y+2);
  cout<<"Email :-";
  gotoxy(x+8,y);
  puts(name);
  gotoxy(x+10,y+1);
  puts(mobile);
  gotoxy(x+9,y+2);
  puts(email);
 }
};
void contact::contactsMenu()
{system("cls");
 int option;
 char choice;
 Menu:
 border();
 sub_heading("CONTACTS");
 gotoxy(28,8);
 cout<<"1) ADD CONTACT";
 gotoxy(44,8);
 cout<<"2) SEARCH CONTACT";
 gotoxy(28,11);
 cout<<"3) DELETE";
 gotoxy(44,11);
 cout<<"4) EDIT";
 gotoxy(28,14);
 cout<<"5) DISPLAY";
 gotoxy(44,14);
 cout<<"6) EXIT";
 gotoxy(30,17);
 cout<<"ENTER YOUR OPTION :-";
 gotoxy(51,17);
 cin>>option;

 switch(option)
 {
  case 1: addc:
	  add();
	  gotoxy(24,21);
	  cout<<"Go to contacts menu?(Y/N):-";
	  cin>>choice;
	  if(choice=='Y'||choice=='y')
	  {
	   system("cls");
	   goto Menu;
	  }
	  else
	  if(choice=='N'||choice=='n')
	  {
	   goto addc;
	  }
  case 2: searchc:
	  search();
	  gotoxy(23,22);
	  cout<<"Go to contacts Menu(Y/N):-";
	  cin>>choice;
	  if(choice=='Y'||choice=='y')
	  {
	   system("cls");
	   goto Menu;
	  }
	  else
	  if(choice=='N'||choice=='n')
	  {
	   goto searchc;
	  }

  case 3: delc:
	  Delete();
	  gotoxy(24,20);
	  cout<<" Go to Contacts Menu(Y/N)? :-";
	  cin>>choice;
	  if(choice=='Y'||choice=='y')
	  {
	   system("cls");
	   goto Menu;
	  }
	   else
	   if(choice=='N'||choice=='n')
	  {
	   goto delc;
	  }

  case 4: editc:
	  edit();
	  gotoxy(25,20);
	  cout<<"Go to Contacts Menu(Y/N)? :-";
	  cin>>choice;
	  if(choice=='Y'||choice=='y')
	  {
	   system("cls");
	   goto Menu;
	  }
	  else
	  if(choice=='N'||choice=='n')
	  {
	   goto editc;
	  }


  case 5: dispc:
	  display();
	  gotoxy(24,20);
	  cout<<"Go to Contacts Menu(Y/N)? :- ";
	  cin>>choice;
	  if(choice=='Y'||choice=='y')
	  {
	   system("cls");
	   goto Menu;
	  }
	  else
	  if(choice=='N'||choice=='n')
	  {
	   goto dispc;
	  }

  case 6: return;
  default : goto Menu;
 }
}
//////////////////////////////////////////////////////////////////

void contact::add()
{char ch;
 contact c;
 fstream file;
 file.open("contacts.dat",ios::app|ios::binary);
 system("cls");
 border();
 sub_heading("CONTACTS");
 gotoxy(24,7);
 cout<<"ENTER THE FOLLOWING :-";
 gotoxy(24,10);
 cout<<"Name :-";
 gotoxy(24,13);
 cout<<"Number :-";
 gotoxy(24,16);
 cout<<"Email :-";
 gotoxy(32,10);
 gets(c.name);
 gotoxy(34,13);
 gets(c.mobile);
 gotoxy(33,16);
 gets(c.email);
 file.write((char*)&c,sizeof(c));
 gotoxy(35,19);
 cout<<"CONTACT SAVED";
 file.close();
}
//////////////////////////////////////////////////

void contact::search()
{contact c;
 int option,status=0;
 char mob[10];
 char name1[50],email1[50];
 Searchmenu:
 system("cls");
 border();
 sub_heading("CONTACTS");
 fstream file;
 file.open("contacts.dat",ios::in|ios::binary);
 gotoxy(35,7);
 cout<<"SEARCH BY :-";
 gotoxy(22,9);
 cout<<"1) NAME";
 gotoxy(35,9);
 cout<<"2) NUMBER";
 gotoxy(50,9);
 cout<<"3) EMAIL";
 gotoxy(28,11);
 cout<<"Enter your option :- ";
 cin>>option;
 switch(option)
 {
  case 1: gotoxy(23,13);
	  cout<<"enter the name :- ";
	  gets(name1);
	  while(file.read((char*)&c,sizeof(c)))
	  {
	   if(_strcmpi(name1,c.retname())==0)
	   {status=1;
	    gotoxy(32,15);
	    cout<<"Contact Details";
	    c.display1();
	    break;
	   }
	  }
	  if(status==0)
	  {
	    gotoxy(32,15);
	    cout<<"Contact Not Found";
	    break;
	  }
	  break;

  case 2: gotoxy(23,13);
	  cout<<"Enter the Number :- ";
	  gets(mob);
	  while(file.read((char*)&c,sizeof(c)))
	  {
	   if(strcmp(mob,c.retmob())==0)
	   {status=1;
	    gotoxy(32,15);
	    cout<<"contact Details";
	    c.display1();
	    break;
	   }
	  }
	  if(status==0)
	  {
	   gotoxy(32,15);
	   cout<<"Contact Not Found";
	   break;
	  }
	  break;

  case 3: gotoxy(23,13);
	  cout<<"Enter the Email ID :- ";
	  gets(email1);
	  while(file.read((char*)&c,sizeof(c)))
	  {
	   if(strcmp(email1,c.retemail())==0)
	   {status=1;
	    gotoxy(32,15);
	    cout<<"Contact Details";
	    c.display1();
	    break;
	   }
	  }
	  if(status==0)
	  {
	   gotoxy(32,15);
	   cout<<"Contact Not Found";
	   break;
	  }
	  break;
  default : goto Searchmenu;
 }
 file.close();
}
/////////////////////////////////////////////////////////

void contact:: Delete()
{int status =0;
 contact c;
 char name[50];
 system("cls");
 border();
 sub_heading("DELETION");
 ifstream fin;
 fin.open("contacts.dat",ios::in|ios::binary);
 ofstream fout;
 fout.open("temp.dat",ios::app|ios::binary);
 gotoxy(14,7);
 cout<<"Enter the name of the contact to be deleted :-";
 gets(name);
 while(fin.read((char*)&c,sizeof(c)))
 {
  if(_strcmpi(name,c.retname())==0)
  {
   status=1;
  }
  else
  {
   fout.write((char*)&c,sizeof(c));
  }
 }
 if(status==1)
 {
  gotoxy(24,10);
  cout<<"Contact Deleted";
 }
 else
 {
  gotoxy(24,10);
  cout<<"Invalid contact";
 }
 remove("contacts.dat");
 rename("temp.dat","contacts.dat");
 fin.close();
 fout.close();
}
///////////////////////////////////////////////////////
void contact::edit()
{int status = 0,mob1;
 contact c;
 char name[50],email[50];
 fstream file;
 file.open("contacts.dat",ios::in|ios::out|ios::binary);
 system("cls");
 border();
 sub_heading("Edit Contacts");
 gotoxy(12,7);
 cout<<"Enter the name of the contact to be updated :- ";
 gets(name);
 while(file.read((char*)&c,sizeof(c)))
 {
  if(_strcmpi(name,c.retname())==0)
  {
   status=1;
   gotoxy(20,10);
   cout<<"Update the Following :-";
   gotoxy(20,12);
   cout<<"Name :-";
   gotoxy(20,14);
   cout<<"Number :-";
   gotoxy(20,16);
   cout<<"Email :-";
   gotoxy(28,12);
   gets(c.name);
   gotoxy(30,14);
   gets(c.mobile);
   gotoxy(29,16);
   gets(c.email);
   long l=file.tellg();
   file.seekp((l-sizeof(c)),ios::beg);
   file.write((char*)&c,sizeof(c));
   gotoxy(35,18);
   cout<<"Contact Updated";
  }
 }
 if(status==0)
 {
  gotoxy(24,10);
  cout<<"Invalid Contact";
 }
 file.close();
}
//////////////////////////////////////////////////////////////
void contact::display()
{
 int i=9,k=1;
 contact c;
 fstream file;
 file.open("contacts.dat",ios::in|ios::binary);
 system("cls");
 border();
 sub_heading("Contact List");
 gotoxy(10,7);
 cout<<"Name";
 gotoxy(30,7);
 cout<<"Number";
 gotoxy(50,7);
 cout<<"Email";
 while(file.read((char*)&c,sizeof(c)))
 {
  gotoxy(8,i);
  cout<<k<<")";
  puts(c.name);
  gotoxy(30,i);
  puts(c.mobile);
  gotoxy(50,i);
  puts(c.email);
  i++,k++;
 }
 file.close();
}
/////////////////////////////////////////////////////////
void contact::border()
{char str[]="D I G I T A L  D I A R Y";
 system("cls");
 int i,j;
 for( i=2;i<=75;i++)
 {
  gotoxy(i,1);
  cout<<"--";
  
 }
 for(i=2;i<=75;i++)
 {
  gotoxy(i,24);
  cout<<"--";
  
 }
 for(j=1;j<=24;j++)
 {
  gotoxy(1,j);
  cout<<"|";
  
 }
 for(j=1;j<=24;j++)
 {
  gotoxy(76,j);
  cout<<"|";
  
 }
 for(i=2;i<=74;i++)
 {
  gotoxy(i,3);
  cout<<"--";
  
 }
 gotoxy(28,2);
 for(int a=0;a<strlen(str);a++)
 {
  cout<<str[a];
 
 }
}
/////////////////////////////////////////////////////////////

void contact:: sub_heading(char str[50])
{
 int m,n;
 n=40+(strlen(str)/2)+2;
 m=40-(strlen(str)/2)-2;
 for(int i=m;i<=n;i++)
 {
  gotoxy(i,5);
  cout<<"--";
 }
 gotoxy(m+2,4);
 cout<<str;
}

class worldclock{
struct zones_places
{
 char zone[7];      //takes the UTC zone  eg. -03:30
 char places[4][30];
 int num;           //number of places assigned

};

public:
zones_places zonplace[13] ;
worldclock();
void initialize_struct();
void display_time(char time[]);
void time_in_pc();
};
void worldclock:: initialize_struct(){

strcpy(zonplace[0].zone,"-10:00");
strcpy(zonplace[0].places[0],"Hawaii");
zonplace[0].num=1;

strcpy(zonplace[1].zone,"-06:00");
strcpy(zonplace[1].places[0],"Central Time(US and Canada)");
zonplace[1].num=1;

strcpy(zonplace[2].zone,"-03:00");
strcpy(zonplace[2].places[0],"Greenland,");
strcpy(zonplace[2].places[1],"Brasila,");
strcpy(zonplace[2].places[2],"Santiago");
zonplace[2].num=3;

strcpy(zonplace[3].zone,"+00:00");
strcpy(zonplace[3].places[0],"Coordinated Universal Time,");
strcpy(zonplace[3].places[1],"London,");
strcpy(zonplace[3].places[2],"Casablanca,");
strcpy(zonplace[3].places[3],"Edinburgh,");
zonplace[3].num=4;

strcpy(zonplace[4].zone,"+01:00");
strcpy(zonplace[4].places[0],"West Central Africa,");
strcpy(zonplace[4].places[1],"Paris,");
strcpy(zonplace[4].places[2],"Berlin,");
strcpy(zonplace[4].places[3],"Madrid");
zonplace[4].num=4;

strcpy(zonplace[5].zone,"+02:00");
strcpy(zonplace[5].places[0],"Cairo,");
strcpy(zonplace[5].places[1],"Athens,");
strcpy(zonplace[5].places[2],"Jerusalem");
zonplace[5].num=3;

strcpy(zonplace[6].zone,"+03:00");
strcpy(zonplace[6].places[0],"Bahrain,");
strcpy(zonplace[6].places[1],"Kuwait, Riyadh,");
strcpy(zonplace[6].places[2],"Moscow,");
strcpy(zonplace[6].places[3],"St. Petersburg");
zonplace[6].num=4;

strcpy(zonplace[7].zone,"+05:30");
strcpy(zonplace[7].places[0],"New Delhi,");
strcpy(zonplace[7].places[1],"Mumbai,");
strcpy(zonplace[7].places[2],"Kolkata");
zonplace[7].num=3;

strcpy(zonplace[8].zone,"+06:00");
strcpy(zonplace[8].places[0],"Dhaka");
zonplace[8].num=1;

strcpy(zonplace[9].zone,"+08:00");
strcpy(zonplace[9].places[0],"Beijing,");
strcpy(zonplace[9].places[1],"Hong kong,");
strcpy(zonplace[9].places[2],"Singapore,");
strcpy(zonplace[9].places[3],"Kuala Lumpur");
zonplace[9].num=4;

strcpy(zonplace[10].zone,"+10:00");
strcpy(zonplace[10].places[0],"Sydney,");
strcpy(zonplace[10].places[1],"Melbourne");
zonplace[10].num=2;
strcpy(zonplace[11].zone,"+11:00");
strcpy(zonplace[11].places[0],"Solomon,");
zonplace[11].num=1;

strcpy(zonplace[12].zone,"+12:00");
strcpy(zonplace[12].places[0],"Fiji");
zonplace[12].num=1;
}

void worldclock:: display_time(char time[])   //time array format- 88:88
{
int x,y;

for(x=20;x<=53;++x)
{ gotoxy(x,7);  cout<<"*";
  gotoxy(x,17);  cout<<"*";
}

for(y=7;y<=17;++y)
{ gotoxy(20,y);  cout<<"*";
  gotoxy(53,y);  cout<<"*";
}

char ch;
for(int i=0;i<5;++i)
{
ch=time[i];
y=10;

if(i==0)
x=25;
else if(i==1)
x=30;
else if(i==2)
x=35;
else if(i==3)
x=39;
else if(i==4)
x=44;


switch(ch){


case '0':gotoxy(x,y);  cout<<" __ ";
	    gotoxy(x,y+1);cout<<"|  |";
	    gotoxy(x,y+2);cout<<"|  |";
	    gotoxy(x,y+3);cout<<"|  |";
	    gotoxy(x,y+4);cout<<"|__|";
	    break;

case '1':gotoxy(x,y);   cout<<"   ";
	    gotoxy(x,y+1); cout<<"  |";
	    gotoxy(x,y+2); cout<<"  |";
	    gotoxy(x,y+3); cout<<"  |";
	    gotoxy(x,y+4); cout<<"  |";
	    break;

case '2':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"   |";
	    gotoxy(x,y+2); cout<<" __|";
	    gotoxy(x,y+3); cout<<"|   ";
	    gotoxy(x,y+4); cout<<"|__ ";
	    break;

case ':':gotoxy(x,y);   cout<<" _ ";
	    gotoxy(x,y+1); cout<<"|_|";
	    gotoxy(x,y+2); cout<<"   ";
	    gotoxy(x,y+3); cout<<" _ ";
	    gotoxy(x,y+4); cout<<"|_|";
	    break;

case '3':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"   |";
	    gotoxy(x,y+2); cout<<" __|";
	    gotoxy(x,y+3); cout<<"   |";
	    gotoxy(x,y+4); cout<<" __|";
	    break;

case '4':gotoxy(x,y); cout<<"    ";
	    gotoxy(x,y+1); cout<<"|  |";
	    gotoxy(x,y+2); cout<<"|__|";
	    gotoxy(x,y+3); cout<<"   |";
	    gotoxy(x,y+4); cout<<"   |";
	    break;

case '5':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"|   ";
	    gotoxy(x,y+2); cout<<"|__ ";
	    gotoxy(x,y+3); cout<<"   |";
	    gotoxy(x,y+4); cout<<" __|";
	    break;

case '6':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"|   ";
	    gotoxy(x,y+2); cout<<"|__ ";
	    gotoxy(x,y+3); cout<<"|  |";
	    gotoxy(x,y+4); cout<<"|__|";
	    break;

case '7':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"   |";
	    gotoxy(x,y+2); cout<<"   |";
	    gotoxy(x,y+3); cout<<"   |";
	    gotoxy(x,y+4); cout<<"   |";
	    break;

case '8':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"|  |";
	    gotoxy(x,y+2); cout<<"|__|";
	    gotoxy(x,y+3); cout<<"|  |";
	    gotoxy(x,y+4); cout<<"|__|";
	    break;

case '9':gotoxy(x,y);   cout<<" __ ";
	    gotoxy(x,y+1); cout<<"|  |";
	    gotoxy(x,y+2); cout<<"|__|";
	    gotoxy(x,y+3); cout<<"   |";
	    gotoxy(x,y+4); cout<<" __|";
	    break;


	}//switch ends
}//for ends

}



void worldclock:: time_in_pc(){

time_t timer;

struct tm *tblock;
timer=time(NULL);
tblock =localtime(&timer);

cout<<"\nSeconds is "<<tblock->tm_sec;
cout<<"\nMinutes is "<<tblock->tm_min;
cout<<"\nHours is "<<tblock->tm_hour;
cout<<"\nDay is "<<tblock->tm_mday;
cout<<"\nMonth is "<<tblock->tm_mon;

}

worldclock::worldclock(){
int option;
initialize_struct();
int n;
restart:
system("cls");
for(int i=0;i<13;++i)
{
cout<<setw(2)<<(i+1)<<" "<<zonplace[i].zone<<" ";

 for(n=0;n<zonplace[i].num;++n)
 cout<<zonplace[i].places[n]<<" ";

cout<<'\n';
}
cout<<setw(2)<<(14)<<" Main Menu ";

cout<<"\n\tEnter your option: ";
cin>>option;
if(option==14)
	return;
else if(option<1||option>14)
	  goto restart;
      
option=option-1;
int hh,mm;  //current;

time_t timer;

struct tm *tblock;
timer=time(NULL);
tblock =localtime(&timer);

mm=tblock->tm_min;
hh=tblock->tm_hour;
hh-=3;

char time[6];//to make the integer time compatible with display_time()
int chh=0,cmm=0;  //to hold values of string zonplace[option].zone[]
int sign=1;
int spare1,spare2;
//obtaining string character and inserting into integer variable

if(zonplace[option].zone[0]=='-')
sign=-1;

spare1=int(zonplace[option].zone[1])-48;
spare2=int(zonplace[option].zone[2])-48;
chh=spare1*10+spare2;
spare1=int(zonplace[option].zone[4])-48;
spare2=int(zonplace[option].zone[5])-48;
cmm=spare1*10+spare2;

hh=hh+sign*chh;
mm=mm+sign*cmm;
if(hh>23)
hh-=24;
else if(hh<00)
hh+=24;

if(mm>59)
mm-=60;
else
if(mm<00)
mm+=60;
time[0]=48+(hh/10);
time[1]=48+(hh%10);
time[2]=':';
time[3]=48+(mm/10);
time[4]=48+(mm%10);
system("cls");
display_time(time);

int x;
//23,17  53,17
x=53%(zonplace[option].num);
x+=13;
gotoxy(x,19);
for(n=0;n<zonplace[option].num;++n)
cout<<zonplace[option].places[n]<<" ";

char a;
cout<<"\n\tPress any key to continue";
a=_getch();
goto restart;
}



class Horoscope
{
	char zsign[15];
	char Desc[400];



		public:
            Horoscope(){
             int option;
             
//system("cls");
             cout<<"WELCOME TO FORTUNE TELLER"<<endl<<endl;
	         cout<<"1.Predict my fortune today\n2.Go back to Main menu\n";
		     cin>>option;
             if(option==1) 
             {
				 Intializezodiac();
                 Inputzodiac();
             }
           // else if(option==2)
            //return;
//else if(option>2||option<1)
//goto restart;   
           }
  
                         
		void Intializezodiac();
		char* retzodiac()
		{
			return zsign;
		}
		char* retdesc()
		{
			return Desc;
		}

		char* zodiacIdentifier(int d, int m);
			void Inputzodiac();

};
char* Horoscope::zodiacIdentifier(int d, int m)
{
	int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	char zod[12][15]={"Aries","Taurus","Gem ini","Cancer","Leo","Virgo","Libra","Scorpio","Sagittarius","Capricon","Aquarius","Pisces"};

	if(m<=0||m>12||d<=0||d>month[m-1])
	{cout<<"INVALID DATE"<<endl;
	 return 0;
	}
	else
	{
		if((m==3&&d>=21)||(m==4&&d<=19))
		return zod[0];
		else if((m==2 && d>=20) || (m==5 && d<=20))
		return zod[1];
		else if((m==5 && d>=21) || (m==6&&d<=20))
		return zod[2];
		else if((m==6&&d>=21)||(m==7&&d<=22))
		return zod[3];
		else if((m==7&&d>=23)||(m==8&&d<=22))
		return zod[4];
		else if((m==8&&d>=23)||(m==9&&d<=22))
		return zod[5];
		else if((m==9&&d>=23)||(m==10&&d<=22))
		return zod[6];
		else if((m==10&&d>=23)||(m==11&&d<=21))
		return zod[7];
		else if((m==11&&d>=22)||(m==12&&d<=21))
		return zod[8];
		else if((m==12&&d>=22)||(m==1&&d<=19))
		return zod[9];
		else if((m==1&&d>=20)||(m==2&&d<=18))
		return zod[10];
		else if((m==2&&d>=19)||(m==3&&d<=20))
		return zod[11];
	}
}
void Horoscope::Intializezodiac()
{
Horoscope C;
	ofstream fout("Horoscope.dat", ios::binary|ios::out);
	strcpy(C.zsign, "Aries");
	strcpy(C.Desc,"Details tend to clump up espically if you dont take care of it");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Taurus");
	strcpy(C.Desc, "Good luck on the horizon if you think positive");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Gemini");
	strcpy(C.Desc, "Your destiniy is regarded by what you do today and when you believe yourself");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Cancer");
	strcpy(C.Desc, "Maybe you might have a tough time in helping others today.Becalm and respond properly");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Leo");
	strcpy(C.Desc, "Today you have a very good chance of winning something.Try your best maybe it might be with you when you are reading this");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Virgo");
	strcpy(C.Desc, "Maybe you will have a feeling that you are doing something good but you are not");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Libra");
	strcpy(C.Desc, "Danger could be on your side any moment today");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Scorpio");
	strcpy(C.Desc, "Chances of being happy is more abundant on your side");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Sagittarius");
	strcpy(C.Desc, "You may have a good luck waiting for you in the commingdats of your life");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Capricorn");
	strcpy(C.Desc, "Life is all about struggles.You are boumd with struggles and you can overcome them easily");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Aquarius");
strcpy (C.Desc,"life can be unfair at times but be brave and handle the situations bravely");
	fout.write((char*)&C, sizeof(C));
		strcpy(C.zsign, "Pisces");
	strcpy(C.Desc, "Maybe you have a good chance of meeting the people you love and they might all be around you");
	fout.write((char*)&C, sizeof(C));
	fout.close();

}
void Horoscope::Inputzodiac()
{   
	char ch;
	Horoscope H;
	int date, month;
	char zodiacs[15];
	cout<<"Enter your date wdaddof birth (dd/mm)";
	cin>>date>>month;
	cout<<date<<" "<<month;
	if(zodiacIdentifier(date, month)==0)
	{cout<<"Wrong date!";
	 return;
	}
	strcpy(zodiacs, zodiacIdentifier(date, month));
	ifstream fin;
	fin.open("Horoscope.dat", ios::in|ios::binary);
	while(!fin.eof())
	{fin.read((char*)&H, sizeof(H));
	 if(strcmp(zodiacs, H.retzodiac())==0)
	 {cout<<H.retzodiac();
	cout<<H.retdesc();
	 }
	}
	fin.close();

char a;
cout<<"\n\tPress any key to continue";
a=_getch();
}


class Note{
public:
	Note();
void display_word_count(int i);
void Note_Border();
void Delete_Note();
void Add_Note();
void View_note();
};




void Note::Note_Border()
{
 gotoxy(8,5);
 cout<<"------------------------------------------------------";
 gotoxy(8,17);
 cout<<"-----------------------------------------------------";
 for(int y=6;y<=17;++y){
 gotoxy(8,y);cout<<"|";   gotoxy(61,y);cout<<"|";
 }
                  
}

void Note::Delete_Note(){
	ifstream fin("Notes.txt");
	ofstream fout("Temporary.txt");
	char temp_str[351];
	int temp=0;
	int count;
	int flag=0;
	cout<<"Which note do you want to delete??";
	cin>>count;
	while(!fin.eof())
	{fin.getline(temp_str,351);
	temp++;
	if(temp!=count)
	fout<<temp_str<<'\n';	
	if(temp==count)
	flag=1;
	}
	fin.close();
	fout.close();
	if(flag==0)
		{cout<<"Note not found!"; return;}
	
	fin.close();
	fout.close();
	remove("Notes.txt");
	rename("Temporary.txt","Notes.txt");
	cout<<"Note deleted";
	char a;
	a=_getch();
}	

void Note:: display_word_count(int i){
gotoxy(45,15);
int n=350-i;
cout<<setw(3)<<n;
//returning cursor back to typing area
int defined_x=10;
int defined_y=6;
int x,y;
y=i/50;
x=i%50;
gotoxy(defined_x+x,defined_y+y);
}

void Note:: Add_Note(){
system("cls");
Note_Border();
gotoxy(17,3);  cout<<"ADD NOTE";
   char Note_String[351];
gotoxy(5,4);          cout<<"Press 'Enter' to save\exit note when you are done entering ";
int i=0;
do{
char ch;
display_word_count(i);
ch=_getche();
if(ch!=13)
Note_String[i++]=ch;     //NOT ++i !
else
break;
}while(i<350);

Note_String[i]='\0';
display_word_count(i);
_getch();
system("cls");
ofstream fout("Notes.txt",ios::app);
fout<<Note_String<<'\n';
}


void Note:: View_note(){
char str[351];
ifstream fin("Notes.txt");
fin.seekg(0);
int count=1;
system("cls");
Note_Border();
gotoxy(23,3);  cout<<"VIEW NOTES";
gotoxy(10,20);  cout<<"Press any key to view next note";
while(fin.getline(str,351))
{for(int i=0;str[i]!='\0';++i)
 {int defined_x=10;
 int defined_y=6;
 int x,y;
 y=i/50;
 x=i%50;
 gotoxy(23,4);   cout<<"NOTE"<<count;
 gotoxy(defined_x+x,defined_y+y);
 cout<<str[i];

}
++count; 
_getch();
}
return;

}


Note::Note(){
int option;
Again: system("cls");// replace with function thats includes clrscr() with border
       cout<<"1. Add Notes\n2. View Notes\n3.Delete note\n4.Main Menu\n";
       cout<<"Enter option:";
       cin>>option;
       if(option==1)
       Add_Note();
        else if(option==2)
              View_note();
       else if(option==3)
			Delete_Note();
	   else if(option==4)
		   return;
goto Again;  

}




void displaycontactsmenu(){
//picture of contacts book
gotoxy(25,5);
int x,y;
for(y=5;y<=18;y++)
for(x=25;x<=45;x++)
{ if(y!=6)
   {gotoxy(x,y);
    cout<<"-";
   }
}

gotoxy(25,5);  cout<<"|";
gotoxy(45,5);  cout<<"|";
for(y=6;y<=18;y++)
{gotoxy(25,y);  cout<<"|";
 gotoxy(45,y);  cout<<"|";
}

gotoxy(32,6); cout<<"CONTACTS";

gotoxy(45,20); cout<<"***";
gotoxy(45,21); cout<<"*****D";
gotoxy(45,22); cout<<"***";
}

void displaygamesmenu(){
gotoxy(7,5); cout<<"                              GAMES                             \n";
gotoxy(7,6); cout<<"                                                ,  ,       \n";
gotoxy(7,7); cout<<"                                               / \\/ \\      \n";
gotoxy(7,8); cout<<"                                              (/ //_ \\_    \n";
gotoxy(7,9); cout<<"     .-._                                      \\||  .  \\   \n";
gotoxy(7,10);cout<<"      \\  '-._                            _,:__.-\"/---\\_ \\  \n";
gotoxy(7,11);cout<<" ______/___  '.    .--------------------'~-'--.)__( , )\\ \\ \n";
gotoxy(7,12);cout<<"`'--.___  _\\  /    |             Here        ,'    \\)|\\ `\\|\n";
gotoxy(7,13);cout<<"     /_.-' _\\ \\ _:,_          Be Dragons           \" ||   (\n";
gotoxy(7,14);cout<<"   .'__ _.' \\'-/,`-~`                                |/    \n";
gotoxy(7,15);cout<<"       '. ___.> /=,|  Abandon hope all ye who enter  |     \n";
gotoxy(7,16);cout<<"        / .-'/_ )  '---------------------------------'     \n";
gotoxy(7,17);cout<<"       )'  ( /(/                                           \n";
gotoxy(7,18);cout<<"             \\\\ \"                                          \n";
gotoxy(7,19);cout<<"              '=='                                         \n";



gotoxy(25,20); cout<<"   ***";
gotoxy(25,21); cout<<"A*****";
gotoxy(25,22); cout<<"   ***";

gotoxy(45,20); cout<<"***";
gotoxy(45,21); cout<<"*****D";
gotoxy(45,22); cout<<"***";
}


void displayclockmenu(){
gotoxy(30,5); cout<<"       WORLD CLOCK     \n ";
gotoxy(30,6); cout<<"|---------------------|\n ";
gotoxy(30,7); cout<<"|         12          |\n ";
gotoxy(30,8); cout<<"|                     |\n ";
gotoxy(30,9); cout<<"|                     |\n ";
gotoxy(30,10);cout<<"|                     |\n ";
gotoxy(30,11);cout<<"|                     |\n ";
gotoxy(30,12);cout<<"|9<--------*         3|\n ";
gotoxy(30,13);cout<<"|          |          |\n ";
gotoxy(30,14);cout<<"|          |          |\n ";
gotoxy(30,15);cout<<"|          V          |\n ";
gotoxy(30,16);cout<<"|                     |\n ";
gotoxy(30,17);cout<<"|                     |\n ";
gotoxy(30,18);cout<<"|          6          |\n ";
gotoxy(30,19);cout<<"|---------------------|\n ";

gotoxy(25,20); cout<<"   ***";
gotoxy(25,21); cout<<"A*****";
gotoxy(25,22); cout<<"   ***";

gotoxy(45,20); cout<<"***";
gotoxy(45,21); cout<<"*****D";
gotoxy(45,22); cout<<"***";

}


void displaynotesmenu(){


gotoxy(20,6); cout<<"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|     ____        \n ";
gotoxy(20,7); cout<<"|        NOTES        |    /____\\       \n ";
gotoxy(20,8); cout<<"|                     |    |____|       \n ";
gotoxy(20,9); cout<<"|_____________________|    |    |       \n ";
gotoxy(20,10);cout<<"|                     |    |  N |       \n ";
gotoxy(20,11);cout<<"|_____________________|    |  A |       \n ";
gotoxy(20,12);cout<<"|                     |    |  T |       \n ";
gotoxy(20,13);cout<<"|_____________________|    |  A |       \n ";
gotoxy(20,14);cout<<"|                     |    |  R |       \n ";
gotoxy(20,15);cout<<"|_____________________|    |  A |       \n ";
gotoxy(20,16);cout<<"|                     |    |  J |       \n ";
gotoxy(20,17);cout<<"|_____________________|    |____|       \n ";
gotoxy(20,18);cout<<"|                     |     \\  /        \n ";
gotoxy(20,19);cout<<"|_____________________|      \\/         \n ";


gotoxy(25,20); cout<<"   ***";
gotoxy(25,21); cout<<"A*****";
gotoxy(25,22); cout<<"   ***";

gotoxy(45,20); cout<<"***";
gotoxy(45,21); cout<<"*****D";
gotoxy(45,22); cout<<"***";
}

void displayhoroscopemenu()
{
gotoxy(30,5); cout<<"       HOROSCOPE        \n ";
gotoxy(30,6); cout<<"                        \n ";
gotoxy(30,7); cout<<"                        \n ";
gotoxy(30,8); cout<<"   ________          /| \n ";
gotoxy(30,9); cout<<"     |  |           //| \n ";
gotoxy(30,10);cout<<"     |  |           /   \n ";
gotoxy(30,11);cout<<"   __|__|___      \\/    \n ";
gotoxy(30,12);cout<<"                  /\\    \n ";
gotoxy(30,13);cout<<"                 /      \n ";
gotoxy(30,14);cout<<"  _____                 \n ";
gotoxy(30,15);cout<<"      /    /\\   /\      \n ";
gotoxy(30,16);cout<<"     /       \\_/        \n ";
gotoxy(30,17);cout<<"    /__      / \\        \n ";
gotoxy(30,18);cout<<"   /\\  \\    /   \\       \n ";
gotoxy(30,19);cout<<"  /  \\_/    \\___/       \n ";



gotoxy(25,20); cout<<"   ***";
gotoxy(25,21); cout<<"A*****";
gotoxy(25,22); cout<<"   ***";

gotoxy(45,20); cout<<"***";
gotoxy(45,21); cout<<"*****D";
gotoxy(45,22); cout<<"***";
}

void displayexit(){

gotoxy(30,6); cout<<"                              \n ";
gotoxy(30,7); cout<<"                              \n ";
gotoxy(30,8); cout<<"                              \n ";
gotoxy(30,9); cout<<"  ____        _____  _____    \n ";
gotoxy(30,10);cout<<" |      \\  /    |      |      \n ";
gotoxy(30,11);cout<<" |___    \\/     |      |      \n ";
gotoxy(30,12);cout<<" |       /\\     |      |      \n ";
gotoxy(30,13);cout<<" |____  /  \\  __|__    |      \n ";
gotoxy(30,14);cout<<"                              \n ";
gotoxy(30,15);cout<<"                              \n ";


gotoxy(25,20); cout<<"   ***";
gotoxy(25,21); cout<<"A*****";
gotoxy(25,22); cout<<"   ***";

}

void displaycredits(){



gotoxy(20,6); cout<<"                                                       \n ";
gotoxy(20,7); cout<<"                                                       \n ";
gotoxy(20,8); cout<<"   __   ___    ____   ___    ______  ______  ______    \n ";
gotoxy(20,9); cout<<"  /    |   \\  |      |   \\      |       |    |         \n ";
gotoxy(20,10);cout<<" |     |___|  |      |  _ \\     |       |    |         \n ";
gotoxy(20,11);cout<<" |     |\\     |---   | |_| |    |       |    |-----    \n ";
gotoxy(20,12);cout<<" |     | \\    |      |    /     |       |         |    \n";
gotoxy(20,13);cout<<"  \\__  |  \\   |____  |___/   ___|___    |    _____|    \n ";
gotoxy(20,14);cout<<"                                                       \n ";

gotoxy(25,20); cout<<"   ***";
gotoxy(25,21); cout<<"A*****";
gotoxy(25,22); cout<<"   ***";

gotoxy(45,20); cout<<"***";
gotoxy(45,21); cout<<"*****D";
gotoxy(45,22); cout<<"***";


}



void main_menu(){
int option=1;
char ch;
displaycontactsmenu();
for(;;){
ch=_getch();
if((ch=='D'||ch=='d')&&option<7)
++option;
else if((ch=='A'||ch=='a')&&option>1)
--option;
else if(ch==13)
	   switch(option)
	   {
	   case 1:contact C; 
		      C.contactsMenu();
			 break;
	   //case 2:Games G;
		//	 break;
	    case 3:{
			  worldclock W;
			  break;}
	   case 4:{Note N;
		   break ;}
		case 5:{Horoscope H;}
			 break ;
	  //  case 6:credits();
		//	 break;*/
	    case 7:exit(0);
	   }


system("cls");
switch(option)
{
case 1:displaycontactsmenu();
	  break;
case 2:displaygamesmenu();
	  break;
case 3:displayclockmenu();
	  break;
case 4:displaynotesmenu();
	  break;
case 5:displayhoroscopemenu();
	  break;
case 6:displaycredits();
	  break;
case 7:displayexit();
}

}//for ends

}//main_menu() ends


void main() {
main_menu();

}












