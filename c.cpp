#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <regex>

using namespace std;


string availableNames[]={
"Katti",
"Lizzie",
"Rossy",
"Bette",
"Hortensia",
"Marlo",
"Dacia",
"Rosie",
"Tymon",
"Belicia",
"Anatol",
"Ive",
"Bondon",
"Allix",
"Penny",
"Fan",
"Benny",
"Pierre",
"Andriette",
"Latia",
"Charil",
"Luke",
"Cletus",
"Hilliard",
"Ollie",
"Nonah",
"Annissa",
"Antonietta",
"Tyrus",
"Elfrieda",
"Philly",
"Meredithe",
"Bernadette",
"Dyna",
"Chucho",
"Pyotr",
"Constantin",
"Chilton",
"Bradly",
"Kaspar",
"Rosy",
"Leslie",
"Rozelle",
"Herbie",
"Rachael",
"Jamill",
"Nikolaos",
"Bengt",
"Cassandry",
"Eilis",
"Brose",
"Oran",
"Donnie",
"Desmond",
"Darelle",
"Jerrome",
"Kimmi",
"Mycah",
"Phaedra",
"Vanessa",
"Rinaldo",
"Alica",
"Daniela",
"Jasmin",
"Forrester",
"Harli",
"Tommy",
"Vivyanne",
"Adolpho",
"Eloise",
"Andrea",
"Clerc",
"Felipa",
"Pembroke",
"Aloin",
"Coralie",
"Harlan",
"Lexine",
"Yorgo",
"Tatum",
"Margarita",
"Gerik",
"Debor",
"Ofilia",
"Holmes",
"Phil",
"Doloritas",
"Aldric",
"Mavis",
"Elsy",
"Mal",
"Melly",
"Brock",
"Bryant",
"Montgomery",
"Nani",
"Thia",
"Stanislaw",
"Jacquette",
"Shannan",
"Padriac",
"Hewitt",
"Brena",
"Rebe",
"Delia",
"Marci",
"Art",
"Lucian",
"Garrot",
"Aila",
"Gerty",
"Sam",
"Tiler",
"Flynn",
"Starlin",
"Parnell",
"Huberto",
"Emile",
"Rosco",
"Flora",
"Meridel",
"Melvin",
"Poppy",
"Clary",
"Aliza",
"Ike",
"Toddie",
"Tremain",
"Rozele",
"Elissa",
"Livy",
"Madelle",
"Xever",
"Abigail",
"Katerine",
"Adrien",
"Mikkel",
"Towny",
"Cleve",
"Chauncey",
"Dede",
"Hewett",
"Laurette",
"Adolph",
"Pearline",
"Cullin",
"Gerome",
"Ilysa",
"Aleksandr",
"Glendon",
"Jerri",
"Annadiane",
"Salaidh",
"Sharia",
"Tanner",
"Bertrando",
"Josephina",
"Luther",
"Bradney",
"Ola",
"Henryetta",
"Lorita",
"Samara",
"Clo",
"Kevyn",
"Duff",
"Delora",
"Wynnie",
"Granger",
"Roderick",
"Davida",
"Millie",
"Concettina",
"Hillary",
"Emelda",
"Falkner",
"Felicio",
"Katey",
"Helena",
"Clayborn",
"Melva",
"Abby",
"Lenka",
"Jan",
"Melisa",
"Germaine",
"Luz",
"Heath",
"Pierce",
"Fairlie",
"Phedra",
"Yvette",
"Jdavie",
"Kizzie",
"Terry",
"Nancie",
"Christophe",
"Saloma",
"Vanya",
"Neila",
"Issie",
"Candy",
"Sander",
"Massimiliano",
"Gustaf",
"Orv",
"Bidget",
"Sol",
"Pincas",
"Vania",
"Trstram",
"Orella",
"Fidelity",
"Claresta",
"Hinda",
"Avictor",
"Ilario",
"Somerset",
"Jacquetta",
"Hastings",
"Simonne",
"Thibaud",
"Paul",
"Tyne",
"Elyssa",
"Kermy",
"Dari",
"Haroun",
"Denis",
"Moss",
"Marcellina",
"Weston",
"Rochette",
"Tawsha",
"Michel",
"Blinny",
"Benedick",
"Stafford",
"Bathsheba",
"Cleve",
"Deva",
"Phillipp",
"Peyton",
"Sandra",
"Kandace",
"Selma",
"Hilda",
"Eveleen",
"Deane",
"Ruthie",
"Merrili",
"Corabel",
"Keely",
"Carlotta",
"Fredelia",
"Normy",
"Peri",
"Estelle",
"Demetris",
"Erich",
"Claudina",
"Vannie",
"Sauncho",
"Halsy",
"Abra",
"Court",
"Max",
"Harcourt",
"Pearla",
"Collen",
"Vivie",
"Gayel",
"Far",
"Tracie",
"Norman",
"Jodee",
"Mikkel",
"Idelle",
"Lenora",
"Pip",
"Hollis",
"Melanie",
"Mickie",
"Farrand",
"Opalina",
"Xever",
"Estrellita",
"Barton",
"Gratiana",
"Marne",
"Veda",
"Alene",
"Muire",
"Krispin",
"Valle",
"Kliment",
"Carol",
"Levi",
"Ruperta",
"Sammie",
"Roch",
"Erinna",
"Lawry",
"Berenice",
"Klemens",
"Marlena",
"Renault",
"Ross",
"Lurette",
"Josey",
"Bevvy",
"Millie",
"Elliott",
"Catharina",
"Shea",
"Gelya",
"Gerda",
"Zerk",
"Bev",
"D'arcy",
"Storm",
"Wesley",
"Rosemonde",
"Stevana",
"Prudy",
"Pepillo",
"Tasha",
"Nara",
"Dell",
"Trixy",
"Adeline",
"Pattie",
"Levy",
"Sayre",
"Izaak",
"Valentine",
"Kin",
"Haskell",
"Malynda",
"Pavia",
"Egon",
"John",
"Kiley",
"Hayward",
"Giles",
"Noble",
"Andria",
"Leisha",
"Molly",
"Ethelyn",
"Georgetta",
"Maurits",
"Sullivan",
"Bob",
"Candie",
"Hilary",
"Robinet",
"Aurea",
"Sibby",
"Alyssa",
"Sula",
"Rozamond",
"Talbert",
"Zackariah",
"Bertine",
"Lewes",
"Lester",
"Innis",
"Karlan",
"Lavina",
"Hyacinthe",
"Cyril",
"Yul",
"Nichol",
"Baudoin",
"Zonda",
"Bennie",
"Kyla",
"Christy",
"Anne-corinne",
"Anatol",
"Florenza",
"Bram",
"Sianna",
"Phillie",
"Clemmie",
"Atlanta",
"Quill",
"Stephan",
"Dennis",
"Riordan",
"Morgan",
"Rose",
"Cacilia",
"Layney",
"Chev",
"Stanislaus",
"Alleyn",
"Alicea",
"Sydelle",
"Elfrieda",
"Josiah",
"Julita",
"Lazarus",
"Douglass",
"Orion",
"Cly",
"Edlin",
"Ethelind",
"Chen",
"Seline",
"Lucho",
"Irwinn",
"Clerc",
"Waverley",
"Gayle",
"Neddy",
"Wendye",
"Alyosha",
"Tarah",
"Dione",
"Paolina",
"Barbara",
"Gerrie",
"Sergent",
"Darci",
"Vito",
"Tremayne",
"Kai",
"Linea",
"Chrissie",
"Debera",
"Jammie",
"Madison",
"Hyacinthie",
"Virginie",
"Nathanil",
"Allan",
"Kirstin",
"Astra",
"Oneida",
"Berny",
"Mychal",
"Darrel",
"Bettina",
"Janetta",
"Esme",
"Ailis",
"Wilhelmine",
"Brandise",
"Brucie",
"Ase",
"Corena",
"Drusi",
"Nicolais",
"Gilda",
"Ciro",
"Viola",
"Pattin",
"Lira",
"Killie",
"Deeann",
"Marja",
"Rae",
"Jana",
"Giralda",
"Deane",
"Orv",
"Nonie",
"Marice",
"Elenore",
"Kent",
"Davin",
"Costanza",
"Chlo",
"Jacqui",
"Jeffry",
"Bendick",
"Darrell",
"Saleem",
"Tobe",
"Conway",
"Bernette",
"Daisie",
"Kerr",
"Marie-jeanne",
"Malcolm",
"Cesar",
"Dun",
"Annissa",
"Hershel",
"Vanny",
"Corbett",
"Vladimir",
"Caron",
"Sherman",
"Waly",
"Mendy",
"Torrie",
"Tiphanie",
"Deeyn",
"Dorothy",
"Pace",
"Susanna",
"Kelsey",
"Illa",
"Natasha",
"Rivy",
"Celia",
"Gauthier",
"Denni",
"Hanna",
"Paige",
"Jens",
"Anitra",
"Odetta",
"Ninon",
"Iormina",
"Cilka",
"Claire",
"Jeane",
"Sabine",
"Billi",
"Odille",
"Mufi",
"Alikee",
"Karalee",
"Granger",
"Roxie",
"Field",
"Sargent",
"Gael",
"Aundrea",
"Celestia",
"Brucie",
"Shepard",
"Lurleen",
"Craggie",
"Job",
"Siward",
"Dacey",
"Eadmund",
"Budd",
"Oswald",
"Franny",
"Tremain",
"Kellby",
"Toiboid",
"Helge",
"Sophia",
"Justinian",
"Garvin",
"Jerrilee",
"Duane",
"Aldus",
"Kimberli",
"Darryl",
"Nil",
"Isak",
"Hillyer",
"Ody",
"Bertie",
"Carol",
"Laurent",
"Bryan",
"Zita",
"Bessie",
"Nola",
"Teodoor",
"Niccolo",
"Deina",
"Jacklyn",
"Editha",
"Armando",
"Brittan",
"Gizela",
"Burgess",
"Amalie",
"Amabel",
"Lainey",
"Jennica",
"Selina",
"Cirilo",
"Griz",
"Lynne",
"Conrado",
"Esma",
"Farly",
"Aline",
"Eilis",
"Thaine",
"Manfred",
"Ursuline",
"Andriette",
"Ax",
"Emmie",
"Jens",
"Hi",
"Kerrill",
"Jackie",
"Kalina",
"Iona",
"Christiana",
"Leyla",
"Arlette",
"Ingeborg",
"Helen-elizabeth",
"Zebadiah",
"Berkley",
"Priscilla",
"Lane",
"Sol",
"Marja",
"Catlaina",
"Ashley",
"Mitch",
"Tedman",
"Ronda",
"Cheston",
"Pip",
"Gianina",
"Adolphe",
"Reina",
"Clarke",
"Chrystal",
"Dene",
"Hesther",
"Augusta",
"Aarika",
"Aubrey",
"Abigail",
"Doreen",
"Marcus",
"Annamaria",
"Kari",
"Wilma",
"Dehlia",
"Zuzana",
"Deeyn",
"Stanford",
"Philbert",
"Eliot",
"Deeanne",
"Fan",
"Cheslie",
"Lyndell",
"Rosabel",
"Weber",
"Ebba",
"Sibyl",
"Fran",
"Cody",
"Cathrin",
"Kimmie",
"Garrik",
"Kelsey",
"Hobey",
"Celene",
"Kizzee",
"Catarina",
"Gabbi",
"Henrieta",
"Aron",
"Gray",
"Holmes",
"Edmon",
"Angelique",
"Michael",
"Nye",
"Raynell",
"Corbett",
"Rozalie",
"Osbert",
"Maje",
"Deanne",
"Aurelie",
"Vinita",
"Auberon",
"Brandtr",
"Jeane",
"Jean",
"Vivianne",
"Lesley",
"Stevie",
"Linette",
"Travers",
"Roana",
"Judy",
"Suki",
"Jerrie",
"Ruby",
"Ruddy",
"Travers",
"Chery",
"Brittany",
"Chery",
"Nickie",
"Karyl",
"Jeanine",
"Antonina",
"Ailyn",
"Claribel",
"Nikos",
"Jory",
"Aguste",
"Brant",
"Sissie",
"Herbert",
"Simonne",
"Berton",
"Emerson",
"Dita",
"Jorgan",
"Tarrah",
"Clari",
"Jennica",
"Geraldine",
"Rik",
"Bel",
"Toni",
"Sibel",
"Christa",
"Tuckie",
"Winnie",
"Delia",
"Ozzy",
"Rainer",
"Denna",
"Baxter",
"Miranda",
"Shaine",
"Lorenzo",
"Vanya",
"Jacquetta",
"Gabrielle",
"Alvira",
"Serena",
"Leslie",
"Brockie",
"Matias",
"Jeromy",
"Aaron",
"Benni",
"Lorrie",
"Ulla",
"Demetre",
"Panchito",
"Calla",
"Leshia",
"Wyn",
"Hollyanne",
"Ladonna",
"Ilario",
"Lita",
"Sky",
"Kahaleel",
"Ginnie",
"Moise",
"Diane-marie",
"Jdavie",
"Shellie",
"Clemmie",
"Cookie",
"Deny",
"Tamara",
"Charlean",
"Darla",
"Erie",
"Davin",
"Ladonna",
"Micky",
"Mathew",
"Bertie",
"Gretchen",
"Lurleen",
"Krishna",
"Raina",
"Rabi",
"Lorin",
"Isabella",
"Christel",
"Danita",
"Tallulah",
"Virgie",
"Leelah",
"Ethel",
"Agace",
"Lula",
"Morley",
"Jerrold",
"Leticia",
"Spense",
"Gabriell",
"Elroy",
"Esma",
"Carmen",
"Morganne",
"Tudor",
"Alyce",
"Romona",
"Nina",
"Emory",
"Shermy",
"Kale",
"Arlette",
"Shani",
"Brnaby",
"Onfre",
"Tomlin",
"Rocky",
"Marinna",
"Ofella",
"Cart",
"Sayres",
"Anastasie",
"Sephira",
"Sonny",
"Fitzgerald",
"Elizabet",
"Roseanne",
"Arlan",
"Darice",
"Sheeree",
"Leisha",
"Nerissa",
"Kay",
"Philippine",
"Coreen",
"Jud",
"Stanleigh",
"Kizzee",
"Ambros",
"Jedediah",
"Winifield",
"Beryl",
"Yalonda",
"Xaviera",
"Linnea",
"Andonis",
"Dell",
"Chris",
"Rakel",
"Lia",
"Gabriela",
"Maureen",
"Etty",
"Fayette",
"Tremaine",
"Erda",
"Putnam",
"Mychal",
"Margery",
"Dorise",
"Annemarie",
"Rebbecca",
"Paulina",
"Angelina",
"Helen-elizabeth",
"Nichols",
"Hort",
"Helenka",
"Michal",
"Helen",
"April",
"Heindrick",
"Rebekah",
"Orren",
"Kellen",
"Ben",
"Lanae",
"Cherise",
"Shirlee",
"Taffy",
"Shelbi",
"Orlan",
"Wilt",
"Nettie",
"Aggie",
"Dorothea",
"Lurleen",
"Winn",
"Tiena",
"Lizzie",
"Welch",
"Lissi",
"Darryl",
"Ty",
"Kaila",
"Sorcha",
"Aili",
"Cello",
"Marlon",
"Darrel",
"Darcie",
"Ettie",
"Desmond",
"Alic",
"Greta",
"Samuel",
"Joelynn",
"Marni",
"Herschel",
"Nikaniki",
"Dalston",
"Joell",
"Hewet",
"Moises",
"Conny",
"Craggie",
"Kim",
"Franklyn",
"Jsandye",
"Austin",
"Aileen",
"Lucais",
"Eunice",
"Uriah",
"Darice",
"Janina",
"Filide",
"Gaven",
"Woody",
"Rosalyn",
"Merl",
"Yehudit",
"Olympie",
"Giuditta",
"Zondra",
"Frances",
"Ibbie",
"Kayla",
"Lynnett",
"Jard",
"Ruddy",
"Zilvia",
"Maurie",
"Hadleigh",
"Bobbee",
"Emalia",
"Clea",
"Sunny",
"Jaimie",
"Della",
"Bessie",
"Annmarie",
"Morgen",
"Staffard",
"Gertrude",
"Calhoun",
"Lulita",
"Shermie",
"Gaylene",
"Yurik",
"Jesus",
"Pietrek",
"Pasquale",
"Dilly",
"Piper",
"Archibald",
"Trixie",
"Kaia",
"Marigold",
"Albert",
"Ashley",
"Ines",
"Nickola",
"Kerri",
"Kristy",
"Gerek",
"Bernadette",
"Lovell",
"Alva",
"Michel",
"Sebastien",
"Guendolen",
"Siana",
"Jannelle",
"Dolf",
"Udale",
"Tyne",
"Randell",
"Gunar",
"Kalie",
"Glennie",
"Katine",
"Ned",
"Harley",
"Jeremiah",
"Demeter",
"Quinta",
"Arden",
"Bail",
"Pietrek",
"Camala",
"Lucky",
"Barry",
"Annetta",
"Enrichetta",
"Meagan",
"Lexis"
};
string availableLastnames[]={"Mustill",
"Landre",
"Hazley",
"Sydney",
"Bickerton",
"Chesson",
"Burris",
"Sharpe",
"O'Scandall",
"Bofield",
"Scotchmur",
"Melbury",
"Killford",
"Lehrmann",
"Eagar",
"Lembrick",
"Swinden",
"Stopper",
"Wilcox",
"Voden",
"Bromfield",
"Luchetti",
"Micco",
"Benedidick",
"Woodlands",
"Gasson",
"Leacy",
"Bess",
"Thorby",
"Davsley",
"Ivett",
"Freund",
"Arnaldi",
"Tamsett",
"Simmonds",
"Tolworthy",
"Chiverton",
"Klimkov",
"Amiss",
"Isoldi",
"Omand",
"Creagh",
"Hullin",
"Udell",
"Gland",
"Lown",
"Recher",
"Batts",
"Thirlaway",
"Sommerton",
"McGreary",
"MacGilpatrick",
"Gobbet",
"Burdett",
"Pateman",
"Cricket",
"Spridgeon",
"Andersson",
"Westrey",
"Coffin",
"Paye",
"Caldecot",
"Penrith",
"Pallas",
"Caveill",
"Ramsey",
"Hourihan",
"Ithell",
"Comello",
"Tash",
"Ladson",
"Hansill",
"Bantock",
"McCraine",
"O'Carmody",
"Ketch",
"Balf",
"Willbourne",
"Suero",
"Amery",
"Magill",
"Hopfer",
"Choppen",
"Knocker",
"Whapham",
"Geraudy",
"Docksey",
"Choke",
"Cutler",
"Yeates",
"Aughton",
"Bellin",
"Noden",
"Spanswick",
"Inskipp",
"Hamblett",
"Speares",
"Gooderick",
"Sharer",
"Fernanando",
"Pointin",
"Cornfield",
"Gatcliff",
"Yuryatin",
"Adamoli",
"Picton",
"Ramsey",
"MacCrackan",
"Jaram",
"Velasquez",
"McNamee",
"Wyldes",
"Parlour",
"Tucsell",
"Clavey",
"Paddy",
"Twallin",
"Pilmoor",
"Pirrone",
"Erdely",
"Bagguley",
"Marlin",
"Bernasek",
"Bridgewater",
"Livesay",
"Hurdle",
"Muldoon",
"Hardman",
"Tanby",
"Haggleton",
"Milius",
"Grenshiels",
"Kemm",
"Donne",
"Reynish",
"Bissett",
"Yedall",
"Bruin",
"McCandless",
"Bickerdyke",
"Wollers",
"Shone",
"Rengger",
"Tellwright",
"Sharpus",
"Beneteau",
"Antonazzi",
"Barmadier",
"Monnery",
"Vorley",
"Exrol",
"Labbez",
"Doodson",
"Stansbie",
"Yukhnini",
"Frays",
"Arpino",
"Zanini",
"Simcoe",
"Barthorpe",
"Symondson",
"Sneller",
"Birtles",
"Cornewall",
"Dengate",
"Rielly",
"Hulbert",
"Antonsson",
"McMoyer",
"Reder",
"Kew",
"Ellacott",
"Stirley",
"Wingeatt",
"Kesteven",
"Oulet",
"Selbach",
"Lawrenceson",
"Fould",
"Aldridge",
"Joule",
"Mawne",
"Bache",
"Tarply",
"Feckey",
"Llewhellin",
"Duncklee",
"Eaglestone",
"Jovasevic",
"Kirsch",
"Chalfont",
"Maureen",
"Forrington",
"Starmore",
"Brawn",
"Sebley",
"Skedge",
"Pflieger",
"Viollet",
"Yellep",
"Champion",
"Ledeker",
"Olek",
"Kuzemka",
"Dun",
"Brumhead",
"Goudard",
"Jeannet",
"Cutriss",
"Kells",
"Samples",
"Hadenton",
"Fawdrie",
"Mattiussi",
"Summergill",
"Puckrin",
"Adamovicz",
"Andrusyak",
"Joplin",
"Hulett",
"Culleford",
"Castella",
"Eathorne",
"Pozer",
"Lowater",
"Lafont",
"Hollyard",
"Mazey",
"Attew",
"Dumbar",
"Webland",
"Romayne",
"MacKim",
"Carsey",
"Duckinfield",
"Stede",
"Thomazin",
"Jamson",
"Gibb",
"Childrens",
"Rotter",
"McGrale",
"Ebbett",
"Clinton",
"Plowright",
"Penhaligon",
"Gregorio",
"Frankowski",
"Spittall",
"Bail",
"Gotthard",
"Teager",
"Tuftin",
"Lengthorn",
"Carlton",
"Antliff",
"Jump",
"Dabell",
"Ghidelli",
"Ruegg",
"Winspar",
"Mawditt",
"Hobgen",
"Moyler",
"Wicklin",
"Pedro",
"Bickley",
"Urion",
"Dornin",
"Spraggon",
"Cozby",
"Iglesias",
"Ellgood",
"Wynch",
"Kassel",
"Rushmere",
"Bygate",
"Meeus",
"Slack",
"Gon",
"Gosney",
"Beattie",
"Scully",
"Snufflebottom",
"Hollingdale",
"Hollows",
"MacCorley",
"Worsfold",
"Ketchaside",
"Ellse",
"Feldharker",
"Leer",
"Giffkins",
"Christofor",
"Hawkswell",
"Rabbatts",
"Hellen",
"Ogilvie",
"Woodus",
"Meak",
"Rait",
"Sandcroft",
"Baddiley",
"Howatt",
"Porcher",
"Stowers",
"Trickey",
"Marner",
"Millmoe",
"Sinderland",
"Henworth",
"Stealy",
"Ivoshin",
"Skerritt",
"Fincken",
"Wilmott",
"Steffens",
"McCritchie",
"Mundee",
"Dunmore",
"Gabbatiss",
"Meus",
"Larwood",
"McKeurton",
"Revie",
"Cortnay",
"Ketley",
"Frampton",
"Gadsby",
"Rainsbury",
"Cauderlie",
"Ungerechts",
"Sayer",
"Fairhurst",
"Bentz",
"Wilcott",
"Benneton",
"Goadsby",
"Vaud",
"Heinrici",
"Pilmoor",
"Farncomb",
"Sconce",
"Engley",
"Pardal",
"Tomkin",
"Seignior",
"Easun",
"Scamadine",
"Burleigh",
"Fairburne",
"Crosetti",
"Reide",
"Zavattieri",
"Crose",
"Ovenell",
"Butchart",
"O'Murtagh",
"Glascott",
"Wilks",
"Huertas",
"Aizikovitch",
"Copozio",
"McGuinley",
"Dorey",
"Ferson",
"Levane",
"Olivazzi",
"Spensly",
"Cortes",
"Wilstead",
"Christian",
"Henden",
"Kennedy",
"Markham",
"Dohrmann",
"Kernes",
"Scini",
"Halhead",
"Tindle",
"Ramas",
"Noddles",
"Wolver",
"Dorin",
"Rodolphe",
"Segeswoeth",
"Sweedy",
"Astles",
"Wingfield",
"Poynser",
"Ivons",
"Padell",
"Buche",
"Dorn",
"Thaine",
"Leyson",
"Stretton",
"McRuvie",
"Goater",
"McCrone",
"McCaskell",
"Arnao",
"Loudiane",
"Haddleston",
"Leah",
"Peltzer",
"Ditt",
"Thomkins",
"Billson",
"Grinaugh",
"Yateman",
"Thoresbie",
"Shakspeare",
"Broomhall",
"Sibbert",
"MacDunlevy",
"Sagar",
"Cutchey",
"McKibben",
"Stilldale",
"Battrick",
"Iorizzo",
"FitzGibbon",
"Stollenbeck",
"Sulman",
"Macvain",
"Hurdidge",
"Graundisson",
"MacMeanma",
"O'Hern",
"Felkin",
"Sporrij",
"Ottewill",
"Olpin",
"Fairholme",
"Dana",
"Matusov",
"Hauxwell",
"Singh",
"Meakes",
"Peerman",
"MacEveley",
"Voysey",
"Misken",
"Swalwell",
"Dimblebee",
"Forge",
"Godfery",
"Mosson",
"Slaney",
"Lynagh",
"Tuison",
"Donalson",
"Booley",
"DelaFeld",
"Brownsword",
"Piotrkowski",
"Spieck",
"Rankin",
"Schaumann",
"Benettolo",
"Suff",
"Reicharz",
"Addyman",
"Starling",
"Coddrington",
"Campes",
"Hacksby",
"Wanne",
"Bruntje",
"Eades",
"Dedmam",
"Cansdell",
"Marchington",
"Ebbett",
"Juggings",
"Foltin",
"Elcoate",
"Clarke",
"Dagon",
"Payler",
"Rother",
"Dieton",
"Falks",
"Willerstone",
"Struys",
"Ormistone",
"Beernt",
"Bluett",
"Poxon",
"Dalligan",
"Trembath",
"Madill",
"Reynoldson",
"Dyball",
"Rodell",
"Scough",
"Fison",
"Bannell",
"Cotterel",
"Ransom",
"Tipperton",
"Lorentzen",
"Filyushkin",
"Gethen",
"Blaby",
"Patriskson",
"Shilliday",
"Lulham",
"Spennock",
"Hymor",
"Marconi",
"Wilhelmy",
"Sebring",
"Budleigh",
"Melsom",
"Idenden",
"Essery",
"Tudge",
"Brehaut",
"Hackworthy",
"Brimilcombe",
"Moorhouse",
"Fairleigh",
"Learmouth",
"Haryngton",
"Jammes",
"Fosberry",
"Hallen",
"Shenfish",
"Dillinger",
"Pengilly",
"Soame",
"Jachimiak",
"Sullivan",
"Sherbourne",
"Elsie",
"Bosden",
"Riseam",
"St.Paul",
"Clopton",
"Pershouse",
"Buncher",
"Schubbert",
"Chalfain",
"Scullion",
"Grenter",
"Haken",
"Fairman",
"Berk",
"Tetley",
"Pinnock",
"Bodleigh",
"Snoddon",
"Bearns",
"Leithgoe",
"Brighty",
"Kegley",
"Rockwill",
"Mattsson",
"Hordle",
"Slainey",
"Valder",
"Weyland",
"Barhem",
"Billings",
"Beau",
"Robertsson",
"Coldham",
"Pepperill",
"Donovin",
"Ruskin",
"Furnell",
"Orring",
"Phebee",
"Trumpeter",
"Briatt",
"Bletsoe",
"Grassin",
"Normanville",
"Perell",
"Gilders",
"DeMoreno",
"Goulstone",
"Sowman",
"Hymas",
"Penwright",
"VanHault",
"Clifforth",
"Leeburne",
"Garbar",
"Eveleigh",
"Labbett",
"Senior",
"Yorkston",
"Ranyard",
"Gammidge",
"Goodoune",
"Matiebe",
"Tomek",
"Clace",
"Rawls",
"Wurz",
"Fuentez",
"Kevis",
"Guiness",
"Carlan",
"Causer",
"Bowling",
"Phillins",
"Jedrachowicz",
"Macauley",
"Wasmer",
"Steffans",
"Mooreed",
"Sannes",
"Godilington",
"Willeman",
"Darycott",
"Burrass",
"Drewitt",
"Prestwich",
"Volette",
"Briscam",
"Cossentine",
"Stalf",
"Canfield",
"Cheeld",
"Bleyman",
"McParland",
"Lowfill",
"Darwent",
"Graybeal",
"Mougin",
"Neame",
"Sermin",
"Portail",
"Gillison",
"Totterdill",
"Cheavin",
"Torald",
"Moy",
"Cufley",
"Matthewman",
"Goldstein",
"Hoston",
"Scarbarrow",
"Brabben",
"Gherardesci",
"Talloe",
"Llorens",
"Bazylets",
"Nutton",
"Jentin",
"Burthom",
"Rowberry",
"MacKeller",
"Matuszyk",
"Hagstone",
"Vurley",
"Hotson",
"Broster",
"Preddle",
"Ferrone",
"Dodimead",
"Looks",
"Heisham",
"Jeyes",
"Whal",
"Tubb",
"Domico",
"Cawker",
"Gadeaux",
"Leel",
"Aldersey",
"Veld",
"Roper",
"McLaren",
"Sinkins",
"Taberer",
"Sanbrook",
"Kisby",
"Tourot",
"Wadie",
"Dinesen",
"Edgar",
"Sumnall",
"Blowes",
"Rosenblath",
"Gulliver",
"Bunch",
"Surcomb",
"Doble",
"Morrallee",
"Tolworthie",
"Chung",
"Millery",
"Jacobson",
"Pitceathly",
"Gerritzen",
"Lownsbrough",
"Lowdeane",
"McGovern",
"Fisbey",
"Deller",
"Gilvear",
"Citrine",
"Aspy",
"Lazer",
"Munt",
"Macvain",
"Weins",
"Lyddyard",
"Kix",
"Orteu",
"Wones",
"Gault",
"Greatbanks",
"Astley",
"Lardner",
"Haddleton",
"Mantripp",
"Booton",
"Rubinchik",
"Bourthoumieux",
"Kauscher",
"Ireson",
"Barstock",
"Redan",
"Dinsey",
"Mitchiner",
"Poon",
"McElane",
"Skipping",
"Filipovic",
"Worsalls",
"Dudman",
"Whooley",
"O'Moylan",
"Dall",
"Hamblington",
"Northin",
"Clucas",
"Skippings",
"Will",
"Howton",
"Chansonne",
"Clace",
"Pidgeley",
"Reuben",
"Caesman",
"Layzell",
"Hurdman",
"Regglar",
"Bagge",
"Peron",
"Themann",
"Derkes",
"Pillington",
"Jakubowicz",
"Wake",
"Laetham",
"Ivic",
"Plumridge",
"Salters",
"Brayne",
"Barwis",
"Yurkevich",
"Dundon",
"Mougin",
"Cato",
"Btham",
"DiFranceshci",
"Doulton",
"Lapsley",
"Iseton",
"Gawn",
"O'Fallowne",
"Munday",
"Beadnall",
"Jenckes",
"Avrahamian",
"Shorey",
"Droogan",
"Gillooly",
"Eastmead",
"Rollin",
"Foxten",
"Stirton",
"Ewestace",
"Woolstenholmes",
"Haack",
"Coade",
"Djurevic",
"Bazely",
"Mayer",
"Reid",
"Wassell",
"Fewster",
"Gerhts",
"Battyll",
"Barttrum",
"Orbine",
"Drayn",
"Firpo",
"Hemeret",
"Brahams",
"Boxe",
"Spurling",
"Norvell",
"Flockhart",
"Bonnar",
"Lindholm",
"Birks",
"Jess",
"Baber",
"Clunan",
"Rizziello",
"Ewert",
"Sherry",
"Toffaloni",
"Blasgen",
"Bartzen",
"Tompion",
"Ilott",
"Crossfeld",
"Neggrini",
"Blann",
"Hazelby",
"Slowgrove",
"VanderKruys",
"Weildish",
"Paolazzi",
"Ellery",
"Eads",
"LeEstut",
"Jacobs",
"Whenham",
"Crevagh",
"Bogie",
"Morigan",
"Hallet",
"Vennings",
"Hellen",
"Skaid",
"Gilluley",
"Zellmer",
"Greguol",
"Servant",
"Dubbin",
"Summersett",
"Choake",
"Hakewell",
"Croxford",
"Sephton",
"Byford",
"Brownjohn",
"Dring",
"Mence",
"Fahy",
"Southernwood",
"Lukash",
"Edsell",
"Shenfisch",
"Pringuer",
"Skally",
"Hazle",
"Parradice",
"Devanney",
"Fullilove",
"Barajaz",
"Nolleth",
"Winley",
"Hofton",
"Gazey",
"McIleen",
"Ovise",
"Marioneau",
"Geary",
"Noddle",
"Shadrack",
"Teaz",
"Yeldham",
"Wallbanks",
"Skeemer",
"Fatscher",
"Paffett",
"Ortler",
"Pirnie",
"Anniwell",
"Thurske",
"Gawthrope",
"Lonie",
"Cramond",
"Mushet",
"Hanhardt",
"Loveguard",
"McKirton",
"Rittelmeyer",
"Goodchild",
"Fearnill",
"Lightbody",
"Crathern",
"Drinkel",
"Escolme",
"Skirrow",
"O'Grogane",
"Kristof",
"Coates",
"Marishenko",
"Luetkemeyer",
"Joust",
"Greedy",
"Espin",
"Giff",
"Weond",
"Abeau",
"McBoyle",
"Pickworth",
"O'Bradden",
"Pyecroft",
"Fike",
"Shadrach",
"Gunbie",
"Full",
"Godwin",
"Kiwitz",
"Rihanek",
"Chichgar",
"Dwyr",
"Everiss",
"Mordecai",
"Bownes",
"Matousek",
"Winsiowiecki",
"Rignoldes",
"Burch",
"Gabites",
"Willoughby",
"Bruff",
"Flipek",
"Bickers",
"Borrow",
"Kellaway",
"Cowderay",
"Bleckly",
"Pomphrey",
"Novotni",
"Beavis",
"Knewstub",
"VanDerWeedenburg",
"Sleight",
"Swaite",
"Fenemore",
"Topping",
"Bagg",
"Giovannetti",
"Chasmoor",
"Keunemann",
"Qualtrough",
"Snelle",
"Jobke",
"Keilloh",
"Arnault",
"McCarrick",
"McAviy",
"Constantine",
"Bonicelli",
"Dressel",
"Renhard",
"Shellcross",
"Dowers",
"Cratchley",
"Marflitt",
"Wickes",
"Horsey",
"Watchorn",
"McGinley",
"Rosenwasser",
"Swainsbury",
"Twitchett",
"Chumley",
"Andreotti",
"Bartrum",
"Lowing",
"Ivasechko",
"Kalewe",
"Whitmell",
"Bwye",
"Cockell",
"Ledram",
"Hennemann",
"Overnell",
"Youings",
"Stubbin",
"Rapport",
"Jentle",
"Matashkin",
"Songist",
"Albiston",
};


struct studentInfo {
    string fisrtname = "", lastname = "";
    double homeworkScore = 0, examScore = 0, median = 0, average = 0, averageM = 0;
};

struct arrayDataInt{
    int *array = nullptr;
    int size = 0;
};

arrayDataInt generateGrades(){
    arrayDataInt newStorage;
    int *grades = new int[201];
    int numberOfGrades = rand() % 200;
    for (int i = 0; i < numberOfGrades+1; i++)
    {
        grades[i] = (rand() % 11);
    }
    newStorage.array = grades;
    newStorage.size = numberOfGrades+1;
    return newStorage;
}

int generateExamScore(){
    return (rand() % 11);
}

string generateFirstName(){
    return availableNames[rand() % 1000];
}

string generateLastNames(){
    return availableLastnames[rand() % 1000];
}

void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted){
    std::cout<<"Fisrtname: "<<studentInfoToBePrinted.fisrtname<<endl;
    std::cout<<"lastname: "<<studentInfoToBePrinted.lastname<<endl;
    std::cout<<"homeworkScore: "<<studentInfoToBePrinted.homeworkScore<<endl;
    std::cout<<"examScore: "<<studentInfoToBePrinted.examScore<<endl;
    std::cout<<"median: "<<studentInfoToBePrinted.median<<endl;
    std::cout<<"average: "<<studentInfoToBePrinted.average<<endl;
    std::cout<<"averageM: "<<studentInfoToBePrinted.averageM<<endl;
}

double calculateAverage(double score, double examScore){
    return 0.4 * score + 0.6 * examScore;
}

int findLongestName(studentInfo data[], int size){
    int longestName = 0;
    for (int i = 0; i < size; i++)
    {
        if (longestName < data[i].fisrtname.length())
        {
            longestName = data[i].fisrtname.length();
        }   
    }
    return longestName;
}

int findLongestLastname(studentInfo data[], int size){
    int longestLastname = 0;
    for (int i = 0; i < size; i++)
    {
        if (longestLastname < data[i].lastname.length())
        {
            longestLastname = data[i].lastname.length();
        }   
    }
    return longestLastname;
}

void invalidInput(){
    std::cout<<"-----------------------------------" << endl;
    std::cout<<"           Invalid Input           " << endl;
    std::cout<<"-----------------------------------" << endl << endl;

}


int selectionOptionValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "How would you like to enter data?" << endl;
        std::cout << "1 - by hand, 2 - generate grades, 3 - generate grades, first and last names, 4 - exit program" << endl;
        regex pat {R"(^([1-3]|4))"};
        string tmp = "";
        getline(std::cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
        }
    }
    return selection;
}

int selectionEntryValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "Are you done with data entry?" << endl;
        std::cout << "1 - no, 2 - yes" << endl;
        regex pat {R"(^(1|2))"};
        string tmp = "";
        getline(std::cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
        }
    }
    return selection;
}

int selectionGenerationValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "How many students data should be generated? (1-1000)" << endl;
        regex pat {R"(^([1-9]|[1-9][0-9]{1,2}|1000))"};
        string tmp = "";
        getline(std::cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
        }
    }
    return selection;
}

int selectionDisplayValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << endl << "How would you like to see the data?" << endl;
        std::cout << "1 - \"Galutinis(Vid.)\", 2 - \"Galutinis(Med.)\", 3 - \"Galutinis(Vid.) / Galutinis(Med.)\"" << endl;
        regex pat {R"(^([1-2]|3))"};
        string tmp = "";
        getline(std::cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
        }
    }
    return selection;
}

studentInfo singleInputModule(int selection){
    
    studentInfo newStudentInfo;

    switch (selection)
    {
        case 1:
        {
            bool nameValid = false;
            while (!nameValid)
            {
                regex pat {R"(^([a-zA-Z]{2,}\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\s?([a-zA-Z]{1,})?))"};
                std::cout<<"Please enter fullname of the student: "<<endl;
                string tmp = "";
                getline(std::cin, tmp);
                smatch sm;
                nameValid = regex_match(tmp,sm,pat);
                if (!nameValid)
                {
                    invalidInput();
                }else
                {
                    size_t spaceLocation = tmp.find(" ");
                    newStudentInfo.fisrtname = tmp.substr(0, spaceLocation);
                    newStudentInfo.lastname = tmp.substr(spaceLocation+1, tmp.length());
                }
            }
            break;
        }
        case 2:
        {
            bool nameValid = false;
            while (!nameValid)
            {
                regex pat {R"(^([a-zA-Z]{2,}\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\s?([a-zA-Z]{1,})?))"};
                std::cout<<"Please enter fullname of the student: "<<endl;
                string tmp = "";
                getline(std::cin, tmp);
                smatch sm;
                nameValid = regex_match(tmp,sm,pat);
                if (!nameValid)
                {
                    invalidInput();
                }else
                {
                    size_t spaceLocation = tmp.find(" ");
                    newStudentInfo.fisrtname = tmp.substr(0, spaceLocation);
                    newStudentInfo.lastname = tmp.substr(spaceLocation+1, tmp.length());
                }
            }
            break;
        }
        case 3:
        {
            string firstName = generateFirstName();
            string lastName = generateLastNames();
            std::cout<< "Generated name: " << firstName << " " << lastName << endl;
            newStudentInfo.fisrtname = firstName;
            newStudentInfo.lastname = lastName;
            break;
        }
    }
    

    
    switch (selection)
    {
        case 1:
        {
            int grades[201];
            int xr = 0;
            bool areWeDone = false;
            while (!areWeDone) {
            if (xr == 200) {
                areWeDone = true;
            } else {

                std::cout << "Please enter the grade number " << xr + 1 << ": " << endl;
                regex patGrade {R"(^([0-9]|10))"};
                bool singleGradeInvalid = false;
                while (!singleGradeInvalid) {

                string tmpSingle = "";
                getline(std::cin, tmpSingle);
                smatch sm;
                singleGradeInvalid = regex_match(tmpSingle, sm, patGrade);
                if (!singleGradeInvalid) {
                    invalidInput();
                } else {
                    grades[xr] = stoi(tmpSingle);
                    xr++;
                }

                }
                if (selectionEntryValidator() == 2) {
                areWeDone = true;
                }
            }
            }

            sort(grades, grades + xr);

            int homeWorkToalScore = 0;
            for (int i = 0; i < xr; i++) {
            homeWorkToalScore += grades[i];
            }

            if (xr != 0) {
            newStudentInfo.homeworkScore = (double) homeWorkToalScore / xr;
            }
            int numberOfHomeWork = xr;
            if (numberOfHomeWork % 2 == 0) {
            newStudentInfo.median = (grades[(numberOfHomeWork / 2)] + grades[(numberOfHomeWork / 2) - 1]) / 2.0;
            } else {
            newStudentInfo.median = grades[(numberOfHomeWork / 2)];
            }

            bool examScoreValid = false;
            while (!examScoreValid) {
            regex pat {R"(^([0-9]|10))"};
            std::cout << "Please enter the students exam score: " << endl;
            string tmp = "";
            getline(std::cin, tmp);
            smatch sm;
            examScoreValid = regex_match(tmp, sm, pat);
            if (!examScoreValid) {
                invalidInput();
            } else {
                newStudentInfo.examScore = stoi(tmp);
            }
            }
            break;
        }
        case 2:
        {
            arrayDataInt  generatedGrades = generateGrades();
            int examScore = generateExamScore();

            std::cout<< "Auto generated grades: ";
            for(int i = 0; i < generatedGrades.size; i++){
                std::cout << generatedGrades.array[i] << " ";
            }
            std::cout << endl << "Auto generated exam score: " << examScore << endl << endl;

            sort(generatedGrades.array, generatedGrades.array + generatedGrades.size);

            int homeWorkToalScore = 0;
            for (int i = 0; i < generatedGrades.size; i++)
            {
                homeWorkToalScore += generatedGrades.array[i];
            }

            if (generatedGrades.size != 0)
            {
                newStudentInfo.homeworkScore = (double)homeWorkToalScore/generatedGrades.size;
            }

            int numberOfHomeWork = generatedGrades.size;
            if (numberOfHomeWork%2 == 0)
            {
                newStudentInfo.median = (generatedGrades.array[(numberOfHomeWork/2)] + generatedGrades.array[(numberOfHomeWork/2)-1]) / 2.0;
            }else{
                newStudentInfo.median = generatedGrades.array[(numberOfHomeWork/2)];
            }
            newStudentInfo.examScore = examScore;

            delete[] generatedGrades.array;
            break;
        }
        case 3:
        {
            arrayDataInt generatedGrades = generateGrades();
            int examScore = generateExamScore();

            std::cout<< "Auto generated grades: ";
            for(int i = 0; i < generatedGrades.size; i++){
                std::cout << generatedGrades.array[i] << " ";
            }
            std::cout << endl << "Auto generated exam score: " << examScore << endl << endl;

            sort(generatedGrades.array, generatedGrades.array + generatedGrades.size);

            int homeWorkToalScore = 0;
            for (int i = 0; i < generatedGrades.size; i++)
            {
                homeWorkToalScore += generatedGrades.array[i];
            }

            if (generatedGrades.size != 0)
            {
                newStudentInfo.homeworkScore = (double)homeWorkToalScore/generatedGrades.size;
            }

            int numberOfHomeWork = generatedGrades.size;
            if (numberOfHomeWork%2 == 0)
            {
                newStudentInfo.median = (generatedGrades.array[(numberOfHomeWork/2)] + generatedGrades.array[(numberOfHomeWork/2)-1]) / 2.0;
            }else{
                newStudentInfo.median = generatedGrades.array[(numberOfHomeWork/2)];
            }
            newStudentInfo.examScore = examScore;
            delete[] generatedGrades.array;
            break;
        }
    }
    return newStudentInfo;
}

void resulter(studentInfo allStudentInfo[], int size){
    if (size == 0)
    {
        std::cout << "No data was found..." << endl;
    }else{
        for (int i = 0; i < size; i++)
        {
            allStudentInfo[i].average = calculateAverage(allStudentInfo[i].homeworkScore, allStudentInfo[i].examScore);
            allStudentInfo[i].averageM = calculateAverage(allStudentInfo[i].median, allStudentInfo[i].examScore);
        }
        int longestName = findLongestName(allStudentInfo, size);
        int longestLastname = findLongestLastname(allStudentInfo, size);
        int selection = selectionDisplayValidator();

         std::cout << "Pavarde";
        if (longestLastname<10)
        {
            std::cout << "   ";
        }else{
            for (int i = 0; i < longestLastname-7+2; i++)
            {
                std::cout << " ";
            }
        }
        
        std::cout << "Vardas";
        if (longestName < 9)
        {
            std::cout << "   ";
        }else{
            for (int i = 0; i < longestName-6+2; i++)
            {
                std::cout << " ";
            }
        }

        switch (selection)
        {
        case 1:
            std::cout << "Galutinis (Vid).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                std::cout << "-";
            }
            std::cout << "-----------------" << endl;
            break;
        case 2:
            std::cout << "Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                std::cout << "-";
            }
            std::cout << "-----------------" << endl;
            break;
        case 3:
            std::cout << "Galutinis (Vid). / Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                std::cout << "-";
            }
            std::cout << "-----------------------------------" << endl;
        break;
        }

        for (int i = 0; i < size; i++)
        {
            std::cout << allStudentInfo[i].lastname;
            if (longestLastname < 10)
            {
                for (int y = 0; y < (10 - allStudentInfo[i].lastname.length()); y++)
                {
                    std::cout << " ";
                }
            }else{
                for (int y = 0; y < (longestLastname - allStudentInfo[i].lastname.length())+2; y++)
                {
                    std::cout << " ";
                }
            }
            
            std::cout << allStudentInfo[i].fisrtname;
            if (longestName < 9)
            {
                for (int y = 0; y < (9 - allStudentInfo[i].fisrtname.length()); y++)
                {
                    std::cout << " ";
                }
            }else{
                for (int y = 0; y < (longestName - allStudentInfo[i].fisrtname.length())+2; y++)
                {
                    std::cout << " ";
                }
            }
            
            switch (selection)
            {
            case 1:
                std::cout<< fixed << setprecision(2) << allStudentInfo[i].average << endl;
                break;
            case 2:
                std::cout<< fixed << setprecision(2) << allStudentInfo[i].averageM << endl;
                break;
            case 3:
                if(allStudentInfo[i].average == 10){
                    std::cout<< fixed << setprecision(2) << allStudentInfo[i].average << "              " << allStudentInfo[i].averageM << endl;
                }else{
                    std::cout<< fixed << setprecision(2) << allStudentInfo[i].average << "               " << allStudentInfo[i].averageM << endl;
                }
                break;
            }
        }   
    }
}

int main() {
    srand(time(0));

    studentInfo allStudentInfo[1001];
    std::cout << "Hello,\nYou will be asked to enter students data.\nPress Enter to Continue.\n";
    cin.ignore();
    bool notDone = true;
    while (notDone)
    {
        int selection = selectionOptionValidator();
        int iterator = 0;
        switch (selection)
        {
        case 1:
        {
            allStudentInfo[iterator] = singleInputModule(selection);
            iterator++;
            bool doneWithDataEntry = false;
            while (!doneWithDataEntry)
            {
                int option = selectionEntryValidator();
                switch (option)
                {
                case 1:
                    if (iterator == 1000)
                    {
                        doneWithDataEntry = true;
                    }else{
                        allStudentInfo[iterator] = singleInputModule(selection);
                        iterator++;
                    }
                    break;
                case 2:
                    doneWithDataEntry = true;
                    break;
                default:
                    invalidInput();
                    break;
                }
            }
            resulter(allStudentInfo, iterator);
            std::cout << endl << endl;
            break;
        }
        case 2:
        {
            allStudentInfo[iterator] = singleInputModule(selection);
            iterator++;
            bool doneWithDataEntry = false;
            while (!doneWithDataEntry)
            {
                int option = selectionEntryValidator();
                switch (option)
                {
                case 1:
                    if (iterator == 1000)
                    {
                        doneWithDataEntry = true;
                    }else{
                        allStudentInfo[iterator] = singleInputModule(selection);
                        iterator++;
                    }                    
                    break;
                case 2:
                    doneWithDataEntry = true;
                    break;
                default:
                    invalidInput();
                    break;
                }
            }
            resulter(allStudentInfo, iterator);
            std::cout << endl << endl;
            break;
        }
        case 3:
        {
            int numberOfStudentsToGenerate = selectionGenerationValidator();
            for (int i = 0; i < numberOfStudentsToGenerate; i++)
            {
                allStudentInfo[iterator] = singleInputModule(selection);
                iterator++;
            }
            resulter(allStudentInfo, iterator);
            std::cout << endl << endl;
            break;
        }
        case 4:
        {
            std::cout<< "Ending the program..." << endl <<endl;
            notDone = false;
            break;
        }
        default:
        {
            invalidInput();
            break;
        }
        }
    }
    return 0;
}

