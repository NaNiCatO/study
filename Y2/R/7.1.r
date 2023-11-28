#Hw 7 Mean as a balance point
#Suvijuk Samitimata 65011558

my.mean <- function(data) {
  # generating a sequence of trial mean values (mx_values) using the "seq" function
  mx_values <- seq(min(data), max(data), by = 0.01)  
  
  # initiates a loop that iterates through each value in the mx_values sequence
  for (mx in mx_values) {
    # Calculate the sum of differences
    sum.diff <- sum(data - mx)  
    
    # Check if the sum of differences is close to zero
    if (abs(sum.diff) < 0.01) {  
      
      # print the result
      cat("sum.diff =", sum.diff, "\n")
      cat("Mean =", mx, "\n")
      
      # Stop the loop if the sum of differences is close to zero
      break  
    }
  }
}

# create vector of "data"
#data <- c(2, 7, 9)
data <- c(4.9, 6.8, 1.3, 7.4, 2.5)

#call function my.mean
my.mean(data)

# Compare with built-in mean function
built_in_mean <- mean(data)
cat("Built-in mean =", round(built_in_mean, 2), "\n")
