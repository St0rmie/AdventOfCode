import math
from queue import Queue

"""
Sum all the values in the queue.
"""
def sum_queue(queue):
    sum = 0
    for i in list(queue.queue):
        sum += i
    return sum

"""
Updates sliding window removing last value and adding new value.
"""
def update_window(queue, new_value):
    queue.get()
    queue.put(new_value)

# Open file
f = open("inputp1.txt", "r")

# First value as infinite to compare
previous = math.inf

# Counter for increased values
counter_increased = 0

# Queue for sliding window
q = Queue(maxsize=3)

# Loop through file
for line in f:
    if q.qsize() < 2: # Fill the queue
        q.put(int(line))

    elif q.qsize() == 2: # First fill of the queue
        q.put(int(line))
        sum_q = sum_queue(q)
        if sum_q > previous:
            counter_increased += 1
        previous = sum_q

    else: # Sliding window
        update_window(q, int(line))
        sum_q = sum_queue(q)
        if sum_q > previous:
            counter_increased += 1
        previous = sum_q

# Print result
print(counter_increased)