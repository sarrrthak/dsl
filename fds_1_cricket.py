c=int(input("Enter no of student who play cricket:"))
cr=[]
for i in range(c):
    m=int(input("Enter roll no:"))
    cr.append(m)
print(cr)
#badminton:
B=int(input("Enter no of student who play badminton:"))
ba=[]
for i in range(B):
    d=int(input("Enter roll no:"))
    ba.append(d)
print(ba)
#football:
f=int(input("Enetr no of student who play football:"))
fo=[]
for i in range(f):
    r=int(input("Enter roll no:"))
    fo.append(r)
print(fo)
#a
def inter():
    n=[]
    for i in cr:
        for j in ba:
            if i==j:
                n.append(j)
    print("student who play cricket and badminton:",n)
inter()
#b
def union():
    s=[]
    for i in cr:
        if i not in ba:
            s.append(i)
    for j in ba:
        if j not in cr:
            s.append(j)
    print("student who play cricket and badminton but not both:",s)
union()
#c
def ncnb():
    ncb=[]
    for i in fo:
        if i not in ba:
            if i not in cr:
                ncb.append(i)
    print("student who play only football:",ncb)
ncnb()
#d
def cf():
    x=[]
    for i in cr:
        if i in fo:
            if i not in ba:
                x.append(i)
    print("student who play cricket and football:",x)
cf()
