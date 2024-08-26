package atvd2;

import javax.swing.*;
import java.util.Locale;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        String input = JOptionPane.showInputDialog("Digite o raio do circulo:ex(R²)");
        try {
            double raio = Double.parseDouble(input);

            double area = Math.PI * Math.pow(raio, 2);
            String mensagem = String.format("Área: %.4f", area);
            JOptionPane.showMessageDialog(null, mensagem);
        } catch (NumberFormatException e) {
            JOptionPane.showInputDialog(null, "Valor Invalido");
        }
    }
}
