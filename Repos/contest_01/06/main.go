package main
import "fmt"

func main() {
	var sum, m5000, m1000, m500, m200, m100 int
	fmt.Scan(&sum)
	for sum > 0 {
        
	if sum >= 5000{
		m5000 = sum / 5000
		sum = sum % 5000
	}
	if sum >= 1000 {
		m1000 = sum / 1000
		sum = sum % 1000	
	}
	if sum >= 500 {
		m500 = sum / 500
		sum = sum % 500
	}
	if sum >= 200 {
		m200 = sum / 200
		sum = sum % 200
	}
	if sum >= 100{
		m100 = sum / 100
		sum = sum % 100
	}
	}

	fmt.Print(m5000, m1000, m500, m200, m100)
}
