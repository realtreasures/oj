

x=int(input())

y=2**x-1



s=str(y)
print(len(s))
if len(s)<500:
    s='0'*(500-len(s))+s
    for i in range(len(s)):
        if(i%50==0):
            print()
        print(s[i],end='')

else:
    for i in range(500):
        if(i%50==0):
            print()
        print(s[len(s)-1-i],end='')
