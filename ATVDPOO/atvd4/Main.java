package atvd4;

import javax.swing.*;
import java.time.Year;
import java.util.Locale;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        String inputName = JOptionPane.showInputDialog("Digite seu nome");
        String inputAge = JOptionPane.showInputDialog("Digite seu ano de nascimento");

        try {
            int birthYear = Integer.parseInt(inputAge);
            int currentYear = Year.now().getValue(); // Obtendo o ano atual
            int age = currentYear - birthYear;
            String mensagem = String.format("Você se chama %s e possui " +
                    "%d anos de idade!", inputName, age);
            JOptionPane.showInputDialog(null, mensagem);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Idade Invalida");
        }
    }
}
