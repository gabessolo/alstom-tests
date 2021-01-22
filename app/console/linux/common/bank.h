#ifndef __BANK__H__
#define __BANK__H__

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <unistd.h>  

using namespace std;

#define	_MAXDATA	16

struct bank
{
 char   name[_MAXDATA]; 
 char   addr[_MAXDATA]; 
 int    nbclientsmax;
 int    nbclients;
};

struct person
{
 string firstname;
 string lastname;
 string addr;
 int id;
};

struct account
{
 int number;
 double amount;
 int pin;
 int id;
};

/* cette structure fait la liaison entre la personne et son compte */
struct bankcustomer
{
  int  psId;
  int  acId;
  int id;
};

/* creation de la banque */
void initbank(bool& checkinit,int max);

/* efface tous les fichiers de la banque */
 void razbank();
 void showperson(struct person* ps);
 void addperson(struct person* ps);
 void delperson(struct person* ps);
 void addaccount(struct account* ac);
 void delaccount(struct account* ac);
 void addbankacount(struct bankcustomer* bc,struct person* ps,struct account* ac);
 void delbankaccount(struct bankcustomer* bc);
 void savemoney(struct account* ac,double amount);
 void withdrawmoney(struct account* ac,double amount);
 int  init(int maxclient);
 void submenu_A();
 void closebank();
 void submenu_L();
 void menuBank();
 void menuGaspump();
 void submenu_D();
 void usageBank();
 void usageGaspump();
 void  submenu_S();

#endif /* __BANK__H__*/
/**/
