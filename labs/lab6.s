.section .rodata
    InputStringA: .string "Enter the number a: "            # promt to get the input a
    InputStringB: .string "Enter the number b: "            # promt to get the input b
    StringAx5: .string "%d x 5 = %d\n"                      # output for the function aTime5
    StringWDiv: .string "(%d + %d) - (%d / %d) = %d\n"      # output for the function theOneWithDivision
    StringWMul: .string "(%d - %d) + (%d x %d) = %d\n"      # output for the function theOneWithMultiplication
    substring: .string "%d"


.data
    A: .quad 0              # designating space in data to store the Variable A
    B: .quad 0              # designating space in data to store the Variable B
    input: .space 8         # designating space in data to store the user input as they inter it

.text
.global main

aTime5:
    # Take in value from rdi, return value in rax

    # push a onto the stack
    pushq %rdi 

    # multiply a by 5  
    imulq $5, %rdi

    # move a into the rax register for returning
    movq %rdi, %rax

    # get the original value of a back off the stack and put it back into the %rdi register
    pop %rdi

    # return to where the function was called
    ret

theOneWithDivision:
    # Take in value from rdi and rsi, return value in rax

    # put a, stored in rdi, onto the stack for later use
    pushq %rdi
    # put b, stored in rsi, onto the stack for later use
    pushq %rsi
    

    # add a to b, their sum will be stored in rdi
    addq %rsi, %rdi

    # get b off the stack and put it into rbx
    popq %rbx
    # get a off the stack and put it into rax
    popq %rax
    # put a on to the stack for later use
    pushq %rax
    # cqto to extend a into rdx
    cqto
    
    # divide a by b,b is in rbx the dividend will be in rax, and the remainder in rdx
    idivq %rbx

    # subtract rax and rdi, their difference will be in rdi
    subq %rax, %rdi
    # move rdi into rax
    movq %rdi, %rax
    # get a off the stack and out it back into rdi
    popq %rdi

    ret


theOneWithMultiplication:
    # Take in value from rdi and rsi, return value in rax

    # put a, stored in rdi, onto the stack for later use
    pushq %rdi

    # subtract b from a. Their difference will be stored in rdi
    subq %rsi, %rdi
    # move their difference into rbx
    movq %rdi, %rbx

    # get a off the stack and save it into rax
    popq %rax

    # put a back onto the stack for later use
    pushq %rax

    # multiply a and b, a is in rax and b is in rsi from being passed through
    imulq %rsi

    # add the two parts stored in rax and rbx, their sum will be in rax
    addq %rbx, %rax

    # get a off the stack and move it into rdi
    popq %rdi

    ret

main:
# preamble
    pushq    %rbp
    movq     %rsp, %rbp

# code here 

### Get A
    # move the string requesting user input for a
    mov $InputStringA, %rdi
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
    mov $InputStringB, %rdi
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

### run aTime5
    # move varible a into register rdi
    movq A, %rdi
    # clear the return register
    xor %rax, %rax
    # call the first function aTime5
    call aTime5
    
    # move rdi into rsi
    movq %rdi, %rsi
    # move StringAx5 into rdi
    movq $StringAx5, %rdi
    # move the returned valued from rax to rdx
    movq %rax, %rdx
    # clear the return register
    xor %rax, %rax
    # print the value
    call printf

### run theOneWithDivision
    # move A into rdi
    movq A, %rdi
    # move B into rsi
    movq B, %rsi
    # clear the return register
    xor %rax, %rax
    # call theOneWithDivision
    call theOneWithDivision

    # move b, rsi, into rdx and r8
    movq %rsi, %rdx
    movq %rsi, %r8

    # move a, rdi, into rsi, and rcx
    movq %rdi, %rsi
    movq %rdi, %rcx
    
    # move the calculate value from rax into r9
    movq %rax, %r9
    
    # move StringWDiv into rdi
    movq $StringWDiv, %rdi
    # clear the return register
    xor %rax, %rax
    # print the value
    call printf


### run theOneWithMultiplication
    # move A into rdi
    movq A, %rdi
    # move B into rsi
    movq B, %rsi
    # clear the return register
    xor %rax, %rax
    # call theOneWithMultiplication
    call theOneWithMultiplication

    # move b, rsi, into rdx and r8
    movq %rsi, %rdx
    movq %rsi, %r8

    # move a, rdi, into rsi, and rcx
    movq %rdi, %rsi
    movq %rdi, %rcx

    # move the calculate value from rax into r9
    movq %rax, %r9

    # move StringWMul into rdi
    movq $StringWMul, %rdi
    # clear the return register
    xor %rax, %rax
    # print the value
    call printf

# return
    movq     $0, %rax
    leave
    ret

