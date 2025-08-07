package main 
import ("fmt";"sort")

func main(){
var mapValut = map[string]float64{
    "USD": 1.0,   // Доллар США
    "EUR": 0.92,  // Евро
    "RUB": 90.0,  // Российский рубль
    "JPY": 157.0, // Японская иена
    "CNY": 7.25,  // Китайский юань
    "GBP": 0.78,  // Британский фунт
    "KZT": 460.0, // Казахстанский тенге
    "TRY": 32.5,  // Турецкая лира
    "INR": 83.0,  // Индийская рупия
    "BRL": 5.12,  // Бразильский реал
    "AUD": 1.50,  // Австралийский доллар
    "CAD": 1.36,  // Канадский доллар
    "CHF": 0.89,  // Швейцарский франк
    "SEK": 10.8,  // Шведская крона
    "NOK": 10.5,  // Норвежская крона
}

	sliceValut := make([]string,0, len(mapValut))
	for valt := range  mapValut {
		sliceValut = append(sliceValut,valt)
	} 
	sort.Strings(sliceValut)

	fmt.Printf("Добро пожаловать в конвертер валют! \nДоступные валюты для конвертации:\n")

	for i, valt := range sliceValut {
		fmt.Printf("%d. %s (курс: %.2f)\n", i+1, valt, mapValut[valt])
	}

	number := 0
	money := 0
	for {
		fmt.Printf("Введите сумму в USD: ")
		fmt.Scan(&money)
		if money <= 0 {
			fmt.Println("Сумма должна превышать 0!")
		} else {
			break
		}
	}
	for {
		fmt.Printf("Выберите номер валюты для конвертации из списка ниже: ")
		fmt.Scan(&number)
		if number <= 0 || number > 15 {
			fmt.Println("Неправильный выбор валют!")
		} else {
			break
		}
	}
	selectedCode := sliceValut[number-1]
	rate := mapValut[selectedCode]
	result := float64(money) * rate

	fmt.Printf("%.2f USD = %.2f %s", float64(money), result ,selectedCode)

}