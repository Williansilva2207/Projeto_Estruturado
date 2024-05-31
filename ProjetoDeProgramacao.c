#include <stdio.h>
#include <string.h>

#define TAM_MAX_PLYLST 200
#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLAYLIST 100
#define TAM_TITULO 50
#define TAM_MUSICAS 100

typedef struct {
    int codigo; // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME]; // nome do artista que canta esta música
} Musica;

void menu1(char *user_Adm);
void abas(char user_Adm);
int verificarSenha(char senha[]);
void adicionarMusica(Musica musica[], int *retornar, int *qtdMusica);
void acaoAdm(Musica musica[], int *qtdMusica);
void alterarMusicas(Musica musica[], int qtdMusica);
int binarySearchC(Musica musica[],int cod, int qtdMusica);
int Remove(int k, int n, int v[]);
//________________________________________________________________________________________________________________
int main() {
    Musica musica[TAM_MUSICAS];
    char senha[10] = {'m', '@', 's', 't', '3', 'r', '2', '0', '2', '4'};
    char user_Adm = 'b';
    int qtdMusica = 0;
    
    while (user_Adm == '1' || user_Adm == '2' || user_Adm == 'b') {
        menu1(&user_Adm);
    
        if (user_Adm == '1') {
            printf("Bem vindo Usuário.\n");
        } else if (user_Adm == '2') {
            printf("Coloque a senha do adm (ou digite b para voltar): ");
            int c = verificarSenha(senha);
            printf("\n");
            if (c == 0) {
                user_Adm = 'b';
            } else {
                acaoAdm(musica, &qtdMusica);
            }
        } else {
            break;
        }
    }
    return 0;
}
//_________________________________________________________________________________________________________________
void menu1(char *user_Adm) {
    while (*user_Adm != '1' && *user_Adm != '2' && *user_Adm != '0') {
        printf("Você é usuário ou administrador?\n\n");
        printf("Digite 1: Usuário.\nDigite 2: Administrador.\nDigite 0: Sair do app\n");
        scanf(" %c", user_Adm);
        getchar();
    }
}

int verificarSenha(char senha[]) {
    char senha1[TAM_SENHA];
    fgets(senha1, TAM_SENHA, stdin);
    
    for (int i = 0; senha1[i] != '\n' && senha1[i] != '\0'; i++) {
        if (senha1[i] != senha[i]) {
            printf("Senha errada!\n");
            return 0;
        }
    }
    return 1; // Senha correta
}

void adicionarMusica(Musica musica[], int *retornar, int *qtdMusica) {
    int quantidade;
    printf("Quantas músicas você quer registrar ?\n");
    scanf("%d", &quantidade);
    getchar();
    
    for (int i = 0; i < quantidade; i++) {
        musica[*qtdMusica].codigo = *qtdMusica + 1;
        printf("Digite o nome da música: ");
        fgets(musica[*qtdMusica].titulo, TAM_TITULO, stdin);
        printf("Digite o nome do artista: ");
        fgets(musica[*qtdMusica].artista, TAM_NOME, stdin);
        printf("\n");
        (*qtdMusica)++;
    }
    *retornar = -1;
}

void acaoAdm(Musica musica[], int *qtdMusica) {
    int decisao = -1;
    while (decisao != 0) {
        printf("O que você deseja?\n\nDigite 1: Usuário.\nDigite 2: Adicionar musicas.\nDigite 3: Playlist.\n");
        printf("Digite 4: Modificar informações da música\nDigite 0: Sair.\n");
        scanf("%d", &decisao);
        getchar();
        if (decisao == 1) {
            
        } else if (decisao == 2) {
            adicionarMusica(musica, &decisao, qtdMusica);
        } else if (decisao == 3) {
            
        } else if (decisao == 4) {
            alterarMusicas(musica, *qtdMusica);
        }
    }
}

void alterarMusicas(Musica musica[], int qtdMusica) {
    int cod;
    char mod;
    for (int i = 0; i < qtdMusica; i++) {
        printf("Título: %sArtista: %sCódigo: %d\n\n", musica[i].titulo, musica[i].artista, musica[i].codigo);
    }
    printf("Digite o código da música que você quer modificar:\n");
    scanf("%d", &cod);
    getchar();
    printf("\n");
    int c = binarySearchC(musica, cod, qtdMusica);
    if(c!=-1){
        printf("Digite T: Título\nDigite A: Artista\nDigite D: Deletar\n");
        scanf("%c", &mod);
        getchar();
        if(mod == 'T'){
            printf("Coloque o novo nome da Música:\n");
            fgets(musica[c].titulo, TAM_TITULO, stdin);
        }else if(mod == 'A'){
            printf("Coloque o novo nome do Artista:\n");
            fgets(musica[c].artista, TAM_NOME, stdin);
        }else if(mod == 'D'){
            
        }
        
    }else{
        printf("Foi triste.\n");
    }
}

int binarySearchC(Musica musica[],int cod, int qtdMusica){
    int beggin = 0;
    int end = qtdMusica - 1;
    while(beggin<=end){
        int index = (beggin+end)/2;
        if(musica[index].codigo == cod){
            return index;
            
        }
        else if(musica[index].codigo < cod){
            beggin = index + 1;
        }
        else{
            end = index;
        }
        return -1;
    }
    
    
}
int Remove(int k, int n, int v[])
{
   int x = v[k];
   for (int j = k+1; j < n; ++j)  
      v[j-1] = v[j];
   return x;
}