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
void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica, int qtdUser, Usuario usuarios[],int *posicaoUser, char senhaUsuario[], char login[],int *qtdPlaylists, Playlist playlists[]);
void alterarMusicas(Musica musica[], int *qtdMusica, int *posicaoMusica);
int binarySearchC(Musica musica[], int cod, int qtdMusica);
void Remove(int c, Musica musica[], int *qtdMusica, int *posicaoMusica);
void listarMusica(Musica musica[], int qtdMusica);
int getNextCodigo(Musica musica[], int qtdMusica);
int logar(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser, Musica musica[], int qtdMusica);
int binarySearchLogin(Usuario usuarios[], char login[], int qtdUser);
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
void pesquisarUsuario(Usuario usuarios[], int qtdUser);
int binarySearchStart(Usuario usuarios[], char name[], int qtdUser);
int pesquisarPorParteDoNome(Usuario usuarios[], char name[], int qtdUser);
int pesquisarUserSenha(Usuario usuarios[], int qtdUser, char senhaUsuario[]);
void pesquisarLogin(Usuario usuarios[], int qtdUser, char login[]);
void adicionarPlaylist(Usuario usuarios[], int *qtdUser, int posicaoUser, Musica musicas[], int qtdMusicas);
void adicionarMusicaAPlaylist(Playlist *playlist, Musica musicas[], int qtdMusicas, int *qtdMusicasPlaylist);
void listarMusicasDisponiveis(Musica musicas[], int qtdMusicas);
void listarPlaylists(Usuario usuarios[], int qtdUser);
void testar(Usuario usuarios[], char login[], int qtdUser);
void testarMusica(Musica musica[], int qtdMusica);
int binarySearchStartMusica(Musica musica[], char name[], int qtdMusica);
void pesquisarMusica(Musica musica[], int qtdMusica);
void listarPlaylistsADM(Playlist playlists[], int qtdPlaylist, Usuario usuarios[]);
void pesquisarUsuarioUser(Usuario usuarios[], int qtdUser);
void ordenarMusicaCodigo(Musica musica[], int qtdMusica);
void ordenarMusicaArtista(Musica musica[], int qtdMusica);
int binarySearchStartArtista(Musica musica[], char name[], int qtdMusica);
void pesquisarArtista(Musica musica[], int qtdMusica);
void aadicionarPlaylist(Usuario usuarios[], int *qtdUser, int *posicaoUser, Musica musicas[], int qtdMusicas);
void excluirPlaylist(Usuario usuarios[], int *qtdUser, int *posicaoUser);
void consultarPlaylists(Usuario usuarios[], int qtdUsuarios, int codUsuario, int codPlaylist, char parteTitulo[], int codMusica);



//_________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________

int main() {
    Usuario usuarios[TAM_USER];
    
    int *ptr;
    Musica musica[TAM_MUSICAS];
    Playlist playlists[TAM_PLAYLIST];
    
    strcpy(musica[0].titulo, "Love");
    strcpy(musica[1].titulo, "Believer");
    strcpy(musica[2].titulo, "Redenção");

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
    
    strcpy(playlists[0].titulo, "Jazz");
    strcpy(playlists[1].titulo, "Forró");
    strcpy(playlists[2].titulo, "Rock");
    
    playlists[0].codigo = 1;
    playlists[1].codigo = 2;
    playlists[2].codigo = 3;
    
    playlists[0].codUsuario = usuarios[0].codigo;
    playlists[1].codUsuario = usuarios[1].codigo;
    playlists[2].codUsuario = usuarios[2].codigo;
    

    int qtdPlaylist = 3;
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
            }else{
                user_Adm = 'b';
            }
        }else if (user_Adm == '2') {
            printf("Coloque a senha do adm (ou digite b para voltar): ");
            int c = verificarSenha(senha);
            printf("\n");
            if (c == 0) {
                user_Adm = 'b';
            } else {
                acaoAdm(musica, &qtdMusica, &posicaoMusica, qtdUser, usuarios, &posicaoUser, senhaUsuario, login, &qtdPlaylist, playlists);
                acaoUser(usuarios, login, senhaUsuario, qtdUser, posicaoUser, c, musica, qtdMusica); // Adicionando a chamada para acaoUser
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


void excluirMusicaPlaylist(Usuario usuarios[], int qtdUser, int indice, Musica musica[], int qtdMusica) {
    int codigoPlaylist;
    int i, j;

    printf("Digite o código da playlist da qual deseja excluir uma música: ");
    scanf("%d", &codigoPlaylist);
    getchar(); // Limpar o buffer do teclado

    // Verificar se o usuário possui a playlist com o código fornecido
    int indicePlaylist = -1;
    for (i = 0; i < usuarios[indice].qtdPlaylists; i++) {
        if (usuarios[indice].playlists[i].codigo == codigoPlaylist) {
            indicePlaylist = i;
            break;
        }
    }

    if (indicePlaylist == -1) {
        printf("Playlist não encontrada.\n");
        return;
    }

    printf("Músicas na playlist '%s':\n", usuarios[indice].playlists[indicePlaylist].titulo);
    for (i = 0; i < usuarios[indice].playlists[indicePlaylist].qtdMusicas; i++) {
        int codigoMusica = usuarios[indice].playlists[indicePlaylist].musicas[i];
        printf("%d: %s - %s\n", codigoMusica, musica[binarySearchC(musica, codigoMusica, qtdMusica)].titulo, musica[binarySearchC(musica, codigoMusica, qtdMusica)].artista);
    }

    int codigoMusicaExcluir;
    printf("Digite o código da música que deseja excluir: ");
    scanf("%d", &codigoMusicaExcluir);
    getchar(); // Limpar o buffer do teclado

    // Verificar se a música está na playlist
    int indiceMusica = -1;
    for (j = 0; j < usuarios[indice].playlists[indicePlaylist].qtdMusicas; j++) {
        if (usuarios[indice].playlists[indicePlaylist].musicas[j] == codigoMusicaExcluir) {
            indiceMusica = j;
            break;
        }
    }

    if (indiceMusica == -1) {
        printf("Música não encontrada na playlist.\n");
        return;
    }

    // Remover a música da playlist
    for (j = indiceMusica; j < usuarios[indice].playlists[indicePlaylist].qtdMusicas - 1; j++) {
        usuarios[indice].playlists[indicePlaylist].musicas[j] = usuarios[indice].playlists[indicePlaylist].musicas[j + 1];
    }
    usuarios[indice].playlists[indicePlaylist].qtdMusicas--;

    printf("Música removida com sucesso da playlist.\n");
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


void adicionarMusicaAPlaylist(Playlist *playlist, Musica musicas[], int qtdMusicas, int *qtdMusicasPlaylist) {
    if (*qtdMusicasPlaylist < TAM_MUSICAS) {
        (*qtdMusicasPlaylist)++;
    } else {
        printf("A playlist já atingiu o limite máximo de músicas!\n");
    }
}

void listarMusicasDisponiveis(Musica musicas[], int qtdMusicas) {
    printf("Músicas disponíveis:\n");
    for (int i = 0; i < qtdMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
    printf("\n");
}

void listarPlaylists(Usuario usuarios[], int qtdUser) {
    printf("Playlists adicionadas:\n");
    for (int i = 0; i < qtdUser; i++) {
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            printf("Usuário: %s, Playlist: %s\n", usuarios[i].nome, usuarios[i].playlists[j].titulo);
        }
    }
    printf("\n");
}
void listarPlaylistsADM(Playlist playlists[], int qtdPlaylist, Usuario usuarios[]) {
    printf("Playlists adicionadas:\n");
    for (int i = 0; i < qtdPlaylist; i++) {
        printf("Usuário: %s\n", usuarios[i].nome);
        printf("Playlist: %s\n", playlists[i].titulo);
        printf("\n");
    }
    printf("\n");
}

void acaoAdm(Musica musica[], int *qtdMusica, int *posicaoMusica, int qtdUser, Usuario usuarios[], int *posicaoUser, char senhaUsuario[], char login[], int *qtdPlaylists, Playlist playlists[]) {
    int decisao = -1;
    while (decisao != 0) {
        printf("O que você deseja?\n\nDigite 1: Listar Usuários.\nDigite 2: Adicionar musicas.\nDigite 3: Adicionar Playlist.\n");
        printf("Digite 4: Listar Playlists\nDigite 5: Listar músicas.\nDigite 6: Pesquisar Usuários\nDigite 7: Mudar Senha do Usuário\nDigite 8: Alterar Informações da Musica\nDigite 9: Buscar Música\nDigite 0: Sair.\n");
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
                adicionarPlaylist(usuarios, &qtdUser, posicaoUser, musica, *qtdMusica);
                break;
                
            case 4:
                listarPlaylistsADM(playlists, *qtdPlaylists, usuarios);
                break;
                
            case 5:
                listarMusica(musica, *qtdMusica);
                break;
            case 6:
                testar(usuarios, login,qtdUser);
                break;
            case 7:
                pesquisarUserSenha(usuarios, qtdUser, senhaUsuario);
                break;
            case 8:
                alterarMusicas(musica, qtdMusica, posicaoMusica);
                break;
            case 9:
                testarMusica(musica, *qtdMusica);
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    }
}
void testar(Usuario usuarios[], char login[], int qtdUser){
    char p = '.';
    while(p!='0'){
        printf("\nDigite 1: Código\nDigite 2: Nome\nDigite 3: Login\nDigite 0: Sair\n");
        scanf("%c", &p);
        getchar();
        if(p == '1'){
            ordenarCodigo(usuarios, qtdUser);
            pesquisarUser(usuarios, qtdUser);
            }else if(p == '2'){
                pesquisarUsuario(usuarios, qtdUser);
            }else if(p=='3'){
                pesquisarLogin(usuarios, qtdUser, login);
            }
    }
}
int pesquisarUserSenha(Usuario usuarios[], int qtdUser, char senhaUsuario[]){
    int cod;
    printf("Coloque o código do usuário:\n");
    scanf("%d", &cod);
    getchar();
    int c = binarySearchUser(usuarios, cod, qtdUser);
    if(c!=-1){
        mudarSenha(usuarios, c, senhaUsuario, qtdUser);
    }
    else{
        printf("\nUsuário não encontrado.\n");
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
    int beggin = 0;
    int end = qtdMusica-1;
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
    ordenarMusica(musica, qtdMusica);
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
    orndenarNomes(usuarios, qtdUser);
    printf("\n");
    for(int i = 0; i < qtdUser; i++){
        printf("Nome: %s, Login: %s; Código: %d", usuarios[i].nome, usuarios[i].login, usuarios[i].codigo);
        printf("\n");
    }
    printf("\n");
}
void pesquisarUser(Usuario usuarios[], int qtdUser){
    int cod;
    printf("Coloque o código do usuário:\n");
    scanf("%d", &cod);
    getchar();
    int c = binarySearchUser(usuarios, cod, qtdUser);
    if(c!=-1){
        printf("\nNome: %s\n", usuarios[c].nome);
        printf("Login: %s\n", usuarios[c].login);
        printf("\n");
    }
    else{
        printf("\nUsuário não encontrado.\n");
    }
    
}
int binarySearchUser(Usuario usuarios[], int cod, int qtdUser){
    int beggin = 0;
    int end = qtdUser-1;
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
void ordenarCodigo(Usuario usuarios[], int qtdUser){
        
    for(int i = 0; i<qtdUser; i++){
        for(int e = i+1; e<qtdUser; e++){
            if(usuarios[i].codigo>usuarios[e].codigo){
                Usuario chave = usuarios[e];
                usuarios[e] = usuarios[i]; 
                usuarios[i] = chave;
            }
        }
        
    }
}
void ordenarMusica(Musica musica[], int qtdMusica){
        
    for(int i = 0; i<qtdMusica; i++){
        for(int e = i+1; e<qtdMusica; e++){
            if(strcmp(musica[i].titulo, musica[e].titulo) > 0){
                Musica chave = musica[e];
                musica[e] = musica[i]; 
                musica[i] = chave;
            }
        }
        
    }
}
void ordenarMusicaCodigo(Musica musica[], int qtdMusica){
        
    for(int i = 0; i<qtdMusica; i++){
        for(int e = i+1; e<qtdMusica; e++){
            if(musica[i].codigo > musica[e].codigo){
                Musica chave = musica[e];
                musica[e] = musica[i]; 
                musica[i] = chave;
            }
        }
        
    }
}
void ordenarMusicaArtista(Musica musica[], int qtdMusica){
        
    for(int i = 0; i<qtdMusica; i++){
        for(int e = i+1; e<qtdMusica; e++){
            if(strcmp(musica[i].artista, musica[e].artista) > 0){
                Musica chave = musica[e];
                musica[e] = musica[i]; 
                musica[i] = chave;
            }
        }
        
    }
}
//_________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________
int logar(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser, Musica musica[], int qtdMusica){
    orndenarContas(usuarios, qtdUser);
    printf("Digite seu login: ");
    fgets(login, TAM_LOGIN, stdin);
    login[strcspn(login, "\n")] = '\0';  
    printf("Digite sua senha: ");
    fgets(senhaUsuario, TAM_SENHA, stdin);
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';  

    int index = binarySearchLogin(usuarios, login, qtdUser);
    
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

int binarySearchLogin(Usuario usuarios[], char login[], int qtdUser) {
    int begin = 0;
    int end = qtdUser-1;

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
void orndenarNomes(Usuario usuarios[], int qtdUser){
    for(int i = 0; i<qtdUser; i++){
        for(int e = i+1; e < qtdUser; e++){
            if(strcmp(usuarios[i].nome, usuarios[e].nome) > 0){
                Usuario chave = usuarios[e];
                usuarios[e] = usuarios[i];
                usuarios[i] = chave;
                
            }
        }
    }
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
char decidir(char digiti,Usuario usuarios[], int *qtdUser, int *posicaoUser){
    if(digiti == 'S'){
        cadastrarUsuario(usuarios, qtdUser, posicaoUser);
        return 'b';
    }
    else if(digiti == 'N'){
        return 'b';
    }
}
void cadastrarUsuario(Usuario usuarios[], int *qtdUser, int *posicaoUser)
{
    char confirmar[TAM_SENHA];
    
    char quebrar2 = '.';
    
    printf("Qual é o seu nome?:\n");
    fgets(usuarios[*qtdUser].nome, TAM_NOME, stdin);
    usuarios[*qtdUser].nome[strcspn(usuarios[*qtdUser].nome, "\n")] = '\0';
    
    printf("Ponha o seu login?:\n");
    fgets(usuarios[*qtdUser].login, TAM_LOGIN, stdin);
    usuarios[*qtdUser].login[strcspn(usuarios[*qtdUser].login, "\n")] = '\0';
    
    printf("Ponha a sua senha?:\n");
    fgets(usuarios[*qtdUser].senha, TAM_SENHA, stdin);
    usuarios[*qtdUser].senha[strcspn(usuarios[*qtdUser].senha, "\n")] = '\0';
    
    printf("Confirme a sua senha?:\n");
    fgets(confirmar, TAM_SENHA, stdin);
    confirmar[strcspn(confirmar, "\n")] = '\0';
    int ctd = 0;
    
    while(strcmp(usuarios[*qtdUser].senha,confirmar)!=0  && ctd < 4){
        
        printf("Confirme a sua senha?:\n");
        fgets(confirmar, TAM_SENHA, stdin);
        confirmar[strcspn(confirmar, "\n")] = '\0';
        ctd += 1;
        
        if(ctd == 3){
            
            printf("Não quer retornar em cadastro e tentar uma nova senha?\nDigite S: Sim\nDigite Qualquer Coisa: Não\n");
            scanf("%c", &quebrar2);
            getchar();
            if(quebrar2 == 'S'){
                ctd+=1;
                
            }else{
                ctd = 0;
            }
            
        }
    }
    if(strcmp(usuarios[*qtdUser].senha, confirmar)==0){
        for(int i = 0; i<*qtdUser; i++){
            for(int e = i+1; e<*qtdUser; e++){
                if(usuarios[i].codigo>usuarios[e].codigo){
                    Usuario chave = usuarios[e];
                    usuarios[e] = usuarios[i]; 
                    usuarios[i] = chave;
                }
            }
        }
        usuarios[*qtdUser].codigo = usuarios[*qtdUser-1].codigo + 1; 
        (*posicaoUser) += 1;
        (*qtdUser) += 1;
    }
}    
char acaoUser(Usuario usuarios[], char login[], char senhaUsuario[], int qtdUser, int posicaoUser, int indice, Musica musica[], int qtdMusica) {
    char decisao = '.';
    int i;
    
    while (decisao != '0') {
        printf("\nO que você deseja %s?:\n\n", usuarios[indice].nome);
        printf("Digite 1: Listar Seus Dados\nDigite 2: Alterar o Nome\nDigite 3: Alterar Login\nDigite 4: Alterar a Senha\n");
        printf("Digite 5: Listar Usuários\nDigite 6: Pesquisar Usuários\nDigite 7: Listar Músicas\nDigite 8: Pesquisar Música\n");
        printf("Digite 9: Listar todas as suas playlists\nDigite a: Adicionar Playlist\nDigite e: Excluir Playlist\nDigite G: Para Consultar Uma Playlist\nDigite f: para excluir uma musica da sua playlist\nDigite 0: Para Voltar\n\n");
        scanf("%c", &decisao);
        getchar();
        
        if (decisao == '1') {
            listarDadoUsuario(usuarios, indice);       
        } else if (decisao == '2') {
            mudarNome(usuarios,indice,senhaUsuario, qtdUser);       
        } else if (decisao == '3') {
            mudarLogin(usuarios, indice, senhaUsuario, qtdUser);       
        } else if (decisao == '4') {
            mudarSenha(usuarios, indice, senhaUsuario, qtdUser);       
        } else if (decisao == '5') {
            listarUserNomes(usuarios, qtdUser);
        } else if (decisao == '6') {
            pesquisarUsuarioUser(usuarios, qtdUser);
        } else if (decisao == '7') {
            listarMusica(musica, qtdMusica);
        } else if (decisao == '8') {
            testarMusica(musica, qtdMusica);
        } else if (decisao == '9') {
            printf("\nListando todas as suas playlists...\n");
            for (i = 0; i < usuarios[indice].qtdPlaylists; i++) {
                printf("\nPlaylist: %s\n", usuarios[indice].playlists[i].titulo);
                printf("Código da Playlist: %d\n", usuarios[indice].playlists[i].codigo);
                printf("Criada por: %s\n", usuarios[binarySearchUser(usuarios, usuarios[indice].playlists[i].codUsuario, qtdUser)].nome);
                printf("Músicas:\n");
                for (int j = 0; j < usuarios[indice].playlists[i].qtdMusicas; j++) {
                    int codigoMusica = usuarios[indice].playlists[i].musicas[j];
                    printf("\t%s - %s\n", musica[binarySearchC(musica, codigoMusica, qtdMusica)].titulo, musica[binarySearchC(musica, codigoMusica, qtdMusica)].artista);
                }
                printf("\n");
            }
        } else if (decisao == 'a') {
            adicionarPlaylist(usuarios, &qtdUser, &posicaoUser, musica, qtdMusica);
        } else if (decisao == 'e') {
            excluirPlaylist(usuarios, &qtdUser, &posicaoUser);
        }
        else if (decisao == 'f') {
            excluirMusicaPlaylist(usuarios, qtdUser, indice, musica, qtdMusica);
} else if (decisao == 'g'){
      consultarPlaylists(usuarios, qtdUser, usuarios[indice].codigo, -1, "", -1);
}

    }
    
    return '1';
}
void adicionarPlaylist(Usuario usuarios[], int *qtdUser, int posicaoUser, Musica musicas[], int qtdMusicas) {
    if (*qtdUser < TAM_USER) {
        // Código para adicionar uma nova playlist
        int indiceUsuario = 0; // Defina o índice do usuário que está adicionando a playlist
        if (usuarios[indiceUsuario].qtdPlaylists < TAM_PLAYLIST) {
            Playlist novaPlaylist;
            novaPlaylist.codigo = usuarios[indiceUsuario].qtdPlaylists + 1;
            novaPlaylist.codUsuario = usuarios[indiceUsuario].codigo;
            
            printf("Digite o título da nova playlist: ");
            fgets(novaPlaylist.titulo, TAM_TITULO, stdin);
            novaPlaylist.titulo[strcspn(novaPlaylist.titulo, "\n")] = '\0'; // Remover o '\n' do final da string
            
            novaPlaylist.qtdMusicas = 0; // Inicializa a quantidade de músicas na playlist como zero
            
            // Adicionar músicas à playlist
            int decisao = -1;
            while (decisao != 0) {
                printf("Deseja adicionar uma música a esta playlist?\n");
                printf("Digite 1 para adicionar ou 0 para sair: ");
                scanf("%d", &decisao);
                getchar();
                printf("\n");
                
                if (decisao == 1) {
                    // Listar as músicas disponíveis
                    listarMusicasDisponiveis(musicas, qtdMusicas);
                    
                    int codigoMusica;
                    printf("Digite o código da música que deseja adicionar: ");
                    scanf("%d", &codigoMusica);
                    getchar();
                    
                    // Verificar se o código da música é válido
                    int indiceMusica = -1;
                    for (int i = 0; i < qtdMusicas; i++) {
                        if (musicas[i].codigo == codigoMusica) {
                            indiceMusica = i;
                            break;
                        }
                    }
                    
                    if (indiceMusica != -1) {
                        // Adicionar a música à playlist
                        adicionarMusicaAPlaylist(&novaPlaylist, musicas, qtdMusicas, &novaPlaylist.qtdMusicas);
                        novaPlaylist.musicas[novaPlaylist.qtdMusicas - 1] = codigoMusica;
                        printf("Música adicionada com sucesso!\n");
                    } else {
                        printf("Código de música inválido!\n");
                    }
                } else if (decisao != 0) {
                    printf("Opção inválida!\n");
                }
            }
            
            // Adicionar a nova playlist ao usuário
            usuarios[indiceUsuario].playlists[usuarios[indiceUsuario].qtdPlaylists] = novaPlaylist;
            usuarios[indiceUsuario].qtdPlaylists++;
            printf("Playlist adicionada com sucesso!\n\n");
        } else {
            printf("O usuário já atingiu o limite máximo de playlists!\n\n");
        }
    } else {
        printf("Número máximo de usuários atingido!\n\n");
    }
}

void excluirPlaylist(Usuario usuarios[], int *qtdUser, int *posicaoUser) {
    int codigoPlaylist;
    printf("Digite o código da playlist que deseja excluir: ");
    scanf("%d", &codigoPlaylist);
    getchar();
    
    int indiceUsuario = 0; // Defina o índice do usuário
    
    // Procurar a playlist pelo código e removê-la
    for (int i = 0; i < usuarios[indiceUsuario].qtdPlaylists; i++) {
        if (usuarios[indiceUsuario].playlists[i].codigo == codigoPlaylist) {
            // Remover a playlist encontrada
            for (int j = i; j < usuarios[indiceUsuario].qtdPlaylists - 1; j++) {
                usuarios[indiceUsuario].playlists[j] = usuarios[indiceUsuario].playlists[j + 1];
            }
            usuarios[indiceUsuario].qtdPlaylists--;
            printf("Playlist excluída com sucesso!\n");
            return; // Saia da função após excluir a playlist
        }
    }
    
    printf("Playlist não encontrada!\n");
}

        
void listarDadoUsuario(Usuario usuarios[], int indice){
    
    printf("\nNome: %s\n", usuarios[indice].nome);
    printf("Login: %s\n", usuarios[indice].login);
    printf("Código: %d\n\n", usuarios[indice].codigo);
}

void mudarNome(Usuario usuarios[], int indice, char senhaUsuario[], int qtdUser){
    printf("\n\nConfirme a senha para realizar esta ação:\n");
    fgets(senhaUsuario, TAM_SENHA, stdin);
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';
    if(strcmp(usuarios[indice].senha, senhaUsuario)==0){
        memset(usuarios[indice].senha, '\0', strlen(usuarios[indice].senha));
        printf("\nPonha o seu novo nome:\n");
        fgets(usuarios[indice].nome, TAM_NOME, stdin);
        usuarios[indice].nome[strcspn(usuarios[indice].nome, "\n")] = '\0';
        orndenarContas(usuarios, qtdUser);
    }
    else{
        printf("\nMudança não permitida!\n");
    }
}
void mudarLogin(Usuario usuarios[], int indice, char senhaUsuario[], int qtdUser){
    printf("\n\nConfirme a senha para realizar esta ação:\n");
    fgets(senhaUsuario, TAM_SENHA, stdin);
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';
    if(strcmp(usuarios[indice].senha, senhaUsuario)==0){
        printf("\nPonha o seu novo login:\n");
        fgets(usuarios[indice].login, TAM_LOGIN, stdin);
        usuarios[indice].login[strcspn(usuarios[indice].login, "\n")] = '\0';
        orndenarContas(usuarios, qtdUser);
    }
    else{
        printf("\nMudança não permitida!\n");
    }
}
void mudarSenha(Usuario usuarios[], int indice, char senhaUsuario[], int qtdUser){
    printf("\n\nConfirme a senha para realizar esta ação:\n");
    fgets(senhaUsuario, TAM_SENHA, stdin);
    senhaUsuario[strcspn(senhaUsuario, "\n")] = '\0';
    if(strcmp(usuarios[indice].senha, senhaUsuario)==0){
        printf("\nPonha a nova senha:\n");
        fgets(usuarios[indice].senha, TAM_SENHA, stdin);
        usuarios[indice].senha[strcspn(usuarios[indice].senha, "\n")] = '\0';
        char confirmar[TAM_SENHA];
        printf("Confirme a senha:\n");
        fgets(confirmar, TAM_SENHA, stdin);
        confirmar[strcspn(confirmar, "\n")] = '\0';
        while(strcmp(usuarios[indice].senha, confirmar)!=0){
            printf("Ponha a senha correta:\n");
            fgets(confirmar, TAM_SENHA, stdin);
            confirmar[strcspn(confirmar, "\n")] = '\0';
        }
    }
    else{
        printf("\nMudança não permitida!\n");
    }
}
void listarUserNomes(Usuario usuarios[], int qtdUser)
{
    orndenarNomes(usuarios, qtdUser);
    printf("\n");
    for(int i = 0; i < qtdUser; i++){
        printf("Nome: %s", usuarios[i].nome);
        printf("\n");
    }
    printf("\n");
}
int binarySearchStart(Usuario usuarios[], char name[], int qtdUser) {
    int beggin = 0;
    int end = qtdUser - 1;
    while (beggin <= end) {
        int indice = (beggin + end) / 2;
        if (strstr(usuarios[indice].nome, name) != NULL) {
            
            while (indice > 0 && strstr(usuarios[indice-1].nome, name) != NULL) {
                indice--;
            }
            return indice;
        }
        else if (strcmp(usuarios[indice].nome, name) < 0) {
            beggin = indice + 1;
        }
        else {
            end = indice - 1;
        }
    }
    return -1;
}

void pesquisarUsuario(Usuario usuarios[], int qtdUser) {
    char user[TAM_LOGIN];
    printf("\nPesquise o usuário:\n\n");
    fgets(user, TAM_LOGIN, stdin);
    user[strcspn(user, "\n")] = '\0'; // Remove o '\n' do final da string
    orndenarNomes(usuarios, qtdUser);
    int c = binarySearchStart(usuarios, user, qtdUser);
    if (c != -1) {
        
        int found = 0;
        for (int i = c; i < qtdUser && strstr(usuarios[i].nome, user) != NULL; i++) {
            printf("Usuário encontrado: %s\n", usuarios[i].nome);
            printf("Login: %s\n", usuarios[i].login);
            printf("Código: %d\n", usuarios[i].codigo);
            found = 1;
        }
        if (!found) {
            printf("Não há usuário.\n");
        }
    } else {
        printf("Não há usuário.\n");
    }
}
void pesquisarLogin(Usuario usuarios[], int qtdUser, char login[]){
    printf("Digite o email do usuário:\n");
    fgets(login, TAM_LOGIN, stdin);
    login[strcspn(login, "\n")] = '\0';
    orndenarContas(usuarios, qtdUser);
    int c = binarySearchLogin(usuarios, login, qtdUser);
    if(c!=-1){
        printf("\nNome: %s\n", usuarios[c].nome);
        printf("Login: %s\n", usuarios[c].login);
        printf("Código: %d\n", usuarios[c].codigo);
    }
    else{
        printf("Usuário não foi encontrado.\n");
    }
    
}

int binarySearchStartMusica(Musica musica[], char name[], int qtdMusica) {
    int beggin = 0;
    int end = qtdMusica - 1;
    while (beggin <= end) {
        int indice = (beggin + end) / 2;
        if (strstr(musica[indice].titulo, name) != NULL) {
            
            while (indice > 0 && strstr(musica[indice-1].titulo, name) != NULL) {
                indice--;
            }
            return indice;
        }
        else if (strcmp(musica[indice].titulo, name) < 0) {
            beggin = indice + 1;
        }
        else {
            end = indice - 1;
        }
    }
    return -1;
}

void pesquisarMusica(Musica musica[], int qtdMusica) {
    char user[TAM_TITULO];
    printf("\nPesquise a música:\n\n");
    fgets(user, TAM_TITULO, stdin);
    user[strcspn(user, "\n")] = '\0'; 
    ordenarMusica(musica, qtdMusica);
    int c = binarySearchStartMusica(musica, user, qtdMusica);
    if (c != -1) {
        
        int found = 0;
        for (int i = c; i < qtdMusica && strstr(musica[i].titulo, user) != NULL; i++) {
            printf("Música encontrada: %s\n", musica[i].titulo);
            printf("Artísta: %s\n", musica[i].artista);
            printf("Código: %d\n", musica[i].codigo);
            found = 1;
        }
        if (!found) {
            printf("Música não encontrada.\n");
        }
    } else {
        printf("Música não encontrada.\n");
    }
}

void testarMusica(Musica musica[], int qtdMusica){
    char p = '.';
    while(p!='0'){
        printf("\nDigite 1: Código\nDigite 2: Nome\nDigite 3: Artista\nDigite 0: Sair\n");
        scanf("%c", &p);
        getchar();
        if(p == '1'){
            int cod;
            printf("Digite o código da música:\n");
            scanf("%d", &cod);
            getchar();
            ordenarMusicaCodigo(musica, qtdMusica);
            int c =binarySearchC(musica, cod ,qtdMusica);
            if(c!=-1){
                printf("Título: %s\n", musica[c].titulo);
                printf("Artísta: %s\n", musica[c].artista);
                printf("Código: %d\n", musica[c].codigo);
            }else{
                printf("Música não encontrada.\n");
            }
        }else if(p == '2'){
            pesquisarMusica(musica, qtdMusica);
        }else if(p=='3'){
            pesquisarArtista(musica, qtdMusica);
        }
    }
}
void pesquisarUsuarioUser(Usuario usuarios[], int qtdUser) {
    char user[TAM_LOGIN];
    printf("\nPesquise o usuário:\n\n");
    fgets(user, TAM_LOGIN, stdin);
    user[strcspn(user, "\n")] = '\0'; // Remove o '\n' do final da string
    orndenarNomes(usuarios, qtdUser);
    int c = binarySearchStart(usuarios, user, qtdUser);
    if (c != -1) {
        
        int found = 0;
        for (int i = c; i < qtdUser && strstr(usuarios[i].nome, user) != NULL; i++) {
            printf("Usuário encontrado: %s\n", usuarios[i].nome);
            
            found = 1;
        }
        if (!found) {
            printf("Não há usuário.\n");
        }
    } else {
        printf("Não há usuário.\n");
    }
}
int binarySearchStartArtista(Musica musica[], char name[], int qtdMusica) {
    int beggin = 0;
    int end = qtdMusica - 1;
    while (beggin <= end) {
        int indice = (beggin + end) / 2;
        if (strstr(musica[indice].artista, name) != NULL) {
            
            while (indice > 0 && strstr(musica[indice-1].artista, name) != NULL) {
                indice--;
            }
            return indice;
        }
        else if (strcmp(musica[indice].artista, name) < 0) {
            beggin = indice + 1;
        }
        else {
            end = indice - 1;
        }
    }
    return -1;
}

void pesquisarArtista(Musica musica[], int qtdMusica) {
    char user[TAM_TITULO];
    printf("\nPesquise o artista:\n\n");
    fgets(user, TAM_TITULO, stdin);
    user[strcspn(user, "\n")] = '\0'; 
    ordenarMusicaArtista(musica, qtdMusica);
    int c = binarySearchStartArtista(musica, user, qtdMusica);
    if (c != -1) {
        
        int found = 0;
        for (int i = c; i < qtdMusica && strstr(musica[i].artista, user) != NULL; i++) {
            printf("Música encontrada: %s\n", musica[i].titulo);
            printf("Artísta: %s\n", musica[i].artista);
            printf("Código: %d\n\n", musica[i].codigo);
            found = 1;
        }
        if (!found) {
            printf("Musica não encontrada.\n");
        }
    } else {
        printf("Musica não encontrada.\n");
    }
}
void consultarPlaylists(Usuario usuarios[], int qtdUsuarios, int codUsuario, int codPlaylist, char parteTitulo[], int codMusica) {
    int i, j, k, l;
    for (i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigo == codUsuario) {
            printf("Playlists do usuário %s:\n", usuarios[i].nome);
            for (j = 0; j < usuarios[i].qtdPlaylists; j++) {
                if (codPlaylist != -1 && usuarios[i].playlists[j].codigo == codPlaylist) {
                    printf("Código da Playlist: %d\n", usuarios[i].playlists[j].codigo);
                    printf("Título: %s\n", usuarios[i].playlists[j].titulo);
                    printf("Criador: %s\n", usuarios[i].nome);
                    printf("Músicas:\n");
                    for (k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                        printf("\t%d - %s\n", usuarios[i].playlists[j].musicas[k], "Nome da Música"); // Nome da música pode ser obtido a partir do código da música
                    }
                }
                else if (strstr(usuarios[i].playlists[j].titulo, parteTitulo) != NULL) {
                    printf("Código da Playlist: %d\n", usuarios[i].playlists[j].codigo);
                    printf("Título: %s\n", usuarios[i].playlists[j].titulo);
                    printf("Criador: %s\n", usuarios[i].nome);
                    printf("Músicas:\n");
                    for (k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                        printf("\t%d - %s\n", usuarios[i].playlists[j].musicas[k], "Nome da Música"); // Nome da música pode ser obtido a partir do código da música
                    }
                }
                else {
                    for (l = 0; l < usuarios[i].playlists[j].qtdMusicas; l++) {
                        if (usuarios[i].playlists[j].musicas[l] == codMusica) {
                            printf("Código da Playlist: %d\n", usuarios[i].playlists[j].codigo);
                            printf("Título: %s\n", usuarios[i].playlists[j].titulo);
                            printf("Criador: %s\n", usuarios[i].nome);
                            printf("Músicas:\n");
                            for (k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                                printf("\t%d - %s\n", usuarios[i].playlists[j].musicas[k], "Nome da Música"); // Nome da música pode ser obtido a partir do código da música
                            }
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
}