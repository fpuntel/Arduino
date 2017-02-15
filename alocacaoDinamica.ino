// 02 - 2017 
// Codigo tem como intenção organizar uma lista duplamente encadeada
// onde deve ter no máximo TOTALITENS de elementos, sempre que colocado
// um novo elemento, é preciso retirar o mais velho. 
// Código feito como protótipo, utilizando números randomicos.
// Autor: Fernando Emilio Puntel

#define TOTALITENS 12

typedef struct listaDados{
    	float dado;
	struct listaDados *proximo;
	struct listaDados *anterior;
}dados;

int cont;
float soma;
float media;

void setup(){

  Serial.begin(9600);
}

void loop(){

	dados *primeiro;
	dados *ultimo;
        dados *aux;

        primeiro->proximo = NULL;
        primeiro->anterior = NULL;
        primeiro->dado = NULL;
        
        ultimo->proximo = NULL;
        ultimo->anterior = NULL;
        ultimo->dado = NULL;

	cont = 0;
        soma = 0;
        media = 0;

	while(1){
		// ALOCACAO DINAMICA
          	dados *item = (dados*) malloc(sizeof(dados));
                  
                // LEITURA DADOS
                item->dado = random(0,50);
                item->proximo = NULL;
                item->anterior = NULL; 
	
                // ARRUMA LISTA DUPLAMENTE ENCADEADA
                if (!primeiro->dado){ // PRIMEIRO
                    item->proximo = NULL;
                    item->anterior = NULL;
                    primeiro = item;
                    ultimo = item;
                    cont++;
                    soma = soma + primeiro->dado;
                }else{
                    item->anterior = ultimo;
                    item->proximo = NULL;
                    ultimo->proximo = item;
                    ultimo = item;
                    cont++;
                    soma = soma + ultimo->dado;
                }
                
                // VERIFICA QUANTIDADE DE ITENS NA FILA
                if (TOTALITENS > 1){
                  if (cont > TOTALITENS){
                     Serial.print("ITEM RETIRADO: ");
                     Serial.println(primeiro->dado);
                     soma = soma - primeiro->dado; // RETIRA O PRIMEIRO DA FILA DA SOMA
                     primeiro->proximo->anterior = NULL;
                     aux = primeiro;
                     primeiro = primeiro->proximo;
                     free(aux); // FREE NA MEMORIA
                     cont--;
                  }
                }else{
                    primeiro->proximo = NULL;
                    primeiro->anterior = NULL;
                    primeiro->dado = NULL;
                    
                    ultimo->proximo = NULL;
                    ultimo->anterior = NULL;
                    ultimo->dado = NULL;
                } 
                
                Serial.println("DADOS NA LISTA: ");
                aux = primeiro;
                for (int i = 0; i < cont; i++){
                  Serial.println(aux->dado);
                  aux = aux->proximo;
                }
                
                Serial.print("CONTADOR: ");
                Serial.println(cont);
                
                Serial.print("SOMA: ");
                Serial.println(soma);
                
                media = soma / cont;
                Serial.print("MEDIA: ");	
                Serial.println(media);
                Serial.println("");

		delay(5000);
	}

}
