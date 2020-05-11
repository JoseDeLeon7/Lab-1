//Universidad del Valle de Guatemala
//11/05/2020
//Laboratorio 1
//José Pablo De León Salguero 17001

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"

// Sacado de la presentación de Pablo
#ifdef DEBUG
void
__error_(char *pcfilename, uint32_t ui32Line)
{
    while(1);

}
#endif


// Sacado del dattasheet
int main(void)
{

    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
    volatile uint32_t ui32Loop;

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    //verificar que esta habilitado
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
    //Habilitar el push
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x1;
    //habilitar puertos como salidas o entradas
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    while(1)
    {


      if (!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4)){

          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x00);

          for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++ )
               {
                }
  //Código para luz verde
                   GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xff);

                                                 for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++)
                                                 {
                                                 }

                  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

                                                 for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++ )
                                                 {
                                                 }

 //parpadeo de la luz
                     GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xff);

                                                      for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++)
                                                      {
                                                          }

                       GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

                                                      for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++ )
                                                            {
                                                               }
                  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xff);

                                   for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++)
                                      {
                                         }

                      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

                                      for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++ )
                                           {
                                            }
 //Código luz amarilla
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_3, 0xff);


                  for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++)
                       {
                         }

                      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_3, 0x0);

                           for(ui32Loop = 0; ui32Loop < 5000000; ui32Loop++ )
                                {
                                 }
 //Progra luz roja
          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);


            }


    }
}
