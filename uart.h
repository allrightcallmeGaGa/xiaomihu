#ifndef _uart_h_
#define _uart_h_

void receive();
void Uart0_Init();		
void SendByte(char mydata);
void SendString(char *str);

#endif