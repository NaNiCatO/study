options (scipen=20)
my.Pi <- function (n){

    set.seed(558)
    x = runif(n ,min=0, max=1)
    y = runif(n)
    r = sqrt((x^2)+(y^2))
    num.circle.dots = sum(r<=1)
    num.square.dots = n
    ratio = num.circle.dots/num.square.dots
    my.pi = 4*ratio
    cat(my.pi,"\n")
    cat("difference =" ,abs(pi - my.pi) ,"\n")
    #plot(x,y,col=ifelse(r<=1,"red","blue"),asp=1,pch=20)

}

my.Pi(500000)
my.Pi(1000000)
my.Pi(2000000)