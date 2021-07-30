k = int(input())
a = ""
list1 = ["*", "x", " "]
list1[0] = list1[0] * k
list1[1] = list1[1] * k
list1[2] = list1[2] * k

for i in range(k):
    print(list1[0] + list1[1] + list1[0])
for i in range(k):
    print(list1[2] + list1[1] + list1[1])
for i in range(k):
    print(list1[0] + list1[2] + list1[0])