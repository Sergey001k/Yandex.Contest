package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func split(s string, delimiter rune) []string {
	var result []string
	temp := ""
	markOpen := false

	for _, char := range s {
		if char == '"' {
			markOpen = !markOpen
		}

		if char != delimiter || markOpen {
			if char == '"' {
				if len(s) > 1 && char == rune(s[1]) {
					temp += string(char)
				}
			} else {
				temp += string(char)
			}
		} else {
			result = append(result, temp)
			temp = ""
		}
	}
	result = append(result, temp)

	return result
}

func readCSV(filename string) [][]string {
	var result [][]string
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println("Error opening file:", err)
		return result
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		result = append(result, split(line, ','))
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
	}

	return result
}

func compare(element1, element2 [2]interface{}) bool {
	if element1[0].(int) != element2[0].(int) {
		return element1[0].(int) < element2[0].(int)
	} else {
		return element1[1].(string) < element2[1].(string)
	}
}

func main() {
	var pclass, age int
	var data [][]string
	var people [][2]interface{}

	fmt.Scan(&pclass, &age)

	data = readCSV("train.csv")
	data = data[1:]

	for _, i := range data {
		if i[5] == "" {
			i[5] = "0"
		}

		if intValue, err := strconv.Atoi(i[2]); err == nil {
			if intValue == pclass && i[4] == "female" {
				if intValue, err := strconv.Atoi(i[5]); err == nil {
					if intValue > age {
						temp := [2]interface{}{intValue, i[3]}
						people = append(people, temp)
					}
				}
			}
		}
	}

	sort.Slice(people, func(i, j int) bool { return compare(people[i], people[j]) })

	for _, person := range people {
		fmt.Println(person[1].(string))
	}
	fmt.Print("\n")
}
