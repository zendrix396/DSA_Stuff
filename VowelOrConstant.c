#include <stdio.h>

const char* vowelOrConsonant(char a){
    if (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
        return "Vowel";
    } else{
        return "Consonant";
    }
}

int main(){
    char ch;
    scanf("%c",&ch);
    const char* res = vowelOrConsonant(ch);
    printf("%c is a %s", ch, res);
    return 0;
}