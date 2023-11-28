# Required parameters
alpha <- 2
beta <- 3
max_time <- 2.5  # maximum time in days
time_threshold <- 2  # two days

# Calculate the cumulative distribution function (CDF)
cdf_value <- pbeta(time_threshold / max_time, alpha, beta)

# Calculate the probability of requiring more than two days
probability_more_than_2_days <- 1 - cdf_value

# Print the result
print(probability_more_than_2_days)
