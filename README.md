# Gerenciador de Tarefas
![Capa do trabalho](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/408af570-e754-4d26-8596-72ca5af8927d)



## 1.0 User Stories
### 1.1 Tarefa
### Descrição: 
Como usuário, desejo poder gerenciar meus afazeres com informações detalhadas.
### Critérios de Aceitação:
- Posso adicionar uma nova tarefa com descrição, data, hora, etiqueta e status de conclusão;
- Posso editar os detalhes de uma tarefa existente;
- Posso visualizar todas as informações de uma tarefa;
- Posso marcar uma tarefa como concluída;
- Recebo notificações quando uma tarefa está próxima de ocorrer.

### 1.2 Coordenador de Tarefas
### Descrição: 
Como usuário, desejo um gerenciador de tarefas que me permita organizar e controlar minhas tarefas de forma eficiente.
### Critérios de Aceitação:
- Posso adicionar uma nova tarefa ao gerenciador;
- Posso eliminar uma tarefa do gerenciador;
- Posso editar os detalhes de uma tarefa no gerenciador;
- Posso visualizar todas as tarefas criadas;
- Posso marcar tarefas como concluídas;
- Posso utilizar etiquetas para categorizar tarefas com base em prioridade;
- Posso visualizar o histórico de tarefas concluídas.

### 1.3 Notificações
### Descrição: 
Como usuário, desejo receber notificações sobre minhas tarefas para não perder prazos e eventos importantes.
### Critérios de Aceitação:
- Recebo uma notificação quando uma tarefa está próxima de ocorrer;
- Posso configurar a preferência de horário do alarme (duas horas antes do evento, uma hora antes, etc.).

### 1.4 Etiquetas
### Descrição: 
Como usuário, desejo categorizar minhas tarefas usando etiquetas para melhor organização.
### Critérios de Aceitação:
- Posso criar e editar etiquetas para minhas tarefas;
- Posso definir prioridades para as tarefas usando etiquetas.

### 1.5 Histórico
Descrição: Como usuário, desejo poder acessar o histórico de minhas tarefas concluídas para acompanhar meu progresso.
### Critérios de Aceitação:
- Posso visualizar um histórico das tarefas que ficaram pendentes e das que eu concluí;
- As informações do histórico possuem a descrição, data, hora e etiqueta da tarefa criada.


## 2.0 README

### 2.1 Apresentação do Problema
No mundo atual, a quantidade de tarefas e compromissos diários aumenta constantemente. Gerenciar tarefas diárias pode ser um desafio, especialmente quando se lida com múltiplas atividades e prazos. A falta de um sistema eficiente para organizar essas tarefas pode causar atrasos, esquecimentos e, consequentemente, a perda de produtividade. Este projeto se propõe a resolver esses problemas com o auxílio de um gerenciador de tarefas que ajuda os usuários a registrar, organizar e acompanhar suas atividades diárias.

### 2.2 Visão Geral da Solução
O Gerenciador de Tarefas é uma aplicação que permite aos usuários organizar suas tarefas diárias de forma eficiente. A solução inclui funcionalidades para registrar novas tarefas, marcar tarefas como concluídas, apagar tarefas, adicionar etiquetas para melhor categorização, exibir um histórico de tarefas completadas e receber notificações de tarefas próximas. A interface simples e organizada e as notificações ajudam a garantir que os usuários não percam prazos importantes.

### 2.3 Estrutura do Projeto
A estrutura do projeto do gerenciador de tarefas é construída em C++ e deve ser organizada de forma clara e intuitiva, permitindo a facilidade na compreensão e manutenção do código.

![Estrutura do projeto](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/65a8a65c-f524-47e5-9010-31fd7be6e72f)

### 2.4 Instruções de Instalação
Fornece instruções detalhadas sobre como instalar e configurar o sistema em um ambiente de desenvolvimento. Inclua dependências e requisitos de sistema, se aplicável.

#### Passos para Instalação
1. Clone o repositório: [https://github.com/DoctorMoonlight/gerenciadortarefas.git](https://github.com/DoctorMoonlight/gerenciadortarefas.git)
2. Compile e execute o programa no ambiente de desenvolvimento da sua preferência.

### 2.5 Instruções de Uso
Para utilizar corretamente o sistema, o usuário deve:
- Iniciar uma nova tarefa;
- Adicionar as especificações da tarefa: data, descrição, horário e prioridade;
- Personalizar as notificações: defina o horário do alarme;
- Selecionar a tarefa como concluída;
- Visualizar o histórico de afazeres realizados e pendentes;
- Excluir ou editar a tarefa.

#### Exemplo de Uso:
O usuário tem um evento X e deseja ser notificado desse evento com antecedência. Ele registra o nome, o dia, a hora e outros detalhes do evento e recebe uma notificação do evento naquele certo dia e, assim que concluído, pode determinar como “resolvido”.


## Cartões Class-Responsibility-Collaborator (CRC)

![1](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/4c6ee445-cc59-4c9e-8fad-cedfcca23a89)

![2](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/c6e3663a-50ab-4186-8eb7-600c920e307e)

![3](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/c1fb98bb-9017-49ba-a1fb-190a148bb27b)

![4](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/8a4db2fc-8752-4745-a0ab-75a4db7e7647)

![5](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/dd28bec6-75fc-41c8-ac7e-4fe84c2afce9)
