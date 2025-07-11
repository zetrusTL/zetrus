package main

import "fmt"

func main() {
	var num1, num2 float32
	var symbol string
	fmt.Scan(&num1,&symbol,&num2)
	switch symbol {
		case "+": fmt.Println(num1 + num2)
		case "-": fmt.Println(num1 - num2)
		case "*": fmt.Println(num1 * num2)
		case "%": if num2 == 0 {
			fmt.Println("Делить на ноль нельзя!")
					} else {
						fmt.Println(int(num1) % int(num2))
					}
 		case "/": if num2 == 0 {
			fmt.Println("Делить на ноль нельзя!")
					} else {
						fmt.Println(num1 / num2)
					}
	}
}