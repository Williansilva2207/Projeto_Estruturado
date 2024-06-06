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
void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica, int qtdUser, Usuario usuarios[],int posicaoUser);
void alterarMusicas(Musica musica[], int *qtdMusica, int *posicaoMusica);
int binarySearchC(Musica musica[], int cod, int qtdMusica, int posicaoMusica);
void Remove(int c, Musica musica[], int *qtdMusica, int *posicaoMusica);
void listarMusica(Musica musica[], int qtdMusica);
int getNextCodigo(Musica musica[], int qtdMusica);
int logar(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser);
int binarySearchLogin(Usuario usuarios[], char login[], int posicaoUser);
char cadastrarUsuario(Usuario usuarios[], int *indice);
int getNextCodigoUsuario(Usuario usuarios[], int qtdUsuarios);
void agirUser(Usuario usuarios[], int *indUser);
void listarUser(Usuario usuarios[], int qtdUser);
int binarySearchUser(Usuario usuarios[], int cod, int posicaoUser);
void pesquisarUser(Usuario usuarios[], int qtdUser, int posicaoUser);
void orndenarContas(Usuario usuarios[], int qtdUser);
//_________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________

int main() {
    Usuario usuarios[TAM_USER];
    
    
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
            printf("Bem vindo Usuário.\n");
            int c = logar(usuarios, login, senhaUsuario, qtdUser, posicaoUser);
            if(c == 0){
                user_Adm = 'b';
            }
        } else if (user_Adm == '2') {
            printf("Coloque a senha do adm (ou digite b para voltar): ");
            int c = verificarSenha(senha);
            printf("\n");
            if (c == 0) {
                user_Adm = 'b';
            } else {
                acaoAdm(musica, &qtdMusica, &posicaoMusica, qtdUser, usuarios, posicaoUser);
            }
        } else {
            break;
        }
    }
    return 0;
}
//_________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________
void menu1(char *user_Adm) {
    while (*user_Adm != '1' && *user_Adm != '2' && *user_Adm != '0') {
        printf("Você é usuário ou administrador?\n\n");
        printf("Digite 1: Usuário.\nDigite 2: Administrador.\nDigite 0: Sair do app\n");
        scanf(" %c", user_Adm);
        getchar();
        printf("\n");
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
    return 1; 
}

void adicionarMusica(Musica musica[], int *retornar, int *qtdMusica, int *posicaoMusica) {
    int quantidade;
    printf("\n");
    printf("Quantas músicas você quer registrar ?\n");
    scanf("%d", &quantidade);
    getchar();
    printf("\n");
    for (int i = 0; i < quantidade; i++) {
        musica[*qtdMusica].codigo = getNextCodigo(musica, *qtdMusica);
        printf("Digite o nome da música: ");
        fgets(musica[*qtdMusica].titulo, TAM_TITULO, stdin);
        musica[*qtdMusica].titulo[strcspn(musica[*qtdMusica].titulo, "\n")] = '\0';  
        printf("Digite o nome do artista: ");
        fgets(musica[*qtdMusica].artista, TAM_NOME, stdin);
        musica[*qtdMusica].artista[strcspn(musica[*qtdMusica].artista, "\n")] = '\0';  
        printf("\n");
        (*qtdMusica)++;
    }
    *posicaoMusica = *qtdMusica - 1;
    *retornar = -1;
}

void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica, int qtdUser, Usuario usuarios[], int posicaoUser) {
    int decisao = -1;
    while (decisao != 0) {
        printf("O que você deseja?\n\nDigite 1: Listar Usuários.\nDigite 2: Adicionar musicas.\nDigite 3: Playlist.\n");
        printf("Digite 4: Modificar informações da música\nDigite 5: Listar músicas.\nDigite 6: Pesquisar Usuários\nDigite 0: Sair.\n");
        scanf("%d", &decisao);
        getchar();
        printf("\n");
        if (decisao == 1) {
            listarUser(usuarios, qtdUser);    
        } else if (decisao == 2) {
            adicionarMusica(musica, &decisao, qtdMusica, posicaoMusica);
        } else if (decisao == 3) {
            
        } else if (decisao == 4) {
            alterarMusicas(musica, qtdMusica, posicaoMusica);
        } else if (decisao == 5) {
            listarMusica(musica, *qtdMusica);
        }
        else if (decisao == 6) {
            pesquisarUser(usuarios,  qtdUser, posicaoUser);
        }
    }
}

void alterarMusicas(Musica musica[], int *qtdMusica, int *posicaoMusica) {
    int cod;
    char mod;

    printf("Digite o código da música que você quer modificar:\n");
    scanf("%d", &cod);
    getchar();
    printf("\n");
    int c = binarySearchC(musica, cod, *qtdMusica, *posicaoMusica);
    if (c != -1) {
        printf("Digite T: Título\nDigite A: Artista\nDigite D: Deletar\n");
        scanf("%c", &mod);
        getchar();
        if (mod == 'T') {
            printf("Coloque o novo nome da Música:\n");
            fgets(musica[c].titulo, TAM_TITULO, stdin);
            musica[c].titulo[strcspn(musica[c].titulo, "\n")] = '\0';  
        } else if (mod == 'A') {
            printf("Coloque o novo nome do Artista:\n");
            fgets(musica[c].artista, TAM_NOME, stdin);
            musica[c].artista[strcspn(musica[c].artista, "\n")] = '\0';  
        } else if (mod == 'D') {
            Remove(c, musica, qtdMusica, posicaoMusica);
        }
    } else {
        printf("Código não encontrado.\n");
    }
}

int binarySearchC(Musica musica[], int cod, int qtdMusica, int posicaoMusica) {
    int beggin = 0;
    int end = posicaoMusica;
    while(beggin <= end){
        int indice = (beggin+end)/2;
        if(musica[indice].codigo == cod){
            return indice;
        }
        else if(musica[indice].codigo <= cod){
            beggin = indice + 1;
        }
        else{
            end = indice - 1;
        }
    }
    return -1;
}

void Remove(int c, Musica musica[], int *qtdMusica, int *posicaoMusica) {
    for (int i = c; i < *qtdMusica - 1; i++) {
        musica[i] = musica[i + 1];
    }
    (*qtdMusica)--;
    *posicaoMusica = *qtdMusica - 1;
}

void listarMusica(Musica musica[], int qtdMusica) {
    for (int i = 0; i < qtdMusica; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musica[i].codigo, musica[i].titulo, musica[i].artista);
    }
    printf("\n");
}

int getNextCodigo(Musica musica[], int qtdMusica) {
    int maxCodigo = 0;
    for (int i = 0; i < qtdMusica; i++) {
        if (musica[i].codigo > maxCodigo) {
            maxCodigo = musica[i].codigo;
        }
    }
    return maxCodigo + 1;
}

void listarUser(Usuario usuarios[], int qtdUser)
{
    printf("\n");
    for(int i = 0; i < qtdUser; i++){
        printf("Nome: %s, Login: %s;", usuarios[i].nome, usuarios[i].login);
        printf("\n");
    }
    printf("\n");
}
void pesquisarUser(Usuario usuarios[], int qtdUser, int posicaoUser){
    int cod;
    printf("Coloque o código do usuário:\n");
    scanf("%d", &cod);
    getchar();
    int c = binarySearchUser(usuarios, cod, posicaoUser);
    if(c!=-1){
        printf("\nNome: %s\n", usuarios[c].nome);
        printf("Login: %s\n", usuarios[c].login);
        printf("\n");
    }
    else{
        printf("\nUsuário não encontrado.\n");
    }
    
}
int binarySearchUser(Usuario usuarios[], int cod, int posicaoUser){
    int beggin = 0;
    int end = posicaoUser;
    while(beggin <= end){
        int indice = (beggin+end)/2;
        if(usuarios[indice].codigo == cod){
            return indice;
        }
        else if(usuarios[indice].codigo <= cod){
            beggin = indice + 1;
        }
        else{
            end = indice - 1;
        }
    }
    return -1;
}
//_________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________
int logar(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser){
    orndenarContas(usuarios, qtdUser);
    printf("Digite seu login: ");
    fgets(login, TAM_LOGIN, stdin);
    login[strcspn(login, "\n")] = '\0';  
    printf("Digite sua senha: ");
    fgets(senhaUsuario, TAM_SENHA, stdin);
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';  

    int index = binarySearchLogin(usuarios, login, posicaoUser);
    
    if (index != -1 && strcmp(usuarios[index].senha, senhaUsuario) == 0) {
        printf("Login bem-sucedido!\n");
        printf("\n");
        return index;
    } else {
        printf("Login ou senha incorretos.\n");
        printf("\n");
        return -1; 
    }
}


int binarySearchLogin(Usuario usuarios[], char login[], int posicaoUser) {
    int begin = 0;
    int end = posicaoUser;

    while (begin <= end) {
        int middle = (begin + end) / 2;
        int comparacao = strcmp(usuarios[middle].login, login);
        
        if (comparacao == 0) {
            return middle; 
            
        } else if (comparacao < 0) {
            begin = middle + 1; 
        } else {
            end = middle - 1; 
        }
    }

    return -1; 
}

void orndenarContas(Usuario usuarios[], int qtdUser){
    for(int i = 0; i<qtdUser; i++){
        for(int e = i+1; e < qtdUser; e++){
            if(strcmp(usuarios[i].login, usuarios[e].login) > 0){
                Usuario chave = usuarios[e];
                usuarios[e] = usuarios[i];
                usuarios[i] = chave;
                
            }
        }
    }
}

