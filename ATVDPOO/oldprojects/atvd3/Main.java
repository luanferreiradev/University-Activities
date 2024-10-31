package atvd3;

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        System.out.println("Informe o numero de horas trabalhadas: ");
        double horasTrabalhadas = sc.nextDouble();
        System.out.println("Informe o quanto recebe por horas trabalhadas: ");
        double horasRecebem = sc.nextDouble();

        double salario = horasTrabalhadas * horasRecebem;
        System.out.printf("%.2f", salario);
        sc.close();
    }
}
