/*
 * main.c
 *
 *  Created on: Sep 9, 2022
 *      Author: hp
 */
# include "STD_TYPES.h"
# include "DIO_interface.h"
# include "LCD_interface.h"
# include "LCD_config.h"
# include "KPD_interface.h"
# include <util/delay.h>

void CALCULATOR (void);

u32 Number1=0,Number2=0;
u8 c1=0,c2=0;

int main ()
{
	/*Division*/
	u32 store,rule1,rule2,out1,rule,out;
	u8 Arr_Store[6];
//*****************************************
	u32 Result;
	u8 choice,sel ;

	DIO_VidSetPortDirection(Port_D,0b11100000);
	DIO_VidSetPortDirection(Port_C,0b11111111);

	DIO_VidSetPortDirection(Port_A,0b00001111);
	DIO_VidSetPortValue(Port_A,0b11110000);

	LCD_VidInit();

	LCD_VidSendString(" WELCOME in our");
	LCD_VidGotoXY(1,1);
	LCD_VidSendString("* CALCULATOR *");
	_delay_ms(1000);
	LCD_VidDisplayClear();

	LCD_VidSendString("| Press any KEY|");
	LCD_VidGotoXY(1,0);
	LCD_VidSendString("|   to Start   |");

	while (1)
	{
		choice=KPD_u8GetPressedKey();

		if (choice!=101)
		{
			LCD_VidDisplayClear();

			LCD_VidSendString("Select ONE from");
		    LCD_VidGotoXY(1,0);
		    LCD_VidSendString("the following:");
		    _delay_ms(2000);

  	        LCD_VidDisplayClear();
	        LCD_VidCompleteInSecondLineInString("(+) (-) (*) (/) ---------------");

	        while (1)
	        {
	        	choice=KPD_u8GetPressedKey();

	        	if (choice!=101)
	        	{
	        		LCD_VidDisplayClear();
	        		LCD_VidSendString("Press E -> Enter");
	        		LCD_VidGotoXY(1,0),
	        		LCD_VidSendString("Choice : [");
	        		LCD_VidGotoXY(1,11);
	        		LCD_VidSendData(']');


	        		if (choice=='E')
	        		{
	        			LCD_VidDisplayClear();
	        			break;
	        		}
	        		sel=choice;

	        		LCD_VidGotoXY(1,10);
	        		LCD_VidSendData(choice);

	        	}


	        }//2.while

	        switch (sel)
	        {
	        	case 43:
	        		LCD_VidDisplayClear();

	        		LCD_VidCompleteInSecondLineInString(" * Addition *     ----------");
	        		_delay_ms(1000);
	        		LCD_VidDisplayClear();
            		LCD_VidSendString("      Note:-");
	        		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("{E->ETR**C->CLR}");
            		_delay_ms(2000);
            		LCD_VidDisplayClear();

            		CALCULATOR();
            		Result=Number1+Number2;
            		LCD_VidSendString("OPP1:");
            		LCD_VidSendNumber(Number1);

            		LCD_VidGotoXY(1,0);

            		LCD_VidSendString("OPP2:");
            		LCD_VidSendNumber(Number2);

            		_delay_ms(500);
            		LCD_VidDisplayClear();

            		//LCD_VidSendString("Add Result:");
            		//LCD_VidGotoXY(1,0);

            		LCD_VidSendNumber(Number1);
            		LCD_VidSendData('+');
            		LCD_VidSendNumber(Number2);
            		LCD_VidSendData('=');

            		LCD_VidSendNumber(Result);
            		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("Press KEY->Start");
            		break;

	        	case 45:
	        		LCD_VidDisplayClear();

	        		LCD_VidCompleteInSecondLineInString("* Subtraction * ---------------");
	        		_delay_ms(1000);
	        		LCD_VidDisplayClear();
            		LCD_VidSendString("      Note:-");
	        		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("{E->ETR**C->CLR}");
            		_delay_ms(2000);
            		LCD_VidDisplayClear();

            		CALCULATOR();

            		LCD_VidSendString("OPP1:");
            		LCD_VidSendNumber(Number1);

            		LCD_VidGotoXY(1,0);

            		LCD_VidSendString("OPP2:");
            		LCD_VidSendNumber(Number2);

            		_delay_ms(500);
            		LCD_VidDisplayClear();

            		//LCD_VidSendString("Subtract Result:");
            		//LCD_VidGotoXY(1,0);

            		LCD_VidSendNumber(Number1);
            		LCD_VidSendData('-');
            		LCD_VidSendNumber(Number2);
            		LCD_VidSendData('=');

            		if (Number1>=Number2)
            		{
            			Result=Number1-Number2;
            		}
            		else
            		{
            			LCD_VidSendData('-');
            			Result=Number2-Number1;
            		}
            		LCD_VidSendNumber(Result);
            		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("Press KEY->Start");

	        		break;

	        	case 42:
	        		LCD_VidDisplayClear();

	        		LCD_VidCompleteInSecondLineInString("Mulltiplication ---------------");
	        		_delay_ms(1000);
	        		LCD_VidDisplayClear();
            		LCD_VidSendString("      Note:-");
	        		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("{E->ETR**C->CLR}");
            		_delay_ms(2000);
            		LCD_VidDisplayClear();

            		CALCULATOR();

            		Result=Number1*Number2;

            		LCD_VidSendString("OPP1:");
            		LCD_VidSendNumber(Number1);

            		LCD_VidGotoXY(1,0);

            		LCD_VidSendString("OPP2:");
            		LCD_VidSendNumber(Number2);

            		_delay_ms(500);
            		LCD_VidDisplayClear();

            		//LCD_VidSendString("Multiply Result:");
            		//LCD_VidGotoXY(1,0);

            		LCD_VidSendNumber(Number1);
            		LCD_VidSendData('*');
            		LCD_VidSendNumber(Number2);
            		LCD_VidSendData('=');
            		LCD_VidSendNumber(Result);

            		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("Press KEY->Start");

	        		break;

	        	case 47:
	        		LCD_VidDisplayClear();

	        		LCD_VidCompleteInSecondLineInString("  * Division *   --------------");
	        		_delay_ms(1000);
	        		LCD_VidDisplayClear();
            		LCD_VidSendString("      Note:-");
	        		LCD_VidGotoXY(1,0);
            		LCD_VidSendString("{E->ETR**C->CLR}");
            		_delay_ms(2000);
            		LCD_VidDisplayClear();

            		CALCULATOR();

            		LCD_VidSendString("OPP1:");
            		LCD_VidSendNumber(Number1);

            		LCD_VidGotoXY(1,0);

            		LCD_VidSendString("OPP2:");
            		LCD_VidSendNumber(Number2);

            		_delay_ms(500);
            		LCD_VidDisplayClear();

            		//LCD_VidSendString("Division Result:");
            		//LCD_VidGotoXY(1,0);

            		LCD_VidSendNumber(Number1);
            		LCD_VidSendData('/');
            		LCD_VidSendNumber(Number2);
            		LCD_VidSendData('=');

            		if (Number1>Number2 && Number1%Number2==0)
            		{
                		Result=Number1/Number2;
                		LCD_VidSendNumber(Result);

                		LCD_VidGotoXY(1,0);
                		LCD_VidSendString("Press KEY->Start");
            		}

            		else if (Number1==Number2  && Number2!=0)
            		{
            			LCD_VidSendNumber(1);
            			LCD_VidGotoXY(1,0);
            			LCD_VidSendString("Press KEY->Start");
            		}

            		else if (Number1>Number2 && Number1%Number2!=0 && Number2!=0)
            		{

                		LCD_VidSendNumber(Number1/Number2);
                		LCD_VidSendData('.');

            			rule=(Number1/Number2)*Number2;
            			out=Number1-rule;

            			Number1=out;       /***********************/

            			Number1=Number1*10;
            			Arr_Store[0]=Number1/Number2;
            			rule1=Arr_Store[0]*Number2;
            			out1=Number1-rule1;
            			LCD_VidSendNumber(Arr_Store[0]);

            		    for (u8 i=1;i<=5;i++)
            			{
            				out1=(out1*10);
            				Arr_Store[i]=out1/Number2;
            				rule2=Arr_Store[i]*Number2;
            				out1=out1-rule2;
                			LCD_VidSendNumber(Arr_Store[i]);
            			}
                		LCD_VidGotoXY(1,0);
                		LCD_VidSendString("Press KEY->Start");



            		}
            		else if(Number1<Number2  && Number2!=0)
            		{
            			LCD_VidSendString("0.");

            			Number1=Number1*10;
            			Arr_Store[0]=Number1/Number2;
            			rule1=Arr_Store[0]*Number2;
            			out1=Number1-rule1;
            			LCD_VidSendNumber(Arr_Store[0]);

            		    for (u8 i=1;i<=5;i++)
            			{
            				out1=(out1*10);
            				Arr_Store[i]=out1/Number2;
            				rule2=Arr_Store[i]*Number2;
            				out1=out1-rule2;
                			LCD_VidSendNumber(Arr_Store[i]);
            			}
                		LCD_VidGotoXY(1,0);
                		LCD_VidSendString("Press KEY->Start");

            		}

            		else if (Number2==0)
            		{
            			LCD_VidSendString("Undefined");
                		LCD_VidGotoXY(1,0);
                		LCD_VidSendString("Press KEY->Start");

            		}

	        		break;

	        	default :
	        		LCD_VidSendString("     Invalid");
	        		LCD_VidGotoXY(1,4);
	        		LCD_VidSendString("Operation");
	        		_delay_ms(2000);
	        		LCD_VidDisplayClear();
            		LCD_VidSendString("Press KEY->Start");

	        		break;

	        }//switch

       }//if

		Number1=0;
		Number2=0;
		c1=0;
		c2=0;

    }//1.while

}//main



void CALCULATOR (void)
{
	u8 flag1=1,flag2=1,Opp1,Opp2;

	LCD_VidSendString("OPP1 :");
	LCD_VidGotoXY(0,6);
	while (1)
		{
		    Opp1=KPD_u8GetPressedKey();

		    if (Opp1!=101)
			{
				LCD_VidDisplayClear();
				LCD_VidSendString("OPP1 :");

				LCD_VidGotoXY(0,6);

				if (Opp1=='E')
				{
					LCD_VidDisplayClear();
					break;
				}
				else if (Opp1=='C')
				{
					Number1=Number1/10;
					flag1=0;
					c1--;
				}

				if (flag1==1)
				{
					Number1=(Number1*10)+Opp1-48;
					c1++;
				}
				LCD_VidSendNumber(Number1);
				flag1=1;

			}

		}
	_delay_ms(500);

	LCD_VidDisplayClear();
	LCD_VidSendString("OPP2 :");
	LCD_VidGotoXY(0,6);
	while (1)
		{
		    Opp2=KPD_u8GetPressedKey();

		    if (Opp2!=101)
			{
				LCD_VidDisplayClear();
				LCD_VidSendString("OPP2 :");

				LCD_VidGotoXY(0,6);

				if (Opp2=='E')
				{
					LCD_VidDisplayClear();
					break;
				}
				else if (Opp2=='C')
				{
					Number2=Number2/10;
					flag2=0;
					c2--;
				}

				if (flag2==1)
				{
					Number2=(Number2*10)+Opp2-48;
					c2++;
				}
				LCD_VidSendNumber(Number2);
				flag2=1;

			}

		}
	_delay_ms(500);

	LCD_VidDisplayClear();



}

