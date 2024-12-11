def getdata():
	Club=[]
	n=int(input("Number of Members: "))
	print("Enter Club Member Roll No.")
	for i in range (n):
		Club.append(int(input("Enter Roll No.: " )))
	print("Club Members")
	print(Club)
	return Club

def swap(a,b):
	return b,a

def bubblesort(Club):
	n=len(Club)
	for i in range (n-1):
		for j in range (n-i-1):
			if Club[j]>Club[j+1]:
				Club[j],Club[j+1]=swap(Club[j],Club[j+1])

	print("Sorted!!")
	print(Club)
def Tsearch(Club):
	key=int(input("Enter Roll to Search: "))
	l=0
	h=len(Club)-1
	while (l <= h):
		mid1 = l + (h-l)//3
		mid2 = h - (h-l)//3
		if (key == Club[mid1]):
			return mid1
		elif (key == Club[mid2]):
			return mid2
		elif (key < Club[mid1]):
			h = mid1 - 1
		elif (key > Club[mid2]):
			l = mid2 + 1
		elif (key > Club[mid1] and key < Club[mid2]):
			l = mid1 + 1
			h = mid2 - 1
	return -1
			
Club=getdata()
bubblesort(Club)
while True:
	print("********MENU**********")
	print("1. Search Member")
	print("2. Exit")
	choice=int(input("Enter Choice: "))
	if choice==1:
		T=Tsearch(Club)
		if (T == -1):
			print("Not a Club Member")
		else:
			print("Club Member")
	elif choice ==2:
		break
	else:
		print("Invalid Entry!!") 
	
	
	
	

