#include <stdio.h>
  #include <string.h>
  #define MAX 100

  /* try to find the given pattern in the search string */
  int bruteForce(char *search, char *pattern, int slen, int plen) {
        int i,j;
        for(i=0;i<slen-plen;i++)
        {
                j=0;
                while(j<plen && pattern[j]==search[i+j])
                {
                        j++;
                }
                if(j==plen)
                {
                        return i;
                }
        }
        return -1;
  }

  int main() {
        char searchStr[MAX], pattern[MAX];
        int res;
        printf("Enter Search String:");
        fgets(searchStr, MAX, stdin);
        printf("Enter Pattern String:");
        fgets(pattern, MAX, stdin);
        searchStr[strlen(searchStr) - 1] = '\0';
        pattern[strlen(pattern) - 1] = '\0';
        res = bruteForce(searchStr, pattern, strlen(searchStr), strlen(pattern));
        if (res == -1) {
                printf("Search pattern is not available\n");
        } else {
                printf("Search pattern available at the location %d\n", res);
        }
        return 0;
  }