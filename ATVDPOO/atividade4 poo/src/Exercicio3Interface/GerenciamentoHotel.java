package Exercicio3Interface;

public class GerenciamentoHotel {
    public static void main(String[] args) {
        Acomodacao quartoSimples = new QuartoSimples(2, true, false);
        Acomodacao quartoDuplo = new QuartoDuplo(3, false, true);
        Acomodacao suite = new Suite(4, true, true);

        int dias = 2; // Exemplo de dias
        quartoSimples.exibirDetalhes(dias);
        quartoDuplo.exibirDetalhes(dias);
        suite.exibirDetalhes(dias);
    }
}

