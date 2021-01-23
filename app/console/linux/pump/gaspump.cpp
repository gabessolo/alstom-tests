#ifndef __AUTOMATE__H__
#define __AUTOMATE__H__
#include "../common/gaspump.h"
#include "../common/bank.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

extern FILE* gfp[5]; /* regroupe les id de tous les fichiers ouverts */
extern struct bank gbq;	            /* configuration de la banque */		

extern int gpsId;  /* le compteur des pesonnes */
extern int gacId;  /* le compteur des comptes */
extern int gbcId;  /* le compteur du couple (personne,compte)*/

extern  char*  BANKNAME;    /* config of the bank */
extern  char*  BANKAC;      /* file contains account */
extern  char*  BANKAC2;      /* file contains account */
extern  char*  BANKPS;      /* file contains person */
extern  char*  BANKCUS;     /* file contains pair (person,account)*/

extern int  BANKID;  	/* id du fichier qui identifie la banque */
extern int  BANKACID;    	/* id du fichier qui identifie les comptes*/
extern int  BANKACID2;    	/* id du fichier qui identifie les comptes*/
extern int  BANKPSID;   	/* id du fichier qui identifie les personnes*/
extern int  BANKCUSID;   	/* id du fichier qui identifie la paire personne,compte*/

extern int  NBCUSTOMER; 	
extern int  MAXDATA;	
extern automate gaspump;

int  GASPUMPMINIMUMAMOUNT=15;
   
extern void razbank();
extern void showperson(struct person* ps);
extern void showaccount(struct account* ac);
extern void addperson(struct person* ps);
extern void delperson(struct person* ps);
extern void addaccount(struct account* ac);
extern void delaccount(struct account* ac);
extern void addbankacount(struct bankcustomer* bc,struct person* ps,struct account* ac);
extern void delbankaccount(struct bankcustomer* bc);
extern void savemoney(struct account* ac,double amount);
extern void withdrawmoney(struct account* ac,double amount);
extern int  init(int maxclient);
extern void submenu_A();
extern void closebank();
extern void submenu_L();
extern void submenu_S();
extern void menu();
extern void submenu_D();
extern void initbank(bool& checkinit,int max);

void initautomate(automate* gp)
{
   gp->ac=NOACTION;
   gp->st=NOCARD;
   gp->cardvalid=false;
   gp->pinvalid=false;
}

void entercard(automate* gp)
{
  cout << "enter card ? " ;
  char data[MAXDATA];
  cin >> data;
  if (*data=='e' || *data=='E')
  {
	//cout << data << endl;
	initautomate( gp);
   	return;
  }
  gp->number=atoi(data);
  gp->st=CARDINSERT;
  cout << " card :"<< gp->number << endl ;
}

void enterpin(automate* gp)
{
  char data[MAXDATA];
  if (gp->st==CARDERROR)
  {
	//cout << data << endl;
	initautomate( gp);
	return;
  }
  cout << "enter pin ? " ;
  cin >> data;
  if (*data=='e' || *data=='E')
  {
	//cout << data << endl;
	initautomate( gp);
	return;
  }
  gp->pin=atoi(data);
  gp->st=PININSERT;
  cout << " pin :"<< gp->pin << endl;
  
} 

void checkcard(automate* gp)
{
  ostringstream oss;
  oss<<BANKAC;
  
  gp->st=CARDERROR;
  gfp[BANKACID]	 =fopen(oss.str().c_str(),"r");
  if (gfp[BANKACID]!=NULL)
  {
	int nbclientread=0;
        gp->cardvalid=false;
        while(nbclientread < gbq.nbclients)
        {
        	struct account ac;
	   	fread(&ac.id,1,sizeof(int),gfp[BANKACID]);
   		fread(&ac.pin,1,sizeof(int),gfp[BANKACID]);
   		fread(&ac.number,1,sizeof(int),gfp[BANKACID]);
	   	fread(&ac.amount,1,sizeof(double),gfp[BANKACID]);
		if (ac.number==gp->number)
		{
			gp->cardvalid=true;
  			gp->st=CARDVALID;
	                break;
		}
		nbclientread++;

	}
	fclose(gfp[BANKACID]);
 }

}

void checkpin(automate* gp)
{
  ostringstream oss;
  oss<<BANKAC;
  
  char data[MAXDATA];
  if (gp->cardvalid==false)
  {
	//cout << data << endl;
	initautomate( gp);
	return;
  }

  gfp[BANKACID]	 =fopen(oss.str().c_str(),"r");
  if (gfp[BANKACID]!=NULL)
  {
	int nbclientread=0;
        gp->pinvalid=false;
  	gp->st=PINERROR;
        while(nbclientread < gbq.nbclients)
        {
        	struct account ac;
	   	fread(&ac.id,1,sizeof(int),gfp[BANKACID]);
   		fread(&ac.pin,1,sizeof(int),gfp[BANKACID]);
   		fread(&ac.number,1,sizeof(int),gfp[BANKACID]);
	   	fread(&ac.amount,1,sizeof(double),gfp[BANKACID]);

		if (ac.number==gp->number && ac.pin==gp->pin)
		{
			gp->pinvalid=true;
  			gp->st=PINVALID;
	                break;
		}
		nbclientread++;

	}
	fclose(gfp[BANKACID]);
  }
}

void bankauthorization(automate* gp)
{
  char data[MAXDATA];
  if (gp->cardvalid==false || gp->pinvalid==false)
  {
	//cout << data << endl;
	initautomate( gp);
	return;
 }

 if (gp->pinvalid==true && gp->cardvalid==true)
 {
  ostringstream oss;
  ostringstream oss2;
  oss<<BANKAC;
  oss2<<BANKAC2;
  
  gfp[BANKACID]	 =fopen(oss.str().c_str(),"r");
  if (gfp[BANKACID]!=NULL)
  {
	int nbclientread=0;
        gp->bankauthorization=false;
        while(nbclientread < gbq.nbclients)
        {
        	struct account ac;
	   	fread(&ac.id,1,sizeof(int),gfp[BANKACID]);
   		fread(&ac.pin,1,sizeof(int),gfp[BANKACID]);
   		fread(&ac.number,1,sizeof(int),gfp[BANKACID]);
	   	fread(&ac.amount,1,sizeof(double),gfp[BANKACID]);

		nbclientread++;
		if (ac.number==gp->number && ac.pin==gp->pin)
		{
			if (ac.amount >= GASPUMPMINIMUMAMOUNT)
			{
				gp->bankauthorization=true;
                        	double amount=ac.amount - GASPUMPMINIMUMAMOUNT;
				fclose(gfp[BANKACID]);
				gfp[BANKACID]=NULL;
  			
				gfp[BANKACID]=fopen(oss.str().c_str(),"r");
				gfp[BANKACID2]=fopen(oss2.str().c_str(),"w");
				
				if (gfp[BANKACID]!=NULL && gfp[BANKACID2]!=NULL)
  				{

					int nbclientread=0;
		        		while(nbclientread < gbq.nbclients)
        				{

						fread(&ac.id,1,sizeof(int),gfp[BANKACID]);
			   			fread(&ac.pin,1,sizeof(int),gfp[BANKACID]);
   						fread(&ac.number,1,sizeof(int),gfp[BANKACID]);
			   			fread(&ac.amount,1,sizeof(double),gfp[BANKACID]);
					
						nbclientread++;
						
						if (ac.number==gp->number && ac.pin==gp->pin)
						{
							ac.amount=amount;
							//showaccount(&ac);
						}
						fwrite(&ac.id,1,sizeof(int),gfp[BANKACID2]);
				   		fwrite(&ac.pin,1,sizeof(int),gfp[BANKACID2]);
				   		fwrite(&ac.number,1,sizeof(int),gfp[BANKACID2]);
					   	fwrite(&ac.amount,1,sizeof(double),gfp[BANKACID2]);
					
				     }
       				     fclose(gfp[BANKACID2]);
			    }
		     }
		     break;
	    }

       }
       fclose(gfp[BANKACID]);
    }
 }
 
 if (gp->bankauthorization==true)
 {
	gp->st=AGREEMENT;
  	string s="mv ";
	s+= BANKAC2;
	s+= "  " ;
	s+= BANKAC;
	//cout << s.c_str() << endl;
	system(s.c_str());
 }else
 {
	if (gp->pinvalid==true && gp->cardvalid==true)
        {
		gp->st=DECLINE;
        }
 }
}

void menuGaspump()
{
    char c;

    cout << "**********************************************************************************************************"<<endl;
    cout << "Bank utility help you to create a bank,customers,bank accounts,..."<<endl;
    cout << "**********************************************************************************************************"<<endl;
    cout << "design  by ABESSOLO G. Software Engineer +33641938762 +32474580008  gabessolo@yahoo.fr"<<endl;
    cout << "company Belgatech Bruxelles "<<endl;
    cout << "+++++++++ MENU +++++++"<<endl;
    cout << " 'B' : buy gas   "<<endl;	
    cout << " 'S' : list all bank accounts " << endl;	
    cout << " 'E' : exit  "<<endl;	
    cout << " 'CTRL-Z' : exit  "<<endl;	
    cout << "**********************************************************************************************************"<<endl;
   
   while(c!='Q')
   {
    c=getchar();
    switch(c)
    {
     case 'B': case 'b': submenu_B();break;
     case 'S': case 's': submenu_S();break;
     case 'E': case 'e': c='Q';break;
     case '\r': case '\n':break;
     default:cout << "Unknown command"<<endl;break;
    }
  }
  cout << "bye"<<endl;
  closebank();
}
void submenu_B()
{
	while(true)
	{
         entercard(&gaspump);
	 checkcard(&gaspump);
         enterpin(&gaspump);
	 checkpin(&gaspump);
         bankauthorization(&gaspump);
	 switch(gaspump.st)
	 {
         	case PROCESSING:cout	<<"procesing"<<endl;break; 
	        case CARDINSERT:cout	<<"card insert"<<endl;break; 
        	case PININSERT :cout	<<"pin insert"<<endl;break; 
	        case DECLINE   :cout 	<<"sorry the bank decline"<<endl;break; 
        	case AGREEMENT :cout 	<<"you can use the pump"<<endl;break; 
        	case PINERROR  :cout 	<<"error pin"<<endl;break; 
        	case CARDERROR :cout 	<<"error card"<<endl;break; 
	 }
       }
}

#endif /* __AUTOMATE__H__ */
