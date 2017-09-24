#include <xc.h>
#include "config.h"
#include "clear_LCD.h"
#include <stdbool.h>
#include "main.h"
#include "pulse_E.h"
#include <stdio.h>
#include "init_ports.h"
#include "init_eusart.h"
#include "lcdInit.h"
#include "lcdData.h"
#include "splash_screen.h"
#include "get_at_code.h"
#include "get_previous_AT_code.h"
#include "putch.h"

uchar main (void)
{   
    uchar num = 0;
    init_ports();
    init_eusart();
    lcdInit();
    splash_screen();
    __delay_ms(2000);
    clear_LCD();
    
    while(1)    
        {                   
            while(UP !=0);  // wait for button press
            while(UP !=1)
        {
            __delay_ms(100);
            
            while(*ptr2 != '\0' && *ptr2 != ',' && UP !=1)
            {
                clear_LCD();
                get_at_code();
                ptr2++;
                __delay_ms(500);
            }
        }
        
            
            
   /*             y = 0;
    while(ENTER !=0);
    while(ENTER !=1 & y<z);
    {
        while(copy_of_at_code[y] !='\0')
        {
            putch(copy_of_at_code[y]);
            y++;
        }
        putch(0x0a); //line feed
        putch(0x0d);    // carriage return
        for(num = 0; num < y; num++)
        {
            copy_of_at_code[num]= 0x00;
        }
    }
    y = 0;
    z = 0;*/
            
            
        while(DOWN !=0);
        while(DOWN !=1)
        {
            __delay_ms(100);
            
                while(*ptr2 != ',' && DOWN !=1)
                { 
                    clear_LCD();
                    get_previous_AT_code();
                    get_at_code();
                    ptr2++;
                    __delay_ms(500);
                }  
        }
                
         y = 0;
    while(ENTER !=0);
    while(ENTER !=1 & y<z);
    {
    
        putch(copy_of_at_code[y]);
        y++;
    
    }
    y = 0;
    z=0;
 }      
}
                               
        

