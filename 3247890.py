N = int(input())
ctr = 1
string = ""

string_arr = []

for j in range(N):
    message = input()

    pass_len = len(message) - 1

    for i in range(pass_len):
        
        if i == 0:
            symbol = message[0]

        if message[i+1] == symbol:
            ctr += 1

        if i == pass_len - 1:
            ctr = str(ctr)
            string += (ctr + " " + symbol + " ")
            ctr = int(ctr)

            if message[-1] != message[-2]:
                pass

            else:
                ctr = 1
                string_arr.append(string)
                string = ""

        if (i ==  pass_len - 1) and (message[-1] != message[-2]):
            symbol = message[-1]
            ctr = 1
            ctr = str(ctr)
            string += (ctr + " " + symbol + " ")
            ctr = int(ctr)
            string_arr.append(string)
            string = ""
            
        elif message[i+1] != symbol:
            ctr = str(ctr)
            string += (ctr + " " + symbol + " ")
            ctr = int(ctr)
            symbol = message[i+1]
            ctr = 1

for i in range(len(string_arr)):
    print(string_arr[i])