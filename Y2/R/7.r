#Hw 7 Mean as a balance point
#Suvijuk Samitimata 65011558


# Custom function to calculate mean using the concept of moments
my.mean <- function(data) {
    # Initial guess for mean
    mx <- mean(data) 

    # loop that will continue as long as the sum of differences between "mx" and the data points is not equal to zero
    while (sum(mx - data) != 0) {

    # update the "mx" value by adding the sum of differences between the data points and the current "mx" value, 
    # divided by the number of data points
    mx <- mx + sum(data - mx) / length(data)
    }

    # return the final calculated value of "mx"
    return(mx)
}

# create vector of "data"
#data <- c(2, 7, 9)
data <- c(4.9, 6.8, 1.3, 7.4, 2.5)

# use the my.mean function store it in the custom_mean
custom_mean <- my.mean(data)

# use the built-in mean() function to calculate the mean store it in the built_in_mean variable
built_in_mean <- mean(data)

# print the result
cat("Custom Mean:", round(custom_mean, 2), "\n")
cat("Built-in Mean:", round(built_in_mean, 2), "\n")



x = c(2, 7, 9)
mx = seq(2, 9)
dif=0

for (i in 1:8){
    sum.diff=0

    for (j in 1:3){
        diff[i] = x[j] - mx[i]
        sum.diff = sum.diff+diff[i]
    }

    cat("sum.diff =",sum.diff,"\n","Mean =",mx[i],"\n\n")
}