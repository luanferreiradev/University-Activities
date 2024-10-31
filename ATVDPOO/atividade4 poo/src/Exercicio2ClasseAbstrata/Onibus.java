package Exercicio2ClasseAbstrata;

public class Onibus extends Veiculo {
    public Onibus(String placa, String marca, String modelo, int anoFabricacao) {
        super(placa, marca, modelo, anoFabricacao);
    }

    @Override
    public double calcularIPVA() {
        double valorEstimado = 100000 - (3000 * (2024 - getAnoFabricacao()));
        return valorEstimado * 0.02;
    }
}

