n, x =map(int,input().split())
s = input()
i = 0
new = ""
while i<n:
    if i+1 < n:
        if s[i] == 'L' or s[i] == 'R' and s[i+1] == 'U':
            i+=2
        else:
            new+=s[i]
            i+=1
    else:
        new+=s[i];
        i+=1
print(new)

for i in new:
    if i == 'U':
        if x!=1:
            x//=2
    elif i == 'R':
        x*=2
        x+=1
    else:
        x*=2
print(x);
