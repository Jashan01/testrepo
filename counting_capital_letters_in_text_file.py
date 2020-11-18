file=open("text.txt", "r")
count=0
line=file.read()
words=line.split()
for i in words:
    if(i.isupper):
        count=count+1
print("The total capital letters found:",count)
