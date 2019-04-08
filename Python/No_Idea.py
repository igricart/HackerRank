if __name__ == '__main__':
    inputs, set_size = raw_input().split()
    ar = raw_input().split()
    A = raw_input().split()
    B = raw_input().split()

    A = set(A)
    B = set(B)

    lst1 = [value for value in ar if value in A]
    lst2 = [value for value in ar if value in B]

    print (len(lst1) - len(lst2))
