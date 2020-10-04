myfile=open("text.txt","r")
def countmy():
    i=0
    str=myfile.read()
    str2=str.split()
    for a in range(len(str2)):
        if str2[a]=="Better":
            i=i+1
    print("'Better' occurs",i,"times.")        
    
            
countmy()   
