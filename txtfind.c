#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define NUMLINES 250

int getLine(char s[]){
    int count = 0;
    char c = getchar();
    while (c != '\n'){
        s[count] = c;
        c = getchar();
        count++;
    }
    s[count]='\0';
    return count;
}

int getWord(char w[]){
    int count = 0;
    char c = getchar();
    while ( c!= '\n' || c!= '\t' || c != ' ' || c!= EOF ){
        w[count] = c;
        count++;
        c = getchar();
    }
    w[count] = '\0';
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
    int count, j;
    if (strlen(s)!= strlen(t)+n){
        return 0;
    }
    for (int i = 0 ; i < strlen(s) - strlen(t)+1; i++){
        count = 0;
        if (s[i] == t[0]){
            for (j = 0 ; j < strlen(t) ; j++){
                if (s[i+j]!= t[j]){
                    count++;
                }
            }
             
        }
        if (count == n){
        return 1;
        }
    }
    
    return 0;
}

void print_similar_words(char * str){
    char current[WORD];
    while(getWord(current) != 0){
        if (similar(current, str, 1)==1 || similar(current,str,0)==1){
            printf("%s", current);
        }
    }
}


void print_line(char* str){
    char current[LINE];
    while(getLine(current) != 0){
        if (substring(current, str) ==1 ){
            printf("%s", current);
        }
    }
}

int main(){
    char word[WORD];
    char space,choice;
    scanf("%s %c%c", word, &space, &choice);

    if (choice == 'a'){
        print_line(word);
    }
    if (choice == 'b'){
        print_similar_words(word);
    }
    return 0;
}