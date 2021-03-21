/*
 * ARMv8 optimized Argon2
*/

// Copyright (c) 2019, notasailor
//
// Please see the included LICENSE file for more information.

////////////////////////////////////////////
#include "Intrinsics/ARM/ProcessBlockARMv8.h"
////////////////////////////////////////////

#include <cstring>

namespace ProcessBlockARMv8
{
    void processBlockARMv8(
        Block &nextBlock,
        const Block &refBlock,
        const Block &prevBlock, bool doXor)
{
    static Block _state;

    uint64_t *state = _state.data();
    const uint64_t *prev = prevBlock.data();
    const uint64_t *ref = refBlock.data();
    uint64_t *next = nextBlock.data();
    uint64_t Xor = doXor ? 0xFFFFFFFFFFFFFFFF : 0;

    asm volatile(
	"mov w24, #8\n"
	"ldr x20, %[state]\n"
	"ldr x21, %[ref]\n"
	"ldr x22, %[prev]\n"

	"doXor_initloop:\n"
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
 
#include "fblamka1.s"

    "stp x0, x1, [x20], #16\n"
    "stp x2, x3, [x20], #16\n"
    "stp x4, x5, [x20], #16\n"
    "stp x6, x7, [x20], #16\n"
    "stp x8, x9, [x20], #16\n"
    "stp x10, x11, [x20], #16\n"
    "stp x12, x13, [x20], #16\n"
    "stp x14, x15, [x20], #16\n"

	"subs w24, w24, #1\n"
	"bne doXor_initloop\n"

	"mov x24, #8\n"
	"subs x20,x20, #1024\n"
	"doXor_mainloop:\n"

	"ldp x0, x1, [x20], #128\n"
	"ldp x2, x3, [x20], #128\n"
	"ldp x4, x5, [x20], #128\n"
	"ldp x6, x7, [x20], #128\n"
	"ldp x8, x9, [x20], #128\n"
	"ldp x10, x11, [x20], #128\n"
	"ldp x12, x13, [x20], #128\n"
	"ldp x14, x15, [x20], #128\n" //x0..x15 is initialized with ref
	"subs x20, x20, #1024\n"

#include "fblamka-gpregs.s"

    "stp x0, x1, [x20], #128\n"
    "stp x2, x3, [x20], #128\n"
    "stp x4, x5, [x20], #128\n"
    "stp x6, x7, [x20], #128\n"
    "stp x8, x9, [x20], #128\n"
    "stp x10, x11, [x20], #128\n"
    "stp x12, x13, [x20], #128\n"
    "stp x14, x15, [x20], #128\n"

    	"subs x20, x20, #1008\n"
	"subs w24, w24, #1\n"
	"bne doXor_mainloop\n"

	"mov w4, #16\n"
	"mov x0, %[Xor]\n"
	"dup v8.2d, x0\n"
	"ldr x0, %[next]\n"
	"subs x21, x21, #1024\n"
	"subs x22, x22, #1024\n"
	"subs x20, x20, #128\n"

	"Xorloop:\n"
	"ld1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x22], #64\n" // prevBlock
        "ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x20], #64\n" // state

	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"

        "ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x21], #64\n" // refBlock

	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"

        "ld1 {v4.2d, v5.2d, v6.2d, v7.2d}, [x0]\n" // nextBlock

	"and v4.16b, v4.16b, v8.16b\n"
	"and v5.16b, v5.16b, v8.16b\n"
	"and v6.16b, v6.16b, v8.16b\n"
	"and v7.16b, v7.16b, v8.16b\n"
	"eor v0.16b, v0.16b, v4.16b\n"
	"eor v1.16b, v1.16b, v5.16b\n"
	"eor v2.16b, v2.16b, v6.16b\n"
	"eor v3.16b, v3.16b, v7.16b\n"

	"st1 {v0.2d, v1.2d, v2.2d, v3.2d}, [x0], #64\n"

	"subs w4, w4, #1\n"
	"bne Xorloop\n"

	: : [state] "m" (state), [prev] "m" (prev), [ref] "m" (ref), [next] "m" (next), [Xor] "r" (Xor)
	: "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7",
	"cc", "x20", "x21", "x22", "x24");
}

}

