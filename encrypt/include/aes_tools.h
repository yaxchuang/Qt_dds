#ifndef AES_TOOLS_H
#define AES_TOOLS_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BYTE unsigned char

void printBytes(BYTE b[], const int len);

int AES_ExpandKey(BYTE key[], const int keyLen);
void AES_Encrypt(BYTE block[], BYTE key[], const int keyLen);
void AES_Decrypt(BYTE block[], BYTE key[], const int keyLen);

void AES_Init();
void AES_Done();

#endif // AES_H