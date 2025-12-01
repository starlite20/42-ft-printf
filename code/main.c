#include "ft_printf.h"

int main()
{
	
	int mfp, ofp;

    const char *str = "Hello";


   // TC-07: Default (Right-Justify) - Base Case
    printf("--- TEST 07: '%%10s', \"Hello\" ---\n");
    // Expected output: |     Hello| (10 chars total)
    ofp = printf("\tOriginal printf:\t[ %%10s ] -> [ %10s ]\n", str);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%10s ] -> [ %10s ]\n", str);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TC-08: Left-Justify Flag (-)
    printf("--- TEST 08: '%%-10s', \"Hello\" ---\n");
    // Expected output: |Hello     | (10 chars total)
    ofp = printf("\tOriginal printf:\t[ %%-10s ] -> [ %-10s ]\n", str);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%-10s ] -> [ %-10s ]\n", str);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TC-09: Space Flag ( ) - Ignored with no '-'
    printf("--- TEST 09: '%% 10s', \"Hello\" ---\n");
    // Expected output: |     Hello| (10 chars total - same as TC-07)
    ofp = printf("\tOriginal printf:\t[ %% 10s ] -> [ % 10s ]\n", str);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %% 10s ] -> [ % 10s ]\n", str);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TC-10: Space Flag ( ) with Left-Justify Flag (-)
    printf("--- TEST 10: '%% -10s', \"Hello\" ---\n");
    // Expected output: |Hello     | (10 chars total - same as TC-08)
    ofp = printf("\tOriginal printf:\t[ %% -10s ] -> [ % -10s ]\n", str);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %% -10s ] -> [ % -10s ]\n", str);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
}
