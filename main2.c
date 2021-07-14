#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int c1 = 0;
    int c2 = 0;
    int i = -2147483648;
    int j = -1024;
    printf("WIDTH\n");
    printf("%%d\n");
    c1 = ft_printf("%d\n", i);
    c2 = printf("%d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%5d\n");
    c1 = ft_printf("%5d\n", i);
    c2 = printf("%5d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%20d\n");
    c1 = ft_printf("%20d\n", i);
    c2 = printf("%20d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%-5d.\n");
    c1 = ft_printf("%-5d.\n", i);
    c2 = printf("%-5d.\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%-20d.\n");
    c1 = ft_printf("%-20d.\n", i);
    c2 = printf("%-20d.\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%020d\n");
    c1 = ft_printf("%020d\n", i);
    c2 = printf("%020d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    
    printf("PRECISION");
    printf("%%d\n");
    c1 = ft_printf("%d\n", i);
    c2 = printf("%d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%.5d\n");
    c1 = ft_printf("%.5d\n", i);
    c2 = printf("%.5d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%.20d\n");
    c1 = ft_printf("%.20d\n", i);
    c2 = printf("%.20d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%.10d.\n");
    c1 = ft_printf("%.10d.\n", i);
    c2 = printf("%-.10d.\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%.-20d. ==> Ne compile pas, paas de precision négative\n");
    //c1 = ft_printf("%.-20d.\n", i);
    //c2 = printf("%.-20d.\n", i);
    //printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%0.20d\n");
    c1 = ft_printf("%0.20d\n", i);
    c2 = printf("%0.20d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
    printf("%%.020d\n");
    c1 = ft_printf("%.020d\n", i);
    c2 = printf("%.020d\n", i);
    printf("c1 = %d\nc2 = %d\n\n", c1, c2);
}
