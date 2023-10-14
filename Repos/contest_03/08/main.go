package main

import "fmt"

func main() {
	var n, temp int
	var numbers []int
	fmt.Scan(&n)
	
	
	for i := 0; i < n; i++{
	    fmt.Scan(&temp)
	    numbers = append(numbers, temp)
	}
	
	counts := make(map[int]int)
	
	for _, num := range numbers {
		counts[num]++
	}
	
	for num, count := range counts {
		if count % 2  != 0{
			fmt.Println(num)
			break
		}
	}
}
