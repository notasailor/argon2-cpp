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
    void processBlockNEON(
        Block &nextBlock,
        const Block &refBlock,
        const Block &prevBlock,
        const bool doXor)
    {
        /* 64 * (128 / 8) = Constants::BLOCK_SIZE_BYTES */
        uint64x2_t state[64];

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
