#include <stdlib.h> 
#include <unistd.h>


static size_t ft_wordcounter(char const *s){

	size_t counter = 0;
	while (*s) {
		while (ft_isspace((unsigned char)*s)) {
			s++;
		}
		if (*s) {
			counter++;	
		}
		while (*s && !ft_isspace((unsigned char)*s)) {
			s++;
		}
	}
	return counter;
}

static size_t ft_count_digits(int n) {
    size_t count = 0;
    if (n <= 0)
        count++;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

int ft_isalpha(int c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	} else if (c >= 'A' && c <= 'Z') {
		return 1;
	} else {
		return 0;
	}
}

int ft_isspace(int c) {
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

int ft_isdigit(char c) {
	return (c >= '0' && c <= '9');
}

int ft_isalnum(int c){
	if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1) {
		return 1;
	}else {
		return 0;
	}

}

int ft_isascci(int c){
	if(c >= 0 && c <= 127 ){
		return 1;
	}else {
		return 0;
	}
}

int ft_isprint(int c){
	if (c >=32 && c <=126) {
		return 1;
	}else {
		return 0;
	}
}

int ft_toupper(int c){
	if (ft_isalpha(c) == 1) {
		return c-32;
	}else {
		return 0;
	}
}

int ft_tolower(int c){
	if (ft_isalpha(c) == 1) {
		return c + 32;
	}else {
		return 0;
	}

}

int ft_strlen(const char *c){
	int counter = 0;
	while(*c != '\0'){
		counter++;
		c++;
	}
	return counter;

}

int ft_strchr(char *c, char foc){
	int counter = 0;
	while(*c != '\0'){
		if(*c == foc){
			return counter;
		}
		c++;
		counter++;
	}
	return 0;
}

int ft_strrchr(char *c, char foc){
	int counter = 0;
	int last = 0;
	while(*c != '\0'){
		if(*c == foc){
			last = counter;
		}
		c++;
		counter++;
	}
	return last;
}


int ft_strcmp(char *a, char *b){
	while(a != '\0' && b != '\0'){
		if (a != b){
			return 1;
		}else{
			return 0;
		}
		a++;
		b++;
	}
}

char *ft_strnstr(const char *c, const char *a, int len)
{
	int a_len;
	if (*a == '\0')
		return (char *)c;
	a_len = ft_strlen(a);
	while (*c != '\0' && len >= a_len)
	{
		if (*c == *a)
		{
			int i = 0;
			while (i < a_len && c[i] == a[i])
				i++;

			if (i == a_len)
				return (char *)c;
		}

		c++;
		len--;
	}

}

size_t ft_strcat(char *c,const char *a, size_t size ){
	size_t c_len = ft_strlen(c);
	size_t a_len = ft_strlen(a);
	size_t i = 0;

	if(a_len == size){
		return size + a_len;
	}

	while(a[i] != '\0' && c_len + i < size - 1){
		c[c_len+i] = a[i];
		i++;
	}

	c[c_len + i] = '\0';

	return c_len + a_len;

}

int ft_strlcpy(char *c,char *a, int len){
	int comp = ft_strlen(a);
	int counter = 0;
	if(  comp == 0){
		return comp;
	}
	while(counter < len-1){
		*c = *a;
		c++;
		a++;
		counter++;
	}
	*c = '\0';
	return comp;
}


char *ft_strdup(const char *s) {
	size_t len = ft_strlen(s);

	char *dup = (char *)malloc(len + 1);
	if (dup == NULL) {
		return NULL;
	}

	ft_strlcpy(dup, s, len + 1); 
	return dup;
}

void *ft_memset(void *s,int c,int len){
	int counter = 0;
	unsigned char *pointer = (unsigned char *)s;
	unsigned char val = (unsigned char *)c;
	while (counter < len) {
		pointer[counter] = val;
		counter++;
	}
	return s;
}

void *ft_bzero(void *s,size_t len){
	size_t counter = 0;
	unsigned char *pointer = (unsigned char *)s;
	while (counter < len) {
		pointer[counter] = 0;
		counter++;
	}
	return s;
}

void *ft_memcpy(void *s,const void *a,size_t len){
	unsigned char *s2 = (unsigned char *)s;
	const unsigned char *a2 = (unsigned char *)a;
	size_t counter = 0;
	while(counter < len){
		s2[counter] = a2[counter];
		counter++;
	}
	return s;
}

void *ft_memmove(void *d,const void *s,size_t len){
	unsigned char *d2 = (unsigned char *)d;
	const unsigned char *s2 = (unsigned char *)s;	
	if (d2 < s2) {
		size_t counter = 0;
		while (counter < len) {
			d2[counter] = s2[counter];
			counter++;
		}	
	}else if(d2 > s2){
		size_t counter = len;
		while(counter > 0){
			d2[counter-1] = s2[counter-1];
			counter--;
		}
	}
	return d;
}


void *ft_memchr(const void *s,int c,size_t len){

	unsigned const char *s2 = (unsigned char *)s;
	unsigned char c2 = (unsigned char *)c;
	int counter = 0;
	while (counter < len) {
		if (s2[counter] == c2) {
			return s2[counter];
		}
		counter++;
	}
	return NULL;

}

void *ft_memcmp(const void *s1, const void *s2, size_t len){

	unsigned const char *string1 = (unsigned char *)s1;
	unsigned const char *string2 = (unsigned char *)s2;

	int counter = 0;
	while (counter < len) {
		if(string1[counter] == string2[counter]){
			counter++;
		}else if (string1 < string2) {
			return  -1;
		}else{
			return 1;
		}
	}
	return 0;
}

int ft_atoi(const char *str){
	int sign = 1;
	int res = 0;
	while (ft_isspace(*str)) {
		str++;
	}
	if (*str == '+' || *str == '-') {
		if (*str == '-') {
			sign = -1;
		}
		str++;
	}
	while (ft_isdigit(*str)) {
		res = res * 10 + (*str - '0');
		str++;
	}
	return sign * res;
}

void *ft_calloc(size_t a, size_t s){

	void *ptr;
	ptr = malloc(a * s);
	if (ptr == NULL) {
		return NULL;
	}
	ft_bzero(ptr, a * s);
	return ptr;
}

char *ft_substr(char const *s, unsigned int start,size_t len){

	char *sub_str;
	size_t s_len;

	if (!s) {
		return NULL;	
	}

	s_len = ft_strlen(s);
	if (start > s_len) {
		return ft_strdup("");
	}
	if (len > s_len - start) {
		len = s_len - start;
	}

	sub_str = (char *)malloc(len - 1);
	if (!sub_str) {
		return NULL;
	}
	ft_memcpy(sub_str, s + start, len);
	sub_str[len] = '\0';
	return sub_str;
}



char *ft_strjoin(char const *s1, char const *s2){

	char *result;
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	if (!s1 || !s2) {

		return NULL;
	}

	ft_memcpy(result, s1, len1);

	ft_memcpy(result + len1, s2, len2);

	result[len1 + len2]='\0';

	return result;

}


char *ft_strtrim(char const *s1) {
    size_t start = 0;
    size_t end;
    char *trimmed;

    if (!s1) {
        return NULL;
    }

    end = ft_strlen(s1);

    while (s1[start] && ft_isspace((unsigned char)s1[start])) {
        start++;
    }
    while (end > start && ft_isspace((unsigned char)s1[end - 1])) {
        end--;
    }

    trimmed = (char *)malloc((end - start + 1) * sizeof(char));
    if (!trimmed) {
        return NULL;
    }

    if (end - start > 0) {
        ft_memcpy(trimmed, s1 + start, end - start);
    }
    
    trimmed[end - start] = '\0';
    
    return trimmed;
}

char **ft_split(char const *s){

	char **result;
	size_t word_c;
	size_t i = 0;
	size_t word_len = 0;

	if (!s) {
		return NULL;
	}	

	word_c = ft_wordcounter(s);
	result = (char **)malloc((word_c + 1) * sizeof(char *));
	if (!result) {
		return NULL;
	}
	while (*s) {
		while (*s == ft_isspace((unsigned char)*s)) {
			s++;
		}
		if (!*s) {
			break;	
		}
		while (s[word_len] && !ft_isspace((unsigned char)s[word_len])) {
			word_len++;
		}
		result[i] = (char *)malloc(word_len + 1);
		if (!result[i]) {
			while (i > 0) {
				free(result[--i]);
			}
			free(result);
			return NULL;
		}
		ft_memcpy(result[i], s, word_len);
		result[i][word_len]= '\0';
		i++;
		s += word_len;
	}

	result[i] = NULL;
	return result;

}

char *ft_itoa(int n){

	char *result;
	size_t len;
	unsigned int num;
	
	len = ft_count_digits(n);
	result = (char *)malloc(len + 1);

	if (!result) {
		return NULL;
	}
	result[len] = '\0';	
	if (n < 0) {
		result[0] = '-';
		num = -n;
	}else {
		num = n;
	}

	if (num == 0) {
		result[0] = '0'; 
	}

	while (num) {
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	return result;
}



char *ft_strmapi(char const *s, char (*f)(char)){

	char *result;
	size_t len;
	size_t i;

	if (!s || !f) {
		return NULL;
	}
	
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	
	if (!result) {
		return NULL;
	}
	
	i = 0;
	
	while (s[i]) {
		result[i] = f(s[i]);
		i++;
	}
	result[i] = '\0';

	return result;


}


void ft_striteri(char *s, void (*f)(unsigned int, char*)) {
    unsigned int i;

    if (!s || !f)
        return;

    i = 0;
    while (s[i]) {
        f(i, &s[i]);
        i++;
    }
}



void ft_putchar_fd(char c, int n){

	write(n, &c, 1);

}

void ft_putstr_fd(char *s, int n) {
    if (!s)
        return;
    write(n, s, ft_strlen(s));
}

void ft_putendl_fd(char *s, int n) {
    if (!s)
        return;
    write(n, s, ft_strlen(s));
    write(n, "\n", 1);
}

void ft_putnbr_fd(int n, int fd) {
    if (n == -2147483648) {
        write(fd, "-2147483648", 11);
        return;
    }

    if (n < 0) {
        write(fd, "-", 1);
        n = -n;
    }

    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);

    ft_putchar_fd((n % 10) + '0', fd);
}
