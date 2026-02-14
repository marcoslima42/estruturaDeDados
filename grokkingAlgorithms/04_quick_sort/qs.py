def quicksort(array):
    #base case
    if len(array) < 2:
        return array
    else:
        #recursive case, breaking the problem
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]

        return quicksort(less) + [pivot] + quicksort(greater)


array = [10, 5, 2, 3, 100]

ans = quicksort(array)
print(ans)
