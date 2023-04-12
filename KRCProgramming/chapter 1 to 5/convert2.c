#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[], int m) {
    int i, sign;

    if ((sign = n) < 0) { // Store the sign of n and check if it's negative
        n = -n; // Make n positive
    }

    i = 0;
    do { // Generate digits in reverse order
        s[i++] = n % 10 + '0';
        if (i >= m - 1) { // Check if we have reached the maximum length
            break;
        }
    } while ((n /= 10) > 0);

    if (sign < 0 && i < m - 1) { // Add a negative sign if the original number was negative and there's room
        s[i++] = '-';
    }

    s[i] = '\0'; // Add the null terminator
    reverse(s); // Reverse the string to get the final result
}

int main() {
    char buffer[20];
    int num = -1234;

    itoa(num, buffer, 20);
    printf("%s\n", buffer);

    return 0;
}
