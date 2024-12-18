.data 0x100
.label a
100
-5
10
33
7
.label s
0

.text 0x200
.label smallest
ldr r0, [r0, 0]
str r0, s

ldr r10, 0
.label while
cmp r10, r1
bge endwhile
ldr r5, [r0], 4
ldr r6, s
cmp r5, r6
bge skip
str r5, s
.label skip
add r10, r10, 1
bal while
.label endwhile
mov r0, r5
mov r15, r14

.text 0x400
.label main
mva r0, a
mov r1, 5
blr smallest
str r0, s
.label end
bal end
