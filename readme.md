# Resolução do desafio C++
A solução que proponho é uma arquitetura de cliente servidor na linguagem C++ para ambientes linux.
O servidor é responsável por enviar a publicação de mensagens (padrão Publish/Subscribe do ZeroMQ), e o cliente escreve em ficheiro json a mensagem do tópico correspondente.

##Bibliotecas
As bibliotecas usadas para o desenvolvimento deste programa foram:
-ZeroMQ
-rapidjson

##Funcionamento do Programa
De forma a usar a biblioteca ZMQ simlificada e com menos probabilidade de erros, uso as funções declaradas em "zhelpers.hpp".
Ao receber os dados, o software deverá salvar em arquivos localmente
a mensagem recebida, com o nome do arquivo TIMESTAMP_DA_MENSAGEM.json.

##Observações
O tempo aproximado que demorei a desenvolver este programa foi aproximadamente 12 horas.
Mais de metade do tempo foi de pesquisa, porque nunca trabalhei com as bibliotecas recomendadas e tive que me habituar. Mas de um ponto de vista geral foi divertido e simples.
A maior dificuldade foi tornar o programa configurável pelo arquivo MODULO/resources/config/MODULO.properties. Não conheço esta arquitetura, de modo que criei um ficheiro simples config.conf para poder alterar o ip.

##Compilação e execução
