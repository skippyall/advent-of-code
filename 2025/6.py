file = input("Datei? ")

with open(file) as fileReader:
    lines = fileReader.readlines()

    tasks = []

    first = True
    count = 0

    for line in lines:
        numbers = line.split()

        i = 0
        for number in numbers:
            if not number.isnumeric():
                if(number == "+"):
                    solution = 0
                    for t in tasks[i]:
                        solution += t
                else:
                    solution = 1
                    for t in tasks[i]:
                        solution *= t
                count += solution
            else:   
                if first:
                    tasks.append([int(number)])
                else:
                    tasks[i].append(int(number))
            i = i + 1
        first = False

    print(count)
        
