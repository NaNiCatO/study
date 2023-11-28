#Hw 4 Empirical Rule of any Normal dist
#Suvijuk Samitimata 65011558


# Required parameters
shape <- 1
scale <- 300
time_threshold <- 4 * 60  # 4 minutes in seconds

# Calculate the cumulative distribution function (CDF)
cdf_value <- pweibull(time_threshold, shape, scale)

# Calculate the probability of spending more than four minutes
probability_more_than_4_minutes <- 1 - cdf_value

# Print the result
print(probability_more_than_4_minutes)
