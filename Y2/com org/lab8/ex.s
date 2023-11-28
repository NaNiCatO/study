.data
win: .asciz "u win\n"
lose: .asciz "u lose\n"
prompt: .asciz " guess the number :\n"
pattern: .asciz "%d"

.balign 4
guess: .word 0
target: .word 23

.text
.global main
.global printf
.global scanf

main:
    mov r2, #0

loop:
    push {r2}

    ldr r0, =prompt
    bl printf

    ldr r0, =pattern
    ldr r1, =guess

    bl scanf
    pop {r2}

    ldr r0, =guess
    ldr r0, [r0]
    ldr r1, =target
    ldr r1, [r1]
    ldr r1, =target
    ldr r1, [r1]
    cmp r0, r1
    beq correct

    push {r2}
    pop {r2}

    add r2, r2, #1
    cmp r2, #4
    ble loop

    ldr r0, =lose
    bl printf
    b end

correct:
    ldr r0, =win
    bl printf

end:
    mov r7, #1
    mov r0, #0
    svc 0
    BX LR
