package main

import (
	"encoding/json"
	"fmt"
	"io"
	"os"
)

type Project struct {
	ProjectID int    `json: "project_id"`
	Tasks     []Task `json: "tasks"`
}

type Task struct {
	User_id   int    `json:"user_id"`
	ID        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

func main() {
	var projects []Project
	var user_ID int

	file, _ := os.Open("data.json")
	data, _ := io.ReadAll(file)

	_ = json.Unmarshal(data, &projects)

	fmt.Scan(&user_ID)
	comp_tasks := 0

	for _, project := range projects {
		for _, task := range project.Tasks {
			if user_ID == task.User_id && task.Completed == true {
				comp_tasks += 1
			}

		}
	}
	fmt.Print(comp_tasks)
}
