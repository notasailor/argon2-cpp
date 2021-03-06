"umull x16, w0, w4\n"
"add x16, x4, x16, lsl #1\n"
"add x0, x0, x16\n"
"umull x16, w1, w5\n"
"add x16, x5, x16, lsl #1\n"
"add x1, x1, x16\n"
"umull x16, w2, w6\n"
"add x16, x6, x16, lsl #1\n"
"add x2, x2, x16\n"
"umull x16, w3, w7\n"
"add x16, x7, x16, lsl #1\n"
"add x3, x3, x16\n"

"eor x16, x12, x0\n"
"lsl x12, x16, #32\n"
"add x12, x12, x16, lsr #32\n"
"eor x16, x13, x1\n"
"lsl x13, x16, #32\n"
"add x13, x13, x16, lsr #32\n"

"umull x16, w8, w12\n"
"add x16, x12, x16, lsl #1\n"
"add x8, x8, x16\n"
"eor x16, x4, x8\n"
"lsl x4, x16, #40\n"
"add x4, x4, x16, lsr 24\n"

"umull x16, w0, w4\n"
"add x16, x4, x16, lsl #1\n"
"add x0, x0, x16\n"
"eor x16, x12, x0\n"
"lsl x12, x16, #48\n"
"add x12, x12, x16, lsr 16\n"

"umull x16, w8, w12\n"
"add x16, x12, x16, lsl #1\n"
"add x8, x8, x16\n"
"eor x16, x4, x8\n"
"lsl x4, x16, #1\n"
"add x4, x4, x16, lsr 63\n"

"umull x16, w9, w13\n"
"add x16, x13, x16, lsl #1\n"
"add x9, x9, x16\n"
"eor x16, x5, x9\n"
"lsl x5, x16, #40\n"
"add x5, x5, x16, lsr 24\n"

"umull x16, w1, w5\n"
"add x16, x5, x16, lsl #1\n"
"add x1, x1, x16\n"
"eor x16, x13, x1\n"
"lsl x13, x16, #48\n"
"add x13, x13, x16, lsr 16\n"

"umull x16, w9, w13\n"
"add x16, x13, x16, lsl #1\n"
"add x9, x9, x16\n"

"eor x16, x5, x9\n"
"lsl x5, x16, #1\n"
"add x5, x5, x16, lsr 63\n"

"eor x16, x14, x2\n"
"lsl x14, x16, #32\n"
"add x14, x14, x16, lsr #32\n"

"eor x16, x15, x3\n"
"lsl x15, x16, #32\n"
"add x15, x15, x16, lsr #32\n"

"umull x16, w10, w14\n"
"add x16, x14, x16, lsl #1\n"
"add x10, x10, x16\n"
"umull x16, w11, w15\n"
"add x16, x15, x16, lsl #1\n"
"add x11, x11, x16\n"

"eor x16, x6, x10\n"
"lsl x6, x16, #40\n"
"add x6, x6, x16, lsr 24\n"

"umull x16, w2, w6\n"
"add x16, x6, x16, lsl #1\n"
"add x2, x2, x16\n"

"eor x16, x14, x2\n"
"lsl x14, x16, #48\n"
"add x14, x14, x16, lsr 16\n"

"umull x16, w10, w14\n"
"add x16, x14, x16, lsl #1\n"
"add x10, x10, x16\n"

"eor x16, x6, x10\n"
"lsl x6, x16, #1\n"
"add x6, x6, x16, lsr 63\n"

"eor x16, x7, x11\n"
"lsl x7, x16, #40\n"
"add x7, x7, x16, lsr 24\n"

"umull x16, w3, w7\n"
"add x16, x7, x16, lsl #1\n"
"add x3, x3, x16\n"

"eor x16, x15, x3\n"
"lsl x15, x16, #48\n"
"add x15, x15, x16, lsr 16\n"

"umull x16, w11, w15\n"
"add x16, x15, x16, lsl #1\n"
"add x11, x11, x16\n"

"eor x16, x7, x11\n"
"lsl x7, x16, #1\n"
"add x7, x7, x16, lsr 63\n"

"umull x16, w0, w5\n"
"add x16, x5, x16, lsl #1\n"
"add x0, x0, x16\n"
"umull x16, w1, w6\n"
"add x16, x6, x16, lsl #1\n"
"add x1, x1, x16\n"
"umull x16, w2, w7\n"
"add x16, x7, x16, lsl #1\n"
"add x2, x2, x16\n"
"umull x16, w3, w4\n"
"add x16, x4, x16, lsl #1\n"
"add x3, x3, x16\n"

"eor x16, x15, x0\n"
"lsl x15, x16, #32\n"
"add x15, x15, x16, lsr #32\n"

"umull x16, w10, w15\n"
"add x16, x15, x16, lsl #1\n"
"add x10, x10, x16\n"

"eor x16, x5, x10\n"
"lsl x5, x16, #40\n"
"add x5, x5, x16, lsr 24\n"

"umull x16, w0, w5\n"
"add x16, x5, x16, lsl #1\n"
"add x0, x0, x16\n"

"eor x16, x15, x0\n"
"lsl x15, x16, #48\n"
"add x15, x15, x16, lsr 16\n"

"umull x16, w10, w15\n"
"add x16, x15, x16, lsl #1\n"
"add x10, x10, x16\n"

"eor x16, x5, x10\n"
"lsl x5, x16, #1\n"
"add x5, x5, x16, lsr 63\n"

"eor x16, x12, x1\n"
"lsl x12, x16, #32\n"
"add x12, x12, x16, lsr #32\n"

"umull x16, w11, w12\n"
"add x16, x12, x16, lsl #1\n"
"add x11, x11, x16\n"

"eor x16, x6, x11\n"
"lsl x6, x16, #40\n"
"add x6, x6, x16, lsr 24\n"

"umull x16, w1, w6\n"
"add x16, x6, x16, lsl #1\n"
"add x1, x1, x16\n"

"eor x16, x12, x1\n"
"lsl x12, x16, #48\n"
"add x12, x12, x16, lsr 16\n"

"umull x16, w11, w12\n"
"add x16, x12, x16, lsl #1\n"
"add x11, x11, x16\n"

"eor x16, x6, x11\n"
"lsl x6, x16, #1\n"
"add x6, x6, x16, lsr 63\n"

"eor x16, x13, x2\n"
"lsl x13, x16, #32\n"
"add x13, x13, x16, lsr #32\n"

"umull x16, w8, w13\n"
"add x16, x13, x16, lsl #1\n"
"add x8, x8, x16\n"

"eor x16, x7, x8\n"
"lsl x7, x16, #40\n"
"add x7, x7, x16, lsr 24\n"

"umull x16, w2, w7\n"
"add x16, x7, x16, lsl #1\n"
"add x2, x2, x16\n"

"eor x16, x13, x2\n"
"lsl x13, x16, #48\n"
"add x13, x13, x16, lsr 16\n"

"umull x16, w8, w13\n"
"add x16, x13, x16, lsl #1\n"
"add x8, x8, x16\n"
"eor x16, x7, x8\n"
"lsl x7, x16, #1\n"
"add x7, x7, x16, lsr 63\n"

"eor x16, x14, x3\n"
"lsl x14, x16, #32\n"
"add x14, x14, x16, lsr #32\n"

"umull x16, w9, w14\n"
"add x16, x14, x16, lsl #1\n"
"add x9, x9, x16\n"

"eor x16, x4, x9\n"
"lsl x4, x16, #40\n"
"add x4, x4, x16, lsr 24\n"

"umull x16, w3, w4\n"
"add x16, x4, x16, lsl #1\n"
"add x3, x3, x16\n"

"eor x16, x14, x3\n"
"lsl x14, x16, #48\n"
"add x14, x14, x16, lsr 16\n"

"umull x16, w9, w14\n"
"add x16, x14, x16, lsl #1\n"
"add x9, x9, x16\n"
"eor x16, x4, x9\n"
"lsl x4, x16, #1\n"
"add x4, x4, x16, lsr 63\n"
