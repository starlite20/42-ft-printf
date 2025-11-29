#include "ft_printf.h"

int main()
{
	
	int mfp, ofp;
	unsigned int num = 123456789;
	int nnum = -123456789;

	// printf("\n\n\n### MY VERSION\n");
	// mfp = ft_printf(" => [%d] [%d] [%%] [%d] [%c] [%s] \nu:[%u] \t p:[%p]\t p:[%p] \t x:[%x] \t X:[%X] ", 100,  5, -545132323, 'a', "hellow", UINT_MAX, &mfp, NULL, num, num);
	// printf("\ncount : %d\n\n", mfp);
	
	// printf("### ORIG VERSION\n");
	// ofp = printf(" => [%d] [%d] [%%] [%d] [%c] [%s] \nu:[%u] \t p:[%p]\t p:[%p] \t x:[%x] \t X:[%X] ", 100,  5, -545132323, 'a', "hellow", UINT_MAX, &mfp, NULL, num, num);
	// printf("\ncount : %d\n\n", ofp);


	

	// printf("\n\n### ORIG VERSION\n");
	// ofp = printf(" NULL %s NULL ", NULL);
	// printf("\ncount : %d\n\n", ofp);
	
	// printf("\n### MY VERSION\n");
	// mfp = ft_printf(" NULL %s NULL ", NULL);
	// printf("\ncount : %d\n\n", mfp);

	

	// printf("\n\n### ORIG VERSION\n");
	// ofp = printf(" [%+d]", num);
	// printf("\ncount : %d\n\n", ofp);
	
	// printf("\n### MY VERSION\n");
	// mfp = ft_printf(" [%+d]", num);
	// printf("\ncount : %d\n\n", mfp);
	
	// printf("\n\nORIG [%++i] [%+i] [%+i].\n\n", 123, -1524, 1900);
	// ft_printf("\n\nNEWW [%++i] [%+i] [%+i].\n\n", 123, -1524, 1900);
	
	// printf("\n [% +5c]", 'a');
	// printf("\n [%0+5d]", 'a');
	
	// printf("\n\n [%10d]\n\n", 512);
	// ft_printf("\n\n [%10d]\n\n", 512);
	


	char *null_str = NULL;
    int ret;
	
	ft_printf("[%%d] Expected: [100] | Actual: ");
    ret = ft_printf("[%d]", 100);
    printf(" (Count: %d)\n\n", ret);

    // Test 2: [%+d]100[+100] (Test the + flag)
    ft_printf("[%%+d] Expected: [+100] | Actual: ");
    ret = ft_printf("[%+d]", 100);
    printf(" (Count: %d)\n\n", ret);

    // Test 3: [% d]100[ 100] (Test the space flag)
    ft_printf("[%% d] Expected: [ 100] | Actual: ");
    ret = ft_printf("[% d]", 100);
    printf(" (Count: %d)\n\n", ret);

    // Test 4: [%+d]-100[-100] (Test + flag is ignored for negative)
    ft_printf("[%%+d] Expected: [-100] | Actual: ");
    ret = ft_printf("[%+d]", -100);
    printf(" (Count: %d)\n\n", ret);

    // Test 5: [% d]-100[-100] (Test space flag is ignored for negative)
    ft_printf("[%% d] Expected: [-100] | Actual: ");
    ret = ft_printf("[% d]", -100);
    printf(" (Count: %d)\n\n", ret);

    // Test 6: [% d]0[ 0]
    ft_printf("[%% d] Expected: [ 0] | Actual: ");
    ret = ft_printf("[% d]", 0);
    printf(" (Count: %d)\n\n", ret);

    // Test 7: [%10d]123[       123] (Test width padding with spaces)
    ft_printf("[%%10d] Expected: [       123] | Actual: ");
    ret = ft_printf("[%10d]", 123);
    printf(" (Count: %d)\n\n", ret);

    // Test 8: [%10d]-123[      -123]
    ft_printf("[%%10d] Expected: [      -123] | Actual: ");
    ret = ft_printf("[%10d]", -123);
    printf(" (Count: %d)\n\n", ret);



	// Test 8: [%10d]-123[      -123]
    printf("[%%-10d] Expected: [%+-10d] || actual : ", 123);
    ret = ft_printf(" => [%+-10d]", 123);
    printf(" (Count: %d)\n\n", ret);


	
    // Test 9: [%10s]"hi"[        hi] (Test width padding with spaces)
    ft_printf("[%%10s] Expected: [        hi] | Actual: ");
	printf("\n[%10s] \t", "hello123456789");
    ret = ft_printf("[%10s]", "hello123456789");
    printf(" (Count: %d)\n\n", ret);

    // Test 10: [%s]NULL[(null)] (Test null string handling)
    ft_printf("[%%s] NULL Expected: [(null)] | Actual: ");
    ret = ft_printf("[%s]", null_str);
    printf(" (Count: %d)\n\n", ret);

    // Test 11: [%p]&mfp[0x...address...] (Pointer test)
    ft_printf("[%%p] &mfp Expected: [0x...address...] | Actual: ");
    ret = ft_printf("[%p]", &mfp);
    printf(" (Count: %d) *Count varies based on address size/format\n\n", ret);

	
}
