
package KVM

import (
    "fmt"
    "syscall"
)

//usr/include/asm-generic/ioctl.h
//usr/include/linux/kvm.h
//usr/include/x86_64-linux-gnu/asm/kvm.h

var kvmctl uintptr

func control( operation, arg uintptr ) (uintptr,error) {
    result,_,errno := syscall.Syscall( syscall.SYS_IOCTL, kvmctl, operation, arg )
    if errno != 0 { return result,errno }
    return result,nil
}

func Create() {
    fmt.Println("create vm")
}

