#include <cstdio>
#include <vector>
using namespace std;

#define MAXIMO 100000

int n_vertices, n_arestas;

/* Contém o grafo :
grafo é um vetor com quantidade de posicoes maximo
cada posicao desse vetor, pode ser expandida (vector), contendo os nos adjacentes ao no considerado
o no considerado e a posicao em si do vetor
*/
vector<int> grafo[MAXIMO];

/* Contém os vertices com grau de entrada zero */
int grau_entrada[MAXIMO];

// No final de tudo, contera a lista com os nos visitados, considerando a predecessão entre os nos
vector<int> lista_pred;


int indice_par = -1;


void predecessor(int num_vertices, int num_arestas);

void main()
{
	
	n_vertices = 42;
	n_arestas = 36;
	

	
	predecessor(n_vertices, n_arestas);

	system("pause");
}


void predecessor(int num_vertices, int num_arestas)
{
	/* contem as arestas do grafo, considerando pares de vertices */
	int pares[] = {3, 4, 4, 5, 5, 6, 5, 7, 7, 8, 8, 9, 9, 10, 10, 11, 9, 13, 13, 14, 14, 15, 11, 15, 15, 16, 16, 17,
		17, 18, 18, 19, 19, 20, 16, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 26, 33, 33, 34, 33, 35,
		34, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44};
	

	
	indice_par = -1;

	for (int i = 1; i <= num_arestas; i++){

		grau_entrada[pares[indice_par + 2]]++;
		/* vetor pares: contem as arestas que sao indicadas por pares de nos no grafo
		   indice_par+1: predecessor
		   indice_par+2: dependente
		*/
		grafo[pares[indice_par + 1]].push_back(pares[indice_par + 2]);

		/* Apos alterar em grau_entrada e grafo, incremento o indice_par em 2
		   pois deve-se andar de 2 em 2
		*/
		indice_par += 2;

	}

	/* Em grau_entrada, as posicoes em si sao os vertices
	   Se o conteudo associado ao indice for 0
	   O grau de entrada do indice (vertice) e 0 
	*/
	for (int i = 1; i <= num_vertices; i++)
	{
		if (grau_entrada[i] == 0)
		{
			/* Se grau de entrada do vertice e 0, adicionar vertice na lista_pred */
			lista_pred.push_back(i);
		}

	}

	int comeco = 0;

	/* comeco contem a posicao do vertice que deve ter suas arestas removidas */
	while (comeco < (int)lista_pred.size())
	{

		int indice_atual = lista_pred[comeco];
		comeco++;

		for (int i = 0; i < (int)grafo[indice_atual].size(); i++)
		{

			int vertice = grafo[indice_atual][i];

			/* remover arestas do vertice
			   significa diminuir o grau de entrada dos vertices adjacentes ao vertice considerado
			*/
			grau_entrada[vertice]--;

			/* Se o grau de entrada do vertice e 0
			   adicionar vertice a lista_pred
			*/
			if (grau_entrada[vertice] == 0)
			{
				/* Quando o vertice fica com grau zero, vai para a lista de predecessão */
				lista_pred.push_back(vertice);
			}
		}

	}

	/* Se o tamanho da lista_pred for menor que num_vertices
	   significa que há ciclo(s) no grafo considerado.
	   Sem ordem topologica para resolver o problema.
	*/
	if ((int)lista_pred.size() < num_vertices)
	{
		printf("Grafo com ciclo(s)\n");
		printf("Impossível fazer ordenacao topologica\n");
	}

	/* Caso contrario: a ordenacao topologica para o grafo e exibida. */
	else
	{
		printf("Ordenacao topologica do grafo:\n");

		for (int i = 0; i < (int)lista_pred.size(); i++)
		{
			if (i != lista_pred.size() - 1)
			{

				printf("%i -> ", lista_pred[i]);
			}

			else
			{
				printf("%i\n", lista_pred[i]);
			}

		}
	}

}


