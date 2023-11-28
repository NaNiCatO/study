#HW 10 Interval Estimation
#Suvijuk Samitimata 65011558


# Define a custom function called 'int.est' with two parameters.
int.est = function(x,conf) {
    # Calculate the area for the confidence interval.
    area = (conf/100)+((1-(conf/100))/2)

    # Calculate the standard error of the sample 'x'.
    se = sd(x)/sqrt(length(x))

    # Calculate the margin of error using the t-distribution.
    margin = qt(area, length(x)-1)*se

        # Calculate the lower bounds of the confidence interval.
        lower = mean(x) - margin
        # Calculate the upper bounds of the confidence interval.
        upper = mean(x) + margin

    # Print the result
    cat("lower=",lower,"upper",upper)
}

score = c(83,73,62,63,71,77,77,59,92)
int.est(score,95)

# used to obtain the confidence interval associated with the results of a t-test 
cat("\n  ",t.test(score)$conf.int)

