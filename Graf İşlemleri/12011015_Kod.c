#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct node{
    int vertex;
    int weight;
    struct node* next;
};

struct Graph{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

struct node* createNode(int, int);
struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int, int);
void directConnected(int, int, int);
void calculateNeighbor(int, int, int*, int*);

int main(){
    int i = 0, N, M, basla, var,v1,v2,w,maxv1=0,maxv2=0,k1=0,k2=0;
    FILE *fptr;
    if ((fptr = fopen("Graf1.txt", "r")) == NULL){
        printf("Error! opening file");
        exit(1);         
    }
    fscanf(fptr, "%d %d", &N, &M);
    printf("1) Dosyadan N = %d adet dugum, M = %d adet baglanti okundu.\n\n",N, M);
    fscanf(fptr, "%d %d", &basla, &var);
    printf("2) Baslangic : %d\n   Varis     : %d\n", basla, var);
    struct Graph* graph = createGraph(N);
    printf("6) DOGRUDAN BAGLI DUGUMLER\n");
    int* Ndestination = (int*)calloc(N,sizeof(int));
    int* Nsource = (int*)calloc(N,sizeof(int));
    while(!feof(fptr)){
       fscanf(fptr, "%d %d %d",&v1, &v2, &w);
       directConnected(v1, v2, w);
       calculateNeighbor(v1, v2, Nsource, Ndestination);
       addEdge(graph, v1, v2, w);
    }
    for(i=0;i<N;i++) {
        if(Nsource[i]>maxv1) {
            maxv1 = Nsource[i];
            k1=i;
        }
        if(Ndestination[i]>maxv2) {
            maxv2 = Ndestination[i];
            k2=i;
        }
    }
    printf("\n7) En fazla komsusu olan dugum: ");
    if(maxv1>maxv2) {
        printf("%d\n   Komsu sayisi : %d\n",maxv1,Nsource[k1]);
    }else{
        printf("%d\n   Komsu sayisi : %d\n",maxv2,Ndestination[k2]);
    }
    fclose(fptr);
    return 0;
}

struct node* createNode(int v, int w){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest, int weight){
    struct node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
void directConnected(int v1, int v2, int w){
    int i;
    printf("   %d birim      : %d ",w,v1);
    for(i=0;i<w;i++){
        printf("-");
    }
    printf("> %d\n",v2);
}
void calculateNeighbor(int v1, int v2, int* Nsource, int* Ndestination){
        Nsource[v1]++;
        Ndestination[v2]++;
}
