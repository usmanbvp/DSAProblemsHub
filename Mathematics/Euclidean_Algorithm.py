@@ -0,0 +1,15 @@
def GCD(a,b):
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    return a
c = int(input())
d = int(input())
print(GCD(c,d))
#input
#24
#30
#output
#6
