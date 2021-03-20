// Copyright (c) 2019, Zpalmtree
//
// Please see the included LICENSE file for more information.

#pragma once

#include <arm_neon.h>

#include "Argon2/Argon2.h"

namespace ProcessBlockNEON
{
    inline uint64x2_t fblamka(uint64x2_t &x, uint64x2_t &y)
    {

	uint64x2_t r;

	asm volatile(
	"xtn v18.2s, %[x].2d\n"
	"xtn v19.2s, %[y].2d\n"
	"add v20.2d, %[x].2d, %[y].2d\n" 
	"umull %[r].2d, v18.2s, v19.2s\n"
	"add %[r].2d, %[r].2d, %[r].2d\n"
	"add %[r].2d, %[r].2d, v20.2d\n"

	: [r] "=wr" (r) : [x] "wr" (x), [y] "wr" (y)
        : "v18", "v19", "v20");

        //const uint64x2_t z = vmull_u32(vmovn_u64(x), vmovn_u64(y));
        //return vaddq_u64(vaddq_u64(x, y), vaddq_u64(r, r));
        return r;
    }

    void blamkaG1NEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1);

    void blamkaG2NEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1);

    void diagonalizeNEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1);

    void undiagonalizeNEON(
        uint64x2_t &a0, uint64x2_t &b0, uint64x2_t &c0, uint64x2_t &d0,
        uint64x2_t &a1, uint64x2_t &b1, uint64x2_t &c1, uint64x2_t &d1);

    void Round(
        uint64x2_t &a0, uint64x2_t &a1, uint64x2_t &b0, uint64x2_t &b1,
        uint64x2_t &c0, uint64x2_t &c1, uint64x2_t &d0, uint64x2_t &d1);

    void processBlockNEON(
        Block &nextBlock,
        const Block &refBlock,
        const Block &prevBlock,
        const bool doXor);
}
