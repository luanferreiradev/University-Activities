package Exercicio2ClasseAbstrata;

public class Caminhao extends Veiculo {
    public Caminhao(String placa, String marca, String modelo, int anoFabricacao) {
        super(placa, marca, modelo, anoFabricacao);
    }

    @Override
    public double calcularIPVA() {
        double valorEstimado = 50000 - (5000 * (2024 - getAnoFabricacao()));
        return valorEstimado * 0.015;
    }
}


