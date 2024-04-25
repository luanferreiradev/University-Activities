# Simulação de Operações Bancárias 💰🏦

## Enunciado

Você foi contratado para desenvolver um programa em C que simula operações bancárias básicas para clientes de um banco fictício. O programa deve permitir que os clientes realizem saques, depósitos e transferências de dinheiro entre contas.

![Operações Bancárias](img/Presentes%20criativos%20e%20muita%20variedade.jpeg)

O programa deve ser estruturado da seguinte forma:

1. **Struct Cliente**: Deve ser definida uma estrutura `Cliente` contendo os seguintes campos:
   - `nome`: uma string de até 50 caracteres para armazenar o nome do cliente.
   - `saldo`: um número de ponto flutuante para armazenar o saldo da conta do cliente.

2. **Função criarCliente**: Deve ser implementada uma função `criarCliente` que recebe como argumentos o nome do cliente e o saldo inicial da conta, e retorna um ponteiro para uma estrutura do tipo `Cliente`. Esta função deve alocar dinamicamente memória para o novo cliente, inicializar seus campos com os valores fornecidos e retornar o ponteiro para o cliente criado.

3. **Funcionalidades do Banco**: As seguintes funcionalidades devem ser implementadas como funções:
   - `sacar`: recebe um ponteiro para um cliente e um valor a ser sacado da conta. Esta função deve verificar se o saldo é suficiente para o saque e, se for o caso, realizar a operação deduzindo o valor do saldo do cliente.
   - `depositar`: recebe um ponteiro para um cliente e um valor a ser depositado na conta. Esta função deve adicionar o valor ao saldo do cliente.
   - `transferir`: recebe dois ponteiros para clientes (remetente e destinatário) e um valor a ser transferido da conta do remetente para a conta do destinatário. Esta função deve verificar se o saldo do remetente é suficiente para a transferência e, se for o caso, realizar a operação deduzindo o valor do saldo do remetente e adicionando ao saldo do destinatário.

4. **Teste do Programa**: No programa principal (`main`), crie pelo menos dois clientes para teste, realize algumas operações como saques, depósitos e transferências entre eles, e imprima os saldos resultantes.

5. **Liberação de Memória**: Não se esqueça de liberar a memória alocada para os clientes no final do programa.

Ao executar o programa, os clientes devem ser capazes de interagir com as funcionalidades bancárias, fornecendo seus nomes, realizando saques, depósitos e transferências de dinheiro conforme necessário.

Você deve garantir que seu código seja robusto o suficiente para lidar com situações como saldo insuficiente para saque ou transferência, além de verificar a correta alocação e liberação de memória para evitar vazamentos de memória.

6. **Contribuidores**: Se você contribuiu para este projeto, adicione seu nome e link para o seu perfil abaixo:
   - [Victor Davidson](https://github.com/vctrdavidsom)
   - [Rebeca Maria](https://github.com/rebecamariamg)
   - [João Gabriel](https://github.com/joaochecchia)
