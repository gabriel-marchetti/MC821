import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BigInteger num1, num2;
        num1 = sc.nextBigInteger();
        num2 = sc.nextBigInteger();

        num2 = num2.multiply(BigInteger.valueOf(2));
        num2 = num2.add(BigInteger.valueOf(1));

        System.out.println(num2);

        sc.close();
    }
}