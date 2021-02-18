/*************************************************************************
	> File Name: 20.有效的括号.c
	> Author: 
	> Mail: 
	> Created Time: Saturday, December 05, 2020 PM12:08:16 CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char ss[100];

bool isValid(char *s) {
    char (*str) = (char *)malloc(sizeof(char) * 100);
    int top = 0;
    for (int i = 0; s[i] != '\0' || s[i] != '\n'; i++) {
        switch (s[i]) {
            putchar(s[i]);
            case '{':
            case '[':
            case '(':
                str[top++] = s[i];
                break;
            case '}':
                    if (str[top] == '{') {
                        str[top--] = '\0';
                        break;
                    } else {
                        free(str);
                        return false;
                    }
                    break;
            case ']':
                    if (str[top] == '[') {
                        str[top--] = '\0';
                        break;
                    } else {
                        free(str);
                        return false;
                    }
                    break;
            case ')':
                    if (str[top] == '(') {
                        str[top--] = '\0';
                        break;
                    } else {
                        free(str);
                        return false;
                    }
                    break;
            default:
                    break;
        }
    }
}

int main(){
    scanf("%s", ss);
    printf("%s\n", ss);
    if (isValid(ss)) printf("OK"); 
    
    return 0;
}
