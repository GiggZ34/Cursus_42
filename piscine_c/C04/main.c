#include <assert.h>

int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);
int ft_atoi_base(char *str, char *base);

void test_ft_strlen(void)
{
	assert(ft_strlen("") == 0);
	assert(ft_strlen("Hello, world!") == 13);
	assert(ft_strlen("Hello,\0world!") == 6);
}

void test_ft_putstr(void)
{
	ft_putstr("Hello, world!\n");
}

void test_ft_putnbr(void)
{
	ft_putnbr(-2147483648);
	ft_putstr("\n");
	ft_putnbr(-42);
	ft_putstr("\n");
	ft_putnbr(0);
	ft_putstr("\n");
	ft_putnbr(42);
	ft_putstr("\n");
	ft_putnbr(2147483647);
	ft_putstr("\n");
}

void test_ft_atoi(void)
{
	assert(ft_atoi("  ---+--+1234ab567") == -1234);
	assert(ft_atoi("\t\v\n\f\r ---+--+1234ab567") == -1234);
	assert(ft_atoi("  ---+--+00000002147483648ab567") == -2147483648);
	assert(ft_atoi("  ---+-+00000002147483647ab567") == 2147483647);
	assert(ft_atoi("  ---+-+000000b567") == 0);
	assert(ft_atoi("  ---+-+b567") == 0);
}

void test_ft_putnbr_base(void)
{
	ft_putnbr_base(42, "01");
	ft_putstr("\n");
	ft_putnbr_base(42, "10");
	ft_putstr("\n");
	ft_putstr("Should not print: '");
	ft_putnbr_base(42, "1+0");
	ft_putstr("'\n");
	ft_putstr("Should not print: '");
	ft_putnbr_base(42, "1");
	ft_putstr("'\n");
	ft_putstr("Should not print: '");
	ft_putnbr_base(42, "");
	ft_putstr("'\n");
	ft_putstr("Should not print: '");
	ft_putnbr_base(42, "9123456789");
	ft_putstr("'\n");
	ft_putstr("Should not print: '");
	ft_putnbr_base(42, "9923456781");
	ft_putstr("'\n");
	ft_putnbr_base(-42, "0123456789");
	ft_putstr("\n");
	ft_putnbr_base(42, "0123456789");
	ft_putstr("\n");
	ft_putnbr_base(-2147483648, "0123456789");
	ft_putstr("\n");
	ft_putnbr_base(2147483647, "0123456789");
	ft_putstr("\n");
	ft_putnbr_base(0, "0123456789");
	ft_putstr("\n");
	ft_putnbr_base(-42, "0123456789abcdef");
	ft_putstr("\n");
	ft_putnbr_base(42, "0123456789abcdef");
	ft_putstr("\n");
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	ft_putstr("\n");
	ft_putnbr_base(2147483647, "0123456789abcdef");
	ft_putstr("\n");
	ft_putnbr_base(0, "0123456789abcdef");
	ft_putstr("\n");
	ft_putnbr_base(-42, "poneyvif");
	ft_putstr("\n");
	ft_putnbr_base(42, "poneyvif");
	ft_putstr("\n");
	ft_putnbr_base(-2147483648, "poneyvif");
	ft_putstr("\n");
	ft_putnbr_base(2147483647, "poneyvif");
	ft_putstr("\n");
	ft_putnbr_base(0, "poneyvif");
	ft_putstr("\n");
}

void test_ft_atoi_base(void)
{
	assert(42 == ft_atoi_base("101010", "01"));
	assert(42 == ft_atoi_base("010101", "10"));
	assert(0 == ft_atoi_base("10", "1+0"));
	assert(0 == ft_atoi_base("10", "1"));
	assert(0 == ft_atoi_base("10", ""));
	assert(0 == ft_atoi_base("10", "9123456789"));
	assert(0 == ft_atoi_base("10", "9923456781"));
	assert(0 == ft_atoi_base("--+--+-+42142", "\t\n\v\f\r0123456789"));
	assert(-42 == ft_atoi_base(" --+-42", "0123456789"));
	assert(42 == ft_atoi_base("\t\n\v\f\r0000042", "0123456789"));
	assert(-2147483648 == ft_atoi_base("-2147483648", "0123456789"));
	assert(2147483647 == ft_atoi_base("2147483647", "0123456789"));
	assert(0 == ft_atoi_base("-+0", "0123456789"));
	assert(-42 == ft_atoi_base("-2a", "0123456789abcdef"));
	assert(42 == ft_atoi_base("2a", "0123456789abcdef"));
	assert(-2147483648 == ft_atoi_base("-80000000", "0123456789abcdef"));
	assert(2147483647 == ft_atoi_base("7fffffff", "0123456789abcdef"));
	assert(0 == ft_atoi_base("0", "0123456789abcdef"));
	assert(-42 == ft_atoi_base("-vn", "poneyvif"));
	assert(42 == ft_atoi_base("vn", "poneyvif"));
	assert(-2147483648 == ft_atoi_base("-npppppppppp", "poneyvif"));
	assert(2147483647 == ft_atoi_base("offffffffff", "poneyvif"));
	assert(0 == ft_atoi_base("p", "poneyvif"));
}

int main(void)
{
	test_ft_strlen();
	test_ft_putstr();
	test_ft_putnbr();
	test_ft_atoi();
	test_ft_putnbr_base();
	test_ft_atoi_base();
	return (0);
}
