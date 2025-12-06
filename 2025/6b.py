file = input("Datei? ")

with open(file) as fileReader:
    lines = fileReader.readlines()
    count = 0

    numbers = []

    for i in range(0, len(lines[0])):
        white = True
        number = ""
        for j in range(0, len(lines)):
            if lines[j][i].isnumeric():
                number += lines[j][i]
                white = False
            elif not lines[j][i].isspace():
                operation = lines[j][i]
                white = False

        if(white):
            if(operation == "+"):
                solution = 0
                for number in numbers:
                    solution += number
            elif operation == "*":
                solution = 1
                for number in numbers:
                    solution *= number
            count += solution
            numbers = []
        else:
            numbers.append(int(number))

    print(count)
        
