# Desafio C++

Esse desafio é a parte pratica, onde podemos analisar seu nível técnico, organização de código e arquitetura da solução.

O Desafio consiste em escrever um cliente e um servidor na linguagem C++ para ambientes linux utilizando as premissas solicitadas.

O Intuito do software servidor é enviar a publicação de mensagens (padrão Publish/Subscribe do ZeroMQ), e o cliente 
deverá se escrever no topico de qual o servidor disponibilizar, ao receber os dados, o software deverá salvar em arquivos localmente
a mensagem recebida, com o nome do arquivo TIMESTAMP_DA_MENSAGEM.json.

# Orientações

- Efetuar um Fork desse Repositório para sua conta do GitHub
- Fazer um Clone do seu Repositório
- Realizar o Teste
- Efetuar o Commit e o Push
- Solicitar um Pull Request

# Premissas:

 - A posta do servidor e do cliente deverá ser configurável pelo arquivo MODULO/resources/config/MODULO.properties
 - O Topico do Pub/Sub do servidor e cliente também deverá ser configurada pelo arquivo de configuração de ambos os módulos
 - Comunicação TCP

# Observações:

- Sistema Operacional Debian 9
- Poco C++
- ZeroMQ
- ZeroMQPP
- CMake

# O que você deve nos entregar após a conclusão do desafio:

1) Código-fonte de tudo que foi desenvolvido, esteja o software funcionando ou
não;
2) Makefile, CMakeLists ou linha de compilação;
3) Informações sobre quais bibliotecas e versões foram utilizadas;
4) Qual o tempo aproximado gasto no desenvolvimento do software;
5) E por último, não menos importante, quais a dificuldades que você enfrentou
no desafio

# Ponto Extra:
- Build sem Alertas de compilação
- Google Code Style