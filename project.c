#include <stdio.h>
#include <string.h>
#define TAM_USER 100
#define TAM_MAX_PLYLST 200
#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLAYLIST 100
#define TAM_TITULO 50
#define TAM_MUSICAS 100

typedef struct {
    int codigo; // autoincremento
    int codUsuario; // o código do usuário que criou a playlist
    char titulo[TAM_TITULO]; // título desta playlist
    int qtdMusicas; // qtd atual de músicas incluídas nesta playlist
    int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas
} Playlist;

typedef struct {
    int codigo; // autoincremento
    char nome[TAM_NOME];
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylists; // quantid. de playlists criadas pelo usuário
    Playlist playlists[TAM_PLAYLIST]; // todas playlists criadas
    int qtdPlaylistsFav; // quantid. de playlists favoritadas pelo usuário
    int playlistsFav[TAM_PLAYLIST]; // códigos das playlists favoritadas pelo usuário
} Usuario;

typedef struct {
    int codigo; // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME]; // nome do artista que canta esta música
} Musica;

void menu1(char *user_Adm);
int verificarSenha(char senha[]);
void adicionarMusica(Musica musica[], int *retornar, int *qtdMusica, int *posicaoMusica);
void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica, int qtdUser, Usuario usuarios[],int *posicaoUser);
void alterarMusicas(Musica musica[], int *qtdMusica, int *posicaoMusica);
int binarySearchC(Musica musica[], int cod, int qtdMusica, int posicaoMusica);
void Remove(int c, Musica musica[], int *qtdMusica, int *posicaoMusica);
void listarMusica(Musica musica[], int qtdMusica);
int getNextCodigo(Musica musica[], int qtdMusica);
int logar(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser, Musica musica[], int qtdMusica);
int binarySearchLogin(Usuario usuarios[], char login[], int posicaoUser);
void cadastrarUsuario(Usuario usuarios[], int *qtdUser, int *posicaoUser);
int getNextCodigoUsuario(Usuario usuarios[], int qtdUsuarios);
void agirUser(Usuario usuarios[], int *indUser);
void listarUser(Usuario usuarios[], int qtdUser);
int binarySearchUser(Usuario usuarios[], int cod, int qtdUser);
void pesquisarUser(Usuario usuarios[], int qtdUser);
void orndenarContas(Usuario usuarios[], int qtdUser);
char decidir(char digiti,Usuario usuarios[], int *qtdUser, int *posicaoUser);
void listarDadoUsuario(Usuario usuarios[], int indice);
char acaoUser(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser, int indice, Musica musica[], int qtdMusica);
void ordenarCodigo(Usuario usuarios[], int qtdUser);
void mudarNome(Usuario usuarios[], int indice, char senhaUsuario[], int qtdUser);
void mudarLogin(Usuario usuarios[], int indice, char senhaUsuario[], int qtdUser);
void mudarSenha(Usuario usuarios[], int indice, char senhaUsuario[], int qtdUser);
void listarUserNomes(Usuario usuarios[], int qtdUser);
void orndenarNomes(Usuario usuarios[], int qtdUser);
void ordenarMusica(Musica musica[], int qtdMusica);
//_________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________

int main() {
    Usuario usuarios[TAM_USER];
    
    int *ptr;
    Musica musica[TAM_MUSICAS];
    
    strcpy(musica[0].titulo, "Love");
    strcpy(musica[1].titulo, "Believer");
    strcpy(musica[2].titulo, "Êxodo");

    musica[0].codigo = 1;
    musica[1].codigo = 2;
    musica[2].codigo = 3;

    strcpy(musica[0].artista, "Taylor Swift");
    strcpy(musica[1].artista, "Imagine Dragons");
    strcpy(musica[2].artista, "Projeto Sola");
    
    strcpy(usuarios[0].nome, "Willian");
    strcpy(usuarios[1].nome, "Vinícius");
    strcpy(usuarios[2].nome, "Renata");
    
    usuarios[0].codigo = 1;
    usuarios[1].codigo = 2;
    usuarios[2].codigo = 3;
    
    strcpy(usuarios[0].login, "wil@uni.br");
    strcpy(usuarios[1].login, "vin@uni.br");
    strcpy(usuarios[2].login, "ren@uni.br");
    
    strcpy(usuarios[0].senha, "200887");
    strcpy(usuarios[1].senha, "872008");
    strcpy(usuarios[2].senha, "208708");
    
    
    char login[TAM_LOGIN];
    char senhaUsuario[TAM_SENHA];
    char senha[10] = {'m', '@', 's', 't', '3', 'r', '2', '0', '2', '4'};
    char user_Adm = 'b';
    int qtdMusica = 3;  
    int posicaoMusica = 2;
    int qtdUser = 3;
    int posicaoUser = 2;

    while (user_Adm == '1' || user_Adm == '2' || user_Adm == 'b') {
        menu1(&user_Adm);

        if (user_Adm == '1') {
            char digiti ;
            printf("Degite 1: Realizar Login\nDigite 2: Realizar Cadastro\nDigite 0: Voltar\n");
            scanf("%c", &digiti);
            getchar();
            while(digiti == '1'){
                int c = logar(usuarios, login, senhaUsuario, qtdUser, posicaoUser, musica, qtdMusica);
                if(c==-1){
                    printf("Deseja realizar cadasto?\nDigite S: Sim\nDigite N: Não\n");
                    scanf("%c", &digiti);
                    getchar();
                    printf("\n");
                    user_Adm = decidir(digiti, usuarios, &qtdUser, &posicaoUser);
                    
                }else{
                    digiti = acaoUser(usuarios, login, senhaUsuario, qtdUser, posicaoUser, c, musica, qtdMusica);
                    
                }
            }if(digiti == '2'){
                cadastrarUsuario(usuarios, &qtdUser, &posicaoUser);
            }
            if(digiti == '0'){
                user_Adm = 'b';
            }
        }if (user_Adm == '2') {
            acaoAdm(musica, &qtdMusica, &posicaoMusica, qtdUser, usuarios, &posicaoUser);
        }
    }

    return 0;
}
void menu1(char *user_Adm){
    printf("\nVoce e Admnistrador?\nDigite 1: NÃO\nDigite 2: SIM\n");
    scanf("%c", user_Adm);
    getchar();
    printf("\n");
}

void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica, int qtdUser, Usuario usuarios[],int *posicaoUser) {
    int decisao = -1;
    while (decisao != 0) {
        printf("O que você deseja?\n\nDigite 1: Listar Usuários.\nDigite 2: Adicionar músicas.\n");
        printf("Digite 3: Listar todas as playlists.\nDigite 4: Consultar playlist por código.\n");
        printf("Digite 5: Consultar playlist por parte do título.\nDigite 6: Consultar playlists por música.\n");
        printf("Digite 7: Modificar informações da música.\nDigite 8: Listar músicas.\nDigite 9: Pesquisar Usuários\nDigite 0: Sair.\n");
        scanf("%d", &decisao);
        getchar();
        printf("\n");
        
        switch (decisao) {
            case 1:
                listarUser(usuarios, qtdUser);
                break;
            case 2:
                adicionarMusica(musica, &decisao, qtdMusica, posicaoMusica);
                break;
            case 3:
                listarTodasPlaylists(usuarios, *posicaoUser);
                break;
            case 4: {
                int codigo;
                printf("Digite o código da playlist: ");
                scanf("%d", &codigo);
                getchar();
                consultarPlaylistCodigo(usuarios, *posicaoUser, codigo);
                break;
            }
            case 5: {
                char parteTitulo[TAM_TITULO];
                printf("Digite parte do título da playlist: ");
                fgets(parteTitulo, TAM_TITULO, stdin);
                consultarPlaylistTitulo(usuarios, *posicaoUser, parteTitulo);
                break;
            }
            case 6: {
                int codigoMusica;
                printf("Digite o código da música: ");
                scanf("%d", &codigoMusica);
                consultarPlaylistPorMusica(usuarios, *posicaoUser, codigoMusica);
                break;
            }
            case 7:
                alterarMusicas(musica, qtdMusica, posicaoMusica);
                break;
            case 8:
                listarMusica(musica, *qtdMusica);
                break;
            case 9:
                pesquisarUser(usuarios, *posicaoUser);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}

void listarTodasPlaylists(Usuario usuarios[], int qtdUser) {
    printf("Listagem de todas as playlists:\n");
    for (int i = 0; i < qtdUser; i++) {
        printf("Playlists criadas por %s:\n", usuarios[i].nome);
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            printf("Código da playlist: %d\n", usuarios[i].playlists[j].codigo);
            printf("Título da playlist: %s\n", usuarios[i].playlists[j].titulo);
            printf("Músicas:\n");
            for (int k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                // Aqui você pode recuperar os detalhes da música usando o código da música
                // A lógica para recuperar as informações da música dependerá da estrutura de dados que você está usando
                // Por exemplo, se você tiver um array de músicas, pode usar o código da música para encontrar os detalhes
                printf("Detalhes da música (código, título, artista):\n");
            }
            printf("\n");
        }
    }
}

void consultarPlaylistCodigo(Usuario usuarios[], int qtdUser, int codigo) {
    printf("Consultar playlist por código %d:\n", codigo);
    for (int i = 0; i < qtdUser; i++) {
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            if (usuarios[i].playlists[j].codigo == codigo) {
                printf("Playlist encontrada:\n");
                printf("Título: %s\n", usuarios[i].playlists[j].titulo);
                printf("Criador: %s\n", usuarios[i].nome);
                printf("Músicas:\n");
                for (int k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                    // Mesma lógica de recuperação de detalhes da música como na função anterior
                }
                printf("\n");
                return; // Playlist encontrada, então podemos sair da função
            }
        }
    }
    printf("Playlist com código %d não encontrada.\n", codigo);
}

void consultarPlaylistTitulo(Usuario usuarios[], int qtdUser, char parteTitulo[]) {
    printf("Consultar playlists por título contendo '%s':\n", parteTitulo);
    for (int i = 0; i < qtdUser; i++) {
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            if (strstr(usuarios[i].playlists[j].titulo, parteTitulo) != NULL) {
                printf("Playlist encontrada:\n");
                printf("Título: %s\n", usuarios[i].playlists[j].titulo);
                printf("Criador: %s\n", usuarios[i].nome);
                printf("Músicas:\n");
                for (int k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                    // Mesma lógica de recuperação de detalhes da música como nas funções anteriores
                }
                printf("\n");
            }
        }
    }
}

void consultarPlaylistPorMusica(Usuario usuarios[], int qtdUser, int codigoMusica) {
    printf("Consultar playlists contendo música com código %d:\n", codigoMusica);
    for (int i = 0; i < qtdUser; i++) {
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            for (int k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                if (usuarios[i].playlists[j].musicas[k] == codigoMusica) {
                    printf("Playlist encontrada:\n");
                    printf("Título: %s\n", usuarios[i].playlists[j].titulo);
                    printf("Criador: %s\n", usuarios[i].nome);
                    printf("Músicas:\n");
                    for (int l = 0; l < usuarios[i].playlists[j].qtdMusicas; l++) {
                        // Mesma lógica de recuperação de detalhes da música como nas funções anteriores
                    }
                    printf("\n");
                    break; // Não precisamos continuar procurando nesta playlist
                }
            }
        }
    }
}
