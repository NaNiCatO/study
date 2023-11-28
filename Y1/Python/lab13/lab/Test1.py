import pickle
outfile1 = open("Datafile.dat", "rb")
print(pickle.load(outfile1))