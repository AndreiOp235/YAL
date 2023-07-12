Aplicatie pentru managementul unei biblioteci

Functiile necesare rularii au fost impartite in 3 categorii:
1. Manipulare stringuri
	a) functia "cuvant" returneaza un singur cuvant din tot sirul, delimitator implicit este considerat un SINGUR spatiu
	b) functia "interclasare" reuneste eficient 2 vectori deja sortati. Rezultatul este tot un vector sortat
	c) functia "SI" realizeaza reuniunea a vectorului de la punctul b). Se pleaca de la idee ca un element ce se afla in ambele multimi, trebuie sa EXISTE de 2 ori in vectorul reunit. Prima copie se sterge, a 2 ramane pe loc 
	d) functia "afisareVector" se explica din prototip
	e) functia "exista" cauta eficient intr-un vector deja sortat daca respectivul element face parte din multime

2. Manipulare Hash Table
	a) functia "modKey" returneaza hash-ul unei chei de tip string. Se ia in vederea dimensiunii tabelei prin acces la variabila globala sizeH
	b) functia "insertHT" creaza si insereaza elemente din HashTable mentinand valorile cheilor sortate lexicografic. Creerea unei noi chei este contorizata fiind necesar pentru alte functii
	c) functia "redimensionare", pleaca de la un HashTable de dimensiune sizeH si returneaza unul de dimensiune dubla. Practic se muta pointerii elementelor dintr-un vector in altul respectand proprietatile de HashTable. Elementele fiind pointeri nu este necesara eliberarea memoriei in momentul executiei.
	d) functia "calcFI" returneaza factorul de incarcare al tabelei de dispersie utilizandu-se de variabilele globale ce ii definesc parametrii

3. Meniu
	a) functia "help" afiseaza un meniu minimal ce ofera sintaxa fiecarei instructiuni, extrase din cerintele clientului
	b) functia "PUTb" aferenta comenzii PUT insereaza fiecare valoare aferenta unei chei. La terminarea valorilor se verifica daca are sens redimensionarea tabelei.
	c) functia "GETb" aferenta comenzii GET trateaza 2 cazuri: primul cel in care se cer titlurile unei chei si celalalt cand e necesara si intersectia valorilor. A ridicat un grad de complexitate aparte prin ansamblul de functii necesare.
	d) functia "PLAYb" aferenta comenzii PLAY este aborbata mai jos in document.

Functia PLAY putea fi scrisa in 2 moduri:
1. inversand legaturile din HT, obtinand eficienta foarte buna pe partea de timp (se verifica daca vectorul cheii titlu contine toate valorile din cuvinte), dar necesitand spatiu suplimentar de memorie pentru retinearea legaturilor bidirectionale
2. utilizand functiile de interclasare si reuniune de la operatia GET. Pentru fiecare cuvant se genereaza intersectia de titluri ce le contine. Daca titlul din play apartine vectorului de solutii se afiseaza YOU WIN. Pentru a o optimaza cautarea in acest vecttor sortat am apelat la metoda cautarii binare.

Daca Tabela de dispersie era implementata conform primei metode din cerinta, ar fi avut mai mult sens modul 1 pentru PLAY. Discutia este favorizarea functiei GET in detrimentul celei de PLAY

Interactiunea cu consola se face asemantor unei baze date mentionand instructiunea si dupa optiunile aferente
Utilizarea metodelor aferente clasei string si vector a facilitat implementarea rapida a unor operatii pentru care in cerinta nu era mentionata o metoda anume.
Alte metode din algorithm/standard de asemenea au redus timpul de scriere al aplicatiei.

Tratarea erorilor nu a fost menționată explicit, așadar am presupus că utilizatorul va introduce date corecte.
Cu toate acestea, datorită versatilității stringurilor și vectorilor utilizate, funcțiile pot fi rulate și cu valori de intrare vide, iar în acest caz se va afișa un mesaj corespunzător în cazul în care nu există valori de returnat.

Software offered under the MIT license, and not limited to 
"The software is provided AS IS, without warranty of any kind, express or implied"

Andrei Valeriu Cosa,
AC_1204B

/* DATE TEST
PUT Morometii sat viata tarani lupta familie traditii destin iubire putere conflict
PUT Enigma mostenire dragoste dezamagire societate tradare pasiune secrete invidie ipocrizie instrainare
PUT Ion iubire tara saracie dorinta sacrificiu razboi destin tradare constiinta putere
PUT Maitreyi iubire India exotism calatorie confuzie cultura pasiune conflict descoperire regasire
PUT Baltagul cautare mister natura legenda justitie traditii sacrificiu responsabilitate vanatoare supravietuire
PUT Ultima dragoste casatorie inselaciune razboi decadere framantare constiinta obsesie suferinta autodezvaluire
PUT Rascoala tarani rascoala inechitate revolutie eroism tradare opresiune libertate speranta justitie
PUT Calatorie razboi suferinta disperare umor absurd umanitate calatorie boala cautare introspectie
PUT Padurea razboi eroism sacrificiu tradare iubire lupta onoare suferinta destin libertate
PUT Nunta mit religie moarte transcendentă misticism cautare spiritualitate metamorfoza ritual sacru
PUT Mortii sat razboi viata camaraderie sacrificiu iubire speranta renaștere
PUT Ciuleandra pasiune dans dragoste traditii invidie obsesie trădare destinare răscruce
PUT Padurea test test
PUT Mesterul legenda constructie sacrificiu mister dragoste supravietuire mitologie instrainare
PUT Moara dorinta putere război înșelăciune trădare responsabilitate vinovatie secret
PUT Calatoriile aventura satira calatorie umor fantastice instrainare explorare transformare
PUT Levantica iubire pasiune obsesie sexualitate instrainare libertate revolutie egoism sacrificiu
PUT Nopti exotism calatorie spiritualitate obsesie iubire renuntare mister
PUT Cel iubire sacrificiu calatorie introspectie moarte misticism transcendentă existenta
PUT Romanul adolescenta cautare identitate prietenie dragoste dezamagire suferinta descoperire regasire
PUT T1 c1 c2 c3
PUT T2 c1 c3 c2
PUT T3 c1 c2 c3
GET iubire tarani
GET c1
GET c1 c2
GET c1 c3 c2
GET c1 c3 c2 test
PLAY T1 c1
PLAY T1 c3
PLAY T1 c3 c2
PLAY T1 c3 c2 test

*/
Datele de text pentru comanda PUT au fost generate cu ChatGPT dupa urmatorul set
1. da-mi o lista de 10 carti romanesti cu cate 10 cuvinte cheie ce se regasesc in ele
2. rescrie lista cu acest template
PUT <titlu> <cuvant1> <cuvant2> ... <cuvant10>
3. elimina " si diacriticele

S-au adaugat date critice pentru a verifica cazurile limita.