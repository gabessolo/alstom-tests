
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <unistd.h>  
#include "../common/bank.h"

using namespace std;

extern const char*  BANKNAME ;    /* config of the bank */
extern const char*  BANKAC   ;  /* file contains account */
extern const char*  BANKPS   ;  /* file contains person */
extern const char*  BANKCUS  ; /* file contains pair (person,account)*/

extern const int  BANKID     ;	/* id du fichier qui identifie la banque */
extern const int  BANKACID   ;	/* id du fichier qui identifie les comptes*/
extern const int  BANKPSID   ;      /* id du fichier qui identifie les personnes*/
extern const int  BANKCUSID  ;	/* id du fichier qui identifie la paire personne,compte*/

extern const int  NBCUSTOMER ;
extern const int  MAXDATA    ;
extern FILE* gfp[4]; /* regroupe les id de tous les fichiers ouverts */
extern struct bank gbq;	            /* configuration de la banque */		

extern int gpsId;  /* le compteur des pesonnes */
extern int gacId;  /* le compteur des comptes */
extern int gbcId;  /* le compteur du couple (personne,compte)*/

