#HW 8 Statistical Mode
#Suvijuk Samitimata 65011558

my.mode <- function(data) {
  # Use the table() function to count the occurrences of each value
  value_counts <- table(data)

  # check if when data have multiple number and have same frequency
  if (max(value_counts) == min(value_counts) && length(unique(data)) > 1) {
     return("no mode")
  }

  # Find the maximum count
  max_count <- max(value_counts)
  
  # Find the values with the maximum count
  most_frequent_values <- names(value_counts[value_counts == max_count])
  
  # return value
  return(most_frequent_values)
}

# Sample data
data1 <- c(1, 2, 3, 4, 5)
data2 <- c(3, 3, 3, 3, 3)
data3 <- c(1, 2, 2, 3, 4, 4, 5)
data4 <- c(1, 1, 2, 2, 3, 3, 4, 4, 5)
data5 <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)

# Print the result
cat("data set : ", data1, "\nMode : ", my.mode(data1), "\n\n")
cat("data set : ", data2, "\nMode : ", my.mode(data2), "\n\n")
cat("data set : ", data3, "\nMode : ", my.mode(data3), "\n\n")
cat("data set : ", data4, "\nMode : ", my.mode(data4), "\n\n")
cat("data set : ", data5, "\nMode : ", my.mode(data5), "\n\n")