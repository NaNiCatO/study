package Lab7;

import Lab7.code.Coins;

public class Tester {
    public static void main(String[] args) {
        //ex1();
        int amount = 0;
        for (amount = 4; amount < 12; amount++) {
        System.out.println("amount " + amount + " uses " + minNumCoin(amount));
        // int [] minCoinResidual = new int[amount+1];
        // println("amount " + amount + " uses "+ minNumCoin(amount,minCoinResidual));
        }
    }

    static void ex1() {
        for (Coins c : Coins.values())
        System.out.println("Coin " + c + "s are ready ");
    
    }
    static int minNumCoin(int amount) {
        // System.out.println("call for " + amount);
        if (amount == 0) return 0; //base case
        int coinsNeeded = Integer.MAX_VALUE;
        int numCoin = 0;
        for (Coins c : Coins.values()) {
            if (c.value() <= amount) {
                numCoin = 1 + minNumCoin(amount - c.value());
                /* your code */
            }
    }
    
    /* equiv to below code */
    // int minP, minN, minD;
    // minP = minN = minD = 0;
    // if (amount >= Coins.PENNY.value()) {
    // minP = 1 + minNumCoin(amount - Coins.PENNY.value());
    // if (minP < coinsNeeded)
    // coinsNeeded = minP;
    // }
    // if (amount >= Coins.NICKEL.value()) {
    // minN = 1 + minNumCoin(amount - Coins.NICKEL.value());
    // if (minN < coinsNeeded)
    // coinsNeeded = minN;
    // }
    // if (amount >= Coins.DIME.value()) {
    // minD = 1 + minNumCoin(amount - Coins.DIME.value());
    // if (minD < coinsNeeded)
    // coinsNeeded = minD;
    // }
    return coinsNeeded;
    }
}
