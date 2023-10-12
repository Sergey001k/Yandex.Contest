package main
import "fmt"

func main(){
	var a, b, c, max_num int
    fmt.Scan(&a, &b, &c)
    
    if a < b {
    	max_num = b            
    }
    
    if a > b {
    	max_num = a    
    }
	
    if max_num < c {
    	max_num = c   
    }
	
    fmt.Print(max_num)

}
