"ext v18.16b, %[b0].16b, %[b1].16b, #8\n"
"ext v19.16b, %[b1].16b, %[b0].16b, #8\n"
"mov %[b0].16b, v18.16b\n"
"mov %[b1].16b, v19.16b\n"
"mov v18.16b, %[c0].16b\n"
"mov %[c0].16b, %[c1].16b\n"
"mov %[c1].16b, v18.16b\n"

"ext v18.16b, %[d1].16b, %[d0].16b, #8\n"
"ext v19.16b, %[d0].16b, %[d1].16b, #8\n"

"mov %[d0].16b, v18.16b\n"
"mov %[d1].16b, v19.16b\n"

