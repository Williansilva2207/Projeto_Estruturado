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
void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica);
void alterarMusicas(Musica musica[], int *qtdMusica, int *posicaoMusica);
int binarySearchC(Musica musica[], int cod, int qtdMusica);
void Remove(int c, Musica musica[], int *qtdMusica, int *posicaoMusica);
void listarMusica(Musica musica[], int qtdMusica);
int getNextCodigo(Musica musica[], int qtdMusica);
int logar(Usuario usuarios[], char login[], char senhaUsuario[], int *indUser);
int binarySearchLogin(Usuario usuarios[], char login[], int qtdUsuarios);
int binarySearchSenha(Usuario usuarios[], char senha[], int qtdUsuarios);
char cadastrarUsuario(Usuario usuarios[], int *indice);
int getNextCodigoUsuario(Usuario usuarios[], int qtdUsuarios);
void agirUser(Usuario usuarios[], int *indUser);

int main() {
    Usuario usuarios[10];
    
    int indUser = 0;
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

    char login[TAM_LOGIN];
    char senhaUsuario[TAM_SENHA];
    char senha[10] = {'m', '@', 's', 't', '3', 'r', '2', '0', '2', '4'};
    char user_Adm = 'b';
    int qtdMusica = 3;  
    int posicaoMusica = 2;

    while (user_Adm == '1' || user_Adm == '2' || user_Adm == 'b') {
        menu1(&user_Adm);

        if (user_Adm == '1') {
            printf("Bem vindo Usuário.\n");
            int c = logar(usuarios, login, senhaUsuario, &indUser);
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
                acaoAdm(musica, &qtdMusica, &posicaoMusica);
            }
        } else {
            break;
        }
    }
    return 0;
}

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
    return 1; 
}

void adicionarMusica(Musica musica[], int *retornar, int *qtdMusica, int *posicaoMusica) {
    int quantidade;
    printf("Quantas músicas você quer registrar ?\n");
    scanf("%d", &quantidade);
    getchar();
    
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

void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica) {
    int decisao = -1;
    while (decisao != 0) {
        printf("O que você deseja?\n\nDigite 1: Usuário.\nDigite 2: Adicionar musicas.\nDigite 3: Playlist.\n");
        printf("Digite 4: Modificar informações da música\nDigite 5: Listar músicas.\nDigite 0: Sair.\n");
        scanf("%d", &decisao);
        getchar();
        if (decisao == 1) {
            
        } else if (decisao == 2) {
            adicionarMusica(musica, &decisao, qtdMusica, posicaoMusica);
        } else if (decisao == 3) {
            
        } else if (decisao == 4) {
            alterarMusicas(musica, qtdMusica, posicaoMusica);
        } else if (decisao == 5) {
            listarMusica(musica, *qtdMusica);
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
    int c = binarySearchC(musica, cod, *qtdMusica);
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

int binarySearchC(Musica musica[], int cod, int qtdMusica) {
    for (int i = 0; i < qtdMusica; i++) {
        if (musica[i].codigo == cod) {
            return i;
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

int logar(Usuario usuarios[], char login[], char senhaUsuario[], int *indUser) {
    printf("Digite seu login: ");
    fgets(login, TAM_LOGIN, stdin);
    login[strcspn(login, "\n")] = '\0';  
    printf("Digite sua senha: ");
    fgets(senhaUsuario, TAM_SENHA, stdin);
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';  

    int index = binarySearchLogin(usuarios, login, *indUser);
    if (index != -1) {
        int senhaIndex = binarySearchSenha(usuarios, senhaUsuario, *indUser);
        if (senhaIndex != -1 && senhaIndex == index) {
            printf("Login bem-sucedido!\n");
            return 1;
        }
    }
    printf("Login ou senha incorretos.\n");
    return 0;
}

int binarySearchLogin(Usuario usuarios[], char login[], int qtdUsuarios) {
    for (int i = 0; i < qtdUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0) {
            return i;
        }
    }
    return -1;
}

int binarySearchSenha(Usuario usuarios[], char senha[], int qtdUsuarios) {
    for (int i = 0; i < qtdUsuarios; i++) {
        if (strcmp(usuarios[i].senha, senha) == 0) {
            return i;
        }
    }
    return -1;
}

char cadastrarUsuario(Usuario usuarios[], int *indice) {
    Usuario usuario;
    usuario.codigo = getNextCodigoUsuario(usuarios, *indice);
    printf("Digite o nome do usuário: ");
    fgets(usuario.nome, TAM_NOME, stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';  
    printf("Digite o login do usuário: ");
    fgets(usuario.login, TAM_LOGIN, stdin);
    usuario.login[strcspn(usuario.login, "\n")] = '\0';  
    printf("Digite a senha do usuário: ");
    fgets(usuario.senha, TAM_SENHA, stdin);
    usuario.senha[strcspn(usuario.senha, "\n")] = '\0';  
    usuarios[*indice] = usuario;
    (*indice)++;
    printf("Usuário cadastrado com sucesso!\n");
    return 1;
}

int getNextCodigoUsuario(Usuario usuarios[], int qtdUsuarios) {
    int maxCodigo = 0;
    for (int i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigo > maxCodigo) {
            maxCodigo = usuarios[i].codigo;
        }
    }
    return maxCodigo + 1;
}

void agirUser(Usuario usuarios[], int *indUser) {
    // Função a ser implementada
}
