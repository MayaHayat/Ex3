#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define NUMLINES 250




int getLine(char s[]){
    int count = 0;
    char temp='\0';
    while (count<LINE ){
        if (scanf("%c", &temp) == EOF){
            return 0;
        }
        else{
            s[count] = temp;
        }

        if(s[count] != '\n' && s[count] != '\r'){
            count++;
        }
    
        else{
            s[count] = '\0';
            count++;
            break;
    
        }
    }return count; 
}


int getWord(char w[]){
    int count = 0;
    while (count<WORD){
        scanf("%c", &(w[count]));
        if (w[count]!= '\n' && w[count]!= '\t' && w[count]!= ' '&& w[count]!= '\r'){
                    count++;
        }
        else{
            w[count] = '\0';
            count++;
            break;
        }
            
    }
    return count;
}



int substring(char* str1, char* str2){
    int j;
    for (int i = 0 ; i < strlen(str1)-strlen(str2)+1 ; i++){
        if (str1[i] == str2[0]){
            for (j = 0 ; j < strlen(str2) ; j++){
                if (str1[i+j]!= str2[j]){
                    break;
                }
            }
            if (j == strlen(str2)){
                return 1;
            }
        }
    }
    return 0;
}


int similar(char* s, char* t, int n){
    int count = 0;
    if (strlen(s)!= strlen(t)+n){
        return 0;
    }
    int j, i;
    for (i = 0, j=0 ; i < strlen(s) && j < strlen(t) ; i++){
        if (s[i] == t[j]){
            count ++;
            j++;
        }
    }
    if (count == strlen(t))
        return 1;

    return 0;  
}



void print_similar_words(char * str){
    
    char current[WORD] ={0};
    int count = 0;

    while (NUMLINES*LINE > count){
        getWord(current);
        count++;
        if (similar(current, str,0) ==1|| similar(current, str,1)==1)
            printf("%s\n", current);
    }
}




void printLine(char* str){
    char current[NUMLINES]= {0};
    int count = 0;

    while(NUMLINES > count ){
        count++;
        getLine(current);
        if (substring(current, str)){
            printf("%s\n", current);
        }
        if (current[0]== '\0')
            break;
    }
}


int main(){
    
    char word [WORD] ={0};
    char choice='\0';
    scanf("%s %c", word, &choice);
    char empty[LINE]={0};
    getLine(empty); 


    if (choice == 'a'){
        char temp[LINE]={0} ;
        getLine(temp);
        printLine(word);
    }

    if (choice == 'b'){ 
        char empty[LINE]={0};
        getLine(empty);  
        print_similar_words(word);
    }
    return 0;
}