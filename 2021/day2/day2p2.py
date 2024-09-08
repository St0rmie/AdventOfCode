from collections import defaultdict

# Open file
f = open("inputp2.txt", "r")

# Dictionary with values for positions
values = defaultdict(int)

# Loop through file
for line in f:
    splited = line.split(" ")

    if splited[0] == "down": # Down
        values["aim"] += int(splited[1])
    
    elif splited[0] == "up": # Up
        values["aim"] -= int(splited[1])
    
    else: # Forward
        values["horizontal"] += int(splited[1])
        values["depth"] += values["aim"] * int(splited[1])

# Print result
print(values["horizontal"] * values["depth"])
