# Čtečka novinek ve formátu Atom a RSS s podporou TLS

Autor: Vladislav Mikhed

## Popis
Byla implementována RRS čtečka,která bude vypisovat uživatelům informace uvedené ve stažených zdrojích.
Čtečka podporuje formáty RSS 2.0 a Atom.
## Poznamky
Pro překlad a spuštění projektu je nutné využít knihovny openSSL a nástroj pkg-config.  
## Překlad
Pro překlad je navržen Makefile. A pro překlad je nutné využít příkaz:
```
make
```
### Testováni
```
make test
```


## Spuštění
```
./feadreader <url addresa | -f <feedfile>> [-c <certfile>] [-C <certaddr>] [-T] [-a] [-u]
```
| Argumenty | Popis |
|---|---|
| url | adresa zdroje z kterého bude přijata informace pro výstup programu |
| -f <feedfile> | cesta do souboru feedfile. Soubor musí obsahovat v sobě jednotlivé zdroje, každý zdroj na jednom řádku, takže je možnost komentářů, řádek s komentářem musí se začínat # |
| -c <certfile> | cesta do certifikátu který bude využít pro ověřování serveru.
| -C <certaddr> | cesta do úložiště certifikátů, které bude možné použit pro ověřování serveru
| -T| pro každý záznam se zobrazí čas publikovaní nebo čas změny
| -a | pro každý záznam se zobrazí autor
| -u | pro každý záznam se zobrazí asociované url
| -h | vypíše návod na použití programu

Je nutné aby byl zadán jeden z parametru url nebo feedfile.
Parametry musí být odděleny mezerami.

## Příklad
```
./feedreader 'https://what-if.xkcd.com/feed.atom' -u -T -a
```


## Seznam souboru
- ./Connect.cpp  
- ./Connect.h  
- ./Error.cpp  
- ./Error.h  
- ./feedfile  
- ./FeedReader.cpp  
- ./FeedReader.h  
- ./main.cpp  
- ./ParseArguments.cpp  
- ./ParseArguments.h     
- ./UrlParser.cpp  
- ./UrlParser.h  
- ./XMLParser.cpp  
- ./XMLParser.h  
- ./test/complex/test.py  
- ./test/unit/Error.cpp  
- ./test/unit/test.cpp  
- ./test/unit/TestArgumentParser.cpp  
- ./test/unit/TestArgumentParser.h  
- ./test/unit/TestConnect.cpp  
- ./test/unit/TestConnect.h  
- ./test/unit/TestUrlParser.cpp  
- ./test/unit/TestUrlParser.h  
- ./test/unit/UnitTests.cpp  
- ./test/unit/UnitTests.h  
- ./test/feedlist  
- ./README  
- ./manual.pdf
- ./Makefile 