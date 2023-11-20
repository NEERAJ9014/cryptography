#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 5
void preparekey(char key[],char matrix[SIZE][SIZE]){
	int i,j,k=0;
	int ispresent[26]={0};
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(k<strlen(key)){
				if(!ispresent[key[k]-'A']){
					matrix[i][j]=key[k];
					ispresent[key[k]-'A']=1;
					k++;
				}else{
					j--;
				}
			}else{
				break;
			}
		}
	}
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(matrix[i][j]=='\n'){
				for(k=0;k<26;k++){
					if(!ispresent[k]){
						matrix[i][j]=k+'A';
						ispresent[k]=1;
						break;
					}
				}
			}
		}
	}
}
void findposition(char matrix[SIZE][SIZE],char ch,int *row,int *col){
	if(ch == 'j')
	ch='I';
	for(*row=0;*row<SIZE;(*row)++){
		for(*col=0;*col<SIZE;(*col)++){
			if(matrix[*row][*col]==ch){
				return;
			}
		}
	}
}
void encryptpair(char matrix[SIZE][SIZE],char ch1,char ch2, char encryptedpair[2]){
	int row1,col1,row2,col2;
	findposition(matrix,ch1,&row1,&col1);
	findposition(matrix,ch2,&row2,&col2);
	if(row1=row2){
		encryptedpair[0]=matrix[row1][(col1+1)%SIZE];
		encryptedpair[1]=matrix[row2][(col2+1)%SIZE];
		
	}else if(col1=col2){
		encryptedpair[0]=matrix[(row1+1)%SIZE][col1];
		encryptedpair[1]=matrix[(row2+1)%SIZE][col2];
	}else{
		encryptedpair[0]=matrix[row1][col2];
		encryptedpair[1]=matrix[row2][col1];
	}
}
void encryptplaypair(char matrix[SIZE][SIZE],char text[],char encryptedtext[]){
	int i,length=strlen(text);
	for(i=0;i<length;i+=2){
		char ch1=toupper(text[i]);
		char ch2=(i+1<length)?toupper(text[i+1]):'X';
		char encryptedpair(matrix,ch1,ch2);
		encryptedtext[i]=encrypetedpair[0];
		encryptedtext[i+1]=encryptedpair[1];
		encryptedtext[length]='\n';
	}
	int main(){
		char key[25];
		char matrix[SIZE][SIZE];
		char plaintext[100];
		char encryptedtext[100];
		printf("enter the key:");
		scanf("%s",key);
		preparekey(key,matrix);
		printf("enter the plaintext:");
		scanf("%s",plaintext);
		encryptplayfair(matrix,plaintext,encryptedtext);
		printf("encrypted text:%s\n",encryptedtext);
		return 0;
		
	}
}
