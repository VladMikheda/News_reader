# ISA - Síťové aplikace a správa sítí
#### Projekt: Čtečka novinek ve formátu Atom a RSS s podporou TLS

Jmeno: Vladislav Mikhed  
Loguin: xmikhe00  
Datum vtvoreni: 5.11.2022


## Popis
Byla implementována RRS čtečka,která bude vypisovat uživatelům informace uvedené ve stažených zdrojích.\\
Čtečka podporuje formáty RSS 2.0 a Atom.
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

- url adresa zdroje z kterého bude přijata informace pro vystup programu  
- -f <feedfile> cesta do souboru \texttt{feedfile}. Soubor musí obsahovat v sobě jednotlivý zdroji každé zdroj na jednom řádku, takže je možnost komentářů, řádek s komentářem musí se začínat #  
- -c <certfile> cesta do certifikátu který bude využit pro ověřovaní serveru.  
- -C <certaddr> cesta do úložiště certifikátů, které bude možné použit pro ověřovaní serveru  
- -T pro každý záznam zobrazí čas publikovaní či čas změny  
- -a pro každý záznam zobrazí autor  
- -u pro každý záznam zobrazí asociované url

Je nutné aby byl zadán jeden z parametru url nebo feedfile.

## Seznam souboru
main.cpp
ParseArguments.cpp
ParseArguments.h
URLParser.cpp
URLParser.h
Connect.cpp
Connect.h
