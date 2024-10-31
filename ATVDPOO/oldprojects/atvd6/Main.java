package atvd6;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        String nome = JOptionPane.showInputDialog("Informe seu nome: ");
        String valor = JOptionPane.showInputDialog("Informe seu salário: ");

        try {
            double salario = Double.parseDouble(valor);
            double salarioNovo = salario + (salario * 0.15);

            String mensagem = String.format(
                    "Olá %s, seu antigo salário era: R$ %.2f%n" +
                            "Seu novo salário com aumento de 15%% é: R$ %.2f",
                    nome, salario, salarioNovo
            );

            JOptionPane.showMessageDialog(null, mensagem);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Erro: valor inválido para salário.");
        }
    }
}
