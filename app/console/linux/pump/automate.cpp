#ifndef __AUTOMATE__H__
#define __AUTOMATE__H__

#include <stdio.h>
#include "../common/bank.h"
#include "../common/gaspump.h"
#include <signal.h>
#include <stdlib.h>
 
const int _NBFILES=5;
extern FILE* gfp[_NBFILES]; /* regroupe les id de tous les fichiers ouverts */
extern struct bank gbq;	            /* configuration de la banque */		

extern int gpsId;  /* le compteur des pesonnes */
extern int gacId;  /* le compteur des comptes */
extern int gbcId;  /* le compteur du couple (personne,compte)*/

extern  char*  BANKNAME;    /* config of the bank */
extern  char*  BANKAC;      /* file contains account */
extern  char*  BANKPS;      /* file contains person */
extern  char*  BANKCUS;     /* file contains pair (person,account)*/

extern  int  BANKID;  	/* id du fichier qui identifie la banque */
extern  int  BANKACID;    	/* id du fichier qui identifie les comptes*/
extern  int  BANKPSID;   	/* id du fichier qui identifie les personnes*/
extern  int  BANKCUSID;   	/* id du fichier qui identifie la paire personne,compte*/

extern  int  NBCUSTOMER; 	

extern void enterpin(automate* gp); 
extern void entercard(automate* gp); 
extern void checkpin(automate* gp);
extern void bankauthorization(automate* gp);
extern void initautomate(automate* gp);

extern void initbank(bool& checkinit,int max);
extern  int  NBCUSTOMER; 	

automate gaspump;

void closeGas(int s);

int opt; 
int main(int argc, char** argv)
{
    char* value;
    
    bool checkinit=false;
    initbank(checkinit,NBCUSTOMER);
    signal(SIGINT,closeGas);     

    while((opt = getopt(argc, argv, "P?p?E?e?")) != -1)  
    {  
    	initautomate(&gaspump);
        switch(opt)  
        {  
            case 'P':  
            case 'p':  
	        menuGaspump();	
		break;
	    case '?':
        	if (opt=='p' || opt=='P')
          		printf ("Option %c requires an argument.\n", opt);
	    default: usageGaspump();	
                break;  
        }
   }
      return 0;
}

void closeGas(int s)
{
    	initautomate(&gaspump);
}
#endif
/* __AUTOMATE__H__*/
