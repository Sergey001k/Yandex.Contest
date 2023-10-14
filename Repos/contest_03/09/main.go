package main
import "fmt"

func main() {
    var n int
    var x, rem int64
    var flag bool
    flag = false
    
    fmt.Scan(&n, &x)
    remains := make(map[int64]int64)
    
    for i := 0; i < n; i++{
        var temp int64;
        fmt.Scan(&temp)
        rem = x - temp
        remains[rem] += 1
        
        if remains[temp] > 0{
            if temp < x-temp{
                fmt.Print(temp, x-temp)
            }else{
                fmt.Print(x-temp, temp)
            }           
            
            flag = true
            break          
        }
        
    }
    
    if flag == false{
        fmt.Print(0, 0)
    }   
    
}

