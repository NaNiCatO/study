# Given parameters
mean_lifetime <- 7000
std_deviation <- 600
time_threshold <- 5800

# Standardize the time threshold
z_score <- (time_threshold - mean_lifetime) / std_deviation

# Calculate the probability of failure before 5800 hours
probability_failure_before_5800 <- pnorm(z_score)

# Print the result
print(probability_failure_before_5800)