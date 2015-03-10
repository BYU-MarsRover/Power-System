/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    Timer_1_Start();
    

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {

        uint16 timer1 = Timer_1_ReadCapture();
       
        if (timer1 >= 1000 && timer1 <= 2000)
        {
            if (timer1 > 1500)
            {
                LED_Write(1);
                INPUT_SELECT_Write(1);
            }
            else
            {
                LED_Write(0);
                INPUT_SELECT_Write(0);
            }
        }
        else
        {
            INPUT_SELECT_Write(0);
            LED_Write(0);
        }
        

    }
}

/* [] END OF FILE */
