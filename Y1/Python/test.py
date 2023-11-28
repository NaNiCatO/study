d = {
	"C++": 99.7,
	"C": 96.7,
	"Java": 97.5,
	"Python": 100,
	"C#": 97.5
}

def sort_rank(dict):
    new_dict = {}
    sortdict = sorted(dict.items(),key= lambda index :index[1],reverse=True)
    for i in range(len(sortdict)):
        if sortdict[i][1] == sortdict[i-1][1]:
            new_dict[i] = sortdict[i][0] + ", " + sortdict[i-1][0]
        else :
            new_dict[i+1] = sortdict[i][0]
    return new_dict

print(sort_rank(d))