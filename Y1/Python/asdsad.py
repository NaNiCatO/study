popularity_score = {
	"C++": 99.7,
	"C": 96.7,
	"Java": 97.5,
	"Python": 100,
	"C#": 97.5,
    "A" : 100
}

sorted_x = sorted(popularity_score.items(), key=lambda kv: kv[1])
print(sorted_x)
print(sorted_x[-1])