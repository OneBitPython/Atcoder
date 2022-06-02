s = input()
ok1 = 0;
ok2 = 0
for i in s:
    if i.islower():ok1 = 1;
    if i.isupper():ok2 = 1;
ok3 = 0
se = set()
for i in s:
    se.add(i);
if(len(se) == len(s) and ok1 and ok2):print("Yes")
else: print("No")