#!/bin/bash

for i in blamkaG1NEON  blamkaG2NEON  diagonalizeNEON undiagonalizeNEON
do
	cp ${i}.s ${i}-regs.s
	sed -i -e 's/%\[a0\]/v0/g' -e 's/%\[a1\]/v1/g' -e 's/%\[b0\]/v2/g' -e 's/%\[b1\]/v3/g' \
		-e 's/%\[c0\]/v4/g' -e 's/%\[c1\]/v5/g' -e 's/%\[d0\]/v6/g' -e 's/%\[d1\]/v7/g'  ${i}-regs.s
done

