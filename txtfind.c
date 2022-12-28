// #include <stdio.h>
// #include <string.h>
// #define LINE 256
// #define WORD 30
// #define NUMLINES 250



// int getLine(char s[]){
//     int count = 0;
//     char temp='\0';
//     while (count<LINE ){

//         if (scanf("%c", &temp) == EOF){
//             return 0;
//         }
//         else{
//             s[count] = temp;
//         }

//         if(s[count] != '\n' && s[count] != '\r'){
//             count++;
//         }
    
//         else{
//             s[count] = '\0';
//             count++;
//             break;
    
//         }
//     }return count; 
// }


// int getWord(char w[]){
//     int count = 0;
//     while (count<WORD){
//         scanf("%c", &(w[count]));
//         if (w[count]!= '\n' && w[count]!= '\t' && w[count]!= ' '&& w[count]!= '\r'){
//                     count++;
//         }
//         else{
//             w[count] = '\0';
//             count++;
//             break;
//         }
            
//     }
//     return count;
// }



// int substring(char* str1, char* str2){
//     int j;
//     for (int i = 0 ; i < strlen(str1)-strlen(str2)+1 ; i++){
//         if (str1[i] == str2[0]){
//             for (j = 0 ; j < strlen(str2) ; j++){
//                 if (str1[i+j]!= str2[j]){
//                     break;
//                 }
//             }
//             if (j == strlen(str2)){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }


// int similar(char* s, char* t, int n){
//     int count = 0;
//     if (strlen(s)!= strlen(t)+n){
//         return 0;
//     }
//     int j, i;
//     for (i = 0, j=0 ; i < strlen(s) && j < strlen(t) ; i++){
//         if (s[i] == t[j]){
//             count ++;
//             j++;
//         }
//     }
//     if (count == strlen(t))
//         return 1;

//     return 0;  
// }



// void print_similar_words(char * str){

//     char current[WORD] ={0};
//     int count = 0;

//     while (NUMLINES*LINE > count){
//         getWord(current);
//         count++;
//         if (similar(current, str,0) ==1|| similar(current, str,1)==1)
//             printf("%s\n", current);
//     }
// }




// void printLine(char* str){
//     char current[NUMLINES]= {0};
//     int count = 0;
//     int tostop = 1;
//     while(NUMLINES > count && (tostop!= 0)){
//         count++;
//         tostop = getLine(current);
//         printf("%d\n", tostop);
//         if (substring(current, str)){
//             printf("%s\n", current);
//         }
//         if (current== '\0')
//             break;
//     }
// }


// int main(){
    
//     char word [WORD] ={0};
//     char choice='\0';
//     scanf("%s %c", word, &choice);
//     char empty[LINE]={0};
//     getLine(empty); 


//     if (choice == 'a'){
//         char temp[LINE]={0} ;
//         getLine(temp);
//         printLine(word);
//     }

//     if (choice == 'b'){ 
//         char empty[LINE]={0};
//         getLine(empty);  
//         print_similar_words(word);
//     }
//     return 0;
// }



#include<stdio.h>
#include<math.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define LINE_IN_TEXT 250




int get_line(char s[]){

    int count = 0;
    char c = '\0';
    for(int i =0; i<LINE; i++){

        if (scanf("%c", &(c)) == EOF)
            return 0;

        (s[i])=c;
        
        if(s[i] != '\n'){
            count++;
        }
        else{
            s[i] = '\0';
            break;
        }
    }
    
    return count; 
}


int get_word(char w[]){

    int count = 0;
    char c = '\0';
    for (int i = 0; i < WORD; i++) {

        scanf("%c", &(c));
        if(w[i] != '\r'){

             (w[i])=c;
            if((w[i]!='\n') && (w[i]!='\t') && (w[i]!=' ')) {
                count ++;
            }

            else{
                w[i] = '\0';
                count++;
                break;
            } 
        }
    }

    return count; 

}


int substring (char * str1, char * str2){

	int count = 0;

	for (int i = 0; i <=strlen(str1) - strlen(str2); i++){

    		for (int j = 0; j <= strlen(str2); j++){

       			if(*(str1 + i + j) == *(str2 + j)){
        			count++;       
      			} 
    		}
    		
        	if(count >= strlen(str2)){   
    			return 1;

		    }else{
			count = 0;
		    }
	}
	return 0;
    
}


int similar (char * s, char * t, int n){
    if(strlen(t)+n != strlen(s)){
        return 0;
    }
    int k = 0;
    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        if(*(s+i) == *(t+k)){
            k++;
        }else{
            count++;
        }
    }
    if(count == n){
        return 1;
    }
    return 0;
}



void print_lines(char * str){

    char temp[LINE] = { 0 };
    get_line(temp); //save the second line that empty
    
   
   char s[LINE_IN_TEXT] = { 0 };
   int i = 0;
   int c = 1;

   while(i < LINE_IN_TEXT && c != 0){
    i++;
    c = get_line(s);
    if(substring(s,str)==1) {
            printf("%s\n",s);
            
        }
    
   }


}


void print_similar_words(char * str){

    char temp[LINE] = { 0 };
    get_line(temp); //save the second line that empty

   int text_len = LINE * LINE_IN_TEXT;
   char w[WORD] = { 0 };
   int i = 0;
   while(i<text_len){
    i++;
    get_word(w);
    if(similar(w,str,1) == 1 || similar(w,str,0) == 1){

        printf("%s\n",w);
   
    } 
     
}

}

int main(){

    char word1[WORD] = { 0 };
    get_word(word1); //save first word
    char line1[LINE] = { 0 };
    get_line(line1); //save first line
    char ch = line1[strlen(line1)-1]; //func a or b

    if(ch == 'a'){
        print_lines(word1);
    }
    if(ch == 'b'){
        print_similar_words(word1);
    }
}