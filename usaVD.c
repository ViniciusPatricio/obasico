#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "vetordinamico.h"
#include "pilha.h"
#include "fila.h"
#include "filaprioridade.h"


typedef struct aviao{
  int nroTurbina;
  double nivelCombustivel;
  int prioridade;
} TAviao;

void *criarInstanciaAviao(int nroTurbina, double nivelCombustivel, int prioridade){

  TAviao *carga = malloc(sizeof(TAviao));
  carga->nroTurbina = nroTurbina;
  carga->nivelCombustivel = nivelCombustivel;
  carga->prioridade = prioridade;

  return carga;
}

int compararInstanciasAviao(void *elemA, void *elemB){
    TAviao *pelemA = elemA;
    TAviao *pelemB = elemB;
    if (pelemA->prioridade == pelemB->prioridade){
      return 0;
    }else if(pelemA->prioridade > pelemB->prioridade) {
      return 1;
    }else{
      return -1;
    }
}


void *criarInstanciaTipo(int valor){

  int *carga = malloc(sizeof(int));
  *carga = valor;

  return carga;
}

int compararInstanciasTipo(void *elemA, void *elemB){
    int *pelemA = elemA;
    int *pelemB = elemB;
    if (*pelemA == *pelemB){
      return 0;
    }else if(*pelemA > *pelemB) {
      return 1;
    }else{
      return -1;
    }
}

void usarvdinamico(){
  TVDinamico *vd = criarVD();


  inserirVD(vd, criarInstanciaTipo(10), 1);
  inserirVD(vd, criarInstanciaTipo(100), 2);
  inserirVD(vd, criarInstanciaTipo(1), 3);
  inserirVD(vd, criarInstanciaTipo(20), 4);
  inserirVD(vd, criarInstanciaTipo(24), 5);

  int* valor = acessarVD(vd, 1);

  printf("%d\n", *valor );

  valor = acessarVD(vd, 5);

  printf("%d\n", *valor );

  ordenarVD(vd, compararInstanciasTipo);

  valor = acessarVD(vd, 1);

  printf("%d\n", *valor );

  valor = acessarVD(vd, 5);

  printf("%d\n", *valor );

  // valor = removerVD(vd, 10);
  // if (valor !=NULL){
  //   printf("Removido: %d\n", *valor );
  // }else{
  //   printf("Posição Vazia!\n");
  // }
  //
  // valor = removerVD(vd, 10);
  // if (valor !=NULL){
  //   printf("Removido: %d\n", *valor );
  // }else{
  //   printf("Posição Vazia!\n");
  // }

}

void usarpilha(){
    TPilha *pilha = criarPilha();

    empilhar(pilha, criarInstanciaTipo(10));
    empilhar(pilha, criarInstanciaTipo(100));
    empilhar(pilha, criarInstanciaTipo(1));
    empilhar(pilha, criarInstanciaTipo(20));
    empilhar(pilha, criarInstanciaTipo(24));

    int *p = desempilhar(pilha);
    printf("%d\n", *p);
}


void usarfila(){
    TFila *fila = criarFila();

    enfileirar(fila, criarInstanciaTipo(10));
    enfileirar(fila, criarInstanciaTipo(100));
    enfileirar(fila, criarInstanciaTipo(1));
    enfileirar(fila, criarInstanciaTipo(20));
    enfileirar(fila, criarInstanciaTipo(24));

    int *p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);

    enfileirar(fila, criarInstanciaTipo(200));
    enfileirar(fila, criarInstanciaTipo(240));
    p = desenfileirar(fila);
    printf("%d\n", *p);
    p = desenfileirar(fila);
    printf("%d\n", *p);


}

void usarfilaprioridade(){
  TFilaPrioridade *fp = criarFP(4);

  inserirFP(fp, criarInstanciaAviao(4,0.5,5));
  inserirFP(fp, criarInstanciaAviao(4,0.3,2));
  inserirFP(fp, criarInstanciaAviao(8,0.1,3));
  inserirFP(fp, criarInstanciaAviao(6,0.9,1));

  TAviao *pmenor = encontrarMenorFP(fp, compararInstanciasAviao);

  if (pmenor!=NULL){
    printf("turbinas: %d\n", pmenor->nroTurbina);
    printf("nivelCombustivel: %lf\n", pmenor->nivelCombustivel);
  }

  pmenor = removerMenorFP(fp, compararInstanciasAviao);
  if (pmenor!=NULL){
    printf("turbinas: %d\n", pmenor->nroTurbina);
    printf("nivelCombustivel: %lf\n", pmenor->nivelCombustivel);
  };

  pmenor = encontrarMenorFP(fp, compararInstanciasAviao);
  if (pmenor!=NULL){
    printf("turbinas: %d\n", pmenor->nroTurbina);
    printf("nivelCombustivel: %lf\n", pmenor->nivelCombustivel);
  }


}


int main(int argc, char const *argv[]) {

  // usarpilha();
  // usarfila();
  // usarvdinamico();

  usarfilaprioridade();
  return 0;
}
