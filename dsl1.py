n=int(input("Enter number of Students: "))
list=[]
freq={}
print("Highest marks: 100")
print("Lowest Marks: 0")
print("Enter -1 for absent Student")
for i in range (1,n+1):
	marks=int(input("Enter Marks: "))
	list.append(marks)
print(list)

def Absent():
	absent=0
	for score in list:
		if (score==-1):
			absent+=1
	print("No. of Absent Students: ",absent)
			
def Average():
	absent=0
	for score in list:
		if (score==-1):
			absent+=1
	summ=0	
	for item in list: 
		if (item==-1):
			continue
		summ += item
	Avg=summ/(n-absent)
	print("Average Marks: ",Avg)

def High_Marks():
	high=0
	for maximum in list:
		if (maximum != -1):
			if (maximum>high):
				high=maximum
	print("Highest Marks: ",high)
	return high

def Low_Marks():
	low = 100
	for minimum in list:
		if (minimum != -1):
			if (minimum<low):
				low=minimum
	print("lowest Marks: ",low)
	
def High_f():
	countH=0
	x=High_Marks()
	for highest_f in list:
		if (highest_f==x):
			countH += 1
	print(x," : ",countH)

def marks_freq():
	for mark_f in list:
		if mark_f in freq:
			freq[mark_f] += 1
		else:
			freq[mark_f] = 1
	print("Frequency of each Mark: \n",freq)      
    
def HMarks():
	Max=[]
	max_value=max(freq.values())
	for keys in freq:
		if(keys != -1 ):
			if (freq[keys]==max_value):
				Max.append(keys)
	print("Marks with Highest Frequency: ",Max)
		

while True:
	print("*******************MENU**********************")
	print("Choose which operation to perform")
	print("1. Average of Class")
	print("2. Highest Marks")
	print("3. Lowest Marks")
	print("4. Frequency of Highest Marks")
	print("5. Frequency of Each Mark")
	print("6. Marks with Highest Frequency")
	print("7. No. Absent Students")
	print("8. Exit")
	choice=int(input())
	if (choice==1):
		Average()
	if (choice==2):
		High_Marks()
	if (choice==3):
		Low_Marks()
	if (choice==4):
		High_f()
	if (choice==5):
		marks_freq()
	if (choice==6):
		HMarks()
	if (choice==7):
		Absent()	
	if (choice==8):
		break

