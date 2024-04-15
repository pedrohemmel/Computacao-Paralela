## Instrução para rodar o main.c
- Baixe a lib OpenMP;
- Para quem tem Mac m1 ou adiante (meu caso), baixe o omp pelo homebrew utilizando o comando <brew install libomp> e rode o programa com o comando <clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp main.c -o main>