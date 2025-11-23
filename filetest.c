#include<stdio.h>
#include<string.h>

int encrypt(char input[50], char password[6]){
    FILE *in , *out;
    char output[100];
         sprintf(output,"encrypted_%s",input);
            in = fopen(input,"rb");
            out = fopen(output,"wb");
        int curr;
            
            while((curr=getc(in))!=EOF){
                for(int i=0 ; i<4 ; i++ ){
                    curr=curr^password[i];
                }
                fputc(curr,out);
            }
    fclose(in);
    fclose(out);
    return 0;
}

int decrypt(char input[50], char password[6]){
    FILE *in , *out;
    char output[100];
         sprintf(output,"decrypted_%s",input);
            in = fopen(input,"rb");
            out = fopen(output,"wb");
        if(!in){
           printf("File not Found!!\n");
           return 0; 
        }
        int curr;
            
            while((curr=getc(in))!=EOF){
                for(int i=0 ; i<4 ; i++ ){
                    curr=curr^password[i];
                }
                fputc(curr,out);
            }
    fclose(in);
    fclose(out);
    return 0;
}



int main(){
    char input[100] , password[6];
    int choice;
    while(1){

    printf("choose what you want to do : \n 1. Encryption\n 2. Decryption\n 3.Exit\nEnter choice : ");
    scanf("%d",&choice);
    getchar();
    if(choice==3){
        break;
    }
    printf("Enter the name of your file : ");
    fgets(input, sizeof(input), stdin);    
    for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == '\n') {
        input[i] = '\0';
        break;
    }
    }
    printf("Enter 4 digit password : ");
    fgets(password, sizeof(password), stdin); 
    for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] == '\n') {
        password[i] = '\0';
        break;
    }
    }   
    
    if(choice==1){
        char output[100];
        printf("\n encrypting...\n");
      encrypt(input,password);
      sprintf(output,"encrypted_%s",input);
        printf("New encrypted file added by the name %s",output);
    }else{
        char output[100];
        printf("\n decrypting...\n");
      decrypt(input,password);
      sprintf(output,"decrypted_%s",input);
        printf("New decrypted file added by the name %s\n",output);
    }
    }

    return 0;
}