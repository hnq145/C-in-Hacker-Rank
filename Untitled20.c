// Functions | Permutations of Strings
/* 
Strings are usually ordered in lexicographical order. That means they are ordered by comparing their leftmost different characters. For example,  because . Also  because . If one string is an exact prefix of the other it is lexicographically smaller, e.g., .

Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order. If two permutations look the same, only print one of them. See the 'note' below for an example.

Complete the function next_permutation which generates the permutations in the described order.

For example, . The six permutations in correct order are:

ab bc cd
ab cd bc
bc ab cd
bc cd ab
cd ab bc
cd bc ab
Note: There may be two or more of the same string as elements of .
For example, . Only one instance of a permutation where all elements match should be printed. In other words, if , then print either  or  but not both.

A three element array having three distinct elements has six permutations as shown above. In this case, there are three matching pairs of permutations where  and  are switched. We only print the three visibly unique permutations:

ab ab bc
ab bc ab
bc ab ab
Input Format

The first line of each test file contains a single integer , the length of the string array .

Each of the next  lines contains a string .

Constraints

 contains only lowercase English letters.
Output Format

Print each permutation as a list of space-separated strings on a single line.

Sample Input 0

2
ab
cd
Sample Output 0

ab cd
cd ab
Sample Input 1

3
a
bc
bc
Sample Output 1

a bc bc
bc a bc
bc bc a
Explanation 1

This is similar to the note above. Only three of the six permutations are printed to avoid redundancy in output.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s){
    // Find non-increasing suffix
    int i = n-1;
    while(i>0 && strcmp(s[i-1],s[i])>=0) 
        i--;    // find key
    if (i<=0) return 0;
    
    // Swap key with its successor in suffix
    int j = n-1;
    while(strcmp(s[i-1],s[j])>=0) 
        j--;    // find rightmost successor to key
    char *tmp = s[i-1];
    s[i-1] = s[j];
    s[j] = tmp;
    
    // Reverse the suffix
    j = n-1;
    while(i<j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
