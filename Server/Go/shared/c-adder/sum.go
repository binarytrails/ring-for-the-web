package main

import "C"

//export Sum
func Sum(a, b int32) int32 {
    return a + b
}

func main() {}
