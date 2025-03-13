#include <stdio.h>
#include "libft.h"

int main(){
	//char *result = ft_memchr(c , 'o', 13);
	//printf("\n%s\n",ft_memcpy(a,c,10));
	//printf("%d\n",ft_atoi("    -123abc"));
	//printf("\n%ld\n", ft_strcat(c,a,sizeof(c)));
	//char *result = ft_strnstr("Hello world", "world", 13);
	//printf ("\n%d" ,ft_strlen(str));
	//printf ("\n%d\n" ,ft_strchr(str, 'o'));
	//printf ("\n%d\n" ,ft_strrchr(str, 'o'));
	//printf ("\n%d\n" ,ft_strcmp("Hello", "foda se"));
	//printf ("\n%s\n" ,result);
	//printf("%d\n",ft_strlcpy(str, "World", 10));
	//printf("A = %s\n",a);
	char const sentence[] = "Ola eu sou o alberto";
    	char **words = ft_split(sentence); // Get split words
    	size_t i = 0;

    	if (!words) {
        	printf("Memory allocation failed\n");
        	return 1;
    	}

  	  while (words[i]) { // Loop through the array of words
        printf("%s\n", words[i]);
        free(words[i]); // Free each allocated word
        i++;
    }
    free(words); // Free the array itself
}
