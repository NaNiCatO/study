# Given parameters
mean_log <- 0.5
sd_log <- 1
time_threshold <- 10

# Calculate the cumulative probability of the lognormal distribution
probability_more_than_10_seconds <- 1 - plnorm(time_threshold, mean_log, sd_log)

# Print the result
print(probability_more_than_10_seconds)