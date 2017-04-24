#include <arm_neon.h>
#include <stdio.h>

static void neonMemcpy(unsigned char *dst, unsigned char *src, unsigned int num_bytes)
{
	uint8x8_t row = {0};
	unsigned int i = 0;
	uint8x8_t tmp;

	row = vld1_u8((uint8_t *)src);
	vst1_u8((uint8_t *)dst, row);

}

int main(void)
{
	unsigned int i = 0;
	uint8x8_t a = { 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
			};
	uint8x8_t b = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			};
	uint8x8_t c = {0};

	neonMemcpy((unsigned char*)&c, (unsigned char*)&a, 8);

	for (i = 0; i < 8; i++) {
		printf("%d:0x%x ", i, c[i]);
	}
	printf("\n");

	return 0;
}
