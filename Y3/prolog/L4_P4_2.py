from pyswip import Prolog

# Initialize Prolog interpreter
prolog = Prolog()

# Consult the external Prolog file
prolog.consult("L4_P4_1.pro")

# Query Prolog for all animals
print("Animals in the knowledge base:")
for result in prolog.query("animal(Animal)"):
    print(f"Animal: {result['Animal']}")
