#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>


void algoindex(char* flow);

int main(int argc, char *argv[])  
{ 
    /*int opt; 
    char* value;
 
    while((opt = getopt(argc, argv, "i:")) != -1)  
    {  
        switch(opt)  
        {  
	    case 'i':case 'I':algoindex();break;
	    case '?':
        	if (opt == 'i' || opt=='I') 
          		printf ("Option %c requires an argument.\n", opt);
	    default: 	
                break;  
        }  
    } */
 
    algoindex("AALLALSTOMOOALSTMOOOALSTOMSTOMALSTOM");
    return 0; 
};

void algoindex(char* flow)
{	
	if (flow==NULL)  	return;
   	if (*flow=='\0') 	return;
        
	printf("index of 'ALSTOM' from '%s'\n",flow);
        char* scan=flow;

	int dimMAX=1 + sizeof(flow)/sizeof("ALSTOM")*sizeof(char);
        int* index=(int*)malloc(dimMAX*sizeof(int));
        int i=0,j=0;  
        do
	{
          if (*(scan+0)=='A')
	          if (*(scan+1)=='L')
        		  if (*(scan+2)=='S')
			          if (*(scan+3)=='T')
				          if (*(scan+4)=='O')
					          if (*(scan+5)=='M')
        					  {
							index[i++]=j;
						  }
	j++;
       }while(*scan++ != '\0');

       index[i]=0;
      
       for(int k=0;k<1+dimMAX;k++)
        printf("index[%d]=%d\n",k,index[k]);
         	
};
