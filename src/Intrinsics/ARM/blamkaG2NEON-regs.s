        "xtn v18.2s, v0.2d\n"
        "xtn v19.2s, v2.2d\n"
        "add v20.2d, v0.2d, v2.2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "shl v18.2d, v18.2d, #1\n"
        "add v0.2d, v18.2d, v20.2d\n"

        "xtn v18.2s, v1.2d\n"
        "xtn v19.2s, v3.2d\n"
        "add v20.2d, v1.2d, v3.2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "shl v18.2d, v18.2d, #1\n"
        "add v1.2d, v18.2d, v20.2d\n"

        "eor v6.16b, v6.16b, v0.16b\n"
        "eor v7.16b, v7.16b, v1.16b\n"

        "mov v18.16b, v6.16b\n"
        "ushr v18.2d, v6.2d, #16\n"
        "shl v19.2d, v6.2d, #48\n"
        "orr v6.16b, v18.16b, v19.16b\n"
        "mov v18.16b, v7.16b\n"
        "ushr v18.2d, v7.2d, #16\n"
        "shl v19.2d, v7.2d, #48\n"
        "orr v7.16b, v18.16b, v19.16b\n"

        "xtn v18.2s, v4.2d\n"
        "xtn v19.2s, v6.2d\n"
        "add v20.2d, v4.2d, v6.2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "shl v18.2d, v18.2d, #1\n"
        "add v4.2d, v18.2d, v20.2d\n"

        "xtn v18.2s, v5.2d\n"
        "xtn v19.2s, v7.2d\n"
        "add v20.2d, v5.2d, v7.2d\n"
        "umull v18.2d, v18.2s, v19.2s\n"
        "shl v18.2d, v18.2d, #1\n"
        "add v5.2d, v18.2d, v20.2d\n"

        "eor v2.16b, v2.16b, v4.16b\n"
        "eor v3.16b, v3.16b, v5.16b\n"

        "mov v18.16b, v2.16b\n"
        "ushr v18.2d, v2.2d, #63\n"
        "shl v19.2d, v2.2d, #1\n"
        "orr v2.16b, v18.16b, v19.16b\n"
        "mov v18.16b, v3.16b\n"
        "ushr v18.2d, v3.2d, #63\n"
        "shl v19.2d, v3.2d, #1\n"
        "orr v3.16b, v18.16b, v19.16b\n"

