#HW 12 Central Limit Theorem (CLT.)
#Suvijuk Samitimata 65011558

# initializes a variable x.bar with the value 0
x.bar = 0 

# generates a random sample of size 700 from a chi-squared distribution with 4 degrees of freedom
popu.x <- rchisq(n=3000, df=17)

# iterate 3000 times
for(i in 1:3000){
    # takes a random sample of size 80 from the popu.x dataset with replacement
    samp.x = sample(popu.x, size=80, replace=TRUE)
    # calculates the sample mean of the samp.x dataset and stores it in the x.bar vector
    x.bar[i] = mean(samp.x)
}

# creates a histogram of the popu.x dataset
#hist(popu.x)
# creates a histogram of the x.bar vector
hist(x.bar)

# calculates and prints the mean of the x.bar vector.
cat("mean(x.bar) = \t", mean(x.bar), "\n")
#  calculates and prints the mean of the popu.x dataset.
cat("mean(popu.x) = \t", mean(popu.x), "\n")

# calculates and prints the standard deviation of the x.bar vector.
cat("sd(x.bar) = \t\t", sd(x.bar), "\n")
# calculates and prints the standard error of the mean for the popu.x dataset.
cat("sd(popu.x)/sqrt(80) = \t", sd(popu.x)/sqrt(80), "\n")