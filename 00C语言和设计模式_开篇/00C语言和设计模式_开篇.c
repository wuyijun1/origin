
#include 


typedef struct _music_file
{
    HANDLE hFile;
    void (*read_file)(struct _music_file* pMusicFile);
    void (*play)(struct _music_file* pMusicFile);
    void (*stop)(struct _music_file* pMusicFile);
    void (*back)(struct _music_file* pMusicFile);
    void (*front)(struct _music_file* pMusicFile);
    void (*down)(struct _music_file* pMusicFile);
    void (*up)(struct _music_file* pMusicFile);           
}music_file;

