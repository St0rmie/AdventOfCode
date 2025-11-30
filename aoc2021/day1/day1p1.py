import math

# Open file
f = open("inputp1.txt", "r")

# First value as infinite to compare
previous = math.inf

# Counter for increased values
counter_increased = 0

# Loop through file
for line in f:
    if int(line) > previous:
        counter_increased += 1
    previous = int(line)

# Print result
print(counter_increased)