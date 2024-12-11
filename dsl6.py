def getdata():
    pcent = []
    n = int(input("Number of Students: "))
    print("Enter Student Percentages:")
    for i in range(n):
        pcent.append(int(input(f"Enter Percentage for Student {i + 1}: ")))
    print("Entered Percentages:", pcent)
    return pcent

def partition(pcent, l, h):
    pivot = pcent[l]
    i = l + 1
    j = h
    while True:
        while i <= h and pcent[i] < pivot:
            i += 1
        while pcent[j] > pivot:
            j -= 1
        if i < j:
            pcent[i], pcent[j] = pcent[j], pcent[i]
        else:
            break
    pcent[l], pcent[j] = pcent[j], pcent[l]
    return j

def quicksort(pcent, l, h):
    if l < h:
        pos = partition(pcent, l, h)
        quicksort(pcent, l, pos - 1)
        quicksort(pcent, pos + 1, h)

pcent = getdata()
while True:
    print("\n*********** MENU **********")
    print("1. Quick Sort")
    print("2. Exit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        quicksort(pcent, 0, len(pcent) - 1)
        print("Sorted Percentages:")
        print(pcent)
    elif choice == 2:
        print("Exiting program.")
        break
    else:
        print("INVALID INPUT! Please choose a valid option.")

