package main

import (
    "bufio"
    "fmt"
    "os"
	"strings"
)

func main() {
    fmt.Println("Welcome to the TO DO List CLI app!")
    fmt.Println()
    fmt.Println("Enter your command (create, read, update, delete):")

	spisok := make([]string, 0)
	for {
		reader := bufio.NewReader(os.Stdin)
		input, err := reader.ReadString('\n')
		if err != nil {
			return
		}


		if len(input) > 0 && input[len(input)-1] == '\n' {
			input = input[:len(input)-1]
		}
		if len(input) > 0 && input[len(input)-1] == '\r' {
			input = input[:len(input)-1]
		}

		switch input {

		case "create" :    
			fmt.Println("Enter task name:")
			task, _ := reader.ReadString('\n')
			task = strings.TrimSpace(task)	

				if len(task) > 0 && task[len(task)-1] == '\n' {
					task = task[:len(task)-1]
				}
			spisok = append(spisok,task)

		case "read" : 
			for i, val := range spisok {
				fmt.Printf("%d. %s\n",i+1, val)
			}


		case "update" :
			fmt.Println("Enter task name to update:")
			update,_ := reader.ReadString('\n')
			update = strings.TrimSpace(update)
			for i,val := range spisok {
				if val == update {
					fmt.Println("Enter new task name:")
					new_update,_ := reader.ReadString('\n')
					new_update = strings.TrimSpace(new_update)
					spisok[i] = new_update
				}
		}

		case "delete" : 
			fmt.Println("Enter task name to remove:")
			delete, _ := reader.ReadString('\n')
			delete = strings.TrimSpace(delete)
				for i, val := range spisok {
					if val == delete {
					spisok = append( spisok[:i],spisok[i + 1:] ...)
					fmt.Printf("Removed task #%d with name \"%s\" successfully!\n", i, delete)
					}
				}
		case "exit" : 
			fmt.Println("Good buy!")
			return

			default : fmt.Println("Invalid command! Please, try again!")
		}
		fmt.Println("Enter your command (create, read, update, delete):")
		input, _ = reader.ReadString('\n')
		input = strings.TrimSpace(input)
	}
}