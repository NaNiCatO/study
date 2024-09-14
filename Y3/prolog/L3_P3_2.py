from pyswip import Prolog
import turtle

# Initialize Prolog
prolog = Prolog()

# Consult the Prolog file with the drawTree/2 predicate
prolog.consult("L3_P3_1.pro")

# Query the tree drawing instructions for size 25
result = list(prolog.query("drawTree(25, L)"))

print("Result:", result)
# Extract the list of instructions (L) from the result
# steps = result[0]['L']

# Function to draw based on instructions

