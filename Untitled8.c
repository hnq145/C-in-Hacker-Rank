// Sum of Digits of a Five Digit Number
/* 
Objective

The modulo operator, %, returns the remainder of a division. For example, 4 % 3 = 1 and 12 % 10 = 2. The ordinary division operator, /, returns a truncated integer value when performed on integers. For example, 5 / 3 = 1. To get the last digit of a number in base 10, use  as the modulo divisor.

Task

Given a five digit integer, print the sum of its digits.

Input Format

The input contains a single five digit number, .

Constraints


Output Format

Print the sum of the digits of the five digit number.

Sample Input 0

10564
Sample Output 0

16
*/
#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    // Calculate the sum of the digits
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Add the last digit to the sum
        n /= 10; // Remove the last digit
    }

    printf("%d\n", sum);

    return 0;
}
