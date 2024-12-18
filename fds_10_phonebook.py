def binary_search_recursive(phonebook, name, low, high):
    if low > high:
        return -1
    mid = (low + high) // 2   
    if phonebook[mid][0] == name:
        return mid
    elif phonebook[mid][0] > name:
        return binary_search_recursive(phonebook, name, low, mid-1)
    else:
        return binary_search_recursive(phonebook, name, mid + 1, high)

def binary_search_non_recursive(phonebook, name):
    low, high = 0, len(phonebook) - 1
    while low <= high:
        mid = (low + high) // 2
        if phonebook[mid][0] == name:
            return mid
        elif phonebook[mid] [0] > name:
            high = mid - 1
        else:
            low = mid + 1
    return -1

def insert_friend(phonebook, name, number):
    index = binary_search_non_recursive(phonebook, name)
    if index == -1:
        phonebook.append((name, number))
        phonebook.sort(key=lambda x: x[0])
        print(f"(name) added to phonebook.")
    else:
        print(f"{name} is already in the phonebook.")

def display_phonebook (phonebook):
    for name, number in phonebook:
        print(f"Name: {name}, Number: {number}")

phonebook = []

while True:
    print("\n1. Add Friend")
    print("2. Search Friend")
    print("3. Display Phonebook")
    print("4. Exit")
    choice = input("Enter your choice: ")

    if choice == '1':
        name = input("Enter friend's name: ")
        number = input("Enter friend's mobile number: ")
        insert_friend(phonebook, name, number)
    elif choice == '2':
        name_to_search = input("Enter the name to search: ")
        index = binary_search_recursive(phonebook, name_to_search, 0, len(phonebook) - 1)
        if index != -1:
            print(f"{name_to_search} found in phonebook at index {index}.")
        else:
            print(f"{name_to_search} not found in phonebook.")
    elif choice == '3':
        print("\nPhonebook:")
        display_phonebook(phonebook)
    elif choice == '4':
        break
    else:
        print("Invalid choice. Please try again.")
