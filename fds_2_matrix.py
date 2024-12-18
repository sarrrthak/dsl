def matrix_addition(matrix_a, matrix_b):
    result = []
    for i in range(len(matrix_a)):
        row = []
        for j in range(len(matrix_a[i])):
            row.append(matrix_a[i][j] + matrix_b[i][j])
        result.append(row)
    return result

def matrix_subtraction(matrix_a, matrix_b):
    result = []
    for i in range(len(matrix_a)):
        row = []
        for j in range(len(matrix_a[i])):
            row.append(matrix_a[i][j] - matrix_b[i][j])
        result.append(row)
    return result

def matrix_multiplication(matrix_a, matrix_b):
    result = []
    for i in range(len(matrix_a)):
        row = []
        for j in range(len(matrix_b[0])):
            sum_product = sum(matrix_a[i][k] * matrix_b[k][j] for k in range(len(matrix_b)))
        row.append(sum_product)
    result.append(row)
    return result

def matrix_transpose(matrix):
    result = []
    for j in range(len(matrix[0])):
        row = []
        for i in range(len(matrix)):
            row.append(matrix[i][j])
        result.append(row)
    return result

# Sample matrices

matrix_a = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]
]

matrix_b = [
[9, 8, 7],
[6, 5, 4],
[3, 2, 1]
]

# a) Addition of two matrices

added_matrix = matrix_addition(matrix_a, matrix_b)
print("Addition of two matrices:")
for row in added_matrix:
    print(row)
    
# b) Subtraction of two matrices

subtracted_matrix = matrix_subtraction(matrix_a, matrix_b)
print("\nSubtraction of two matrices:")
for row in subtracted_matrix:
    print(row)
    
# c) Multiplication of two matrices

multiplied_matrix = matrix_multiplication(matrix_a, matrix_b)
print("\nMultiplication of two matrices:")
for row in multiplied_matrix:
    print(row)
    
# d) Transpose of a matrix

transposed_matrix_a = matrix_transpose(matrix_a)
print("\nTranspose of matrix A:")
for row in transposed_matrix_a:
    print(row)
