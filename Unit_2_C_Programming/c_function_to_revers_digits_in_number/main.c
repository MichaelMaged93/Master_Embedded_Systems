#include "stdio.h"
#include "string.h"
void reverse_digit(char arr[]);
int main() {
    char arr[20];
    printf("Enter the number you need to reverse: ");
    fflush(stdin); fflush(stdout);
    scanf("%s", arr);
    reverse_digit(arr);
    return 0;
}
void reverse_digit(char arr[]) {
    int length = strlen(arr);
    char rev_arr[20];
    for (int i = 0; i < length; i++) {
        rev_arr[i] = arr[length - i - 1];
    }
    rev_arr[length] = '\0';
    printf("-> output: %s\n", rev_arr);
}
