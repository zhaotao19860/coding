//go run check_endian.go
package main

import (
	"unsafe"
)

func is_big_endian() bool {
	var i uint16 = 0x1
	bt := (*[2]byte)(unsafe.Pointer(&i))
	if bt[0] == 0 {
		return true
	} else {
		return false
	}
}

/*
func main() {
	rc := is_big_endian()
	if rc == true {
		fmt.Println("system is big endian.")
	} else {
		fmt.Println("system is little endian.")
	}
}
*/
