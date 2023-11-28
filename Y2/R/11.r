
diameter <- c(8.24, 8.25, 8.20, 8.23, 8.24, 8.21, 8.26, 8.26, 8.20, 8.25, 8.23, 8.23, 8.19, 8.28, 8.24)

t_test_result = t.test(diameter, mu=8.25,alter="greater")

print(t_test_result)

alpha <- 0.05  # Set significance level
# Check if the p-value is less than alpha
if (t_test_result$p.value < alpha) {
  cat("Reject the null hypothesis. The sample mean is significantly greater than 8.25.\n")
} else {
  cat("Fail to reject the null hypothesis. There is not enough evidence to conclude that the sample mean is significantly greater than 8.25.\n")
}
