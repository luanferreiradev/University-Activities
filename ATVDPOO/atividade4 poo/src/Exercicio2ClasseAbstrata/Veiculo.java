package Exercicio2ClasseAbstrata;

public abstract class Veiculo {
    private String placa;
    private String marca;
    private String modelo;
    private int anoFabricacao;

    public Veiculo(String placa, String marca, String modelo, int anoFabricacao) {
        this.placa = placa;
        this.marca = marca;
        this.modelo = modelo;
        this.anoFabricacao = anoFabricacao;
    }

    public int getAnoFabricacao() {
        return anoFabricacao;
    }

    public abstract double calcularIPVA();

    public void exibirDetalhes() {
        System.out.println("Placa: " + placa);
        System.out.println("Marca: " + marca);
        System.out.println("Modelo: " + modelo);
        System.out.println("Ano de Fabricação: " + anoFabricacao);
        System.out.println("IPVA: " + calcularIPVA());
    }
}

