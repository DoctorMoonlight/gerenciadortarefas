# Gerenciador de Tarefas
![Capa do trabalho](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/408af570-e754-4d26-8596-72ca5af8927d)


## 1.0 README

### 1.1 Apresentação do Problema
No mundo atual, a quantidade de afazeres e compromissos diários aumenta constantemente. Gerenciar tarefas diárias pode ser um desafio, especialmente quando se lida com múltiplas atividades e prazos. A falta de um sistema eficiente para organizar essas tarefas pode causar atrasos, esquecimentos e, consequentemente, a perda de produtividade. Esse projeto se propõe a resolver esses problemas com o auxílio de um gerenciador de tarefas, que tem o objetivo de ajudar o usuário a sistematizar seus compromissos.

### 1.2 Visão Geral da Solução
Gerenciar uma tarefa traz benefícios como evitar sobrecarga de trabalho e diminuir o tempo perdido com atividades de pouca importância. Por isso, a solução inclui funcionalidades para registrar novas tarefas, marcar tarefas como concluídas, apagar tarefas, adicionar etiquetas para melhor categorização, exibir um histórico de tarefas completadas e receber notificações de tarefas próximas. Essas funcionalidades asseguram que os usuários possam gerenciar suas atividades de forma prudente.

### 1.3 Estrutura do Projeto
A estrutura do projeto do gerenciador de tarefas é construída em C++ de maneira intuitiva, permitindo a facilidade na compreensão e manutenção do código.
 ```
gerenciador-de-tarefas/

│

├── bin/                           # Diretório para o executável

│   └── gerenciador-de-tarefas

│

├── build/                         # Diretório para arquivos de compilação

│

├── src/                           # Código-fonte do projeto

│   ├── main.cpp                   # Arquivo principal

│   ├── tarefa.cpp                 # Implementação da classe Tarefa

│   ├── gerenciador_de_tarefa.cpp  # Implementação da classe GerenciadorDeTarefas

│   ├── notificacao.cpp            # Implementação da classe Notificacao

│   ├── etiqueta.cpp               # Implementação da classe Etiqueta

│   └── historico.cpp              # Implementação da classe Historico

│

├── include/                       # Cabeçalhos do projeto

│   ├── tarefa.h                   # Declaração da classe Tarefa

│   ├── gerenciador_de_tarefa.h    # Declaração da classe GerenciadorDeTarefas

│   ├── notificacao.h              # Declaração da classe Notificacao

│   ├── etiqueta.h                 # Declaração da classe Etiqueta

│   └── historico.h                # Declaração da classe Historico

│

├── obj/                           # Diretório para arquivos objeto (.o)

│   ├── main.o

│   ├── tarefa.o

│   ├── gerenciador_de_tarefa.o

│   ├── notificacao.o

│   ├── etiqueta.o

│   └── historico.o

│

├── tests/                         # Testes unitários

│   ├── test_tarefa.cpp

│   ├── test_gerenciador_de_tarefa.cpp

│   ├── test_notificacao.cpp

│   ├── test_etiqueta.cpp

│   └── test_historico.cpp

│

└── README.md                      # Documentação principal do projeto
```

### 1.4 Instruções de Instalação
### 1.4.1 Instalação e Uso no Windows

### Requisitos do Sistema
- MinGW ou outro ambiente de desenvolvimento C++ (como Visual Studio)
- Git (para clonar o repositório)

### Passos para Instalação
1.	**Clone o repositório:**

- Abra o terminal e execute o seguinte comando para clonar o repositório do Gerenciador de Tarefas:

```
git clone https://github.com/DoctorMoonlight/gerenciadortarefas.git
```

2.	**Acesse o diretório do projeto:**

```
cd gerenciadortarefas
```

3.	**Compile o programa:**

```
g++ -o gerenciador main.cpp tarefa.cpp etiqueta.cpp gerenciador_de_tarefa.cpp historico.cpp notificacao.cpp catch_amalgamated.cpp
```

Isso compilará os arquivos principais (main.cpp, tarefa.cpp, etiqueta.cpp, gerenciador_de_tarefa.cpp, historico.cpp, notificacao.cpp e catch_amalgamated.cpp) e criará um executável chamado gerenciador.exe.

### Instruções de Uso

1.	**Executar o Gerenciador de Tarefas:**

- Execute o programa no terminal ou no explorador de arquivos clicando duas vezes no executável gerenciador.exe.

2.	**Funcionalidades Disponíveis:**

-	Adicionar novas tarefas.
-	Editar tarefas existentes.
-	Marcar tarefas como concluídas.
-	Excluir tarefas.
-	Visualizar o histórico de tarefas concluídas.

---

### 1.4.2 Instalação e Uso no Linux

### Requisitos do Sistema
- Compilador C++ (por exemplo, g++)
- Git (para clonar o repositório)

### Passos para Instalação

1. **Clone o repositório:**

   - Abra o terminal e execute o seguinte comando para clonar o repositório do Gerenciador de Tarefas:
  
 ```
git clone https://github.com/DoctorMoonlight/gerenciadortarefas.git
```

2.	**Acesse o diretório do projeto:**

```
cd gerenciadortarefas
```

3.	**Compile o programa:**

```
g++ -o gerenciador main.cpp tarefa.cpp etiqueta.cpp gerenciador_de_tarefa.cpp historico.cpp notificacao.cpp catch_amalgamated.cpp
```

Isso compilará os arquivos principais (main.cpp, tarefa.cpp, etiqueta.cpp, gerenciador_de_tarefa.cpp, historico.cpp, notificacao.cpp e catch_amalgamated.cpp) e criará um executável chamado gerenciador.

### Instruções de Uso
1.	Executar o Gerenciador de Tarefas: Execute o programa digitando o seguinte comando no terminal:

```
./gerenciador
```

2. **Funcionalidades Disponíveis:**
   - Adicionar novas tarefas.
   - Editar tarefas existentes.
   - Marcar tarefas como concluídas.
   - Excluir tarefas.
   - Visualizar o histórico de tarefas concluídas.

### Observações sobre a instalação 
O utilizador deve se certificar de ter as permissões adequadas para compilar e executar o programa no Linux ou no Windows. Caso aconteça algum problema durante a compilação ou execução, será necessário verificar as dependências e assegurar de que todas as etapas foram seguidas corretamente.

### 1.5 Instruções de Uso
Para utilizar corretamente o sistema, o usuário deve:
- Iniciar uma nova tarefa;
- Adicionar as especificações da tarefa: data, descrição, horário e prioridade;
- Personalizar as notificações: defina o horário do alarme;
- Selecionar a tarefa como concluída;
- Visualizar o histórico de afazeres realizados e pendentes;
- Excluir ou editar a tarefa.

#### Exemplo de Uso:
O utilizador tem um evento X e deseja ser notificado desse evento com antecedência. Ele registra o nome, o dia, a hora e outros detalhes do evento e recebe uma notificação do evento naquele certo dia e, assim que concluído, pode determinar como “resolvido”.

## 2.0 User Stories
### 2.1 Tarefa
### Descrição: 
Como usuário, desejo poder gerenciar meus afazeres com informações detalhadas.
### Critérios de Aceitação:
- Posso adicionar uma nova tarefa com descrição, data, hora, etiqueta e status de conclusão;
- Posso editar os detalhes de uma tarefa existente;
- Posso visualizar todas as informações de uma tarefa;
- Posso marcar uma tarefa como concluída;
- Recebo notificações quando uma tarefa está próxima de ocorrer.

### 2.2 Gerenciador de Tarefas
### Descrição: 
Na posição de usuário, desejo um gerenciador de tarefas que me permita organizar e controlar minhas tarefas de forma eficiente.
### Critérios de Aceitação:
- Posso adicionar uma nova tarefa ao gerenciador;
- Posso eliminar uma tarefa do gerenciador;
- Posso editar os detalhes de uma tarefa no gerenciador;
- Posso visualizar todas as tarefas criadas;
- Posso marcar tarefas como concluídas;
- Posso utilizar etiquetas para categorizar tarefas com base em prioridade;
- Posso visualizar o histórico de tarefas concluídas.

### 2.3 Notificações
### Descrição: 
Na posição de usuário, pretendo receber notificações sobre minhas tarefas para não perder prazos e eventos importantes.
### Critérios de Aceitação:
- Recebo uma notificação quando uma tarefa está próxima de ocorrer;
- Posso configurar a preferência de horário do alarme (duas horas antes do evento, uma hora antes, etc.).

### 2.4 Etiquetas
### Descrição: 
Como usuário, pretendo categorizar minhas tarefas usando etiquetas para melhor organização.
### Critérios de Aceitação:
- Posso criar e editar etiquetas para minhas tarefas;
- Posso definir prioridades para as tarefas usando etiquetas.

### 2.5 Histórico
Descrição: Como usuário, quero poder acessar o histórico das minhas tarefas concluídas para acompanhar meu progresso.
### Critérios de Aceitação:
- Posso visualizar um histórico das tarefas que ficaram pendentes e das que eu concluí;
- As informações do histórico possuem a descrição, data, hora e etiqueta da tarefa criada.

## 3.0 Cartões Class-Responsibility-Collaborator (CRC)

![1](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/4c6ee445-cc59-4c9e-8fad-cedfcca23a89)

![2](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/c6e3663a-50ab-4186-8eb7-600c920e307e)

![3](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/c1fb98bb-9017-49ba-a1fb-190a148bb27b)

![4](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/8a4db2fc-8752-4745-a0ab-75a4db7e7647)

![5](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/dd28bec6-75fc-41c8-ac7e-4fe84c2afce9)

## 4.0 Principais Dificuldades

- Execução dos Testes do Programa.
 A execução dos testes apresentou-se como um dos maiores desafios. Devido a complexidade das funcionalidades implementadas e a necessidade de garantir a precisão e a robustez do sistema, os testes demandaram um esforço considerável. Foi necessário criar um conjunto abrangente de casos de teste para cobrir todas as possíveis interações do usuário com o sistema.

- Além disso, a depuração de erros detectados durante os testes revelou-se uma tarefa árdua. A falta de ferramentas avançadas de depuração em C, comparado a outras linguagens de alto nível, contribuiu para aumentar a dificuldade na identificação e correção de "bugs".

- Implementação das notificações.
 Outra dificuldade encontrada foi a falta de emissão de som nas notificações. A intenção era que cada notificação fosse acompanhada por um alerta sonoro para garantir que o usuário percebesse o lembrete. No entanto, a integração com bibliotecas de áudio em C mostrou-se mais complicada do que o previsto, que introduziu complexidades adicionais e problemas de compatibilidade.

## 5.0 Conclusão 

 Apesar dos desafios enfrentados, o desenvolvimento do gerenciador de tarefas em C++ proporcionou uma valiosa experiência de aprendizado e contribuiu significativamente para o aprimoramento das habilidades de programação e resolução de problemas. As dificuldades encontradas na execução dos testes do programa e na implementação das notificações foram superadas com uma abordagem persistente, resultando em um produto final funcional e mais eficiente. 
   As atividades em grupo também foram essenciais para o sucesso do projeto. A colaboração e o compartilhamento de conhecimentos entre os membros da equipe permitiram resolver problemas de forma mais eficaz e desenvolver soluções inovadoras para os desafios encontrados. Portanto, o trabalho foi de signficativa importância para aprimoramentos dos conhecimentos e experiências de programação. 

## Autoras

| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174665776?v=4" width=115><br><sub>Ana Luiza Silva e Mendes</sub>](https://github.com/analuizasmendes) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/91071877?v=4" width=115><br><sub>Maria Clara Moreira Alves de Araújo</sub>](https://github.com/DoctorMoonlight) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174662300?v=4" width=115><br><sub>Elen Caroline Izidoro de Aguiar</sub>](https://github.com/ellenuf) |[<img loading="lazy" src="https://avatars.githubusercontent.com/u/165835956?v=4" width=115><br><sub>Ana Sarah da Silva Gomes</sub>](https://github.com/anasarahsg) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174651649?v=4" width=115><br><sub>Bruna Kamily dos Santos</sub>](https://github.com/BrunaKamilySantos)
| :---: | :---: | :---: |:---: |:---: |
