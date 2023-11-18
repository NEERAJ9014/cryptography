#include<stdio.h>
#include<string.h>
#include<ctype.h>
void monoalphabeticsubstitution(char*plaintext,char*key){
	int i;
	int len = strlen(plaintext);
	for(i=0;i<len;i++){
		if(isalpha(plaintext[i])){
			char currentchar = tolower(plaintext[i]);
			int index = currentchar - 'a';
			int ciphertext[i]=isupper(plaintext[i])?toupper(key[index]):(key[index]);
		}
		else{
			ciphertext[i]=plaintext[i];
		}
	}
	ciphertext[i]='\0';
}
int main(){
	char plaintext[100];
	char ciphertext[100];
	char key[]= "QWERTYUIOPASDFGHJKLZXCVBNM";
	printf("enter the plain text:");
	fgets(plaintext,sizeof(plaintext),stdin);
	plaintext[strln(plaintext,"\n")]='\0';
	int monoalphabeticsubstitition(plaintext,ciphertext,key);
	printf("ciphertext:%s\n",ciphertext);
	return 0;
}
