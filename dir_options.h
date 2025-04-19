// dir_options.h

#ifndef DIR_OPTIONS_H
#define DIR_OPTIONS_H

#define MAX_FILES 100
#define MAX_FILENAME 256

// Função que preenche o array com nomes de arquivos .txt encontrados no diretório
// Retorna a quantidade de arquivos encontrados
int find_files(const char *relative_path, char files[][MAX_FILENAME], int max_files);

#endif // DIR_OPTIONS_H
