package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x)
	if x%2 == 0 && x != 2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
