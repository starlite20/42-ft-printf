#include "ft_printf.h"

int main()
{
	
	int mfp, ofp;

    ofp = printf("\tOriginal printf:\t-> [ %.5d ]\n", -123);
    mfp = ft_printf("\tYour ft_printf:\t\t-> [ %.5d ]\n", -123);
    printf("\tCount: (O %d | M %d)\n\n", ofp, mfp);

    
}
