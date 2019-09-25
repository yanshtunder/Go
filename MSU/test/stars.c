#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <string.h>

int main() {
    setlocale(LC_CTYPE, "");
    wchar_t* word1 = (wchar_t* )malloc(1024);
    wchar_t* word2 = (wchar_t* )malloc(1024);
    wchar_t* word3 = (wchar_t* )malloc(1024);

    wscanf(L"%ls", word1);
    wscanf(L"%ls", word2);
    wscanf(L"%ls", word3);
    wchar_t* words[4] = {word1, word2, word3, NULL};
    wchar_t** w = words;
    wchar_t endword[] = L"END";
    bool end = false;
    bool nextWord = false;
    while (*w != NULL) {
        nextWord = false;
        wprintf(L"Новое слово, букв: %d\n", wcslen(*w));
        wchar_t* l = (wchar_t* )malloc(1024);
        wchar_t* stars = (wchar_t* )malloc(sizeof(wchar_t) * (wcslen(*w) + 1));
        for (int i = 0; i < wcslen(*w); ++i) {
            stars[i] = L'*';
        }
        stars[wcslen(*w)] = '\0';
        while (!nextWord) {
            wscanf(L"%ls", l);
            if (wcslen(l) == 1) {
                for (int i = 0; i < wcslen(*w); ++i) {
                    if (*(*w + i) == *l) {
                        stars[i] = *(*w + i);
                    }
                }
                for (int i = 0; i < wcslen(*w); ++i) {
            		if (stars[i] == '*') {
                		nextWord = false;
                		break;
            		}
            		else
            			nextWord = true;
        		}
                
                wprintf(L"%ls\n", stars);
            } else if (memcmp(l, endword, sizeof(wchar_t) * wcslen(l)) == 0) {
                end = true;
                break;
            } else {
                wprintf(L"Введите 1 букву\n");
            }
        }
        if (end) {
            break;
        }
        w++;
        free(l);
        free(stars);
    }

    w = words;
    while (*w != NULL) {
        w++;
        free(*w);
    }
    return 0;
}

//http://ideone.com/c5CEfi

