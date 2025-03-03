int ft_isalpha(int c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int ft_isdigit(int c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
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
