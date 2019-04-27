#include <stdio.h>
#include <stdlib.h>

int MAX_LEN= 255;
char  REPLACED_WORD = ' ';
char *WORD = "&32";


char * moveChars(char text[], int len,int start, int offset){
    int j = len;
    text[j+offset+1] = '\n';

    while(j>start){
        text[j+offset] = text[j];
        text[j] = ' ';
        j--;
    }
    

    return text;
    

}



void replaceSpace(char text[], int len){
    

    
    
    int i = 0;
    while(i<len){
        if(text[i] == REPLACED_WORD){
            text = moveChars(text, len,i, 2); 
            for(int j = i; j<i+3;j++){
                text[j] = WORD[j-i];
            }
            
            i+=3;
            continue;
        }
        
        i++;
    } 
}




int main(int argc, char * argv[]){
    char * text =(char*) malloc(MAX_LEN);
    int len;

    printf("TEXT INPUT>>");
    fgets(text, MAX_LEN, stdin);
    printf("SIZE INPUT>>");

    scanf("%d",&len);

    len--;

    replaceSpace(text,len);

    printf("%s",text);
    
    free(text);
}


