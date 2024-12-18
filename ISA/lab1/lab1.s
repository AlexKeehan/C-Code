.data 0x100
.label stack
.label a
0
.label b
20
.label c
30

.text 0x200 // load brings stuff from memory to registers
	    // move adds a value into registers without going to memory
ldr r1, b // load b into r1
ldr r2, c // load c into r2
mov r4, 20 // doesn't go to memory, stores 20 in r4
mov r5, -20 // doesn't go to memory, stores -20 in r5
add r14, r1, r2 // add b and c and store result in r14
str r14, a // store result into a
.label bp1 // create new variable bp1
mva r13, stack // put stack into r13
ldr r5, [r13, 0] // uses address in r13 plus whatever's after it (0)
.label end // create variable end
bal end // 

