#ifndef __GASPUMP__H__
#define __GASPUMP__H__ 

#include <string>
using namespace std;

/* state machine */
enum  state
{ 
  NOCARD,
  CARDINSERT,
  CARDERROR,
  CARDVALID,
  NOPIN,
  PROCESSING,
  BANKAUTHORIZATION,
  WAITINPUT,
  PININSERT,
  PINVALID,
  PINERROR,
  DECLINE,
  AGREEMENT
};

/* transition of state machine */
enum action 
{
 NOACTION,
 ENTERCARD,
 ENTERPUMP,
 ENTERPIN,
 REMOVECARD
};

typedef struct automate 
{
   enum action ac;
   enum state  st;
   int  pin; /* pin code */
   int  number; /* number of credit card*/
	       /* the credit card is supplied by gas pump users*/
   bool pinvalid;
   bool cardvalid;
   bool bankauthorization;

}automate;


 void enterpin(automate* gp); 
 void entercard(automate* gp); 
 void checkpin(automate* gp);
 void bankauthorization(automate* gp);
 void initautomate(automate* gp);
 void menuGaspump();
 void submenu_B();

#endif /* __GASPUMP__H__ */
