from collections import defaultdict

# Open file
f = open("inputp2.txt", "r")

# Dictionary with values for positions
values = defaultdict(int)

# Loop through file
for line in f:
    splited = line.split(" ")
    values[splited[0]] += int(splited[1])

# Print result
print(values["forward"] * (values["down"] - values["up"]))
