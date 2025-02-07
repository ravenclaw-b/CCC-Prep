import os

location = r"C:\\Users\bamdad\Documents\\CCC Prep"
day = 1

while (os.path.exists(f"{location}\\Day {day}")):
    day += 1

os.makedirs(f"{location}\\Day {day}")