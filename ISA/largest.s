.data 0x100
.label a
100
-5
10
33
7
.label s
0
.label i
0
.text 0x200
mva r8, a
ldr r0, [r8, 0] // a[0] to r0
str r0, s

.label while
ldr r10, i
cmp r10, 5       // cmp i to 5
bge endwhile     // quit while when i >= 5
ldr r5, [r8], 4  // put a[i] into r5
ldr r6, s        // put s into r6
cmp r5, r6       // cmp a[i] to s
bge skip         // do not update s when geq
str r5, s        // update s when lt
.label skip
ldr r10, i       // put i into r10
add r10, r10, 1  // add 1 to r10
str r10, i       // str r10 into i
bal while        // continue our while loop
.label endwhile
.label end
bal end
