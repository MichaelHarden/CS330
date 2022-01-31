.section .rodata
    InputStrA: .string "Enter the number a: "            # promt to get the input a
    InputStrB: .string "Enter the number b: "            # promt to get the input b
    InputStrC: .string "Enter the number c: "            # promt to get the input c
    substring: .string "%d"
    IsTriangleStr: .string "Do the sides %d, %d and %d make a triangle? %s\n"
    NoStr: .string "No"
    YesStr: .string "Yes"
    
.data
    A: .quad 0              # designating space in data to store the variable A
    B: .quad 0              # designating space in data to store the variable B
    C: .quad 0              # designating space in data to store the variable C
    input: .space 8         # designating space in data to store the user input as they inter it

.text
.global main

_returnT:
    # Run when the triangle is True. Returns a string 'True'
    movq $YesStr, %rax
    ret

_triangleCheck:
    # set the number of sides Checked to 0
    movq $0, %rcx           # the number of sides checked so far.


_checkSide:
    # check if all 3 sides have been checked. If so, return
    cmpq $3, %rcx           # (3 - %rcx) 
    je _returnT             # if all 3 sides have been checked then return
    addq $1, %rcx           # increase the sides checked

    # stage a, b, and c for comparison
    movq %rdi, %rax
    addq %rsi, %rax
    # compare a + b with c
    cmpq %rdx, %rax
    # rotate a into rsi, b into rdx, and c into rdi for the next comparison. 
    # This is done so that the same function can be used for all three sides.
    pushq %rdi
    movq %rdx, %rdi
    movq %rsi, %rdx
    pop %rsi
    # if to this point the copmarison has provien the legs to be a triangle then the loop is run again.
    jg _checkSide
    # if its not a triagle return a string 'False'
    movq $NoStr, %rax
    ret






main:
# preamble
    pushq    %rbp
    movq     %rsp, %rbp

# code here 

### Get A
    # move the string requesting user input for a
    mov $InputStrA, %rdi
    # clear the return register
    xor %rax, %rax
    # print the string to request a
    call printf

    # Run scanf and get a
    # move the substition string into rdi for scanf
    movq $substring, %rdi
    # move address of the variable into rsi
    movq $input, %rsi
    # clear the return register
    xor %rax, %rax
    # call scanf to get a
    call scanf

    # move a into rdi
    movq (input), %rdi
    # move rdi into data A
    movq %rdi, A

### Get B
    # move the string requesting user input for b
    mov $InputStrB, %rdi
    # clear the return register
    xor %rax, %rax
    # print the string to request b
    call printf

    # Run scanf and get b
    # move the substition string into rdi for scanf
    movq $substring, %rdi
    # move address of the variable into rsi
    movq $input, %rsi
    # clear the return register
    xor %rax, %rax
    # call scanf to get b
    call scanf

    # move b into rdi
    movq (input), %rdi
    # move rdi into data B
    movq %rdi, B

### Get C
    # move the string requesting user input for c
    mov $InputStrC, %rdi
    # clear the return register
    xor %rax, %rax
    # print the string to request c
    call printf

    # Run scanf and get c
    # move the substition string into rdi for scanf
    movq $substring, %rdi
    # move address of the variable into rsi
    movq $input, %rsi
    # clear the return register
    xor %rax, %rax
    # call scanf to get c
    call scanf

    # move c into rdi
    movq (input), %rdi
    # move rdi into data C
    movq %rdi, C

### check for Triangle 
    # Stage a, b, and c in rdi, rsi, and rdx registers for comparison 
    movq A, %rdi
    movq B, %rsi
    movq C, %rdx
    # clear the rax register
    xor %rax, %rax
    # call triangleCheck. The ouput will be stored in rax
    call _triangleCheck

### Print output
    # Stage IsTriangleStr, a, b, and c, and triangleCheck output in 
    # rdi, rsi, rdx, rcx, and r8 registers for printing
    movq $IsTriangleStr, %rdi
    movq A, %rsi
    movq B, %rdx
    movq C, %rcx
    movq %rax, %r8              # the output is being moved from rax to r8
    
    # clear rax register and call printf
    xor %rax, %rax
    call printf





# return
    movq     $0, %rax
    leave
    ret
