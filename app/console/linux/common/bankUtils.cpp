#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <unistd.h>  
#include "bank.h"
#include <signal.h>

using namespace std;

char*  BANKNAME = "../nosql/bank.txt";    /* config of the bank */
char*  BANKAC   = "../nosql/bankac.txt";  /* file contains account */
char*  BANKAC2  = "../nosql/bankac2.txt";  /* file contains account */
char*  BANKPS   = "../nosql/bankps.txt";  /* file contains person */
char*  BANKCUS  = "../nosql/bankcus.txt"; /* file contains pair (person,account)*/

int  BANKID     =	0;	/* id du fichier qui identifie la banque */
int  BANKACID   =	1;	/* id du fichier qui identifie les comptes*/
int  BANKPSID   =	2;      /* id du fichier qui identifie les personnes*/
int  BANKCUSID  =	3;	/* id du fichier qui identifie la paire personne,compte*/
int  BANKACID2  =	4;	/* id du fichier qui identifie les comptes*/

int  NBCUSTOMER =	1000;
int  MAXDATA    =	64;

const int  NBFILES    =	5;

FILE* gfp[NBFILES]={NULL,NULL,NULL,NULL,NULL}; /* regroupe les id de tous les fichiers ouverts */

int gpsId=0;  /* le compteur des pesonnes */
int gacId=0;  /* le compteur des comptes */
int gbcId=0;  /* le compteur du couple (personne,compte)*/

struct bank gbq;	            /* configuration de la banque */		



 extern void submenu_B();

/* efface tous les fichiers de la banque */
void razbank()
{
  for (int i=0;i<NBFILES;i++)
  {
    if ( NULL!=gfp[i])
    {
         fclose(gfp[i]);
         gfp[i]=NULL;
    }
  }
  string s="rm ./";
  s+= BANKNAME;
  cout << s.c_str() << endl;
  system(s.c_str());
 
  s="rm ./";
  s+=BANKAC;
  cout << s.c_str() << endl;
  system(s.c_str());

  s="rm ./";
  s+=BANKAC2;
  cout << s.c_str() << endl;
  system(s.c_str());
  
  s="rm ./";
  s+= BANKPS;
  cout << s.c_str() << endl;
  system(s.c_str());

  s="rm ./";
  s+= BANKCUS;
  cout << s.c_str() << endl;
  system(s.c_str());
  
  gpsId=0;  /* le compteur des pesonnes */
  gacId=0;  /* le compteur des comptes */
  gbcId=0;  /* le compteur du couple (personne,compte)*/
  gbq.nbclients=0;
};

void showperson(struct person* ps)
{
  cout << "\n+++++++++ PERSON +++++++"<<endl;
  cout <<"firstname : " <<ps->firstname.c_str() << endl;
  cout <<"lastname  : " <<ps->lastname.c_str() << endl;
  cout <<"address : " <<ps->addr.c_str() << endl;
  cout <<"id : " <<ps->id << endl;
  cout << "++++++++++" << endl;
}

void addperson(struct person* ps)
{ 
   ps->id=gpsId++;
   if (gfp[BANKPSID]!=NULL && ps!=NULL)
   {
         fwrite(&ps->id,1,sizeof(int),gfp[BANKPSID]);
         fwrite(ps->firstname.c_str(),1,MAXDATA,gfp[BANKPSID]);
         fwrite(ps->lastname.c_str(),1,MAXDATA,gfp[BANKPSID]);
         fwrite(ps->addr.c_str(),1,MAXDATA,gfp[BANKPSID]);
   }
   showperson(ps);
};

void delperson(struct person* ps)
{
    cout << "not implemented yet"<<endl;;
};

void showaccount(struct account* ac)
{
  cout << "\n++++++++++ ACCOUNT ++++++++"<<endl;
  cout <<"number : " <<ac->number << endl;
  cout <<"amount : " <<ac->amount << endl;
  cout <<"pin : "    <<ac->pin << endl;
  cout <<"id     : " <<ac->id << endl;
  cout << "++++++++++" << endl;
}

void addaccount(struct account* ac)
{
   ac->id=gacId++;
   if (gfp[BANKACID]!=NULL && ac!=NULL)
   {
         fwrite(&ac->id,1,sizeof(int),gfp[BANKACID]);
         fwrite(&ac->pin,1,sizeof(int),gfp[BANKACID]);
         fwrite(&ac->number,1,sizeof(int),gfp[BANKACID]);
         fwrite(&ac->amount,1,sizeof(double),gfp[BANKACID]);
   }
   showaccount(ac);
};

void delaccount(struct account* ac)
{
    cout << "not implemented yet"<<endl;;
}
void addbankacount(struct bankcustomer* bc,struct person* ps,struct account* ac)
{
   if (gbq.nbclients < gbq.nbclientsmax) 
   {
   	if (gfp[BANKCUSID]!=NULL && bc!=NULL && ac!=NULL && ps!=NULL)
	{
		gbq.nbclients++; /* count up bank account*/
                cout << "new client added  "<<endl;  
		bc->id=gbcId++;	 /* set id to the bank account */
                bc->psId=ps->id; /* pair link with person */
                bc->acId=ac->id; /* pair link with account*/

		fwrite(&bc->id,1,sizeof (int),gfp[BANKCUSID]);
        	fwrite(&bc->psId,1,sizeof (int),gfp[BANKCUSID]);
        	fwrite(&bc->acId,1,sizeof (int),gfp[BANKCUSID]);
	}
   }else
   {
	cout << "sorry the bank is full"<<endl;
   }
};

void delbankaccount(struct bankcustomer* bc)
{
    cout << "not implemented yet"<<endl;;
}

void savemoney(struct account* ac,double amount)
{
	ac->amount+=amount;
};

void withdrawmoney(struct account* ac,double amount)
{
	ac->amount-=amount;
};

int  init(int maxclient)
{
       bool check=false;
       initbank(check,maxclient);
       if (check==false)
       {
   	cout << "KO initbank"<<endl;
   	return 1;
       }
       return 0;
}


void submenu_A()
{
   struct person  ps;
   struct account ac;
   struct bankcustomer bc;

   cout << "firstname ? ";
   cin >> ps.firstname;
   
   cout << "lastname ? ";
   cin >> ps.lastname;

   cout << "address ? ";
   cin >> ps.addr;

   cout << "pin [4 digits] ? ";
   cin >> ac.pin;

   cout << "initial amount ? ";
   cin >> ac.amount;

   ac.number=random()%NBCUSTOMER;

   /* make the pair (person,account) */ 
   bc.psId=ps.id;
   bc.acId=ac.id;
   
   addperson(&ps);
   addaccount(&ac);
   addbankacount(&bc,&ps,&ac);

}

void closebank()
{
  for (int i=0;i<4;i++)
  {
    if ( NULL!=gfp[i])
    {
	fclose(gfp[i]);
        gfp[i]=NULL;
    }
  }

 gfp[BANKID]	 =fopen(BANKNAME,"w");
 if (gfp[BANKID]!=NULL)
 {
    fwrite("BankGasPump",1,MAXDATA,gfp[BANKID]);
    fwrite("Place jean bosco 7500 Tournai",1,MAXDATA,gfp[BANKID]);
    fwrite(&gbq.nbclients,1,sizeof(int),gfp[BANKID]);
    fwrite(&gbq.nbclientsmax,1,sizeof(int),gfp[BANKID]);
    fclose(gfp[BANKID]);
    gfp[BANKID]=NULL;
 }

}

void submenu_L()
{
   struct person  ps;
   struct account ac;
   struct bankcustomer bc;

   closebank();

   gfp[BANKID]	 =fopen(BANKNAME,"r");
   gfp[BANKACID] =fopen(BANKAC,  "r");
   gfp[BANKPSID] =fopen(BANKPS,  "r");
   gfp[BANKCUSID]=fopen(BANKCUS, "r");

   if (gfp[BANKPSID]!=NULL)
   {
   	fread(gbq.name,1,MAXDATA,gfp[BANKID]);
   	fread(gbq.addr,1,MAXDATA,gfp[BANKID]);
   	fread(&gbq.nbclients,1,sizeof(int),gfp[BANKID]);
   	fread(&gbq.nbclientsmax,1,sizeof(int),gfp[BANKID]);
   }
   
   int nbpersonread=0;  
   if (gfp[BANKPSID]!=NULL)
   {
	 cout << "nb. clients :" << gbq.nbclients << endl;
         while(nbpersonread < gbq.nbclients)
         { 
		fread(&ps.id,1,sizeof(int),gfp[BANKPSID]);
         	char data[MAXDATA];
		fread(data,1,MAXDATA,gfp[BANKPSID]);
	        ps.firstname=data;
		fread(data,1,MAXDATA,gfp[BANKPSID]);
         	ps.lastname=data;
	 	fread(data,1,MAXDATA,gfp[BANKPSID]);
        	ps.addr=data;
   
	      	showperson(&ps);

		nbpersonread++;
        }
   } 

   closebank();
   
   gfp[BANKID]	 =fopen(BANKNAME,"r");
   gfp[BANKACID] =fopen(BANKAC,  "a+");
   gfp[BANKPSID] =fopen(BANKPS,  "a+");
   gfp[BANKCUSID]=fopen(BANKCUS, "a+");
}

void menuBank()
{
    char c;

    cout << "**********************************************************************************************************"<<endl;
    cout << "Bank utility help you to create a bank,customers,bank accounts,..."<<endl;
    cout << "**********************************************************************************************************"<<endl;
    cout << "design  by ABESSOLO G. Software Engineer +33641938762 +32474580008  gabessolo@yahoo.fr"<<endl;
    cout << "company Belgatech Bruxelles "<<endl;
    cout << "+++++++++ MENU +++++++"<<endl;
    cout << " 'A' : add a bank account   "<<endl;	
    cout << " 'D' : del a bank account " << endl;	
    cout << " 'L' : list all bank clients " << endl;	
    cout << " 'S' : list all bank accounts " << endl;	
    cout << " 'E' : exit  "<<endl;	
    cout << " 'CTRL-Z' : exit  "<<endl;	
    cout << "**********************************************************************************************************"<<endl;
   
   while(c!='Q')
   {
    c=getchar();
    switch(c)
    {
     case 'A': case 'a': submenu_A();break;
     case 'D': case 'd': submenu_D();break;
     case 'E': case 'e': c='Q';break;
     case 'L': case 'l': submenu_L();break;
     case 'S': case 's': submenu_S();break;
     case '\r': case '\n':break;
     default:cout << "Unknown command"<<endl;break;
    }
  }
  cout << "bye"<<endl;
  closebank();
}

void submenu_D()
{
    cout << "not implemented yet"<<endl;;
}


void usageBank()  
{ 
     cout << "bank [-m max] : create the bank database with limited max clients"<<endl;  
     cout << "bank [-r ] : erase  database "<<endl;  
     cout << "bank [-p ] : start menu "<<endl;  
     cout << "bank [-i ] : init bank "<<endl;  
}

void usageGaspump()  
{ 
     cout << "bank [-p ] : show menu "<<endl;  
}

/* creation de la banque */
void initbank(bool& checkinit,int max)
{ 
   gfp[BANKID]	 =fopen(BANKNAME,"r");
   gfp[BANKACID] =fopen(BANKAC,  "a+");
   gfp[BANKACID2] =fopen(BANKAC2,  "a+");
   gfp[BANKPSID] =fopen(BANKPS,  "a+");
   gfp[BANKCUSID]=fopen(BANKCUS, "a+");

   /* the bank exist read config */
   if (gfp[BANKID]!=NULL)
   {
   	fread(gbq.name,1,MAXDATA,gfp[BANKID]);
   	fread(gbq.addr,1,MAXDATA,gfp[BANKID]);
   	fread(&gbq.nbclients,1,sizeof(int),gfp[BANKID]);
   	fread(&gbq.nbclientsmax,1,sizeof(int),gfp[BANKID]);

        cout << "bank:" << gbq.name << endl; 
        cout << "address:" << gbq.addr << endl; 
        cout << "customers:" << gbq.nbclients << endl;
        cout << "max customers:" << gbq.nbclientsmax << endl;

	gpsId=gbq.nbclients;  /* le compteur des pesonnes */
	gacId=gbq.nbclients;  /* le compteur des comptes */
	gbcId=gbq.nbclients;  /* le compteur du couple (personne,compte)*/
   	if (gfp[BANKID]!=NULL)
   	{
	     fclose(gfp[BANKID]);
   	     gfp[BANKID]=NULL;
   	}
   }
   
  /* create/update the bank */
   
   gfp[BANKID]	 =fopen(BANKNAME,"w");
   if (gfp[BANKID]!=NULL)
   {
	gbq.nbclientsmax=max;
	gbq.nbclients;
	
	fwrite("BankGasPump",1,MAXDATA,gfp[BANKID]);
	fwrite("Place jean bosco 7500 Tournai",1,MAXDATA,gfp[BANKID]);
	fwrite(&gbq.nbclients,1,sizeof(int),gfp[BANKID]);
	fwrite(&gbq.nbclientsmax,1,sizeof(int),gfp[BANKID]);

        cout << "Bank created successfully ( max clients:" << gbq.nbclientsmax << ")"<< endl;
	fclose(gfp[BANKID]);
   	gfp[BANKID]=NULL;
   	
   }
   
   checkinit=true;
   for (int i=0;i<NBFILES;i++)
   {
    if ( NULL==gfp[i])
    {
         checkinit=false;
         break;
    }
  }
};

void submenu_S()
{
   struct person  ps;
   struct account ac;
   struct bankcustomer bc;

   closebank();

   gfp[BANKID]	 =fopen(BANKNAME,"r");
   gfp[BANKACID] =fopen(BANKAC,  "r");
   gfp[BANKPSID] =fopen(BANKPS,  "r");
   gfp[BANKCUSID]=fopen(BANKCUS, "r");

   if (gfp[BANKPSID]!=NULL)
   {
   	fread(gbq.name,1,MAXDATA,gfp[BANKID]);
   	fread(gbq.addr,1,MAXDATA,gfp[BANKID]);
   	fread(&gbq.nbclients,1,sizeof(int),gfp[BANKID]);
   	fread(&gbq.nbclientsmax,1,sizeof(int),gfp[BANKID]);
   }
   
   int nbpersonread=0;  
   if (gfp[BANKPSID]!=NULL)
   {
	 cout << "nb. clients :" << gbq.nbclients << endl;
         while(nbpersonread < gbq.nbclients)
         { 
         
	 fread(&ac.id,1,sizeof(int),gfp[BANKACID]);
         fread(&ac.pin,1,sizeof(int),gfp[BANKACID]);
         fread(&ac.number,1,sizeof(int),gfp[BANKACID]);
         fread(&ac.amount,1,sizeof(double),gfp[BANKACID]);
   
         showaccount(&ac);
  	 nbpersonread++;

        }
   } 

   closebank();
   
   gfp[BANKID]	 =fopen(BANKNAME,"r");
   gfp[BANKACID] =fopen(BANKAC,  "a+");
   gfp[BANKPSID] =fopen(BANKPS,  "a+");
   gfp[BANKCUSID]=fopen(BANKCUS, "a+");
}

void closeapp(int s)
{
	if (s==SIGINT) closebank();	
}

void adddefaultcustomers()
{
   struct person  PS[]=
   {
	{
	   .firstname="pierre",
	   .lastname="vaernewyck",
   	   .addr="Tournai"
   	},
	{
	   .firstname="gaetan",
	   .lastname="abessolo",
   	   .addr="paris"
   	}
   };

   struct account AC[]=
   {
	{
   	.number=random()%NBCUSTOMER,
 	.amount=1500.0,
   	.pin=1234
   	},
	{
   	.number=random()%NBCUSTOMER,
 	.amount=915.0,
   	.pin=1452
   	}
  };

   for(int i=0;i<sizeof(AC)/sizeof(AC[0]);i++)
   {
   struct bankcustomer bc;
   /* make the pair (person,account) */ 
   bc.psId=PS[i].id;
   bc.acId=AC[i].id;
   
   addperson(&PS[i]);
   addaccount(&AC[i]);
   addbankacount(&bc,&PS[i],&AC[i]);
   }
}
