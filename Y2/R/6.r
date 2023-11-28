#Hw 6 Mean and Variance of Conditional Joint Probability Function
#Suvijuk Samitimata 65011558

# Define the matrix and vectors
Joint <- matrix(c(0.01, 0.02, 0.25, 0.02, 0.03, 0.20, 0.02, 0.01, 0.05, 0.15, 0.10, 0.05), nrow = 4, ncol = 3, byrow = TRUE)
y <- c(1, 2, 3, 4)

# Calculate mean and variance for a given x
my.Matrix <- function(x) {
    margin <- apply(Joint, 2, sum)
    column_value <- Joint[, x]
    condition <- column_value / margin[x]
    mean_value <- sum(y * condition)
    variance_value <- sum((y - mean_value)^2 * condition)
    
    cat("-----------------------------------\n")
    cat("x =", x, "\n")
    cat("Mean =", mean_value, "\n")
    cat("Variance =", variance_value, "\n")
    cat("-----------------------------------\n")
}

# Calculate and print results for different x values
my.Matrix(1)
my.Matrix(2)
my.Matrix(3)



