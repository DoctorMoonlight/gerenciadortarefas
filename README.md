# Gerenciador de Tarefas
![image](https://github.com/DoctorMoonlight/gerenciadortarefas/assets/174665776/408af570-e754-4d26-8596-72ca5af8927d)



## USER STORY

### Descrição
Como usuário, desejo gerenciar minhas tarefas diárias.

### Critérios de Aceitação
- Posso registrar minhas tarefas diárias, editá-las e visualizá-las;
- Posso adicionar notificações, para que eu seja notificado sempre que alguma tarefa/evento estiver pendente;
- Posso marcar tarefas como concluídas;
- Posso apagar as tarefas quando for necessário;
- Posso ordenar as tarefas de acordo com sua ordem de urgência;
- Posso visualizar o histórico das tarefas concluídas.

## README

### 2.1 Apresentação do Problema
No mundo atual, a quantidade de tarefas e compromissos diários aumenta constantemente. Gerenciar tarefas diárias pode ser um desafio, especialmente quando se lida com múltiplas atividades e prazos. A falta de um sistema eficiente para organizar essas tarefas pode causar atrasos, esquecimentos e, consequentemente, a perda de produtividade. Este projeto se propõe a resolver esses problemas com o auxílio de um gerenciador de tarefas que ajuda os usuários a registrar, organizar e acompanhar suas atividades diárias.

### 2.2 Visão Geral da Solução
O Gerenciador de Tarefas é uma aplicação que permite aos usuários organizar suas tarefas diárias de forma eficiente. A solução inclui funcionalidades para registrar novas tarefas, marcar tarefas como concluídas, apagar tarefas, adicionar etiquetas para melhor categorização, exibir um histórico de tarefas completadas e receber notificações de tarefas próximas. A interface simples e organizada e as notificações ajudam a garantir que os usuários não percam prazos importantes.

### 2.3 Estrutura do Projeto
A estrutura do projeto do gerenciador de tarefas é construída em C++ e deve ser organizada de forma clara e intuitiva, permitindo a facilidade na compreensão e manutenção do código.

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


#### Exemplo de Uso
O usuário tem um evento X e deseja ser notificado desse evento com antecedência. Ele registra o nome, o dia, a hora e outros detalhes do evento e recebe uma notificação do evento naquele certo dia e, assim que concluído, pode determinar como “resolvido”.

### Documentação (README)
Elaborem um arquivo README detalhado que inclua uma visão geral do projeto, os requisitos do sistema, instruções de configuração do ambiente de desenvolvimento e guias de contribuição. A documentação deve facilitar a compreensão do projeto para novos colaboradores, incluindo uma descrição clara das funcionalidades implementadas, exemplos de uso e instruções para a execução de testes.

## Cartão CRC 
## Classe: Usuário

| Responsabilidade                         | Colaborações              |
|------------------------------------------|---------------------------|
| Adicionar tarefas                        | Notificações              |
| Eliminar tarefas                         | Histórico de tarefas      |
| Editar tarefas                           |                           |
| Visualizar tarefas                       |                           |
| Marcar como concluída                    |                           |
| Adicionar notificação                    |                           |
| Ver histórico de tarefas concluídas      |                           |
