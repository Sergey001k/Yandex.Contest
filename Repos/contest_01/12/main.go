package main

import "fmt"

func coll(x int) int {
	if x%2 == 0{
		return x / 2
	}

	return 3*x + 1
}

func main() {
	var cur, count int 
	fmt.Scan(&cur)

	for cur != 1 {
		cur = coll(cur)
		count += 1

	}

	fmt.Print(count)
}
