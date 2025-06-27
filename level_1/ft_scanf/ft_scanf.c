
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int x = fgetc(f);
	if(x == EOF)
		return -1;
	while (isspace(x))
		x = fgetc(f);
	ungetc(x, f);
    return (1);
}

int match_char(FILE *f, char c)
{
	int x = fgetc(f);
	if(x == EOF)
		return -1;
	if(x == c)
		return 1;
	ungetc(x, f);
	return (0);
}

int scan_char(FILE *f, va_list ap)
{
	int x = fgetc(f);
	char *y = va_arg(ap, char *);
	if(x == EOF)
		return -1;
	*y = x;
	ungetc(x, f);
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int x = fgetc(f);
	int *y = va_arg(ap, int *);
	int res = 0;
	int sign = 1;
	if(x == '-' || x == '+')
	{
		if(x == '-')
			sign = -1;
		int xx =fgetc(f);
		if(!isdigit(xx))
		{
			ungetc(xx, f);
			ungetc(x, f);
			return -1;
		}
		x = xx;
	}
	if(!isdigit(x))
	{
		ungetc(x, f);
		return -1;
	}
	while(isdigit(x))
	{
		res = res * 10 + (x - 48);
		x = fgetc(f);
	}
	*y = res * sign;
	ungetc(x, f);
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
	int x = fgetc(f);
	char *s = va_arg(ap, char *);
	int y = 0;
	while(!isspace(x) && x != EOF)
	{
		s[y++] = x;
		x = fgetc(f);
	}
	s[y] = '\0';
	ungetc(x, f);
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}

	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}


//int main(){
//	char x[10];
//
//	// scanf("%s", x);
//	ft_scanf("%s", x);
//	printf("%s", x);
//
//
//}
