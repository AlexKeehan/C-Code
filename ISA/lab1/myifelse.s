// int a = 100;
// int b = 25;
// int c =10;
// if (a < b || c < b) {
//	a = a | 0xf;
//	b = c;
// } else {
//	b = b & 3;
//	a = c;
// }
// int d = a + b + c;
.data 0x100
.label a
100
.label b
25
.label c
10
.label d
0
.text 0x200
ldr r0, a // load a into rq
ldr r1, b // load b into r1
cmp r0, r1 // compare a and b (a < b)
blt then // branch less than
ldr r0, c // load c into r0
ldr r1, b // load b into r1
cmp r0, r1 // compare r0 and r1 (c < b)
blt then
.label then
ldr r0, a // assign a to r0
orr r0, r0, 0xf // bit or with a and 0xf and put result into r0
str r0, a // assign a to value of r0
ldr r0, c // load c into r0
str r0, b // set b equal to r0 (c)
bal endif // branch always, ends this part of the program
.label else // does the else part of the if statement
ldr r0, b // load b into r0
and r0, r0, 3 // and with b and 3, result in r0
str r0, b // assign b to r0
ldr r0, c // load c into r0
str r0, a // assign a to r0 (c)
.label endif // jump past the if statement
ldr r0, a // load a into r0
ldr r1, b // load b into r1
add r0, r0, r1 // add a + b and store result in r0
ldr r1, c // load c into r1
add r0, r0, r1 // add a + c and store result in r0
str r0, d // assign d to r0 (a + c)
