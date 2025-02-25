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

int ft_isalnum(int c){
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


