/*
    This program implements the PSOC 4 ADC, reads in a voltage from 0 to 3.3V, 
    and outputs the voltage over UART.
*/
#include <project.h>

void putdata(void* p, char c);

int main()
{
    UART_1_Start();
    init_printf(NULL, putdata);
    ADC_Start();
    ADC_StartConvert();
    
    for(;;)
    {
        
        uint16 adc = ADC_GetResult16(0);
        uint16 voltage = (adc>>3)*10; //Can we divie using the '/' operator?  ex. adc/19000 ?
        printf("%u\r\n",voltage);
        CyDelay(10);
        LED_Write(1);      
    }
}

void putdata (void* p, char c)
{
    UART_1_UartPutChar(c);
}


/* [] END OF FILE */
