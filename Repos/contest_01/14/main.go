package main

import "fmt"

func main() {
	var row, col int
	fmt.Scan(&col, &row)
	fmt.Printf("    |")

	for i := 1; i <= row; i++ {
		fmt.Printf("%4v", i)

	}
	fmt.Print("\n   --")

	for i := 1; i <= row; i++ {
		fmt.Printf("----")

	}
	fmt.Print("\n")
	for i := 1; i <= col; i++ {
		fmt.Printf("%4v|", i)
		for j := 1; j <= row; j++ {
			fmt.Printf("%4v", i*j)

		}
		fmt.Print("\n")
	}

}

