/*
   BLAKE2 reference source code package - reference C implementations

   Copyright 2012, Samuel Neves <sneves@dei.uc.pt>.  You may use this under the
   terms of the CC0, the OpenSSL Licence, or the Apache Public License 2.0, at
   your option.  The terms of these licenses can be found at:

   - CC0 1.0 Universal : http://creativecommons.org/publicdomain/zero/1.0
   - OpenSSL license   : https://www.openssl.org/source/license.html
   - Apache 2.0        : http://www.apache.org/licenses/LICENSE-2.0

   More information about the BLAKE2 hash function can be found at
   https://blake2.net.
*/

// Copyright (c) 2019, Zpalmtree
//
// Please see the included LICENSE file for more information.

////////////////////////////////////////////
#include "Intrinsics/ARM/ProcessBlockNEON.h"
////////////////////////////////////////////

#include <cstring>

#include "Intrinsics/ARM/RotationsNEON.h"

namespace ProcessBlockNEON
{
    void blamkaG1NEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1)
    {

	asm volatile(
#include "blamkaG1NEON.s"
        : [a0] "+wr" (a0), [a1] "+wr" (a1), [b0] "+wr" (b0), [b1] "+wr" (b1), [c0] "+wr" (c0), [c1] "+wr" (c1), [d0] "+wr" (d0), [d1] "+wr" (d1) : 
        : "v18", "v19", "v20");
#if 0
	asm volatile(
	"xtn v18.2s, %[a0].2d\n"
        "xtn v19.2s, %[b0].2d\n"
        "add v20.2d, %[a0].2d, %[b0].2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "add v18.2d, v18.2d, v18.2d\n"
        "add %[a0].2d, v18.2d, v20.2d\n"

	"xtn v18.2s, %[a1].2d\n"
        "xtn v19.2s, %[b1].2d\n"
        "add v20.2d, %[a1].2d, %[b1].2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "add v18.2d, v18.2d, v18.2d\n"
        "add %[a1].2d, v18.2d, v20.2d\n"

	"eor %[d0].16b, %[d0].16b, %[a0].16b\n"
	"eor %[d1].16b, %[d1].16b, %[a1].16b\n"

	"mov v18.16b, %[d0].16b\n"
	"trn1 %[d0].4s, %[d0].4s, %[d0].4s\n"
	"trn2 %[d0].4s, v18.4s, %[d0].4s\n"
	"mov v18.16b, %[d1].16b\n"
	"trn1 %[d1].4s, %[d1].4s, %[d1].4s\n"
	"trn2 %[d1].4s, v18.4s, %[d1].4s\n"

	"xtn v18.2s, %[c0].2d\n"
        "xtn v19.2s, %[d0].2d\n"
        "add v20.2d, %[c0].2d, %[d0].2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "add v18.2d, v18.2d, v18.2d\n"
        "add %[c0].2d, v18.2d, v20.2d\n"

	"xtn v18.2s, %[c1].2d\n"
        "xtn v19.2s, %[d1].2d\n"
        "add v20.2d, %[c1].2d, %[d1].2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "add v18.2d, v18.2d, v18.2d\n"
        "add %[c1].2d, v18.2d, v20.2d\n"

	"eor %[b0].16b, %[b0].16b, %[c0].16b\n"
	"eor %[b1].16b, %[b1].16b, %[c1].16b\n"

	"mov v18.16b, %[b0].16b\n"
	"ushr v18.2d, %[b0].2d, #24\n"
	"shl v19.2d, %[b0].2d, #40\n"
	"orr %[b0].16b, v18.16b, v19.16b\n"
	"mov v18.16b, %[b1].16b\n"
	"ushr v18.2d, %[b1].2d, #24\n"
	"shl v19.2d, %[b1].2d, #40\n"
	"orr %[b1].16b, v18.16b, v19.16b\n"

        : [a0] "+wr" (a0), [a1] "+wr" (a1), [b0] "+wr" (b0), [b1] "+wr" (b1), [c0] "+wr" (c0), [c1] "+wr" (c1), [d0] "+wr" (d0), [d1] "+wr" (d1) : 
        : "v18", "v19", "v20");
#endif
//        a0 = fblamka(a0, b0);
//        a1 = fblamka(a1, b1);
//
//        d0 = veorq_u64(d0, a0);
//        d1 = veorq_u64(d1, a1);

//        d0 = RotationsNEON::rotr32(d0);
//        d1 = RotationsNEON::rotr32(d1);

//        c0 = fblamka(c0, d0);
//        c1 = fblamka(c1, d1);

//        b0 = veorq_u64(b0, c0);
//        b1 = veorq_u64(b1, c1);
    }

    void blamkaG2NEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1)
    {
	asm volatile(
#include "blamkaG2NEON.s"
        : [a0] "+wr" (a0), [a1] "+wr" (a1), [b0] "+wr" (b0), [b1] "+wr" (b1), [c0] "+wr" (c0), [c1] "+wr" (c1), [d0] "+wr" (d0), [d1] "+wr" (d1) : 
        : "v18", "v19", "v20");

//        a0 = fblamka(a0, b0);
//        a1 = fblamka(a1, b1);

//        d0 = veorq_u64(d0, a0);
//        d1 = veorq_u64(d1, a1);

//        d0 = RotationsNEON::rotr16(d0);
//        d1 = RotationsNEON::rotr16(d1);

//        c0 = fblamka(c0, d0);
//       c1 = fblamka(c1, d1);

//        b0 = veorq_u64(b0, c0);
//        b1 = veorq_u64(b1, c1);

//        b0 = RotationsNEON::rotr63(b0);
//        b1 = RotationsNEON::rotr63(b1);
    }

    void diagonalizeNEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1)
    {
	asm volatile(
#include "diagonalizeNEON.s"
        : [a0] "+wr" (a0), [a1] "+wr" (a1), [b0] "+wr" (b0), [b1] "+wr" (b1), [c0] "+wr" (c0), [c1] "+wr" (c1), [d0] "+wr" (d0), [d1] "+wr" (d1) : 
        : "v18", "v19" );

        //uint64x2_t t0 = vextq_u64(b0, b1, 1);
        //uint64x2_t t1 = vextq_u64(b1, b0, 1);

        //b0 = t0;
        //b1 = t1;
        //t0 = c0;
        //c0 = c1;
        //c1 = t0;

        //t0 = vextq_u64(d1, d0, 1);
        //t1 = vextq_u64(d0, d1, 1);

        //d0 = t0;
        //d1 = t1;
    }

    void undiagonalizeNEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1)
    {
	asm volatile(
#include "undiagonalizeNEON.s"
        : [a0] "+wr" (a0), [a1] "+wr" (a1), [b0] "+wr" (b0), [b1] "+wr" (b1), [c0] "+wr" (c0), [c1] "+wr" (c1), [d0] "+wr" (d0), [d1] "+wr" (d1) : 
        : "v18", "v19" );

        //uint64x2_t t0 = vextq_u64(b1, b0, 1);
        //uint64x2_t t1 = vextq_u64(b0, b1, 1);

        //b0 = t0;
        //b1 = t1;
        //t0 = c0;
        //c0 = c1;
        //c1 = t0;

        //t0 = vextq_u64(d0, d1, 1);
        //t1 = vextq_u64(d1, d0, 1);

        //d0 = t0;
        //d1 = t1;
    }

    void Round(
        uint64x2_t &a0, uint64x2_t &a1, uint64x2_t &b0, uint64x2_t &b1,
        uint64x2_t &c0, uint64x2_t &c1, uint64x2_t &d0, uint64x2_t &d1)
    {
	asm volatile(
#include "blamkaG1NEON.s"
#include "blamkaG2NEON.s"

#include "diagonalizeNEON.s"

#include "blamkaG1NEON.s"
#include "blamkaG2NEON.s"

#include "undiagonalizeNEON.s"
        : [a0] "+wr" (a0), [a1] "+wr" (a1), [b0] "+wr" (b0), [b1] "+wr" (b1), [c0] "+wr" (c0), [c1] "+wr" (c1), [d0] "+wr" (d0), [d1] "+wr" (d1) : 
        : "v18", "v19", "v20" );
    }

    void processBlockNEON(
        Block &nextBlock,
        const Block &refBlock,
        const Block &prevBlock,
        const bool doXor)
    {
        /* 64 * (128 / 8) = Constants::BLOCK_SIZE_BYTES */
        uint64x2_t state[64];
        uint64x2_t prevBlockIntrinsic[64];
        uint64x2_t refBlockIntrinsic[64];

        /* Copy block */
#if 0
        std::memcpy(state, refBlock.data(), Constants::BLOCK_SIZE_BYTES);
#endif
        std::memcpy(refBlockIntrinsic, refBlock.data(), Constants::BLOCK_SIZE_BYTES);
        std::memcpy(prevBlockIntrinsic, prevBlock.data(), Constants::BLOCK_SIZE_BYTES);

	void *next = &nextBlock;
	const void *prev = &prevBlock;
	const void *ref = &refBlock;
	void *_state = &state;
	asm volatile(
        "mov w24, #8\n"
        "ldr x20, %[_state]\n"
        "ldr x21, %[ref]\n"
        "ldr x22, %[prev]\n"

	"initloop:\n"
	"ld1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x21], #64\n"
	"ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x21], #64\n"

	"ld1 {v8.2d, v9.2d, v10.2d, v11.2d}, [x22], #64\n"
	"eor v0.16b, v0.16b, v8.16b\n"
	"eor v1.16b, v1.16b, v9.16b\n"
	"eor v2.16b, v2.16b, v10.16b\n"
	"eor v3.16b, v3.16b, v11.16b\n"

	"ld1 {v8.2d, v9.2d, v10.2d, v11.2d}, [x22], #64\n"
	"eor v4.16b, v4.16b, v8.16b\n"
	"eor v5.16b, v5.16b, v9.16b\n"
	"eor v6.16b, v6.16b, v10.16b\n"
	"eor v7.16b, v7.16b, v11.16b\n"

#include "blamkaG1NEON-regs.s"
#include "blamkaG2NEON-regs.s"
#include "diagonalizeNEON-regs.s"
#include "blamkaG1NEON-regs.s"
#include "blamkaG2NEON-regs.s"
#include "undiagonalizeNEON-regs.s"
	"st1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x20], #64\n"
	"st1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x20], #64\n"

	"subs w24, w24, #1\n"
	"bne initloop\n"

        "mov w24, #8\n"
	"subs x20, x20, #1024\n"
	"subs x21, x21, #1024\n"
	"subs x22, x22, #1024\n"
	"mainloop:\n"

	"ld1 {v0.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v1.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v2.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v3.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v4.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v5.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v6.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"ld1 {v7.2d}, [x20]\n"
	"add x20, x20, #128\n"
#include "blamkaG1NEON-regs.s"
#include "blamkaG2NEON-regs.s"
#include "diagonalizeNEON-regs.s"
#include "blamkaG1NEON-regs.s"
#include "blamkaG2NEON-regs.s"
#include "undiagonalizeNEON-regs.s"
	"subs x20, x20, #1024\n"
	"st1 {v0.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v1.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v2.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v3.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v4.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v5.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v6.2d}, [x20]\n"
	"add x20, x20, #128\n"
	"st1 {v7.2d}, [x20]\n"

	"subs x20, x20, #880\n"
	"subs w24, w24, #1\n"
	"bne mainloop\n"

        "mov w24, #16\n"
        "ldr x20, %[_state]\n"
	"ldr x23, %[next]\n"

	"mov w25, %w[doXor]\n"
	"cmp w25, #0\n"
	"bne xorloop\n"

	"noxorloop:\n"
	"ld1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x20], #64\n"
	"ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x21], #64\n"
	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"
	"ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x22], #64\n"
	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"
	"st1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x23], #64\n"

	"subs w24, w24, #1\n"
	"bne noxorloop\n"
	"bal done\n"

	"xorloop:\n"
	"ld1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x20], #64\n"
	"ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x21], #64\n"
	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"
	"ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x22], #64\n"
	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"
	"ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x23]\n"
	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"
	"st1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x23], #64\n"

	"subs w24, w24, #1\n"
	"bne xorloop\n"
	"done:\n"

	: : [_state] "m" (_state), [prev] "m" (prev), [ref] "m" (ref), [next] "m" (next), [doXor] "r" (doXor)
	: "cc", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7",
	  "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15",
	  "v18", "v19", "v20", "x20", "x21", "x22", "w24", "w25");
    }
}
