package main

import "fmt"
var swim, wing, neck string

func main(){
	fmt.Scan(&swim, &wing, &neck)
	if swim == "Да"{
		if wing == "Да"{
			if neck == "Да"{
				fmt.Print("Утка")
			}else{
				fmt.Print("Пингвин")
			}
		}else{
			if neck == "Да"{
				fmt.Print("Плезиозавры")
			}else{
				fmt.Print("Дельфин")
			}
			
		}
	}else{
		if wing == "Да"{
			if neck == "Да"{
				fmt.Print("Страус")
			}else{
				fmt.Print("Курица")
		}	
		}else{
			if neck == "Да"{
				fmt.Print("Жираф")
			}else{
				fmt.Print("Кот")
			}
		}
	}
}
