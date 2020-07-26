/* 
Update system 
Developed by: Walid Amriou
www.walidamriou.com

Last update: July 2020
*/

#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

// server certificates
extern const char server_cert_pem_start[] asm("_binary_certs_pem_start");
extern const char server_cert_pem_end[] asm("_binary_certs_pem_end");

// receive buffer
char rcv_buffer[200];

int check_updates();
void update();

#endif
