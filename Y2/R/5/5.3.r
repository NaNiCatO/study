#Hw 4 Empirical Rule of any Normal dist
#Suvijuk Samitimata 65011558


# Given parameters
mean_lifetime <- 6
time_interval <- 3

# Calculate the rate parameter
rate <- 1 / mean_lifetime

# Calculate the probability of failure in the next three years (memoryless property)
probability_failure_in_next_3_years <- 1 - exp(-rate * time_interval)

# Print the result
print(probability_failure_in_next_3_years)
