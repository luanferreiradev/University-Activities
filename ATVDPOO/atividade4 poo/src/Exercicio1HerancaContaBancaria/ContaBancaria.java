package Exercicio1HerancaContaBancaria;

public class ContaBancaria {
    private String cliente;
    private String numeroConta;
    private double saldo;

    public ContaBancaria(String cliente, String numeroConta) {
        this.cliente = cliente;
        this.numeroConta = numeroConta;
        this.saldo = 0.0;
    }

    public void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
        } else {
            System.out.println("Saldo insuficiente!");
        }
    }

    public void depositar(double valor) {
        saldo += valor;
    }

    public double getSaldo() {
        return saldo;
    }

    public String getCliente() {
        return cliente;
    }

    public String getNumeroConta() {
        return numeroConta;
    }
}
