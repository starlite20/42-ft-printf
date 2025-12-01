#include "ft_printf.h"

int main()
{
	
	int mfp, ofp;

    // ofp = printf("\tOriginal printf:\t-> [ %.5d ]\n", -123);
    // mfp = ft_printf("\tYour ft_printf:\t\t-> [ %.5d ]\n", -123);
    // printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    
    // TEST(10): 0, Precision 1
    printf("--- TEST 10: ' %%.1d ', 0 ---\n");
    ofp = printf(" %.1d ", 0);
    mfp = ft_printf(" %.1d ", 0);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(11): -1, Precision 2 (Padded: -01)
    printf("--- TEST 11: ' %%.2d ', -1 ---\n");
    ofp = printf(" %.2d ", -1);
    mfp = ft_printf(" %.2d ", -1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(12): 1, Precision 2 (Padded: 01)
    printf("--- TEST 12: ' %%.2d ', 1 ---\n");
    ofp = printf(" %.2d ", 1);
    mfp = ft_printf(" %.2d ", 1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(13): 9, Precision 1
    printf("--- TEST 13: ' %%.1d ', 9 ---\n");
    ofp = printf(" %.1d ", 9);
    mfp = ft_printf(" %.1d ", 9);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(14): 10, Precision 2
    printf("--- TEST 14: ' %%.2d ', 10 ---\n");
    ofp = printf(" %.2d ", 10);
    mfp = ft_printf(" %.2d ", 10);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(15): 11, Precision 3
    printf("--- TEST 15: ' %%.3d ', 11 ---\n");
    ofp = printf(" %.3d ", 11);
    mfp = ft_printf(" %.3d ", 11);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(16): 15, Precision 4
    printf("--- TEST 16: ' %%.4d ', 15 ---\n");
    ofp = printf(" %.4d ", 15);
    mfp = ft_printf(" %.4d ", 15);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(17): 16, Precision 5
    printf("--- TEST 17: ' %%.5d ', 16 ---\n");
    ofp = printf(" %.5d ", 16);
    mfp = ft_printf(" %.5d ", 16);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(18): 17, Precision 6
    printf("--- TEST 18: ' %%.6d ', 17 ---\n");
    ofp = printf(" %.6d ", 17);
    mfp = ft_printf(" %.6d ", 17);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(19): 99, Precision 1 (Value length > Precision, ignored)
    printf("--- TEST 19: ' %%.1d ', 99 ---\n");
    ofp = printf(" %.1d ", 99);
    mfp = ft_printf(" %.1d ", 99);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(20): 100, Precision 2 (Value length > Precision, ignored)
    printf("--- TEST 20: ' %%.2d ', 100 ---\n");
    ofp = printf(" %.2d ", 100);
    mfp = ft_printf(" %.2d ", 100);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(21): 101, Precision 3
    printf("--- TEST 21: ' %%.3d ', 101 ---\n");
    ofp = printf(" %.3d ", 101);
    mfp = ft_printf(" %.3d ", 101);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(22): -9, Precision 1 (Value length == Precision)
    printf("--- TEST 22: ' %%.1d ', -9 ---\n");
    ofp = printf(" %.1d ", -9);
    mfp = ft_printf(" %.1d ", -9);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(23): -10, Precision 2
    printf("--- TEST 23: ' %%.2d ', -10 ---\n");
    ofp = printf(" %.2d ", -10);
    mfp = ft_printf(" %.2d ", -10);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(24): -11, Precision 3 (Padded: -011)
    printf("--- TEST 24: ' %%.3d ', -11 ---\n");
    ofp = printf(" %.3d ", -11);
    mfp = ft_printf(" %.3d ", -11);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(25): -14, Precision 4
    printf("--- TEST 25: ' %%.4d ', -14 ---\n");
    ofp = printf(" %.4d ", -14);
    mfp = ft_printf(" %.4d ", -14);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(26): -15, Precision 1 (Value length > Precision, ignored)
    printf("--- TEST 26: ' %%.1d ', -15 ---\n");
    ofp = printf(" %.1d ", -15);
    mfp = ft_printf(" %.1d ", -15);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(27): -16, Precision 2 (Value length == Precision)
    printf("--- TEST 27: ' %%.2d ', -16 ---\n");
    ofp = printf(" %.2d ", -16);
    mfp = ft_printf(" %.2d ", -16);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(28): -99, Precision 3
    printf("--- TEST 28: ' %%.3d ', -99 ---\n");
    ofp = printf(" %.3d ", -99);
    mfp = ft_printf(" %.3d ", -99);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(29): -100, Precision 3 (Value length > Precision, ignored)
    printf("--- TEST 29: ' %%.3d ', -100 ---\n");
    ofp = printf(" %.3d ", -100);
    mfp = ft_printf(" %.3d ", -100);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(30): -101, Precision 4
    printf("--- TEST 30: ' %%.4d ', -101 ---\n");
    ofp = printf(" %.4d ", -101);
    mfp = ft_printf(" %.4d ", -101);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(31): INT_MAX, Precision 8
    printf("--- TEST 31: ' %%.8d ', INT_MAX ---\n");
    ofp = printf(" %.8d ", INT_MAX);
    mfp = ft_printf(" %.8d ", INT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(32): INT_MIN, Precision 9
    printf("--- TEST 32: ' %%.9d ', INT_MIN ---\n");
    ofp = printf(" %.9d ", INT_MIN);
    mfp = ft_printf(" %.9d ", INT_MIN);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(33): LONG_MAX, Precision 10
    printf("--- TEST 33: ' %%.10d ', LONG_MAX ---\n");
    ofp = printf(" %.10d ", LONG_MAX);
    mfp = ft_printf(" %.10d ", LONG_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(34): LONG_MIN, Precision 11
    printf("--- TEST 34: ' %%.11d ', LONG_MIN ---\n");
    ofp = printf(" %.11d ", LONG_MIN);
    mfp = ft_printf(" %.11d ", LONG_MIN);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(35): UINT_MAX, Precision 12
    printf("--- TEST 35: ' %%.12d ', UINT_MAX ---\n");
    ofp = printf(" %.12d ", UINT_MAX);
    mfp = ft_printf(" %.12d ", UINT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(36): ULONG_MAX, Precision 13
    printf("--- TEST 36: ' %%.13d ', ULONG_MAX ---\n");
    ofp = printf(" %.13d ", ULONG_MAX);
    mfp = ft_printf(" %.13d ", ULONG_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(37): LONG_LONG_MAX, Precision 14
    printf("--- TEST 37: ' %%.14d ', 9223372036854775807LL ---\n");
    ofp = printf(" %.14d ", 9223372036854775807LL);
    mfp = ft_printf(" %.14d ", 9223372036854775807LL);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(38): Multiple Arguments
    printf("--- TEST 38: Multiple %%.pd Arguments ---\n");
    ofp = printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    mfp = ft_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    printf("--------------------------------------------------------\n");
    
    // =======================================================
    // --- SUBCATEGORY: i (Signed Integer with Precision) ---
    // =======================================================

    printf("--- SUBCATEGORY: i ---\n");

    // TEST(39): 0, Precision 1
    printf("--- TEST 39: ' %%.1i ', 0 ---\n");
    ofp = printf(" %.1i ", 0);
    mfp = ft_printf(" %.1i ", 0);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(40): -1, Precision 2
    printf("--- TEST 40: ' %%.2i ', -1 ---\n");
    ofp = printf(" %.2i ", -1);
    mfp = ft_printf(" %.2i ", -1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(41): 1, Precision 2
    printf("--- TEST 41: ' %%.2i ', 1 ---\n");
    ofp = printf(" %.2i ", 1);
    mfp = ft_printf(" %.2i ", 1);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(42): 9, Precision 1
    printf("--- TEST 42: ' %%.1i ', 9 ---\n");
    ofp = printf(" %.1i ", 9);
    mfp = ft_printf(" %.1i ", 9);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(43): 10, Precision 2
    printf("--- TEST 43: ' %%.2i ', 10 ---\n");
    ofp = printf(" %.2i ", 10);
    mfp = ft_printf(" %.2i ", 10);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(44): 11, Precision 3
    printf("--- TEST 44: ' %%.3i ', 11 ---\n");
    ofp = printf(" %.3i ", 11);
    mfp = ft_printf(" %.3i ", 11);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(45): 15, Precision 4
    printf("--- TEST 45: ' %%.4i ', 15 ---\n");
    ofp = printf(" %.4i ", 15);
    mfp = ft_printf(" %.4i ", 15);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(46): 16, Precision 5
    printf("--- TEST 46: ' %%.5i ', 16 ---\n");
    ofp = printf(" %.5i ", 16);
    mfp = ft_printf(" %.5i ", 16);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(47): 17, Precision 6
    printf("--- TEST 47: ' %%.6i ', 17 ---\n");
    ofp = printf(" %.6i ", 17);
    mfp = ft_printf(" %.6i ", 17);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(48): 99, Precision 1
    printf("--- TEST 48: ' %%.1i ', 99 ---\n");
    ofp = printf(" %.1i ", 99);
    mfp = ft_printf(" %.1i ", 99);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(49): 100, Precision 2
    printf("--- TEST 49: ' %%.2i ', 100 ---\n");
    ofp = printf(" %.2i ", 100);
    mfp = ft_printf(" %.2i ", 100);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(50): 101, Precision 3
    printf("--- TEST 50: ' %%.3i ', 101 ---\n");
    ofp = printf(" %.3i ", 101);
    mfp = ft_printf(" %.3i ", 101);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(51): -9, Precision 1
    printf("--- TEST 51: ' %%.1i ', -9 ---\n");
    ofp = printf(" %.1i ", -9);
    mfp = ft_printf(" %.1i ", -9);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(52): -10, Precision 2
    printf("--- TEST 52: ' %%.2i ', -10 ---\n");
    ofp = printf(" %.2i ", -10);
    mfp = ft_printf(" %.2i ", -10);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(53): -11, Precision 3
    printf("--- TEST 53: ' %%.3i ', -11 ---\n");
    ofp = printf(" %.3i ", -11);
    mfp = ft_printf(" %.3i ", -11);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(54): -14, Precision 4
    printf("--- TEST 54: ' %%.4i ', -14 ---\n");
    ofp = printf(" %.4i ", -14);
    mfp = ft_printf(" %.4i ", -14);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(55): -15, Precision 1
    printf("--- TEST 55: ' %%.1i ', -15 ---\n");
    ofp = printf(" %.1i ", -15);
    mfp = ft_printf(" %.1i ", -15);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(56): -16, Precision 2
    printf("--- TEST 56: ' %%.2i ', -16 ---\n");
    ofp = printf(" %.2i ", -16);
    mfp = ft_printf(" %.2i ", -16);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(57): -99, Precision 3
    printf("--- TEST 57: ' %%.3i ', -99 ---\n");
    ofp = printf(" %.3i ", -99);
    mfp = ft_printf(" %.3i ", -99);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(58): -100, Precision 3
    printf("--- TEST 58: ' %%.3i ', -100 ---\n");
    ofp = printf(" %.3i ", -100);
    mfp = ft_printf(" %.3i ", -100);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(59): -101, Precision 4
    printf("--- TEST 59: ' %%.4i ', -101 ---\n");
    ofp = printf(" %.4i ", -101);
    mfp = ft_printf(" %.4i ", -101);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(60): INT_MAX, Precision 8
    printf("--- TEST 60: ' %%.8i ', INT_MAX ---\n");
    ofp = printf(" %.8i ", INT_MAX);
    mfp = ft_printf(" %.8i ", INT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(61): INT_MIN, Precision 9
    printf("--- TEST 61: ' %%.9i ', INT_MIN ---\n");
    ofp = printf(" %.9i ", INT_MIN);
    mfp = ft_printf(" %.9i ", INT_MIN);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(62): LONG_MAX, Precision 10
    printf("--- TEST 62: ' %%.10i ', LONG_MAX ---\n");
    ofp = printf(" %.10i ", LONG_MAX);
    mfp = ft_printf(" %.10i ", LONG_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(63): LONG_MIN, Precision 11
    printf("--- TEST 63: ' %%.11i ', LONG_MIN ---\n");
    ofp = printf(" %.11i ", LONG_MIN);
    mfp = ft_printf(" %.11i ", LONG_MIN);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(64): UINT_MAX, Precision 12
    printf("--- TEST 64: ' %%.12i ', UINT_MAX ---\n");
    ofp = printf(" %.12i ", UINT_MAX);
    mfp = ft_printf(" %.12i ", UINT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(65): ULONG_MAX, Precision 13
    printf("--- TEST 65: ' %%.13i ', ULONG_MAX ---\n");
    ofp = printf(" %.13i ", ULONG_MAX);
    mfp = ft_printf(" %.13i ", ULONG_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(66): LONG_LONG_MAX, Precision 14
    printf("--- TEST 66: ' %%.14i ', 9223372036854775807LL ---\n");
    ofp = printf(" %.14i ", 9223372036854775807LL);
    mfp = ft_printf(" %.14i ", 9223372036854775807LL);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // TEST(67): Multiple Arguments
    printf("--- TEST 67: Multiple %%.pi Arguments ---\n");
    ofp = printf(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    mfp = ft_printf(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    printf("========================================================\n");


    /*
    // T11: Unsigned Precision (u)
    printf("--- TEST T11: '%%.8u', UINT_MAX ---\n");
    ofp = printf("\tOriginal printf:\t[ %%.8u ] -> [ %.8u ]\n", UINT_MAX);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%.8u ] -> [ %.8u ]\n", UINT_MAX);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // T12: Hexadecimal Precision (x)
    printf("--- TEST T12: '%%.8x', 0xDEADBEEF ---\n");
    ofp = printf("\tOriginal printf:\t[ %%.8x ] -> [ %.8x ]\n", 0xDEADBEEF);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%.8x ] -> [ %.8x ]\n", 0xDEADBEEF);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // T13: Hexadecimal Precision and Width (X)
    printf("--- TEST T13: '%%10.5X', 0xABC (Width 10, Precision 5) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%10.5X ] -> [ %10.5X ]\n", 0xABC);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%10.5X ] -> [ %10.5X ]\n", 0xABC);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    
    // T14: Hexadecimal Precision 0, Value 0 (x) - Should print nothing
    printf("--- TEST T14: '%%.0x', 0 (Prints nothing) ---\n");
    ofp = printf("\tOriginal printf:\t[ %%.0x ] -> [ %.0x ]\n", 0);
    mfp = ft_printf("\tYour ft_printf:\t\t[ %%.0x ] -> [ %.0x ]\n", 0);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);
    */
    
}
