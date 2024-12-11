def mat():
	row_num = int(input("Enter no. of rows: "))
	col_num = int(input("Enter no. of columns: "))
	matrix = [[0 for c in range(col_num)] for r in range(row_num)]
	for r in range(row_num):
		for c in range(col_num):
			matrix[r][c] = int(input(f"Enter no at [{r}] [{c}].: "))
	print("The resulting matrix is:")
	for row in matrix:
		print(row)
	return matrix
print("*****MATRIX_1*****")
matrix1=mat()
print("*****MATRIX_2*****")
matrix2=mat()

def summation():
	if len(matrix1[0])==len(matrix2[0]) and len(matrix1)==len(matrix2):
		matrix3 = [[0 for c in range(len(matrix1[0]))] for r in range(len(matrix1))]
		for r in range (len(matrix1)):
			for c in range (len(matrix1[0])):
				matrix3[r][c]=matrix1[r][c]+matrix2[r][c]
		print("Summation is:")
		for row in matrix3:
			print (row)
	else:
		print("Additinis not possible")
def subtraction():
	if len(matrix1[0])==len(matrix2[0]) and len(matrix1)==len(matrix2):
		matrix3 = [[0 for c in range(len(matrix1[0]))] for r in range(len(matrix1))]
		for r in range (len(matrix1)):
			for c in range (len(matrix1[0])):
				matrix3[r][c]=matrix1[r][c]-matrix2[r][c]
		print("Subtraction is:")
		for row in matrix3:
			print (row)
	else:
		print("Subraction is not possible")	
def Transpose(matrix):
    matrix4 = [[0 for c in range(len(matrix[0]))] for r in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix4[i][j]=matrix[j][i]
    for row in matrix4:
        print (row)	

def multiplication():
    matrix5 = [[0 for c in range(len(matrix2[0]))] for r in range(len(matrix1))]
    if len(matrix1[0])==len(matrix2):
        for i in range(len(matrix1)):
            for j in range(len(matrix2[0])):
                matrix5[i][j] = sum(matrix1[i][k] * matrix2[k][j] for k in range(len(matrix1[0])))
        return matrix5
    else:
        return ("Matrix Can't be Multiplied")
while True:
    print("**************MENU*************")
    print("1. Addition of two matrix")
    print("2. Subtraction of two matrix")
    print("3. Multiplication of two matrix")
    print("4. Transpose of Matrix 1")
    print("5. Transpose of Matrix 2")
    print("6. Exit")
    choice=int(input("Enter Your Choice: "))
    if choice==1:
        summation()
    elif choice==2:
        subtraction()
    elif choice==3:
        result=multiplication()
        if isinstance(result, list): 
            print("Multiplication is")
            for row in result:
                print(row)
        else:
            print(result)
    elif choice==4:
        print("Transpose of Matrix 1")
        Transpose(matrix1)
    elif choice==5:
        print("Transpose of Matrix 2")
        Transpose(matrix2)
    elif choice==6:
        break
    else:
        print("Enter a valid input.")

