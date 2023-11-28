#Hw 4 Empirical Rule of any Normal dist
#Suvijuk Samitimata 65011558


options (scipen=20)

q6 <- function(time_threshold, shape, scale){

    # Calculate the cumulative distribution function (CDF)
    cdf_value <- pweibull(time_threshold, shape, scale)

    # Calculate the probability of spending more than four minutes
    probability_more_than_4_minutes <- 1 - cdf_value

    # Print the result
    print(probability_more_than_4_minutes)
}


q7 <- function(max_time, alpha, beta){

    # Calculate the cumulative distribution function (CDF)
    cdf_value <- pbeta(alpha / max_time, alpha, beta)

    # Calculate the probability of requiring more than two days
    probability_more_than_2_days <- 1 - cdf_value

    # Print the result
    print(probability_more_than_2_days)
}


q8 <- function(mean_lifetime, time_interval){

    # Calculate the rate parameter
    rate <- 1 / mean_lifetime

    # Calculate the probability of failure in the next three years (memoryless property)
    probability_failure_in_next_3_years <- 1 - exp(-rate * time_interval)

    # Print the result
    print(probability_failure_in_next_3_years)
}


q9 <- function(time_threshold, mean_lifetime, std_deviation){

    # Standardize the time threshold
    z_score <- (time_threshold - mean_lifetime) / std_deviation

    # Calculate the probability of failure before 5800 hours
    probability_failure_before_5800 <- pnorm(z_score)

    # Print the result
    print(probability_failure_before_5800)
}


q10 <- function(time_threshold, mean_log, sd_log){
    
    # Calculate the cumulative probability of the lognormal distribution
    probability_more_than_10_seconds <- 1 - plnorm(time_threshold, mean_log, sd_log)

    # Print the result
    print(probability_more_than_10_seconds)
}


print("=========6==========")
q6(4 * 60, 1, 300)
print("=========7==========")
q7(2.5, 2, 3)
print("=========8==========")
q8(6, 3)
print("=========9==========")
q9(5800, 7000, 600)
print("=========10=========")
q10(10, 0.5, 1)
print("====================")