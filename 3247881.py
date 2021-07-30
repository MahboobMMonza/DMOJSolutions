switch = True
arr_pos = []
arr_time = []
arr_speed = []

dict = {}

N = int(input())

for i in range(N):
    obs = input()

    data = obs.split()

    time = int(data[0])
    arr_time.append(time)
    
    pos = int(data[1])

    dict.update({time : pos})

arr_time.sort()

if N == 1:
    speed = pos / time
    arr_speed.append(speed)

else:
    for i in range(len(arr_time) - 1):

        differ_pos = (dict[arr_time[i+1]]) - (dict[arr_time[i]])
        differ_time = (arr_time[i+1]) - arr_time[i]
        speed = differ_pos / differ_time

        if speed < 0:
            speed *= -1
                       
        arr_speed.append(speed)

arr_speed.sort()

print(arr_speed[-1])