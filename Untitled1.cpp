#include<stdio.h>
#include<string.h>
void caesarencrypt(char text[],int key){
	int length = strlen(text);
	for(int i=0;i<length;i++){
		if(text[i]>='A'&& text[i]<='Z'){
			text[i]=(text[i]-'a'+key)%26+'a';
		}
	}
}
int main(){
	char message[100];
	int key;
	printf("enter a message:");
	fgets(message,sizeof(message),stdin);
	printf("enter the key(0-25):");
	scanf("%d",&key);
	if (key<0||key>25){
		printf("invalid key! please enter the key between 0 and 25.\n");
		return 1;
		
	}
	size_t length = strlen(message);
	if (length>0&&message[length-1]=='\n'){
		
	}
	caesarencrypt(message,key);
	printf("encrypted message:%s\n",message);
	return 0;
}
