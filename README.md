# Ordenação topológica em grafos

O problema consiste em ajudar uma empresa de software a esquematizar o desenvolvimento de um agente de comunicação com webservices. A tarefa para resolver esse problema, consiste em apresentar o planejamento das tarefas a serem realizadas, para que a empresa possa desenvolver o agente com sucesso e dentro do tempo que foi determinado.
Cada tarefa tem um nome e está associada a um id e às tarefas predecessoras, caso estas existam. 
O problema apresentado é tido como de ordenação topológica em grafos. Os ID das tarefas são os nós e a relação entre esses nós é realizada por meio da predecessão.

Sendo assim, tarefas a serem desempenhadas em um projeto são representadas por vértices;
- Existe um arco entre as tarefas v e w caso a tarefa v obrigatoriamente deve ser terminada antes que a tarefa w seja começada;
- Uma ordenação topológica dos vértices nos fornece uma maneira de realizar todas as tarefas sem violar as precedências entre tarefas.

O algoritmo implementado consiste nos seguintes passos:

i) Verificar os vértices que tem grau de entrada zero e adicioná-los a uma lista;

ii) Remover todas as arestas que partem desse vértice e atualizar o grau de entrada dos vértices que estavam ligados a estas arestas.

Repetir os passos i) e ii) até acabarem os vértices com grau de entrada zero.

Se ao final deste processo ainda restarem vértices, significa que há ciclo(s) no grafo e, sendo assim, não há ordem topológica para resolver o problema. Caso contrário a ordem de execução das tarefas (vértices), estarão na sequência correta na lista.
