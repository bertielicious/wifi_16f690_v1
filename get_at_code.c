#include <xc.h>
#include<stdbool.h>
#include "config.h"
#include "init_ports.h"
#include "init_eusart.h"
#include "lcdData.h"
#include "putch.h"
#include "get_previous_AT_code.h"
uchar get_at_code(void)
{
    uchar copy;
    //z = 0;
    lcdData(0x80, 0);   //position cursor at position 0 of first line
    while(*ptr2 !='\0' && *ptr2 != ',') //  do code block while no EOF or commas(commas removed from string)
    {
        lcdData(*ptr2,1);// display AT code on LCD until  comma or eof 
                // increment pointer to next character in the at_code string
        //copy_of_at_code[z] = *ptr2;
        copy = *ptr2;
        putch(copy);
        ptr2++;  
        //z++;
    } 
        putch(0x0a); //line feed
        putch(0x0d);    // carriage return
     
  /*  y = 0;
    while(ENTER !=0);
    while(ENTER !=1 & y<z);
    {
    
        putch(copy_of_at_code[y]);
        y++;
    
    }*/
   
   
}

   

