if __name__ == '__main__':

    list1 = []
    N = int(raw_input())

    for i in range (0, N) :
        line = raw_input().split()
        command = line[0]

        if command == 'insert':
            list1.insert(int(line[1]),int(line[2]))

        elif command == 'remove':
            list1.remove(int(line[1]))

        elif command == 'append':
            list1.append(int(line[1]))

        elif command == 'sort':
            list1.sort()

        elif command == 'pop':
            list1.pop()

        elif command == 'reverse':
            list1.reverse()

        elif command == 'print':
            print list1
