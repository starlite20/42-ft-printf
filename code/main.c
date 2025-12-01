#include "ft_printf.h"

int main()
{
	
	int mfp, ofp;
	// unsigned int num = 123456789;
	// int nnum = -123456789;



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
	
/*
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
    ft_printf("[%%+10d] Expected: [      +123] | Actual:\t\t");
    ret = ft_printf("[%+10d]", 123);
    printf(" (Count: %d)\n\n", ret);


    nnum = 123;
	// Test 8: [%10d]-123[      -123]
    printf("\n\texpected \t\t=> ");
    ofp = printf("[% -+10d]\n", nnum);
    ft_printf("\n\tactual \t\t\t=> ");
    mfp = ft_printf("[% -+10d]\n", nnum);
    printf(" (Count +3: O %d   M %d)\n\n", ofp, mfp);


	// Test 8: [%10d]-123[      -123]
    // printf("\n[%%-10d] Expected:\t\t[%+-10d] \n", 123);
    // ret = ft_printf("\n\n =>\t\t\t\t[%+-10d] \n", 123);
    // printf(" (Count: %d)\n\n", ret);


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

	*/






    int nnum_pos = 123;
    int nnum_neg = -123;
    

    /*
    printf("\n--- D/I FLAG COMPLEX TESTS (Width 10, Number 123) ---\n\n");

    // --- TEST GROUP 1: RIGHT JUSTIFICATION ONLY (Default) ---

    // Test 1.1: [%10d]123 -> [       123] (7 spaces)
    printf("// Test 1.1: Right-Justification (Positive)\n");
    printf("\tExpected Output:\t[       %d]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[%10d]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%10d]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.2: [%10d]-123 -> [______-123] (6 spaces)
    printf("// Test 1.2: Right-Justification (Negative)\n");
    printf("\tExpected Output:\t[      %d]\n", nnum_neg);
    ofp = printf("\tOriginal printf:\t[%10d]\n", nnum_neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%10d]\n", nnum_neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --------------------------------------------------------------------------------

    // --- TEST GROUP 2: RIGHT JUSTIFICATION + SIGN/SPACE ---

    // Test 2.1: [%+10d]123 -> [______+123] (6 spaces, + sign prints after padding)
    printf("// Test 2.1: Right-Justification with '+' (Positive)\n");
    printf("\tExpected Output:\t[      +%d]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[%+10d]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%+10d]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 2.2: [% 10d]123 -> [______ 123] (6 spaces, ' ' prints after padding)
    printf("// Test 2.2: Right-Justification with ' ' (Positive)\n");
    printf("\tExpected Output:\t[       %d]\n", nnum_pos); // Note: printf uses a space for the sign
    ofp = printf("\tOriginal printf:\t[% 10d]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[% 10d]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 2.3: [% +10d]-123 -> [______-123] ('+' and ' ' ignored for negative, 6 spaces)
    printf("// Test 2.3: Right-Justification with '+' and ' ' (Negative)\n");
    printf("\tExpected Output:\t[      %d]\n", nnum_neg);
    ofp = printf("\tOriginal printf:\t[% +10d]\n", nnum_neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[% +10d]\n", nnum_neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --------------------------------------------------------------------------------

    // --- TEST GROUP 3: LEFT JUSTIFICATION + SIGN/SPACE ---

    // Test 3.1: [%-10d]123 -> [123_______] (7 spaces, no sign/space)
    printf("// Test 3.1: Left-Justification Only (Positive)\n");
    printf("\tExpected Output:\t[123       ]\n");
    ofp = printf("\tOriginal printf:\t[%-10d]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%-10d]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // Test 3.2: [%+-10d]123 -> [+123______] (6 spaces, '+' prints first)
    printf("// Test 3.2: Left-Justification with '+' (Positive) <- CRITICAL TEST\n");
    printf("\tExpected Output:\t[+%d      ]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[%+-10d]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%+-10d]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // Test 3.3: [% -10d]123 -> [ 123______] (6 spaces, ' ' prints first)
    printf("// Test 3.3: Left-Justification with ' ' (Positive)\n");
    printf("\tExpected Output:\t[ %d      ]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[% -10d]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[% -10d]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 3.4: [%+-10d]-123 -> [-123______] (6 spaces, '-' prints first)
    printf("// Test 3.4: Left-Justification with '+' (Negative)\n");
    printf("\tExpected Output:\t[%d      ]\n", nnum_neg);
    ofp = printf("\tOriginal printf:\t[%+-10d]\n", nnum_neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%+-10d]\n", nnum_neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    printf("----------------------------------------------------------\n");
    */



    /*
    //for i

    printf("\n--- D/I FLAG COMPLEX TESTS (Width 10, Number 123) ---\n\n");

    // --- TEST GROUP 1: RIGHT JUSTIFICATION ONLY (Default) ---

    // Test 1.1: [%10i]123 -> [       123] (7 spaces)
    printf("// Test 1.1: Right-Justification (Positive)\n");
    printf("\tExpected Output:\t[       %i]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[%10i]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%10i]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.2: [%10i]-123 -> [______-123] (6 spaces)
    printf("// Test 1.2: Right-Justification (Negative)\n");
    printf("\tExpected Output:\t[      %i]\n", nnum_neg);
    ofp = printf("\tOriginal printf:\t[%10i]\n", nnum_neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%10i]\n", nnum_neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --------------------------------------------------------------------------------

    // --- TEST GROUP 2: RIGHT JUSTIFICATION + SIGN/SPACE ---

    // Test 2.1: [%+10i]123 -> [______+123] (6 spaces, + sign prints after padding)
    printf("// Test 2.1: Right-Justification with '+' (Positive)\n");
    printf("\tExpected Output:\t[      +%i]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[%+10i]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%+10i]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 2.2: [% 10i]123 -> [______ 123] (6 spaces, ' ' prints after padding)
    printf("// Test 2.2: Right-Justification with ' ' (Positive)\n");
    printf("\tExpected Output:\t[       %i]\n", nnum_pos); // Note: printf uses a space for the sign
    ofp = printf("\tOriginal printf:\t[% 10i]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[% 10i]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 2.3: [% +10i]-123 -> [______-123] ('+' and ' ' ignored for negative, 6 spaces)
    printf("// Test 2.3: Right-Justification with '+' and ' ' (Negative)\n");
    printf("\tExpected Output:\t[      %i]\n", nnum_neg);
    ofp = printf("\tOriginal printf:\t[% +10i]\n", nnum_neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[% +10i]\n", nnum_neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --------------------------------------------------------------------------------

    // --- TEST GROUP 3: LEFT JUSTIFICATION + SIGN/SPACE ---

    // Test 3.1: [%-10i]123 -> [123_______] (7 spaces, no sign/space)
    printf("// Test 3.1: Left-Justification Only (Positive)\n");
    printf("\tExpected Output:\t[123       ]\n");
    ofp = printf("\tOriginal printf:\t[%-10i]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%-10i]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // Test 3.2: [%+-10i]123 -> [+123______] (6 spaces, '+' prints first)
    printf("// Test 3.2: Left-Justification with '+' (Positive) <- CRITICAL TEST\n");
    printf("\tExpected Output:\t[+%d      ]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[%+-10i]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%+-10i]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // Test 3.3: [% -10i]123 -> [ 123______] (6 spaces, ' ' prints first)
    printf("// Test 3.3: Left-Justification with ' ' (Positive)\n");
    printf("\tExpected Output:\t[ %d      ]\n", nnum_pos);
    ofp = printf("\tOriginal printf:\t[% -10i]\n", nnum_pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[% -10i]\n", nnum_pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 3.4: [%+-10i]-123 -> [-123______] (6 spaces, '-' prints first)
    printf("// Test 3.4: Left-Justification with '+' (Negative)\n");
    printf("\tExpected Output:\t[%d      ]\n", nnum_neg);
    ofp = printf("\tOriginal printf:\t[%+-10i]\n", nnum_neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%+-10i]\n", nnum_neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    printf("----------------------------------------------------------\n");
    */



    /*
    //unsigned
    unsigned int num_small = 12345U; // 5 characters
    unsigned int num_large = UINT_MAX; // 10 characters

    printf("\n--- UNSIGNED FLAG (%%u) TESTS (Width 10) ---\n\n");

    // --- TEST GROUP 1: NO PADDING/NO FLAGS ---

    // Test 1.1: [%u]12345
    printf("// Test 1.1: Basic Unsigned (Small)\n");
    printf("\tExpected Output:\t[%u]\n", num_small);
    ofp = printf("\tOriginal printf:\t[%%u] -> [%u]\n", num_small);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%u] -> [%u]\n", num_small);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.2: [%u]UINT_MAX
    printf("// Test 1.2: Basic Unsigned (Large)\n");
    printf("\tExpected Output:\t[%u]\n", num_large);
    ofp = printf("\tOriginal printf:\t[%%u] -> [%u]\n", num_large);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%u] -> [%u]\n", num_large);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);


    // --------------------------------------------------------------------------------

    // --- TEST GROUP 2: RIGHT JUSTIFICATION (Width Only) ---

    // Test 2.1: [%10u]12345 -> [     12345] (5 spaces)
    printf("// Test 2.1: Right-Justification (Width 10)\n");
    printf("\tExpected Output:\t[     %u]\n", num_small);
    ofp = printf("\tOriginal printf:\t[%%10u] -> [%10u]\n", num_small);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%10u] -> [%10u]\n", num_small);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 2.2: [%10u]UINT_MAX (Width is less than number length, so width is ignored)
    printf("// Test 2.2: Right-Justification (Width ignored)\n");
    printf("\tExpected Output:\t[%u]\n", num_large);
    ofp = printf("\tOriginal printf:\t[%%10u] -> [%10u]\n", num_large);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%10u] -> [%10u]\n", num_large);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --------------------------------------------------------------------------------

    // --- TEST GROUP 3: LEFT JUSTIFICATION (Width + Minus) ---

    // Test 3.1: [%-10u]12345 -> [12345     ] (5 spaces)
    printf("// Test 3.1: Left-Justification (Width 10 + '-')\n");
    printf("\tExpected Output:\t[%u     ]\n", num_small);
    ofp = printf("\tOriginal printf:\t[%%-10u] -> [%-10u]\n", num_small);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%-10u] -> [%-10u]\n", num_small);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --------------------------------------------------------------------------------

    // --- TEST GROUP 4: IGNORED FLAGS ---

    // Test 4.1: [%+10u]12345 -> [     12345] ('+' is ignored)
    printf("// Test 4.1: Ignored '+' flag (Behaves like [%%10u])\n");
    printf("\tExpected Output:\t[     %u]\n", num_small);
    ofp = printf("\tOriginal printf:\t[%%+10u] -> [%+10u]\n", num_small);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%+10u] -> [%+10u]\n", num_small);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 4.2: [% 10u]12345 -> [     12345] (' ' is ignored)
    printf("// Test 4.2: Ignored ' ' flag (Behaves like [%%10u])\n");
    printf("\tExpected Output:\t[     %u]\n", num_small);
    ofp = printf("\tOriginal printf:\t[%% 10u] -> [% 10u]\n", num_small);
    mfp = ft_printf("\tYour ft_printf:\t\t[%% 10u] -> [% 10u]\n", num_small);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 4.3: [%+-10u]12345 -> [12345     ] ('+' ignored, '-' takes effect)
    printf("// Test 4.3: Ignored '+' flag with Left-Justification (Behaves like [%%-10u])\n");
    printf("\tExpected Output:\t[%u     ]\n", num_small);
    ofp = printf("\tOriginal printf:\t[%%+-10u] -> [%+-10u]\n", num_small);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%+-10u] -> [%+-10u]\n", num_small);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    printf("----------------------------------------------------------\n");
    */


    // hex 
    /*
    printf("\tExpected Output for \t[%%#x]\n");
    ofp = printf("\tOriginal printf:\t[%#x]\n", 123);
    mfp = ft_printf("\tYour ft_printf:\t\t[%#x]\n", 123);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    */


    /*
    unsigned int hex_val = 255; // FF
    unsigned int zero_val = 0;
    unsigned int large_val = 65535; // FFFF
    // --- Basic Width Test (%x) ---
    printf("// Test 1.1: Basic Width (Right-align)\n");
    printf("\tExpected Output:\t[   %x]\n", hex_val); // 3 spaces + FF
    ofp = printf("\tOriginal printf:\t[%%6x] -> [%6x]\n", hex_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%6x] -> [%6x]\n", hex_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Left-Align Test (%X) ---
    printf("// Test 1.2: Left-Align ('-') with Width\n");
    printf("\tExpected Output:\t[%X  ]\n", large_val); // FFFF + 2 spaces
    ofp = printf("\tOriginal printf:\t[%%-6X] -> [%-6X]\n", large_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%-6X] -> [%-6X]\n", large_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Alternate Form Test ('#') for %x ---
    printf("// Test 2.1: Alternate Form ('#')\n");
    printf("\tExpected Output:\t[0x%x]\n", hex_val); // 0xff
    ofp = printf("\tOriginal printf:\t[%%#x] -> [%#x]\n", hex_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%#x] -> [%#x]\n", hex_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Alternate Form Test ('#') for %X ---
    printf("// Test 2.2: Alternate Form ('#') for uppercase\n");
    printf("\tExpected Output:\t[0X%X]\n", hex_val); // 0XFF
    ofp = printf("\tOriginal printf:\t[%%#X] -> [%#X]\n", hex_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%#X] -> [%#X]\n", hex_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Combined Flags: Width + Hash (%x) ---
    printf("// Test 3.1: Width and '#' combined (Right-align)\n");
    printf("\tExpected Output:\t[ 0x%x]\n", hex_val); // 1 space + 0xff
    ofp = printf("\tOriginal printf:\t[%%6#x] -> [%6#x]\n", hex_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%6#x] -> [%6#x]\n", hex_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Combined Flags: Left-Align + Width + Hash (%X) ---
    printf("// Test 3.2: Left-Align, Width, and '#' combined\n");
    printf("\tExpected Output:\t[0X%X ]\n", large_val); // 0XFFFF + 1 space
    ofp = printf("\tOriginal printf:\t[%%#-7X] -> [%#-7X]\n", large_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%#-7X] -> [%#-7X]\n", large_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Corner Case: Zero Value with '#' ---
    printf("// Test 4.1: Zero value with '#'\n");
    printf("\tExpected Output:\t[%x]\n", zero_val); // Standard printf does *not* print 0x for 0
    ofp = printf("\tOriginal printf:\t[%%#x] -> [%#x]\n", zero_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%#x] -> [%#x]\n", zero_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Check for '+' and ' ' being ignored for hex ---
    printf("// Test 5.1: Ignored '+' flag (Behaves like [%%10x])\n");
    printf("\tExpected Output:\t[       %x]\n", hex_val);
    ofp = printf("\tOriginal printf:\t[%%+10x] -> [%+10x]\n", hex_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%+10x] -> [%+10x]\n", hex_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    printf("// Test 5.2: Ignored ' ' flag (Behaves like [%%10x])\n");
    printf("\tExpected Output:\t[       %x]\n", hex_val);
    ofp = printf("\tOriginal printf:\t[%% 10x] -> [% 10x]\n", hex_val);
    mfp = ft_printf("\tYour ft_printf:\t\t[%% 10x] -> [% 10x]\n", hex_val);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    */

    /*
    int var = 42;
    void *ptr_non_null = &var;
    void *ptr_null = NULL;    // --- Test 1.1: Basic Non-NULL Pointer Address ---
    printf("// Test 1.1: Basic Non-NULL Pointer Address\n");
    // Expected output will be '0x' followed by address in lowercase hex
    ofp = printf("\tOriginal printf:\t[%%p] -> [%p]\n", ptr_non_null);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%p] -> [%p]\n", ptr_non_null);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Test 1.2: NULL Pointer (Crucial Edge Case) ---
    printf("// Test 1.2: NULL Pointer (Note: Output is implementation-defined: typically 0x0 or (nil))\n");
    // Run this test with regular printf first to know the exact string you must match!
    ofp = printf("\tOriginal printf:\t[%%p] -> [%p]\n", ptr_null);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%p] -> [%p]\n", ptr_null);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Test 2.1: Width Flag (Right-Align) ---
    printf("// Test 2.1: Width Flag (Right-align)\n");
    // The width should apply to the entire address string, including '0x'.
    ofp = printf("\tOriginal printf:\t[%%20p] -> [%20p]\n", ptr_non_null);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%20p] -> [%20p]\n", ptr_non_null);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Test 2.2: Left-Align ('-') with Width ---
    printf("// Test 2.2: Left-Align ('-') with Width\n");
    ofp = printf("\tOriginal printf:\t[%%-20p] -> [%-20p]\n", ptr_non_null);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%-20p] -> [%-20p]\n", ptr_non_null);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // --- Test 3.1: Ignored Flags ('#', '+', ' ') ---
    printf("// Test 3.1: Ignored Flags ('#', '+', ' ')\n");
    // For %%p, all flags except width and '-' should be ignored.
    ofp = printf("\tOriginal printf:\t[%%#+ 20p] -> [%#+ 20p]\n", ptr_non_null);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%#+ 20p] -> [%#+ 20p]\n", ptr_non_null);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    */

    // 0 
    // ofp = printf("\tOriginal printf:\t[% 010d]\n", 123);
    // mfp = ft_printf("\tYour ft_printf:\t\t[% 010d]\n", 123);
    // printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);



    int pos = 42;
    int neg = -42;
    int zero = 0;

    
    // Test 1.1: Basic Zero Padding (Positive)
    // Expected: Padded with '0's, right-aligned, '0's placed after the sign.
    ofp = printf("\tOriginal printf:\t[%%08d] -> [%08d]\n", pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%08d] -> [%08d]\n", pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.2: Basic Zero Padding (Negative)
    // Expected: Sign must come first, followed by '0's, then digits.
    ofp = printf("\tOriginal printf:\t[%%08d] -> [%08d]\n", neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%08d] -> [%08d]\n", neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.3: Basic Zero Padding (Zero Value)
    ofp = printf("\tOriginal printf:\t[%%05d] -> [%05d]\n", zero);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%05d] -> [%05d]\n", zero);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.1: Basic Zero Padding (Positive)
    // Expected: Padded with '0's, right-aligned, '0's placed after the sign.
    ofp = printf("\tOriginal printf:\t[%%08d] -> [%08d]\n", pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%08d] -> [%08d]\n", pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.2: Basic Zero Padding (Negative)
    // Expected: Sign must come first, followed by '0's, then digits.
    ofp = printf("\tOriginal printf:\t[%%08d] -> [%08d]\n", neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%08d] -> [%08d]\n", neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 1.3: Basic Zero Padding (Zero Value)
    ofp = printf("\tOriginal printf:\t[%%05d] -> [%05d]\n", zero);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%05d] -> [%05d]\n", zero);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);


    // Test 3.1: Conflict with Precision (Positive)
    // Precedence Rule: Precision ('.') must IGNORE the '0' flag. Width padding reverts to spaces.
    // Expected: Spaces for width padding, followed by precision-padded '0's.
    ofp = printf("\tOriginal printf:\t[%%08.5d] -> [%08.5d]\n", pos);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%08.5d] -> [%08.5d]\n", pos);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 3.2: Conflict with Precision (Negative)
    // Expected: Spaces for width padding, followed by sign, followed by precision-padded '0's.
    ofp = printf("\tOriginal printf:\t[%%08.5d] -> [%08.5d]\n", neg);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%08.5d] -> [%08.5d]\n", neg);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 3.3: Conflict with Precision (Zero Value)
    // Edge Case: If precision is 0 and value is 0, nothing is printed for the number.
    // The '0' flag is still ignored due to precision.
    ofp = printf("\tOriginal printf:\t[%%05.0d] -> [%05.0d]\n", zero);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%05.0d] -> [%05.0d]\n", zero);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    ofp = printf("\tOriginal printf:\t[%5d]\n", -1);
    mfp = ft_printf("\tYour ft_printf:\t\t[%5d]\n", -1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    
    
    /*
    ofp = printf("\tOriginal printf:\t[%%-5d] -> [%-5d]\n", 12);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%-5d] -> [%-5d]\n", 12);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Test 2: Width Consumption Failure with Plus and Left-Align ('-')
    // The first call to print_num_flags will prematurely consume the width, resulting in incorrect trailing space.
    ofp = printf("\tOriginal printf:\t[%%-+6d] -> [%-+6d]\n", 123);
    mfp = ft_printf("\tYour ft_printf:\t\t[%%-+6d] -> [%-+6d]\n", 123);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    */


    /*
printf("--- TEST 1: 0 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 0);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 0);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(2): -1
    printf("--- TEST 2: -1 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -1);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(3): 1
    printf("--- TEST 3: 1 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 1);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(4): 9
    printf("--- TEST 4: 9 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 9);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 9);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(5): 10
    printf("--- TEST 5: 10 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 10);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 10);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(6): 11
    printf("--- TEST 6: 11 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 11);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 11);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(7): 15
    printf("--- TEST 7: 15 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 15);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 15);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(8): 16
    printf("--- TEST 8: 16 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 16);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 16);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(9): 17
    printf("--- TEST 9: 17 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 17);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 17);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(10): 99
    printf("--- TEST 10: 99 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 99);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 99);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(11): 100
    printf("--- TEST 11: 100 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 100);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 100);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(12): 101
    printf("--- TEST 12: 101 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 101);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 101);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(13): -9
    printf("--- TEST 13: -9 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -9);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -9);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(14): -10
    printf("--- TEST 14: -10 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -10);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -10);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(15): -11
    printf("--- TEST 15: -11 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -11);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -11);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(16): -14
    printf("--- TEST 16: -14 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -14);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -14);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(17): -15
    printf("--- TEST 17: -15 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -15);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -15);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(18): -16
    printf("--- TEST 18: -16 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -16);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -16);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(19): -99
    printf("--- TEST 19: -99 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -99);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -99);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(20): -100
    printf("--- TEST 20: -100 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -100);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -100);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(21): -101
    printf("--- TEST 21: -101 ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", -101);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", -101);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(22): INT_MAX
    printf("--- TEST 22: INT_MAX ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", INT_MAX);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", INT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(23): INT_MIN
    printf("--- TEST 23: INT_MIN ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", INT_MIN);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", INT_MIN);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // Tests 24-27 check overflow/truncation behavior when passing large types (long, unsigned) to %d.
    
    // TEST(24): LONG_MAX (Casting to long helps ensure the compiler passes a long)
    printf("--- TEST 24: LONG_MAX (Overflow behavior) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", (long)LONG_MAX);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", (long)LONG_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(25): LONG_MIN
    printf("--- TEST 25: LONG_MIN (Overflow behavior) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", (long)LONG_MIN);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", (long)LONG_MIN);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(26): UINT_MAX
    printf("--- TEST 26: UINT_MAX (Overflow behavior) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", (unsigned int)UINT_MAX);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", (unsigned int)UINT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(27): ULONG_MAX
    printf("--- TEST 27: ULONG_MAX (Overflow behavior) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", (unsigned long)ULONG_MAX);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", (unsigned long)ULONG_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);		else
			printed += 1;
    
    // TEST(28): LONG_LONG_MAX constant (using LL suffix)
    printf("--- TEST 28: LONG_LONG constant (Overflow behavior) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%d ] -> [ %d ]\n", 9223372036854775807LL);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%d ] -> [ %d ]\n", 9223372036854775807LL);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    // TEST(29): Multiple Arguments
    printf("--- TEST 29: Multiple Arguments ---\n");
    ofp = printf("\tOriginal printf:\t[ ... ] -> [ %d %d %d %d %d %d %d ]\n", 
                 INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    mfp = ft_printf("\tYour ft_printf:\t\t[ ... ] -> [ %d %d %d %d %d %d %d ]\n", 
                    INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    */
}
