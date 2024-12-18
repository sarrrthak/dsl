def binary_search(arr, target): 
    low, high = 0, len(arr) - 1 
    
    while low <= high: 
        mid = (low + high) // 2 
        
        if arr[mid] == target: 
            return True 
        elif arr[mid] < target: 
            low = mid + 1
        else:
            high = mid - 1
    return False

def fibonacci_search(arr, target):
    n = len(arr)
    fibM2 = 0 
    fibM1 = 1 
    fibM = fibM1 + fibM2
    
    while fibM < n: 
        fibM2 = fibM1 
        fibM1 = fibM
        fibM = fibM1 + fibM2
        offset = -1
        
    while fibM > 1:
        i = min(offset + fibM2, n - 1)
        if arr[i] < target: 
            fibM = fibM1 
            fibM1 = fibM2
            fibM2 = fibM - fibM1 
            offset = i 
        elif arr[i] > target: 
            fibM = fibM2 
            fibM1 -= fibM2 
            fibM2 = fibM - fibM1 
        else:
            return True
        
    if fibM1 and arr[offset + 1] == target:
        return True
    return False

students_sorted = [9, 12, 23, 33, 45, 67]
roll_number = int(input("Enter roll number to search: "))

print("Binary Search Result:", binary_search(students_sorted, roll_number)) 
print("Fibonacci Search Result:", fibonacci_search(students_sorted, roll_number))
