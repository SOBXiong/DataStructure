#include <stdio.h>
#include <stdlib.h>
int main(){
    char str1[100],str2[100],str3[200];
    scanf("%s %s",str1,str2);
    int i,j;
    for(i = 0;;i++){
        if(str1[i] != '\0'){
            str3[i] = str1[i];
        }else{
            break;
        }
    }
    for(j = 0;;j++){
        if(str2[j] != '\0'){
            str3[j + i] = str2[j];
        }else{
            str3[j + i] = '\0';
            break;
        }
    }
    printf("%s",str3);
    return 0;
}