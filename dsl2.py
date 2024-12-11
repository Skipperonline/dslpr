str1=input("Enter String: ")
wrd=[]
wrd=str1.split()
print(wrd)

def longg():
	longest_word=""
	for words in wrd:
		if len(words)>len(longest_word):
			longest_word=words
	print("Longest word: ",longest_word)

def charecter():
	ch=input("Enter Char: ")
	count=0
	for chare in str1:
		if ch==chare:
			count+=1
	print("occurence of Character",ch,": ",count)
	 
def freqW():
	freq={}
	for wrds in wrd:
		if wrds in freq:
			freq[wrds]+=1
		else:
			freq[wrds]=1
	print(freq)
		
def palindrome():
	str2=str1[::-1]
	if (str1==str2):
		print("Its an Palindrome")
	else:
		print("Not a Palindrome")
		
def IndexF():
	substring=input("Enter Substring to find")
	for i in range (len(str1)-len(substring)+1):
		if (str1[i : i+len(substring)]==substring):
			return i
	return -1

while True:
	print("*******************Menu*****************")
	print("1.Find Longest word")
	print("2.ocuurence of particular character")
	print("3.check Palindrome")
	print("4.index of first apperance of subset")
	print("5.Freq. of each word")
	print("6.Exit")
	choice=int(input("Enter Your choice: "))
	if choice==1:
		longg()
	if choice==2:
		charecter()
	if choice==3:
		palindrome()
	if choice==4:
		index=IndexF()
		if(index==-1):
			print("Substring is not Present")
		else:
			print("Substring present at: ",index)
	if choice==5:
		freqW()
	if choice==6:
		break
		
		
		
		

