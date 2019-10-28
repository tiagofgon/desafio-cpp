# Resolução do desafio C++
A solução que proponho é uma arquitetura de cliente servidor na linguagem C++ para ambientes linux.
O servidor é responsável por enviar a publicação de mensagens (padrão Publish/Subscribe do ZeroMQ), e o cliente escreve em ficheiro json a mensagem do tópico correspondente.

## Bibliotecas
As bibliotecas usadas para o desenvolvimento deste programa foram:
- **ZeroMQ**: Biblioteca necessária para tratar da comunicação pub/sub.
- **rapidjson**: Biblioteca usada para fazer parsing de ficheiros json.

## Funcionamento do Programa
De forma a usar a biblioteca ZMQ de uma forma simples e com menos probabilidade de erros, uso as funções declaradas em "zhelpers.hpp", fornecido pela ZMQ.
### Servidor
O servidor quando executado fica a correr num ciclo infinito. Envia a mensagem partida em 3 pedaços. O tópico, uma ordem que é um inteiro random e a mensagem propriamente dita que é composta por: Um id único, uma velocidade que é um inteiro entre 0 e 255 de forma random e um timestamp com o tempo que a velocidade foi criada.
### Cliente
O cliente subscreve uma mensagem com o tópico correspondente. De seguida escreve em ficheiro json a mensagem recebida composta por ID, velocidade e timestamp. O nome do ficheiro é o timestamp recebido, no formato: TIMESTAMP_DA_MENSAGEM.json.

## Compilação e execução
### Compilação
- $ make

### Execução
Para correr o servidor:
- $ ./servidor

Para correr um cliente:
$ ./cliente


## Observações
O tempo aproximado que demorei a desenvolver este programa foi aproximadamente 12 horas.
Mais de metade do tempo foi de pesquisa, porque nunca trabalhei com as bibliotecas recomendadas e tive que me habituar. Mas de um ponto de vista geral foi divertido e simples.
A maior dificuldade foi tornar o programa configurável pelo arquivo MODULO/resources/config/MODULO.properties. Não conheço esta arquitetura, de modo que criei um ficheiro simples config.conf para poder alterar o IP e o tópico das mensagens.
