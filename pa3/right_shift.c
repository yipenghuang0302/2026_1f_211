#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned char uc_253 = 253;
	signed char sc_pos_3 = +3;
	signed char sc_neg_3 = -3;
	printf("uc_253=%d, uc_253>>1=%d\n", uc_253, uc_253>>1);
	printf("sc_pos_3=%d, sc_pos_3>>1=%d\n", sc_pos_3, sc_pos_3>>1);
	printf("sc_neg_3=%d, sc_neg_3>>1=%d\n", sc_neg_3, sc_neg_3>>1);
	return 0;
}