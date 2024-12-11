percentage=[]
selsort=[]
def getdata(percentage):
	n=int(input("Number of Students: "))
	print("Enter Student Percentage")
	for i in range (n):
		percentage.append(float(input("Enter Percentage of Student: " )))
	print("percentage of students")
	print(percentage)
	return n

def swap(a,b):
	return b,a
	
def bubblesort(n):
	global percentage
	for i in range (n-1):
		for j in range (n-i-1):
			if percentage[j]>percentage[j+1]:
				percentage[j],percentage[j+1]=swap(percentage[j],percentage[j+1])
	print("Sorted!!")
	print(percentage)

def selection_sort(n):
    global selsort
    for i in range(0,n - 1):
        for j in range(i + 1, n):
            if selsort[j] < selsort[i]:
                selsort[i], selsort[j] = swap(selsort[i], selsort[j])
    print("Sorted!!")
    print(selsort)

def top5(percentage):
	percentage.reverse()
	print(percentage[0:5])
	

while True:
	print("**************MENU****************")
	print("1. Bubble Sort")
	print("2. Selection Sort")
	print("3. Top 5 Scores using Bubble Sort")
	print("4. Top 5 Scores using selection Sort")
	print("5. Exit")
	choice=int(input("Enter Your Choice: "))
	if choice==1:
		n=getdata(percentage)
		bubblesort(n)
	if choice==2:
		n=getdata(selsort)
		selection_sort(n)
	if choice==3:
		top5(percentage)
	if choice==4:
		top5(selsort)
	if choice==5:
		break
 
