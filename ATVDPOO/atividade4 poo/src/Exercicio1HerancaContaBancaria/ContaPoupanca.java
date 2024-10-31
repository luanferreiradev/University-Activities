package Exercicio1HerancaContaBancaria;

public class ContaPoupanca extends ContaBancaria {
    private int diaRendimento;

    public ContaPoupanca(String cliente, String numeroConta, int diaRendimento) {
        super(cliente, numeroConta);
        this.diaRendimento = diaRendimento;
    }

    public void calcularNovoSaldo(double taxaRendimento) {
        double novoSaldo = getSaldo() + (getSaldo() * taxaRendimento / 100);
        depositar(novoSaldo - getSaldo());
    }
}

