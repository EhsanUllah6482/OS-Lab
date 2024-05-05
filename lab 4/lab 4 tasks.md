# 2022-CS-36

### Task 1 Question 1

##### Solution:

if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <number1> <number2> <number3>"
    exit 1
fi

number1=$1
number2=$2
number3=$3

largest=$number1
if [ "$number2" -gt "$largest" ]; then
    largest=$number2
fi
if [ "$number3" -gt "$largest" ]; then
    largest=$number3
fi

echo "The largest number is: $largest"`



### Task 1 Question 2

##### Solution:

`day_of_week=$(date +"%u")

case $day_of_week in
    1)
        echo "Happy Monday!"
        ;;
    2)
        echo "Terrific Tuesday!"
        ;;
    3)
        echo "Wonderful Wednesday!"
        ;;
    4)
        echo "Thrilling Thursday!"
        ;;
    5)
        echo "Blessed Friday!"
        ;;
    6)
        echo "Super Saturday!"
        ;;
    7)
        echo "Sunny Sunday!"
        ;;
    *)
        echo "Sorry, I'm not sure what day it is!"
        ;;
esac``

### Task 2 Question 1

##### Solution:



```sh
for ((i = 1; i <= 10; i++)); do
if ((i % 2 == 0)); then
    echo "$i is even"
else
    echo "$i is odd"
fi
done
```






### Task 2 Question 2

##### Solution:

```sh

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number=$1

sum=0

while [ $number -gt 0 ]; do
    digit=$((number % 10))
    
    sum=$((sum + digit))
    number=$((number / 10))
done

echo "Sum of digits: $sum"

```


### Task 3 Question 1

##### Solution:



```sh
reverse() {
    local num=$1
    local reversed=0
while [ $num -gt 0 ]; do
    remainder=$((num % 10))
    reversed=$((reversed * 10 + remainder))
    num=$((num / 10))
done

echo "$reversed"
}
palindromeCheck() {
    local num=$1
    local reversed=$2
if [ $num -eq $reversed ]; then
    echo "$num is a palindrome"
else
    echo "$num is not a palindrome"
fi
}
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <positive_integer>"
    exit 1
fi

number=$1

if [ $number -le 0 ]; then
    echo "Please provide a positive integer"
    exit 1
fi

reversed=$(reverse $number)

palindromeCheck $number $reversed`
```
### Task 3 Question 2

##### Solution:



```sh
factorial() {
    local num=$1
if [ $num -eq 0 ]; then
    echo 1
else
    local prev_factorial=$(factorial $((num - 1)))
    echo $((num * prev_factorial))
fi
}
read -p "Enter a number: " number
if [[ ! $number =~ ^[0-9]+$ ]]; then
    echo "Error: Please enter a non-negative integer."
    exit 1
fi
result=$(factorial $number)
echo "Factorial of $number is: $result"
```




