#include "ft_printf.h"

int main()
{
	
	int mfp, ofp;

    char ch_A = 'A';
    char ch_B = 'B';


	printf("\n*** %%c FORMAT SPECIFIER TESTS ***\n\n");

    // TC-01: Default (Right-Justify with Space Padding)
    printf("--- TEST 01: '%%5c', 'A' ---\n");
    // Expected output: |    A| (5 characters total)
    ofp = printf("\tOriginal printf:\t[ %%5c ] -> [ %5c ]\n", ch_A);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%5c ] -> [ %5c ]\n", ch_A);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TC-02: Left-Justify Flag (-)
    printf("--- TEST 02: '%%-5c', 'A' ---\n");
    // Expected output: |A    | (5 characters total)
    ofp = printf("\tOriginal printf:\t[ %%-5c ] -> [ %-5c ]\n", ch_A);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%-5c ] -> [ %-5c ]\n", ch_A);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TC-03: Zero Padding Flag (0)
    printf("--- TEST 03: '%%05c', 'A' ---\n");
    // Expected output: |0000A| (5 characters total)
    ofp = printf("\tOriginal printf:\t[ %%05c ] -> [ %05c ]\n", ch_A);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%05c ] -> [ %05c ]\n", ch_A);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TC-04: No Width (No Padding)
    printf("--- TEST 04: '%%c', 'A' ---\n");
    // Expected output: |A| (1 character total)
    ofp = printf("\tOriginal printf:\t[ %%c ] -> [ %c ]\n", ch_A);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%c ] -> [ %c ]\n", ch_A);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TC-05: Flag (-) without width (Ignored)
    printf("--- TEST 05: '%%-c', 'B' ---\n");
    // Expected output: |B| (1 character total)
    ofp = printf("\tOriginal printf:\t[ %%-c ] -> [ %-c ]\n", ch_B);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%-c ] -> [ %-c ]\n", ch_B);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TC-06: Flag (0) without width (Ignored)
    printf("--- TEST 06: '%%0c', 'B' ---\n");
    // Expected output: |B| (1 character total)
    ofp = printf("\tOriginal printf:\t[ %%0c ] -> [ %0c ]\n", ch_B);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%0c ] -> [ %0c ]\n", ch_B);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
}
