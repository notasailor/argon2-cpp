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

