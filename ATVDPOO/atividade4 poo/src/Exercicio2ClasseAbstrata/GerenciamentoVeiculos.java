package Exercicio2ClasseAbstrata;

public class GerenciamentoVeiculos {
    public static void main(String[] args) {
        Veiculo carro = new Carro("ABC-1234", "Fusca", "Volkswagen", 1970);
        Veiculo caminhao = new Caminhao("DEF-5678", "Mercedes", "Actros", 2010);
        Veiculo onibus = new Onibus("GHI-9101", "Volvo", "B9R", 2015);

        carro.exibirDetalhes();
        caminhao.exibirDetalhes();
        onibus.exibirDetalhes();
    }
}

