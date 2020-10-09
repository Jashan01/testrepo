#List taken from the user and sorted using insertion sort.

print("Enter the list you want to sort(with spaces)")
l=list(map(int,input().split()))
n=len(l)
print("The list you entered: ",l)

for i in range(1,n):
    value = l[i]
    pos=i
    while pos>0 and value<l[pos-1]:
        l[pos]=l[pos-1]
        pos=pos-1
    l[pos]=value
print("The sorted list: ",l)
