.data 0x100
.label a
4
.label b
5
.label c
0
.label f
0x3f000000
.text 0x200
ldr r0, a
ldr r1, b
ldr r2, c
add r3, r0, r1
str r3, c
sub r3, r0, r3
str r3, c
mul r4, r0, r0
str r4, a
div r6, r0, 5
str r6, b
sub r7, r0, 1
str r7, a
sub r8, r2, r1
sub r8, r8, 2
sub r8, r0, r8
str r8, a
mva r4, 0x12
and r5, r4, r0
str r5, b
orr r5, r0, r1
str r5, c
mov r6, 10
str r6, b
ldr r0, f
ldr r1, b
muf r0, r0, r1
str r0, f
