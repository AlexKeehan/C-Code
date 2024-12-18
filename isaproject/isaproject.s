// The code you must implement is provided in ISAproject.pdf

// Define stack start address
.stack 0x5000

// Define address of printf
.text 0x7000
.label printf

.data 0x100
.label sia
50
43
100
-5
-10
50
0
.label sib
500
43
100
-5
-10
50
0
.label ia
2
3
4
1
0
.label fmt1
.string //sia[%d]: %d, sib[%d]: %d
.label fmt2
.string //Something bad
.label fmt3
.string //cmp_arrays(sia, sib): %d
.label fmt4
.string //cmp_arrays(sia, sia): %d
.label fmt5
.string //cmp_arrays(ia, sib): %d
.label fmt6
.string //ia[%d]: %d
.label fmt7
.string //sia[%d}: %d
.label fmt8
.string //smallest(ia): %d
.label fmt9
.string //smallest(sia): %d
.label fmt10
.string //Nice sort and smallest
.label fmt11
.string //factorial(4): %d
.label fmt12
.string //factorial(7): %d
.text 0x300
// r0 has ia - address of null terminated array
// sum_array is a leaf function
// If you only use r0, r1, r2, r3; you do not need a stack
.label sum_array
ldr r3, 0  		//r3 = sum
ldr r2, [r0]		//r2 = first element of r0
.label while		//while loop
cmp r2, 0 		//while ia != 0
beq endwhile 		//end condition
ldr r2, [r0], 4 	//store input into r2 with post increment
add r3, r3, r2 		//s+=ia
bal while		//keep while loop going
.label endwhile		//quit while loop when r1/ia == 0
mov r0, r3		//r0 contains sum
mov r15, r14       	//return

.text 0x400
// r0 has ia1 - address of null terminated array
// r1 has ia1 - address of null terminated array
// cmp_arrays must allocate a stack
// Save lr on stack and allocate space for local vars
.label cmp_arrays
sub r13, r13, 16   	//allocate stack
mov r4, 0		//r4 = s1
str r4, [r13]
mov r5, 0		//r5 = s2
str r5, [r13, 4]
mov r6, r14		//r6 = lr
str r6, [r13, 8]
str r14, [r13, 12] 	//store link register
blr sum_array		//sum_array(ia1)
mov r4, r0		//store result of sum_array(ia1) in r4
mov r0, r1		//move ia2 into r0
blr sum_array		//sum_array(ia2)
mov r5, r0		//store result of sum_array(ia2) in r5
//mva r0, fmt1
//mov r1, r4
//mov r2, r5
//blr printf

.label break		//if statement
cmp r4, r5		//compare s1 and s2
beq then		//if they are equal then branch to then
ble else		//if s1 is less than or equal to s2, then branch to else
mov r0, 1		//if part. If s1 > s2, then return a 1
bal endif		//branch to end of if statement
.label then		//if they are equal
mov r0, 0		//return 0
bal endif		//branch to end
.label else		//s1 <= s2
mov r0, -1		//return -1
.label endif		//end of if statement
mov r1, r6		//move stored lr to r1
ldr r4, [r13]		//Deallocate stack
ldr r5, [r13, 4]
ldr r6, [r14, 8]
ldr r14, [r13, 12]
add r13, r13, 16 
			//r0 has return value
mov r15, r1       	//return

.text 0x500
// r0 has ia - address of null terminated array
// numelems is a leaf function
// If you only use r0, r1, r2, r3; you do not need a stack
.label numelems
ldr r1, 0 		//int c = 0
.label while2 		//while loop
ldr r3, [r0], 4		//load input into r3 with post increment
cmp r3, 0 		//compare r3 with 0
beq endwhile2 		//while input != 0
add r1, r1, 1 		//c++
bal while2		//keep while loop going
.label endwhile2	//end while loop
mov r0, r1		//r0 stores numelems
mov r15, r14       	//return

.text 0x600
// r0 has ia - address of null terminated array
// sort must allocate a stack
// Save lr on stack and allocate space for local vars
.label sort
sub r13, r13, 40	//allocate stack
mov r4, 0		//r4 = i
str r4, [r13]
mov r5, 0		//r5 = k
str r5, [r13, 4]
mov r6, 0		//r6 = lr
str r6, [r13, 8]
mov r7, 0		//r7 = numelems
str r7, [r13, 12]
mov r8, 0		//r8 = t
str r8, [r13, 16]
mov r9, 0		//r9 = s - 1 - i
str r9, [r13, 20]
mov r10, 0		//r10 = ia[k]a
str r10, [r13, 24]
mov r11, 0		//r11 = ia[k+1]
str r11, [r13, 28]
mov r12, 0		//r12 = address of input array
str r12, [r13, 32]
str r14, [r13, 36]	//store lr on stack
mov r6, r14		//store lr in r6
mov r12, r0		//store r0 in r12
blr numelems		//count # of elements
mov r7, r0		//store result in r7
mov r2, r12		//backup address
mov r9, r7		//store result in r9 also, so operations can be done on it
.label while4		//while loop
cmp r4, r7		//compare i and numelems
bge end2		//if i >= numelems, then break the loop
sub r9, r7, 1		//s - 1
sub r9, r9, r4		//s - 1 - i
mov r5, 0		//reset k to 0
mov r12, r2		//reset the address to the start of the array again
.label nestedwhile	//nested while loop
cmp r5, r9		//compare r5/k and r9/s - 1 - i
bge end1		//break nested while loop, but stay in outer while loop
ldr r10, [r12], 4	//r10 = ia[k]
ldr r11, [r12]		//r11 = ia[k+1]
cmp r10, r11		//compare ia[k] and ia[k+1]
ble else2		//if ia[k] <= ia[k+1], then branch to else2
mov r8, r10		//r8/t = r10/ia[k]
mov r10, r11		//r10/ia[k] = r11/ia[k+1]
str r10, [r12, -4]	//use pre increment to store the value of r10 into ia[k-1]
mov r11, r8		//r11/ia[k+1] = r8/t
str r11, [r12]		//store the value of r11 into ia[k]
.label else2		//else for if statement
add r5, r5, 1		//k++
bal nestedwhile		//keep looping in nested while loop
.label end1		//end of nested while loop
add r4, r4, 1 		//i++
bal while4		//keep looping outer while loop
.label end2		//end of both while loops
mov r1, r6		//store lr in r1
ldr r4, [r13]		//deallocate stack
ldr r5, [r13, 4]
ldr r6, [r13, 8]
ldr r7, [r13, 12]
ldr r8, [r13, 16]
ldr r9, [r13, 20]
ldr r10, [r13, 24]
ldr r11, [r13, 28]
ldr r14, [r13, 32]
ldr r12, [r13, 36]
add r13, r13, 40
mov r15, r1       //return - sort is a void function

.text 0x700
// r0 has ia - address of null terminated array
// smallest must allocate a stack
// Save lr on stack and allocate space for local vars
.label smallest
sub r13, r13, 20	//Allocate stack
mov r4, 0		//r4 = i
str r4, [r13]
ldr r5, [r0]		//r5 = smallest
str r5, [r13, 4]
mov r6, 0 		//r6 = lr
str r6, [r13, 8]
mov r7, 0 		//r7 = numelems
str r7, [r13, 12]
mov r8, 0		//r8 = input
str r8, [r13, 16]
str r14, [r13,20]
mov r8, r0		//store input in r8
mov r6, r14		//store lr in r6
blr numelems		//branch to numelems
mov r7, r0		//move the value from numelems to r7
.label while3		//while loop
cmp r4, r7		//compare r4 with r7, r4 = i, r7 = numelems
beq endwhile3		//while i != numelems
ldr r3, [r8], 4		//load input string into r3 with a post increment
cmp r3, r5		//r3 = input, r5 = smallest
bge skip		//if input > smallest, then skip
mov r5, r3		//r5 = smallest, r3 = input
.label skip
add r4, r4, 1		//r4++/i++
bal while3		//branch back to while loop
.label endwhile3
mov r0, r5		//move answer to r0
mov r1, r6		//move lr to r1

ldr r4, [r13]		//deallocate stack
ldr r5, [r13, 4]
ldr r6, [r13, 8]
ldr r7, [r13, 12]
ldr r14, [r13, 16]
add r13, r13, 20	//smallest is in r0 and lr is in r1
mov r15, r1       	//return

.text 0x800
// r0 has an integer
// factorial must allocate a stack
// Save lr on stack and allocate space for local vars
.label factorial
sub r13, r13, 8  	//allocate stack
str r14, [r13]		//store lr on the stack
cmp r8, 1		//r8 has r0 in it. Compare r8 with 1
beq then3		//if r8 == 1, then branch
sub r8, r8, 1		//r8--
cmp r7, 0		//check if r7 = 0. r7 = result
beq else3		//if r7 == 0, then branch
mul r7, r7, r8		//else, r7 = r7 * r8
bal end6		//branch to the end of the if statement
.label else3		//then portion
mul r7, r8, r0		//r7 = r8 * r0
.label end6		//branch to end
blr factorial		//recursive call
.label then3		//end of the factorial function
mov r0, r7		//move answer to r0
ldr r14, [r13]		//deallocate stack
add r13, r13, 8
mov r15, r14       	//return


.text 0x900
// This sample main implements the following
// int main() {
//     int n = 0, l = 0, c = 0;
//     printf("Something bad");
//     for (int i = 0; i < 3; i++)
//         printf("ia[%d]: %d", i, sia[i]);
//     n = numelems(sia);
//     sm1 = smallest(sia);
//     cav = cmp_arrays(sia, sib);
// }
.label main
//mov r0, sia
//blr sum_array

//blr sort
sub r13, r13, 36     	//allocate space for stack
mov r4, 0               //r4 =  cav
str r4, [r13]
mov r5, 0		//r5 = n
str r5, [r13, 4]
mov r6, 0		//r6 = sm1
str r6, [r13, 8]
mov r7, 0		//r7 = l
str r7, [r13, 12]
mov r8, r0		//for factorial
str r8, [r13, 16]
mov r9, 0		//r9 = c
str r9, [r13, 20]
mov r10, 0		//r10 = i
str r10, [r13, 24]
mov r11, 0		//r11 = sm2
str r11, [r13, 28]
str lr, [sp, 32]   	//[sp,12] is lr (save lr)
// printf("Something bad");
// Kernel call to printf expects parameters
// r1 - address of format string - "Something bad"
// mva r1, bad
// ker #0x11
// The os has code for printf at address 0x7000
// The code there generates the ker instruction
// You call printf with
// r0 - has address of format string - "Something bad"
mva r0, fmt2		//fmt2 = Something bad
blr printf		//call print
mva r0, sia		//r0 = address of sia
mva r1, sib		//r1 = address of sib
blr cmp_arrays		//cmp_arrays(sia, sib)
mov r4, r0		//r4/cav = cmp_arrays(sia, sib)
mva r0, fmt3		//print result. fmt3 = cmp_arrays(sia, sib): %d
mva r1, r4		//r1 = r4/cav/cmp_arrays(sia, sib)
blr printf		//call print
mva r0, sia		//r0 = address of ia
mva r1, sia		//r1 = address of sia
blr cmp_arrays		//cmp_arrays(sia, sia)
mov r4, r0		//storing result of cmp_arrays(sia, sia)
mva r0, fmt4		//fmt4 = cmp_arrays(sia, sia): %d
mva r1, r4		//r1 = cmp_arrays(sia, sia)
blr printf		//call print
mva r0, ia		//r0 = address of ia
mva r1, sia		//r1 = address of sia
blr cmp_arrays		//cmp_arrays(ia, sia)
mov r4, r0		//store result in r4
mva r0, fmt5		//print result. fmt5 = cmp_arrays(ia, sib): %d
mva r1, r4		//r1 = r4/cmp_arrays(ia, sia)
blr printf		//call print

mva r0, ia		//r0 = address of ia
blr numelems		//numelems(ia)
mov r5, r0		//n = numelems(ia)
mov r10, 0		//i = 0
mva r4, ia		//r4 has address of input array
.label while400		//while loop
cmp r10, r5		//compare r10/i to n/r5
bge endwhile400		//while(i < n/r5)
mva r1, fmt6		//fmt6 = ia[%d]: %d
mov r2, r10		//i to r2
ldr r3, [r4], 4		//ia[i] to r3 with post increment
ker #0x11		//call printf
add r10, r10, 1		//i++
bal while400		//keep looping
.label endwhile400	//end of the while loop

mva r0, sia		//r0 = address of sia
blr sort		//sort(sia)
mva r0, sia		//n = numelems(sia)
blr numelems		//numelems(sia)
mov r5, r0		//n/r5 = numelems(sia)
mov r10, 0		//i = 0
mva r4, sia		//r4 has address of input array
.label while40		//while loop
cmp r10, r5		//compare r10/i to n/r5
bge endwhile4		//while(i < n/r5)
mva r1, fmt7		//fmt7 = sia[%d]: %d
mov r2, r10		//i to r2
ldr r3, [r4], 4		//sia[i] to r3 with post increment
ker #0x11		//call printf
add r10, r10, 1		//i++
bal while40		//keep looping
.label endwhile4	//end of the while loop

mva r0, ia		//r0 = address of ia
blr smallest		//smallest(ia)
mov r6, r0		//sm1/r6 = smallest(ia)
mva r0, sia		//r0 = address of sia
blr smallest		//smallest(sia)
mov r11, r0		//sm2/r11 = smallest(sia)
mva r0, fmt8		//fmt8 = smallest(ia): %d 
mva r1, r6		//print out sm1/r6
blr printf		//call print
mva r0, fmt9		//fmt9 = smallest(sia): %d
mva r1, r11		//print out sm2/r11
blr printf		//call print
mov r0, ia		//r0 = address of ia
ldr r3, [r0], 0		//ia[0]
cmp r6, r3		//sm1 != ia[0]
beq else90		//branch if (sm1 == ia[0])
mva r0, fmt10		//fmt10 = Nice sort and smallest
blr printf		//call print
bal end90		//branch to end of if statement
.label else90		//if sm1 == ia[0]
mva r0, fmt2		//fmt2 = Something bad
blr printf		//call print
.label end90		//end of if statement

mov r0, sia		//r0 = address of sia
ldr r3, [r0], 0		//sia[0]
cmp r11, r3		//sm2 != sia[0]
beq else100		//branch if sm2 == sia[0]
mva r0, fmt10		//fmt10 = Nice sort and smallest
blr printf		//call print
bal end100		//branch to end of if statement
.label else100		//if sm2 == sia[0]
mva r0, fmt2		//fmt2 = Something bad
blr printf		//call print
.label end100		//end of the if statement

mov r0, 4		//setting parameters for factorial
mov r8, r0		//setting r8 = r0
blr factorial		//call factorial
mov r5, r0		//n = factorial(4)
mva r0, fmt11		//fmt11 = factorial(4): %d
mva r1, r5		//r1 = n/r5
blr printf		//call print
mov r0, 7		//set r0 to 7 for the factorial function call
mov r8, r0		//setting r8 = r0
mov r7, 0		//resetting r7 = 0
blr factorial		//call factorial
mov r5, r0		//n = factorial(7)
mva r0, fmt12		//fmt12 = factorial(7): %d
mva r1, r5		//r1 = n/r5
blr printf		//call print



//This is the implementation of the main that was provided in the template
//
// for (int i = 0; i < 4; i++)
//     printf("ia[%d]: %d", i, sia[i]);

mva r4, sia   // address is sia to r4
.label loop4times  // print 3 elements of sia
cmp r10, 4
bge end_loop4times
// Kernel call to printf expects parameters
// r1 - address of format string - "ia[%d]: %d"
// r2 - value for first %d
// r3 - value for second %d
mva r1, fmt1       // fmt1 to r1
mov r2, r10         // i to r2
ldr r3, [r4], 4    // sia[i] to r3
ker #0x11          // Kernel call to printf
add r10, r10, 1      // i++
bal loop4times
.label end_loop4times
// int n = numelems(sia);
mva r0, sia        // put address of sia in r0
blr numelems       // n = numelems(sia)
str r0, [sp, 4]
// int sm1 = smallest(sia);
mva r0, sia        // put address of sia in r0
blr smallest       // sm1 = smallest(sia)
str r0, [sp, 8]    // store return value in sm1
// cav = cmp_arrays_sia, sib);
mva r0, sia        // put address of sia in r0
mva r1, sib        // put address of sib in r1
blr cmp_arrays
str r0, [sp, 0]
// Do not deallocate stack.
// This leaves r13 with an address that can be used to dump memory
// > d 0x4ff0 
// Shows the three hardcoded values stored in cav, n, and sm1.
// 0x4ff0 (0d20464) 0xffffffff 0x0000000a 0x00000002
.label end
bal end            // branch to self
