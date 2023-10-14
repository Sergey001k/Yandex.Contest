package main

import "fmt"

func main(){
	var n int
	var a float64
	fmt.Scan(&n)
	data := make([]float64, n)
    output := make([]float64, n)
    
	for i := 0; i < n; i++{
		fmt.Scan(&a)
        data[i] = a
	}
	
	output[0] = data[0]
	output[n-1] = data[n-1]
	
	for i := 1; i < n-1; i++{
		output[i] = (data[i-1] + data[i] + data[i+1])/3
        
	}
	
	for i := 0; i < n; i++{
		
		fmt.Print(output[i], " ")
        
	}
	
}
