#Hw 3 Probability Distribution
#Suvijuk Samitimata 65011558

options (scipen=20)
 # deciding to print numeric value in fixed or exponential notation.
my.Prob_Dist <- function (n,chance){

    set.seed(558)
 # set a random seed
    x <- 0:n
 # generate a sequence of numbers from 0 to n into "x"
    probabilities <- dbinom(x, n, chance)
 # call function to calculate the mass probability into "probabilities"
    for (i in x){
        cat("P( x =",i,") =",probabilities[i+1],"\n")
    }
 # using for loop to print the value in "probabilities"


    distributed <- rbinom(100000, n, chance)
 # call function to calculate the empirical mean and variance into "distributed"
    cat("Empirical Mean :", mean(distributed), "\n")
 # print Empirical Mean using function mean()
    cat("Empirical Variance :", var(distributed), "\n")
 # print Empirical Variance using function var()


    probability <- pbinom(3, n, chance)
 # call function to calculate probability that have the most errors is 3, P(X <= 3) into "probability"
    cat("Probability that have the most errors is 3 :", probability, "\n")
 # print Probability that have the most errors is 3, P(X <= 3)


    barplot(probabilities, xlab = "transmitted channel", ylab = "probability", main = "Probability Distribution", names.arg = x, col = "lightblue")
#plot the grahp of probability distribution [x-axis is transmitted channel], [y-axis is mass probability], [main is the title], 
#[names.arg is a vector of names appearing under each bar], [col = color]

}

my.Prob_Dist(4,0.1)
