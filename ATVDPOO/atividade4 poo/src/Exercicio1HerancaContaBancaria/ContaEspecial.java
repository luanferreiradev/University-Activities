package Exercicio1HerancaContaBancaria;

public class ContaEspecial extends ContaBancaria {
    private double limite;

    public ContaEspecial(String cliente, String numeroConta, double limite) {
        super(cliente, numeroConta);
        this.limite = limite;
    }

    @Override
    public void sacar(double valor) {
        if (valor <= (getSaldo() + limite)) {
            depositar(-valor);
        } else {
            System.out.println("Limite excedido!");
        }
    }
}
