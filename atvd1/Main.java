package atvd1;

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        int[] numbers = new int[5];
        int sum = 0;
        for (int i = 0; i < numbers.length; i++) {
            System.out.println("Digite um numero: ");
            numbers[i] = sc.nextInt();
            sum += numbers[i];
        }

        for (int i = 0; i < numbers.length; i++) {
            System.out.printf("%d ", numbers[i]);
        }
        int media = sum / numbers.length;
        System.out.printf("%n%d ", media);

        sc.close();
    }
}