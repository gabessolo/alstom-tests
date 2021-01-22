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
    while((opt = getopt(argc, argv, "r?p?E?e?")) != -1)  
    {  
        switch(opt)  
        {  
            case 'p':  
	        menuBank();	
		break;
            case 'r':  
	        razbank();	
                break;
	    case 'e':case 'E':break;
	    case '?':
        	if (opt == 'r' || opt=='p')
          		printf ("Option %c requires an argument.\n", opt);
	    default: usageBank();	
                break;  
        }  
    }  
    return 0; 
} 
