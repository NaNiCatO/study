#Hw 4 Empirical Rule of any Normal dist
#Suvijuk Samitimata 65011558

options (scipen=20)
 # deciding to print numeric value in fixed or exponential notation.
my.Normal_Distributions <- function (mean,sd){

    set.seed(558)
 # set a random seed
    X <- rnorm(10000000, mean, sd)
 # call function to  to simulate data from a normal distribution 10_000_000 samples

    p_68 <- (sum((mean-sd) < X & X < (mean+sd)))/10000000
 # calculate probability under curve (68%) using Empirical Rule : P( (mean-sd) < X < (mean+sd))
    cat("area (probability) under curve 0.68 :", p_68, "\n")
 # print probability under curve (68%)

    p_95 <- (sum( (mean-(2*sd)) < X & X < (mean+(2*sd) )))/10000000
 # calculate probability under curve (95%) using Empirical Rule : P( (mean-2*sd) < X < (mean+2*sd))
    cat("area (probability) under curve 0.95 :", p_95, "\n")
 # print probability under curve (95%) 

    p_997 <- (sum( (mean-(3*sd)) < X & X < (mean+(3*sd) )))/10000000
 # calculate probability under curve (997%) using Empirical Rule : P( (mean-3*sd) < X < (mean+3*sd))
    cat("area (probability) under curve 0.997 :", p_997, "\n")
 # print probability under curve (997%) 
    cat("-------------------------------------------------------\n")
}

my.Normal_Distributions(14, 5)
my.Normal_Distributions(3, 15)
my.Normal_Distributions(10, 20)
my.Normal_Distributions(20, 20)
my.Normal_Distributions(1, 200)