
# Sistema de Gerenciamento de Assistência Técnica

Este sistema foi desenvolvido como parte do projeto acadêmico do curso de Ciência da Computação no Centro Universitário Braz Cubas, com o objetivo de otimizar o fluxo de trabalho em uma empresa de assistência técnica.

## 🎯 Objetivo

Oferecer uma solução eficaz para o registro, acompanhamento e resolução de problemas técnicos relatados pelos clientes, bem como para a gestão interna de recursos como técnicos e peças de reposição.

## 📘 Cenário

Uma empresa de assistência técnica para dispositivos eletrônicos como smartphones, tablets e laptops, que lida diariamente com um grande volume de chamados. O sistema foi projetado para registrar e organizar esses atendimentos, alocar técnicos e controlar o estoque.

## 🚧 Problemas Resolvidos

- **Gestão de Chamados:** Registro, priorização e acompanhamento de chamados.
- **Atribuição de Técnicos e Recursos:** Alocação eficaz de técnicos e peças.
- **Comunicação com o Cliente:** Registro de atualizações e status do chamado.
- **Gestão de Estoque:** Controle do nível de peças, com alertas para reposição.
- **Análise de Desempenho:** Geração de relatórios para tomada de decisão.

## ⚙️ Funcionalidades

- Cadastro de clientes e técnicos
- Registro e acompanhamento de chamados
- Atribuição de técnicos aos chamados
- Controle de estoque de peças
- Geração de relatórios
- Armazenamento persistente em arquivos `.bin`

## 🧱 Estrutura de Dados Utilizada

- **Fila:** Para organizar a ordem de atendimento.
- **Lista:** Para manter os registros de clientes, técnicos e chamados.
- **Pilha:** Para controlar as etapas do atendimento técnico (futuramente).
- **QuickSort:** Pode ser usado para ordenar os chamados por prioridade.

## 📁 Arquivos Gerados

- `clientes.bin` — Dados dos clientes
- `tecnicos.bin` — Dados dos técnicos
- `chamados.bin` — Dados dos chamados
- `estoque.bin` — Dados do estoque de peças

## 🖥️ Instruções de Compilação

Compile o projeto com:

```bash
gcc main.c -o sistema
```

Execute com:

```bash
./sistema
```

## 👨‍👩‍👧‍👦 Desenvolvedora

- Ana Luiza Guilherme

**Orientadora:** Andrea Ono Sakai, Dr.

📍 Mogi das Cruzes - SP  
🗓️ 2024/1

---

*Este projeto foi uma oportunidade de aplicar conceitos de algoritmos, estruturas de dados e modularização de sistemas, promovendo aprendizado prático e organizacional.*
