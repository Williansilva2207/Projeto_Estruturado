#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_LOGIN 20
#define TAM_SENHA 20
#define TAM_PLAYLIST 10
#define TAM_MUSICA 100

typedef struct {
    int codigo;
    char titulo[TAM_NOME];
    char artista[TAM_NOME];
}Musica;

typedef struct {
    int codigo;
    char titulo[TAM_NOME];
    int qtdMusicas;
    Musica musicas[TAM_MUSICA];
} Playlist;

typedef struct {
    int codigo;
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylist;
    Playlist playlists [TAM_PLAYLIST];
    int qtdPlaylistFav;
    int listPlaylistFav[TAM_PLAYLIST];
} Usuario;
int contadorPlaylist = 0;
int contadorMusicas = 0;
int contadorUsuarios = 0;
Usuario usuarios[100];
Musica musicas[TAM_MUSICA];
int autoincremento(int *contar){}