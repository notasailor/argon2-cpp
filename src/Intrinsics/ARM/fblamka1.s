
        "xtn v8.2s, v0.2d\n"
        "xtn v9.2s, v2.2d\n"
        "add v10.2d, v0.2d, v2.2d\n"
        "umull v8.2d, v8.2s, v9.2s\n"
        "add v8.2d, v8.2d, v8.2d\n"
        "add v0.2d, v8.2d, v10.2d\n"

        "xtn v8.2s, v1.2d\n"
        "xtn v9.2s, v3.2d\n"
        "add v10.2d, v1.2d, v3.2d\n"
        "umull v8.2d, v8.2s, v9.2s\n"
        "add v8.2d, v8.2d, v8.2d\n"
        "add v1.2d, v8.2d, v10.2d\n"

	"eor v6.16b, v6.16b, v0.16b\n"

        "mov v8.16b, v6.16b\n"
        "trn1 v6.4s, v6.4s, v6.4s\n"
        "trn2 v6.4s, v8.4s, v6.4s\n"

        "mov x0, v0.d[0]\n"
        "mov x1, v0.d[1]\n"
        "mov x4, v2.d[0]\n"
        "mov x5, v2.d[1]\n"
        "mov x7, v3.d[1]\n"
        "mov x8, v4.d[0]\n"
        "mov x9, v4.d[1]\n"
        "mov x12, v6.d[0]\n"
        "mov x13, v6.d[1]\n"


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

	"eor v7.16b, v7.16b, v1.16b\n"
        "mov v8.16b, v7.16b\n"
        "trn1 v7.4s, v7.4s, v7.4s\n"
        "trn2 v7.4s, v8.4s, v7.4s\n"

        "xtn v8.2s, v5.2d\n"
        "xtn v9.2s, v7.2d\n"
        "add v10.2d, v5.2d, v7.2d\n"
        "umull v8.2d, v8.2s, v9.2s\n"
        "add v8.2d, v8.2d, v8.2d\n"
        "add v5.2d, v8.2d, v10.2d\n"

        "mov x2, v1.d[0]\n"
        "mov x3, v1.d[1]\n"
        "mov x10, v5.d[0]\n"
        "mov x11, v5.d[1]\n"
        "mov x14, v7.d[0]\n"
        "mov x15, v7.d[1]\n"

        "mov x6, v3.d[0]\n"

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
"eor x16, x13, x2\n"
"lsl x13, x16, #32\n"
"add x13, x13, x16, lsr #32\n"

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
"add x13, x13, x16, lsr #16\n"

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
"add x14, x14, x16, lsr #16\n"

"umull x16, w9, w14\n"
"add x16, x14, x16, lsl #1\n"
"add x9, x9, x16\n"
"eor x16, x4, x9\n"
"lsl x4, x16, #1\n"
"add x4, x4, x16, lsr 63\n"
