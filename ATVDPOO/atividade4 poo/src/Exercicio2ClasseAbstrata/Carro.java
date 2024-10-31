package Exercicio2ClasseAbstrata;

public class Carro extends Veiculo {
    public Carro(String placa, String marca, String modelo, int anoFabricacao) {
        super(placa, marca, modelo, anoFabricacao);
    }

    @Override
    public double calcularIPVA() {
        double valorEstimado = 20000 - (2000 * (2024 - getAnoFabricacao()));
        return valorEstimado * 0.04;
    }
}

