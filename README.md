# InsercaoEmMemoria

Desenvolver uma aplicação que simule os métodos básicos de alocação de processos (first fit, best fit, worst fit e circular fit) em lacunas de memória com particionamento dinâmico.

Para isso, criar uma estrutura que simule um espaço de memória definido inicialmente pelo usuário. Uma estrutura independente para cada método de alocação (quatro "memórias").

Após, criar um conjunto de opções como segue:

Opção 1 - Inserir Processo em memória

Opção 2 - Remover processo em memória

Opção 3 - Listar estado das memórias

Opção 4 - Finalizar aplicação

Observações:

- Considerar uma estrutura de memória independente para cada método de alocação;

- Para cada inserção definir uma identificação de processo e perguntar ao usuário seu tamanho;

- Para cada remoção questionar ao usuário a identificação do processo a ser removido;

- Para cada inserção/remoção, realizar - SE POSSÍVEL - nas quatro memórias 
(independentemente);

- Ao listar a memória, tratar o estado de maneira independente para cada uma das quatro memórias 
(os quatro algoritmos de alocação);

- Entender como "estado da memória" uma situação em que ela possui processos e lacunas. 
Aquele com identificação de processo e tamanho e esta com um tamanho;
	

# Compilar

>g++ -o main.exe main.cpp  memoria.cpp lista.cpp processo.cpp
