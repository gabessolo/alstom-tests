#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <unistd.h>  
#include "../common/bank.h"
#include <signal.h>

using namespace std;

extern  int  NBCUSTOMER;
extern void  closeapp(int);

int main(int argc, char *argv[])  
{ 
    int opt; 
    char* value;
    
    signal(SIGINT,closeapp);     
    init(NBCUSTOMER); /* bank with NB CUSTOMER */	
    while((opt = getopt(argc, argv, "R?r?P?p?E?e?I?i?")) != -1)  
    {  
        switch(opt)  
        {  
            case 'p': case 'P': 
	        menuBank();	
		break;
            case 'r':  case 'R':
	        razbank();	
                break;
	    case 'e':case 'E':break;
	    case 'i':case 'I':razbank();init(NBCUSTOMER);adddefaultcustomers();closebank();break;
	    case '?':
        	if (opt == 'r' || opt=='p' || opt=='i' ||
			opt == 'R' || opt=='P' || opt=='I')
          		printf ("Option %c requires an argument.\n", opt);
	    default: usageBank();	
                break;  
        }  
    }  
    return 0; 
} 
