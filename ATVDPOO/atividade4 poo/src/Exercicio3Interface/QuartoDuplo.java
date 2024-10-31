package Exercicio3Interface;

public class QuartoDuplo implements Acomodacao, ServicoAdicional {
    private static final double DIARIA = 180;
    private int numeroPessoas;
    private boolean cafeDaManha;
    private boolean limpezaExtra;

    public QuartoDuplo(int numeroPessoas, boolean cafeDaManha, boolean limpezaExtra) {
        this.numeroPessoas = numeroPessoas;
        this.cafeDaManha = cafeDaManha;
        this.limpezaExtra = limpezaExtra;
    }

    @Override
    public double calcularDiaria() {
        return DIARIA;
    }

    @Override
    public double calcularServico() {
        double total = 0;
        if (cafeDaManha) {
            total += 20 * numeroPessoas;
        }
        if (limpezaExtra) {
            total += 30;
        }
        return total;
    }

    @Override
    public void exibirDetalhes(int dias) {
        double custoTotal = (calcularDiaria() * dias) + calcularServico();
        System.out.println("Quarto Duplo");
        System.out.println("Custo Total: R$" + custoTotal);
    }
}

