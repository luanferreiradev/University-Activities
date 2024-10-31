package Exercicio1HerancaContaBancaria;

public class Contas {
    public static void main(String[] args) {
        ContaPoupanca contaPoupanca = new ContaPoupanca("João", "12345", 15);
        ContaEspecial contaEspecial = new ContaEspecial("Maria", "67890", 500);

        contaPoupanca.depositar(1000);
        contaPoupanca.calcularNovoSaldo(1.5);
        System.out.println("Saldo Conta Poupança: " + contaPoupanca.getSaldo());

        contaEspecial.depositar(300);
        contaEspecial.sacar(700);
        System.out.println("Saldo Conta Especial: " + contaEspecial.getSaldo());
    }
}
