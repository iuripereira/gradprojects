#ifndef defOPCSigaH
#define defOPCSigaH

typedef struct {
                bool btCEvent;
                bool btSEvent;
                bool btTEvent;
                DWORD sevLow;
                DWORD sevHigh;
                DWORD countEventCategory;
                DWORD *ptEventCategories;
                DWORD numArea;
                LPWSTR *pszAreaList;
                DWORD numSources;
                LPWSTR *pszSourceList;
                string server;
                string host;
                string subscription;
}ESTRUTURA;

typedef struct {
                bool btCEvent;
                bool btSEvent;
                bool btTEvent;
                int sevLow;
                int sevHigh;
                int countEventCategory;
                string *ptEventCategories;
                int numArea;
                string *pszAreaList;
                int numSources;
                string *pszSourceList;
                int evtType;
}Filtro;



#endif
