#A towering problem in Kattis
#solution by: Kyle Latino
# Date: 2020.11.13

def main():
    # Read in the input
    heights = list(map(int, input().split()))
    # Find the two towers
    tower1 = max(heights)
    heights.remove(tower1)
    tower2 = max(heights)
    heights.remove(tower2)
    # Sort the remaining blocks
    heights.sort(reverse=True)
    # Print the towers and blocks
    print(tower1, tower2, heights[0], heights[1], heights[2], heights[3])

if __name__ == "__main__":
    main()
