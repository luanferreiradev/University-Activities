package atvd5;

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        System.out.println("Informe o nome do produto: ");
        String produto = sc.nextLine();
        System.out.println("Informe o volor do produto: ");
        double valor = sc.nextDouble();
        System.out.println("Informe o desconto do produto: ");
        sc.nextLine();
        double desconto = sc.nextDouble();

        double valorFinal = valor - desconto;
        System.out.printf(produto + " Antigo valor: %.3f" + " Novo Valor: %.3f%n", valor, valorFinal);

        sc.close();
    }
}
