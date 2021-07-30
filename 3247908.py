arr = [["1", "2"], ["3", "4"]]

first = arr[0][0]
second = arr[0][1]
third = arr[1][0]
fourth = arr[1][1]

user_input = str(input())

for i in range(len(user_input)):
    if user_input[i] == "H":
        top_left = arr[0][0]
        bottom_left = arr[1][0]
        top_right = arr[0][1]
        bottom_right = arr[1][1]
        arr[0][0] = bottom_left
        arr[1][0] = top_left
        arr[0][1] = bottom_right
        arr[1][1] = top_right

    if user_input[i] == "V":
        top_left = arr[0][0]
        bottom_left = arr[1][0]
        top_right = arr[0][1]
        bottom_right = arr[1][1]
        arr[0][0] = top_right
        arr[0][1] = top_left
        arr[1][0] = bottom_right
        arr[1][1] = bottom_left

line1 = arr[0][0] + " " + arr[0][1]
line2 = arr[1][0] + " " + arr[1][1]
print(line1)
print(line2)