#include <stdlib.h> 


int ft_isalpha(int c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	} else if (c >= 'A' && c <= 'Z') {
		return 1;
	} else {
		return 0;
	}
}

int ft_isspace(char c) {
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

