def linear_search(arr, target): 
    for i in range(len(arr)): 
        if arr[i] == target: 
            return True
    return False

def sentinel_search(arr, target):
    n = len(arr) 
    last = arr[-1]
    arr[-1] = target
    i = 0 
    while arr[i] != target: 
        i += 1
        
    arr[-1] = last
        
    if i < n - 1 or arr[-1] == target:
        return True 
    else: 
        return False
    
students_random = [23, 45, 12, 9, 67, 33]
roll_number = int(input("Enter roll number to search: "))
    
print("Linear Search Result:", linear_search(students_random, roll_number)) 
print("Sentinel Search Result:", sentinel_search(students_random, roll_number))
